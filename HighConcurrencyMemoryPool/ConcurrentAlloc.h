#pragma once

#include"ThreadCache.h"
#include"PageCache.h"
//�ȼ���malloc����
static void* ConcurrentAlloc(const size_t size)
{
	if (size > MAX_BYTES) //���������С�������Ǹ�������󵥸�����Ĵ�Сʱֱ����PageCacheҪ
	{
		size_t alignEndSize = SizeClass::RoundUp(size);
		size_t pageSize = alignEndSize >> PAGE_SHIFT;
		PageCache::GetInstance()->Lock();
		Span* span = PageCache::GetInstance()->NewSpan(pageSize);
		span->_objSize = size;
		PageCache::GetInstance()->UnLock();
		void* ptr = reinterpret_cast<void*>(span->_pageId << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		//ͨ��TLS��ÿһ���߳������ķ��������Լ�ר����ThreadCache���͵Ķ���
		if (pTLSThreadCache == nullptr)
		{
			static ObjectPool<ThreadCache> tcPool; //����һ�������ڴ�������洢ThreadCache����
			pTLSThreadCache = tcPool.New();
			//pTLSThreadCache = new ThreadCache;
		}

		return pTLSThreadCache->Allocate(size);
	}

}

//�ȼ���free����
static void ConcurrentFree(void* ptr)
{
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objSize;
	if (size > MAX_BYTES)
	{
		PageCache::GetInstance()->Lock();
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		PageCache::GetInstance()->UnLock();
	}
	else
	{
		assert(pTLSThreadCache != nullptr);
		pTLSThreadCache->Deallocate(ptr, size);
	}
}