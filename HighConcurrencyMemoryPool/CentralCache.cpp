#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;  //初始化单例对象

//获取一个Span对象，该对象的_freeList非空
Span* CentralCache::GetOneSpan(SpanList& list, const size_t size)
{
	//先查看当前的spanList中是否还有未分配的对象的span 
	Span* obj = list.Begin();
	while (obj != list.End())
	{
		if (obj->_freeList != nullptr)
		{
			return obj;
		}
		else
		{
			obj = obj->_next;
		}
	}

	list.UnLock();
	//走到这里说明这一个桶内没有空闲的span了，只能找PageCache要
	PageCache::GetInstance()->Lock();
	size_t pageSize = SizeClass::NumMovePage(size);
	Span* span = PageCache::GetInstance()->NewSpan(pageSize);
	span->_isUse = true;
	span->_objSize = size;
	PageCache::GetInstance()->UnLock();

	//对获取到的span对象进行切分，切分成小块内存	
	//计算span的大块内存的起始地址和大块内存的字节数
	char* start = reinterpret_cast<char*>(span->_pageId << PAGE_SHIFT);
	size_t bytes = span->_num << PAGE_SHIFT;
	char* end = start + bytes;

	//把大块内存切分成自由链表并链接起来
	//首先要切下来一块去做头，方便我们去尾插
	span->_freeList = start;
	start += size;
	void* tail = span->_freeList;
	while (start < end)
	{
		NextObj(tail) = start;
		tail = start;
		start += size;
	}
	NextObj(tail) = nullptr;

	//把获取到的Span对象插入到对应的桶当中
	list.Lock();
	list.PushFront(span);
	return span;
}

//batchNum是想要获取到的内存对象的个数
//size是每个内存对象的字节数
//返回的是实际获取到的内存对象的个数
size_t CentralCache::FetchRangeObj(void*& start, void*& end, const size_t batchNum, const size_t size)
{
	size_t index = SizeClass::GetIndex(size); //获取对应的桶的下标
	this->_spanLists[index].Lock();  //加锁

	//获取到的这个对象一定不是nullptr，且这个对象的_freeList一定也不为空
	//至少要有一个内存对象空间
	Span* span = GetOneSpan(this->_spanLists[index], size); 
	assert(span != nullptr);
	assert(span->_freeList != nullptr);

	start = span->_freeList; //获取到内存的首地址
	end = start;
	size_t i = 0;
	//因为我们获取到span对象的_freeList一定为非空,所以start一定不为nullptr
	//所以我们实际获取到的内存对象的起始个数为1
	size_t actualNum = 1;  //实际获取到的内存对象个数
	while (i < batchNum - 1 && NextObj(end) != nullptr) //范围头删
	{
		end = NextObj(end);
		++i;
		++actualNum;
	}
	span->_freeList = NextObj(end); //更新这个对象的_freeList
	NextObj(end) = nullptr;  //将获取到的尾的next进行断开链接
	span->_useCount += actualNum;
	this->_spanLists[index].UnLock(); //解锁


	return actualNum; //返回实际获取到的内存对象空间的个数
}

void CentralCache::ReleaseListToSpans(void* start, const size_t size)
{
	size_t index = SizeClass::GetIndex(size); //获取对应的桶的下标
	this->_spanLists[index].Lock();  //加锁
	while (start != nullptr)
	{
		void* next = NextObj(start); //获取到下一个内存的地址

		Span* span = PageCache::GetInstance()->MapObjectToSpan(start); //根据地址强转为PAGE_ID类型，利用哈希映射来得到对应的span对象
		//将这个小块空间头插到对应的span对象
		NextObj(start) = span->_freeList;
		span->_freeList = start;
		--span->_useCount; //归还

		//说明span的切分出去的所有小块内存都还回来了
		//这个span就可以再回收给PageCache，PageCache可以在尝试去做前后页的合并
		//因为我们可以根据span的pageid左移PAGE_SHIFT来得到起始地址
		//再根据_num*pageid，再左移PAGE_SHIFT来得到结束地址
		//这样我们就不需要对span对象的_freeList来进行调整顺序
		//我们可以将这一块地址直接置为空，然后再使用这块地址空间即可
		if (span->_useCount == 0)
		{
			this->_spanLists[index].Erase(span); //将这个span对象从该桶中删除
			span->_next = nullptr;
			span->_prev = nullptr;
			span->_freeList = nullptr;
			
			//释放span给PageCache时，使用PageCache的锁就可以了
			//这时再把桶锁给解掉
			this->_spanLists[index].UnLock();

			PageCache::GetInstance()->Lock();
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
			PageCache::GetInstance()->UnLock();

			this->_spanLists[index].Lock();
		}
		start = next; //指向下一个
	}
	this->_spanLists[index].UnLock();  //加锁
}
