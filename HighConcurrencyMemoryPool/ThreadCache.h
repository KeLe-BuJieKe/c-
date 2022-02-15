#pragma once
#include"Common.h"

class ThreadCache //��ϣͰ�ṹ
{
public:
	void* Allocate(const size_t size); //���ٿռ�
	void  Deallocate(void* delPtr, const size_t size); //���տռ�
	//���ڴ治��ʱ�������Ļ����л�ȡ����
	void* FetchFromCentralCaChe(const size_t index, const size_t size);
	//�ͷŶ����������ʱ�������ڴ�ص�CentralCache
	void ListToLong(FreeList& list, const size_t size);
private:
	FreeList _freeLists[NFREE_LIST]; //����NFREE_LIST���ռ��С��һ������������
};

//�̱߳��ش洢��������ÿ���߳��ж��ܷ��ʣ�����ֵ��ÿ���߳��л���Ӱ�죬�����TLS��Thread Local Storage��
//������_declspec(thread)�ı�������Ϊÿһ���̴߳���һ�������Ŀ�����
static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;