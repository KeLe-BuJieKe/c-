#include"PageCache.h"

PageCache PageCache::_inst;

void PageCache::Lock() //����
{
	this->_pageMutex.lock();
}

void PageCache::UnLock() //����
{
	this->_pageMutex.unlock();
}

Span* PageCache::NewSpan(const size_t k)
{
	assert(k > 0);

	if (k >= NPAGES) //����128ҳ���ڴ�ֱ���Ҷ�����
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

	//���ȼ���k��Ͱ������û��span
	if (!this->_spanLists[k].Empty())
	{
		Span* kSpan = this->_spanLists[k].PopFront();
		//����id(ҳ��)��span�����ӳ�䣬����CentralCache����С���ڴ�ʱ�����Ҷ�Ӧ��span
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
				//��nSpan��ͷ����һ��kҳ����������kҳ��span����
				//Ȼ��nSpan�ڹҵ���Ӧ��ӳ���λ��
				kSpan->_pageId = nSpan->_pageId;
				kSpan->_num = k;

				nSpan->_pageId += k ;
				nSpan->_num -= k;

				this->_spanLists[nSpan->_num].PushFront(nSpan);

				//�洢nSpan����βҳ�Ÿ�nSpanӳ�䣬����PageCache�����ڴ�
				//���еĺϲ����� 

				/*
				this->_idSpanMap[nSpan->_pageId] = nSpan;
				this->_idSpanMap[nSpan->_pageId + nSpan->_num - 1] = nSpan;
				*/
				this->_idSpanMap.set(nSpan->_pageId, nSpan);
				this->_idSpanMap.set(nSpan->_pageId + nSpan->_num - 1, nSpan);


				//����id(ҳ��)��span�����ӳ�䣬����CentralCache����С���ڴ�ʱ�����Ҷ�Ӧ��span
				for (PAGE_ID i = 0; i < kSpan->_num; ++i)
				{
					//this->_idSpanMap[kSpan->_pageId + i] = kSpan;
					this->_idSpanMap.set(kSpan->_pageId + i, kSpan);
				}
				return kSpan;
			}
		}
	}

	//�ߵ����λ�þ�˵��û�д�ҳ��span
	//���ʱ���Ҫȥ�Ҷ�Ҫһ��128ҳ��span
	//Span* bigSpan = new Span;
	Span* bigSpan = _spanPool.New();
	void* ptr = SystemAlloc(NPAGES - 1);
	bigSpan->_pageId = reinterpret_cast<PAGE_ID>(ptr) >> PAGE_SHIFT;
	bigSpan->_num = NPAGES - 1;

	this->_spanLists[bigSpan->_num].PushFront(bigSpan);
	return NewSpan(k); //Ϊ�˷�ֹд�ظ����룬���ｫ��ϵͳ�л�ȡ�Ŀռ���뵽PageCache���У��������else��Ĵ��뷵��
}

//��ȡ��ַ��ֵ��Ӧ�ĵ�span����
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
	if (span->_num >= NPAGES)	//����128ҳ��spanֱ�ӻ�����
	{
		void* ptr = reinterpret_cast<void*>(span->_pageId << PAGE_SHIFT);
		SystemFree(ptr);
		//delete span;
		_spanPool.Delete(span);
		return;
	}

	while (true) //��ǰ�ϲ�
	{
		PAGE_ID prevId = span->_pageId - 1;
		Span* it = reinterpret_cast<Span*>(this->_idSpanMap.get(prevId));
		//std::unordered_map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(prevId);
		/*auto it = _idSpanMap.find(prevId);
		//1����ǰ���ҳ��û�оͲ��ϲ�
		//2����ǰ������ҳ��span��ʹ��Ҳ��ȥ�ϲ�
		//3���ϲ�������128ҳ��span����ʱPageCache�Ĺ�ϣͰû�а취ȥ����Ҳ��ȥ�ϲ�
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
	while (true) //���ϲ�
	{
		PAGE_ID nextId = span->_pageId + span->_num;
		/*std::unordered_map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(nextId);
		//auto it = _idSpanMap.find(nextId);

		//1���������ҳ��û�оͲ��ϲ�
		//2������������ҳ��span��ʹ��Ҳ��ȥ�ϲ�
		//3���ϲ�������128ҳ��span����ʱPageCache�Ĺ�ϣͰû�а취ȥ����Ҳ��ȥ�ϲ�
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
	//���ϲ��Ĵ�ҳ�ڴ�Żص�PageCache���У�����ʹ��״̬����Ϊfalse
	this->_spanLists[span->_num].PushFront(span);
	span->_isUse = false;
	//���¹�ϣӳ��
	//this->_idSpanMap[span->_pageId] = span;
	//this->_idSpanMap[span->_pageId + span->_num - 1] = span;
	this->_idSpanMap.set(span->_pageId, span);
	this->_idSpanMap.set(span->_pageId + span->_num - 1, span);

}
