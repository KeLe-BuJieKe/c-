#include"PageCache.h"

PageCache PageCache::_inst;

void PageCache::Lock() //加锁
{
	this->_pageMutex.lock();
}

void PageCache::UnLock() //解锁
{
	this->_pageMutex.unlock();
}

Span* PageCache::NewSpan(const size_t k)
{
	assert(k > 0);

	if (k >= NPAGES) //大于128页的内存直接找堆申请
	{
		void* ptr = SystemAlloc(k);
		//Span* span = new Span;
		Span* span = _spanPool.New();
		span->_pageId = reinterpret_cast<PAGE_ID>(ptr) >> PAGE_SHIFT;
		span->_num = k;
		//this->_idSpanMap[span->_pageId] = span;
		this->_idSpanMap.set(span->_pageId, span);
		return span;
	}

	//首先检查第k个桶里面有没有span
	if (!this->_spanLists[k].Empty())
	{
		Span* kSpan = this->_spanLists[k].PopFront();
		//建立id(页号)和span对象的映射，方便CentralCache回收小块内存时，查找对应的span
		for (PAGE_ID i = 0; i < kSpan->_num; ++i)
		{
			this->_idSpanMap.set(kSpan->_pageId + i, kSpan);
			//this->_idSpanMap[kSpan->_pageId + i] = kSpan;
		}

		return kSpan;

	}
	else
	{ 
		for (size_t i = k + 1; i < NPAGES; ++i)
		{
			if (!this->_spanLists[i].Empty())
			{
				Span* nSpan = this->_spanLists[i].PopFront();
				//Span* kSpan = new Span;
				Span* kSpan = _spanPool.New();
				//在nSpan的头部切一个k页下来，并将k页的span返回
				//然后将nSpan在挂到对应的映射的位置
				kSpan->_pageId = nSpan->_pageId;
				kSpan->_num = k;

				nSpan->_pageId += k ;
				nSpan->_num -= k;

				this->_spanLists[nSpan->_num].PushFront(nSpan);

				//存储nSpan的首尾页号跟nSpan映射，方便PageCache回收内存
				//进行的合并查找 

				/*
				this->_idSpanMap[nSpan->_pageId] = nSpan;
				this->_idSpanMap[nSpan->_pageId + nSpan->_num - 1] = nSpan;
				*/
				this->_idSpanMap.set(nSpan->_pageId, nSpan);
				this->_idSpanMap.set(nSpan->_pageId + nSpan->_num - 1, nSpan);


				//建立id(页号)和span对象的映射，方便CentralCache回收小块内存时，查找对应的span
				for (PAGE_ID i = 0; i < kSpan->_num; ++i)
				{
					//this->_idSpanMap[kSpan->_pageId + i] = kSpan;
					this->_idSpanMap.set(kSpan->_pageId + i, kSpan);
				}
				return kSpan;
			}
		}
	}

	//走到这个位置就说明没有大页的span
	//这个时候就要去找堆要一个128页的span
	//Span* bigSpan = new Span;
	Span* bigSpan = _spanPool.New();
	void* ptr = SystemAlloc(NPAGES - 1);
	bigSpan->_pageId = reinterpret_cast<PAGE_ID>(ptr) >> PAGE_SHIFT;
	bigSpan->_num = NPAGES - 1;

	this->_spanLists[bigSpan->_num].PushFront(bigSpan);
	return NewSpan(k); //为了防止写重复代码，这里将从系统中获取的空间放入到PageCache当中，最后会调用else里的代码返回
}

//获取地址的值对应的的span对象
Span* PageCache::MapObjectToSpan(void* obj)
{
	PAGE_ID id = (reinterpret_cast<PAGE_ID>(obj) >> PAGE_SHIFT);
	/*
	std::unique_lock<std::mutex> lock(this->_pageMutex);
	auto ret = this->_idSpanMap.find(id);
	if (ret != this->_idSpanMap.end())
	{
		return ret->second;
	}
	else
	{
		assert(false);
		return nullptr;
	}
	*/
	Span* ret = reinterpret_cast<Span*>(this->_idSpanMap.get(id));
	assert(ret != nullptr);
	return ret;
}

void PageCache::ReleaseSpanToPageCache(Span* span)
{
	if (span->_num >= NPAGES)	//大于128页的span直接还给堆
	{
		void* ptr = reinterpret_cast<void*>(span->_pageId << PAGE_SHIFT);
		SystemFree(ptr);
		//delete span;
		_spanPool.Delete(span);
		return;
	}

	while (true) //向前合并
	{
		PAGE_ID prevId = span->_pageId - 1;
		Span* it = reinterpret_cast<Span*>(this->_idSpanMap.get(prevId));
		//std::unordered_map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(prevId);
		/*auto it = _idSpanMap.find(prevId);
		//1、当前面的页号没有就不合并
		//2、当前面相邻页的span在使用也不去合并
		//3、合并出超出128页的span，此时PageCache的哈希桶没有办法去管理，也不去合并
		if (it == _idSpanMap.end())
		{
			break;
		}
		*/
		if (it == nullptr)
		{
			break;
		}
		Span* prevSpan = it;
		if (prevSpan->_isUse == true || ((span->_num + prevSpan->_num) > NPAGES-1))
		{
			break;
		}
		else
		{
			span->_pageId = prevSpan->_pageId;
			span->_num += prevSpan->_num;

			this->_spanLists[prevSpan->_num].Erase(prevSpan);
			//delete prevSpan;
			_spanPool.Delete(prevSpan);
		}
	}
	while (true) //向后合并
	{
		PAGE_ID nextId = span->_pageId + span->_num;
		/*std::unordered_map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(nextId);
		//auto it = _idSpanMap.find(nextId);

		//1、当后面的页号没有就不合并
		//2、当后面相邻页的span在使用也不去合并
		//3、合并出超出128页的span，此时PageCache的哈希桶没有办法去管理，也不去合并
		if (it == _idSpanMap.end())
		{
			break;
		}
		*/

		Span* it = reinterpret_cast<Span*>(this->_idSpanMap.get(nextId));
		if (it == nullptr)
		{
			break;
		}
		Span* nextSpan = it;
		if (nextSpan->_isUse == true || ((span->_num + nextSpan->_num) > NPAGES - 1))
		{
			break;
		}
		else
		{
			span->_num += nextSpan->_num;

			this->_spanLists[nextSpan->_num].Erase(nextSpan);
			//delete nextSpan;
			_spanPool.Delete(nextSpan);
		}
	}
	//将合并的大页内存放回到PageCache当中，并将使用状态更改为false
	this->_spanLists[span->_num].PushFront(span);
	span->_isUse = false;
	//更新哈希映射
	//this->_idSpanMap[span->_pageId] = span;
	//this->_idSpanMap[span->_pageId + span->_num - 1] = span;
	this->_idSpanMap.set(span->_pageId, span);
	this->_idSpanMap.set(span->_pageId + span->_num - 1, span);

}
