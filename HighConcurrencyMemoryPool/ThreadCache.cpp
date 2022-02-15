#pragma once
#include "ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::Allocate(const size_t size)
{
	assert(size <= MAX_BYTES);

	//��ȡʵ�ʶ����Ҫ���ٵĿռ��С
	size_t alignEndSize = SizeClass::RoundUp(size);
	//��ȡ��Ҫ�����Ͱ��
	size_t bucketIndex = SizeClass::GetIndex(size);

	//�����Ϊ�գ���ô���Ǿ���threadCache���_freeLists���������л�ȡ�ռ�
	//���Ϊ�գ���ô���Ǿ�����һ��CentralCache��Ҫ�ռ�
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

	//�ҵ�ӳ��������������ڵ�Ͱ����󽫶�������ȥ
	size_t bucketIndex = SizeClass::GetIndex(size);
	this->_freeLists[bucketIndex].Push(delPtr);

	//�������ȴ���һ������������ڴ�ʱ�Ϳ�ʼ��һ��list��CentralCache
	if (this->_freeLists[bucketIndex].GetSize() >= this->_freeLists[bucketIndex].GetMaxSize())
	{
		ListToLong(this->_freeLists[bucketIndex], size);
	}
}


void* ThreadCache::FetchFromCentralCaChe(const size_t index, const size_t size)
{
	/*�����ڷ��������㷨
	1���ʼ����һ����CentralCacheҪ̫�࣬��ΪҪ̫���˿����ò��������˷�;
	2������㲻�������size��С�ڴ�������ôbatchNum�ͻ᲻��������ֱ�����ޣ���[2,512]֮��;
	*/
	size_t maxSize = this->_freeLists[index].GetMaxSize();
	size_t batchNum = maxSize < SizeClass::NumMoveSize(size) ? maxSize : SizeClass::NumMoveSize(size);
	if (maxSize == batchNum)  //�����ȾͰ�_maxSize���ϵ���
	{
		this->_freeLists[index].ModifyMaxSize() += 1;
	}

	//��FetchRangeObj�������βΣ�����������������Ͳ���
	void* start = nullptr; 
	void* end = nullptr;
	//ͨ������������ú���������ʵ�ʻ�ȡ���˶��ٸ��ڴ����
	size_t actualNum = CentralCache::GetInstance()->FetchRangeObj(start, end, batchNum, size);
	assert(actualNum > 0); //���ٻ�ȡһ��

	if (actualNum == 1)
	{
		assert(start == end); //�����span�����е�_freeListֻ��һ���кõ��ڴ����ʱ�������ǾͰ���һ������
		return start;
	}
	else
	{
		//��������Ҫ����ʼstart���أ���������ֻ��Ҫ��start֮��Ŀռ���뵽����������
		//��start����һ���ռ�ĵ�ַ�洢��start��ǰ�ĸ��ֽڵ���
		this->_freeLists[index].PushRange(NextObj(start), end, actualNum-1); 
		return start;
	}
}

void ThreadCache::ListToLong(FreeList& list, const size_t size)
{
	void* start = nullptr;
	void* end = nullptr;
	list.PopRange(start, end, list.GetMaxSize()); //��ȡ�������ڴ棬��������ThreadCache�ͷŻظ�CentralCache

	CentralCache::GetInstance()->ReleaseListToSpans(start, size);
}
