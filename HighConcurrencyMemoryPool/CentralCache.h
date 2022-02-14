#pragma once
#include"Common.h"

class CentralCache //单例模式---饿汉
{
public:
	static CentralCache* GetInstance() //获取单例对象
	{
		return &_inst;
	}
	//获取一个非空的span
	Span* GetOneSpan(SpanList& list, const size_t size);

	//从中心缓存获取一定数量的对象内存给threadcache
	size_t FetchRangeObj(void*& start, void*& end, const size_t batchNum, const size_t size);
	//将一定数量的对象从释放放到span跨度
	void ReleaseListToSpans(void* start, const size_t size);
private:
	CentralCache()
	{}
	CentralCache(const CentralCache& obj) = delete;  //防拷贝
	CentralCache& operator=(const CentralCache& obj) = delete;
private:
	SpanList _spanLists[NFREE_LIST]; //开辟NFREE_LIST个空间大小不一样的带头双向循环链表的数组，根据字节数大小的一个哈希映射
	static CentralCache _inst; //单例对象
};