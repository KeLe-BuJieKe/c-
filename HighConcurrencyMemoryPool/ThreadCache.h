#pragma once
#include"Common.h"

class ThreadCache //哈希桶结构
{
public:
	void* Allocate(const size_t size); //开辟空间
	void  Deallocate(void* delPtr, const size_t size); //回收空间
	//当内存不足时，从中心缓存中获取对象
	void* FetchFromCentralCaChe(const size_t index, const size_t size);
	//释放对象，链表过长时，回收内存回到CentralCache
	void ListToLong(FreeList& list, const size_t size);
private:
	FreeList _freeLists[NFREE_LIST]; //开辟NFREE_LIST个空间大小不一样的自由链表
};

//线程本地存储，变量在每个线程中都能访问，并且值在每个线程中互不影响，这就是TLS（Thread Local Storage）
//声明了_declspec(thread)的变量，会为每一个线程创建一个单独的拷贝。
static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;