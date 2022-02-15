#pragma once
#include "ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::Allocate(const size_t size)
{
	assert(size <= MAX_BYTES);

	//获取实际对齐后要开辟的空间大小
	size_t alignEndSize = SizeClass::RoundUp(size);
	//获取所要存入的桶号
	size_t bucketIndex = SizeClass::GetIndex(size);

	//如果不为空，那么我们就在threadCache里的_freeLists自由链表中获取空间
	//如果为空，那么我们就向下一层CentralCache索要空间
	if (!this->_freeLists[bucketIndex].Empty())
	{
		return this->_freeLists[bucketIndex].Pop();
	}
	else
	{
 		return this->FetchFromCentralCaChe(bucketIndex, alignEndSize);
	}
}

void ThreadCache::Deallocate(void* delPtr, const size_t size)
{
	assert(delPtr != nullptr);
	assert(size <= MAX_BYTES);

	//找到映射的自由链表所在的桶，最后将对象插入进去
	size_t bucketIndex = SizeClass::GetIndex(size);
	this->_freeLists[bucketIndex].Push(delPtr);

	//当链表长度大于一次批量申请的内存时就开始还一段list给CentralCache
	if (this->_freeLists[bucketIndex].GetSize() >= this->_freeLists[bucketIndex].GetMaxSize())
	{
		ListToLong(this->_freeLists[bucketIndex], size);
	}
}


void* ThreadCache::FetchFromCentralCaChe(const size_t index, const size_t size)
{
	/*慢调节反馈调节算法
	1、最开始不会一次向CentralCache要太多，因为要太多了可能用不完而造成浪费;
	2、如果你不断有这个size大小内存需求，那么batchNum就会不断增长，直到上限，在[2,512]之间;
	*/
	size_t maxSize = this->_freeLists[index].GetMaxSize();
	size_t batchNum = maxSize < SizeClass::NumMoveSize(size) ? maxSize : SizeClass::NumMoveSize(size);
	if (maxSize == batchNum)  //如果相等就把_maxSize向上调整
	{
		this->_freeLists[index].ModifyMaxSize() += 1;
	}

	//给FetchRangeObj函数的形参，这两个参数是输出型参数
	void* start = nullptr; 
	void* end = nullptr;
	//通过单例对象调用函数，返回实际获取到了多少个内存对象
	size_t actualNum = CentralCache::GetInstance()->FetchRangeObj(start, end, batchNum, size);
	assert(actualNum > 0); //至少获取一个

	if (actualNum == 1)
	{
		assert(start == end); //当这个span对象中的_freeList只有一个切好的内存对象时，那我们就把这一个拿走
		return start;
	}
	else
	{
		//由于我们要将起始start返回，所以我们只需要把start之后的空间放入到自由链表中
		//而start的下一个空间的地址存储在start的前四个字节当中
		this->_freeLists[index].PushRange(NextObj(start), end, actualNum-1); 
		return start;
	}
}

void ThreadCache::ListToLong(FreeList& list, const size_t size)
{
	void* start = nullptr;
	void* end = nullptr;
	list.PopRange(start, end, list.GetMaxSize()); //获取批量的内存，并将它从ThreadCache释放回给CentralCache

	CentralCache::GetInstance()->ReleaseListToSpans(start, size);
}
