#pragma once
#include"Common.h" 
#include"PageMap.h"
class PageCache //����ģʽ---����
{
public:
	static PageCache* GetInstance() //��ȡ��������
	{
		return &_inst;
	}
	void Lock(); //����
		
	void UnLock();//����

	Span* NewSpan(const size_t k); //��ȡһ��kҳ��span�ڴ����

	// ��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);

	// �ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
	void ReleaseSpanToPageCache(Span* span);
private:
	PageCache()
	{}
	PageCache(const PageCache& obj) = delete;
	PageCache& operator= (const PageCache& obj) = delete;
private:
	//std::unordered_map<PAGE_ID, Span*> _idSpanMap;	//ҳ����span�����һ����ϣӳ��
	TCMalloc_PageMap1<32 - PAGE_SHIFT> _idSpanMap;
	//std::map<PAGE_ID, Span*> _idSpanMap;
	SpanList _spanLists[NPAGES];  //��ҳ��Ϊ��ϣӳ��
	static PageCache _inst; //��������
	std::mutex _pageMutex;	//ҳ��
};