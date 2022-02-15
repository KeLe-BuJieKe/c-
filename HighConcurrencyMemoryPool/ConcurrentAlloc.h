#pragma once

#include"ThreadCache.h"
#include"PageCache.h"
//等价于malloc函数
static void* ConcurrentAlloc(const size_t size)
{
	if (size > MAX_BYTES) //单个对象大小大于我们给定的最大单个对象的大小时直接找PageCache要
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
		//通过TLS，每一个线程无锁的访问属于自己专属的ThreadCache类型的对象
		if (pTLSThreadCache == nullptr)
		{
			static ObjectPool<ThreadCache> tcPool; //开辟一个定长内存池用来存储ThreadCache对象
			pTLSThreadCache = tcPool.New();
			//pTLSThreadCache = new ThreadCache;
		}

		return pTLSThreadCache->Allocate(size);
	}

}

//等价于free函数
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