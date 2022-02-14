#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;  //��ʼ����������

//��ȡһ��Span���󣬸ö����_freeList�ǿ�
Span* CentralCache::GetOneSpan(SpanList& list, const size_t size)
{
	//�Ȳ鿴��ǰ��spanList���Ƿ���δ����Ķ����span 
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
	//�ߵ�����˵����һ��Ͱ��û�п��е�span�ˣ�ֻ����PageCacheҪ
	PageCache::GetInstance()->Lock();
	size_t pageSize = SizeClass::NumMovePage(size);
	Span* span = PageCache::GetInstance()->NewSpan(pageSize);
	span->_isUse = true;
	span->_objSize = size;
	PageCache::GetInstance()->UnLock();

	//�Ի�ȡ����span��������з֣��зֳ�С���ڴ�	
	//����span�Ĵ���ڴ����ʼ��ַ�ʹ���ڴ���ֽ���
	char* start = reinterpret_cast<char*>(span->_pageId << PAGE_SHIFT);
	size_t bytes = span->_num << PAGE_SHIFT;
	char* end = start + bytes;

	//�Ѵ���ڴ��зֳ�����������������
	//����Ҫ������һ��ȥ��ͷ����������ȥβ��
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

	//�ѻ�ȡ����Span������뵽��Ӧ��Ͱ����
	list.Lock();
	list.PushFront(span);
	return span;
}

//batchNum����Ҫ��ȡ�����ڴ����ĸ���
//size��ÿ���ڴ������ֽ���
//���ص���ʵ�ʻ�ȡ�����ڴ����ĸ���
size_t CentralCache::FetchRangeObj(void*& start, void*& end, const size_t batchNum, const size_t size)
{
	size_t index = SizeClass::GetIndex(size); //��ȡ��Ӧ��Ͱ���±�
	this->_spanLists[index].Lock();  //����

	//��ȡ�����������һ������nullptr������������_freeListһ��Ҳ��Ϊ��
	//����Ҫ��һ���ڴ����ռ�
	Span* span = GetOneSpan(this->_spanLists[index], size); 
	assert(span != nullptr);
	assert(span->_freeList != nullptr);

	start = span->_freeList; //��ȡ���ڴ���׵�ַ
	end = start;
	size_t i = 0;
	//��Ϊ���ǻ�ȡ��span�����_freeListһ��Ϊ�ǿ�,����startһ����Ϊnullptr
	//��������ʵ�ʻ�ȡ�����ڴ�������ʼ����Ϊ1
	size_t actualNum = 1;  //ʵ�ʻ�ȡ�����ڴ�������
	while (i < batchNum - 1 && NextObj(end) != nullptr) //��Χͷɾ
	{
		end = NextObj(end);
		++i;
		++actualNum;
	}
	span->_freeList = NextObj(end); //������������_freeList
	NextObj(end) = nullptr;  //����ȡ����β��next���жϿ�����
	span->_useCount += actualNum;
	this->_spanLists[index].UnLock(); //����


	return actualNum; //����ʵ�ʻ�ȡ�����ڴ����ռ�ĸ���
}

void CentralCache::ReleaseListToSpans(void* start, const size_t size)
{
	size_t index = SizeClass::GetIndex(size); //��ȡ��Ӧ��Ͱ���±�
	this->_spanLists[index].Lock();  //����
	while (start != nullptr)
	{
		void* next = NextObj(start); //��ȡ����һ���ڴ�ĵ�ַ

		Span* span = PageCache::GetInstance()->MapObjectToSpan(start); //���ݵ�ַǿתΪPAGE_ID���ͣ����ù�ϣӳ�����õ���Ӧ��span����
		//�����С��ռ�ͷ�嵽��Ӧ��span����
		NextObj(start) = span->_freeList;
		span->_freeList = start;
		--span->_useCount; //�黹

		//˵��span���зֳ�ȥ������С���ڴ涼��������
		//���span�Ϳ����ٻ��ո�PageCache��PageCache�����ڳ���ȥ��ǰ��ҳ�ĺϲ�
		//��Ϊ���ǿ��Ը���span��pageid����PAGE_SHIFT���õ���ʼ��ַ
		//�ٸ���_num*pageid��������PAGE_SHIFT���õ�������ַ
		//�������ǾͲ���Ҫ��span�����_freeList�����е���˳��
		//���ǿ��Խ���һ���ֱַ����Ϊ�գ�Ȼ����ʹ������ַ�ռ伴��
		if (span->_useCount == 0)
		{
			this->_spanLists[index].Erase(span); //�����span����Ӹ�Ͱ��ɾ��
			span->_next = nullptr;
			span->_prev = nullptr;
			span->_freeList = nullptr;
			
			//�ͷ�span��PageCacheʱ��ʹ��PageCache�����Ϳ�����
			//��ʱ�ٰ�Ͱ�������
			this->_spanLists[index].UnLock();

			PageCache::GetInstance()->Lock();
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
			PageCache::GetInstance()->UnLock();

			this->_spanLists[index].Lock();
		}
		start = next; //ָ����һ��
	}
	this->_spanLists[index].UnLock();  //����
}
