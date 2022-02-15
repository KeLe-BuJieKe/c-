#pragma once
#include"Common.h" 
#include"PageMap.h"
class PageCache //单例模式---饿汉
{
public:
	static PageCache* GetInstance() //获取单例对象
	{
		return &_inst;
	}
	void Lock(); //加锁
		
	void UnLock();//解锁

	Span* NewSpan(const size_t k); //获取一个k页的span内存对象

	// 获取从对象到span的映射
	Span* MapObjectToSpan(void* obj);

	// 释放空闲span回到Pagecache，并合并相邻的span
	void ReleaseSpanToPageCache(Span* span);
private:
	PageCache()
	{}
	PageCache(const PageCache& obj) = delete;
	PageCache& operator= (const PageCache& obj) = delete;
private:
	//std::unordered_map<PAGE_ID, Span*> _idSpanMap;	//页号与span对象的一个哈希映射
	TCMalloc_PageMap1<32 - PAGE_SHIFT> _idSpanMap;
	//std::map<PAGE_ID, Span*> _idSpanMap;
	SpanList _spanLists[NPAGES];  //以页数为哈希映射
	static PageCache _inst; //单例对象
	std::mutex _pageMutex;	//页锁
};