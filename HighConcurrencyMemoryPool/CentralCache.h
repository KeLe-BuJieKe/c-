#pragma once
#include"Common.h"

class CentralCache //����ģʽ---����
{
public:
	static CentralCache* GetInstance() //��ȡ��������
	{
		return &_inst;
	}
	//��ȡһ���ǿյ�span
	Span* GetOneSpan(SpanList& list, const size_t size);

	//�����Ļ����ȡһ�������Ķ����ڴ��threadcache
	size_t FetchRangeObj(void*& start, void*& end, const size_t batchNum, const size_t size);
	//��һ�������Ķ�����ͷŷŵ�span���
	void ReleaseListToSpans(void* start, const size_t size);
private:
	CentralCache()
	{}
	CentralCache(const CentralCache& obj) = delete;  //������
	CentralCache& operator=(const CentralCache& obj) = delete;
private:
	SpanList _spanLists[NFREE_LIST]; //����NFREE_LIST���ռ��С��һ���Ĵ�ͷ˫��ѭ����������飬�����ֽ�����С��һ����ϣӳ��
	static CentralCache _inst; //��������
};