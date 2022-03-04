#pragma once
#include<iostream>
#include<assert.h>
#include<mutex>
#include<unordered_map>
#include<map>
#include"ObjectPool.h"

#ifdef _WIN32
	#include<Windows.h>
#else

#endif 

static const size_t NFREE_LIST = 208;        //���ٵ�Ͱ������
static const size_t MAX_BYTES = 256 * 1024; //�ܴ洢�µĶ��������ֽ���
static const size_t PAGE_SHIFT = 13;	//��������ֽ�����ҳ����ת������һ��ҳ���Ƕ���Ϊ8k��С
static const size_t NPAGES = 129;	//�������ҳ������
class Span;	//ǰ������
static ObjectPool<Span> _spanPool;	//ר�ſ���Span���͵Ķ����ڴ��

#ifdef _WIN64
	typedef unsigned long long PAGE_ID;
#elif _WIN32
	typedef unsigned int PAGE_ID;
#endif // _WIN64

	// ֱ��ȥ���ϰ�ҳ����ռ䣬��������ÿҳ8kb
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << PAGE_SHIFT, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux��brk mmap�� 
#endif

	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}

	return ptr;
}

inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
	// sbrk unmmap��
#endif
}


//���ڻ�ȡ�����ǰ�ĸ��ֽڵĿռ䣬���ڴ洢��һ��С����ĵ�ַ
static void*& NextObj(void* obj)
{
	return *(reinterpret_cast<void**>(obj));
}

//���ڹ����зֺõ�С�������������
class FreeList
{
public:
	FreeList() :_freeList(nullptr)
		, _maxSize(1)
		, _size(0)
	{}

	void Push(void* obj) //ͷ��   Ϊ�˸��ⲿ����������������Ŀռ�
	{
		assert(obj != nullptr);
		//����һ������ĵ�ַ���뵽obj��������ǰ�ĸ��ֽ�
		//*(reinterpret_cast<void**>(obj)) = _freeList;
		NextObj(obj) = _freeList;
		_freeList = obj;
		++_size;
	}

	void* Pop() //ͷɾ  Ϊ�˸��ⲿ������ȡ����������ʣ��Ŀռ�
	{
		assert(_freeList != nullptr);
		void* obj = _freeList;
		_freeList = NextObj(_freeList);
		--_size;
		return obj;
	}
	
	void PushRange(void* start, void* end, const size_t num)
	{
		NextObj(end) = this->_freeList;
		this->_freeList = start;
		_size += num;
	}

	void PopRange(void*& start, void*& end, const size_t num)
	{
		assert(num <= _size);
		start = _freeList;
		end = start;

		for (size_t i = 0; i < num - 1; ++i)
		{
			end = NextObj(end);
		}
		_freeList = NextObj(end);
		NextObj(end) = nullptr;
		this->_size -= num;
	}

	bool Empty() const //�ж��Ƿ�Ϊ��
	{
		return this->_freeList == nullptr ? true : false;
	}

	size_t GetMaxSize() const
	{
		return this->_maxSize;
	}

	size_t GetSize() const
	{
		return this->_size;
	}

	size_t& ModifyMaxSize()
	{
		return this->_maxSize;
	}

private:
	void* _freeList;  //��������
	size_t _maxSize; 
	size_t _size;
};


//���������Щ�����С�Ķ���ӳ�����
//1�������������ʵ����ռ�ռ���
//2�����ݶ������ռ�ռ��������Ķ�������ڵڼ���Ͱ��

class SizeClass
{
public:
	/*
	static inline size_t _RoundUp(const size_t bytesNum, const size_t alignNum) //�Ӻ���
	{
		size_t alignEndSpace = 0; //������֮��ʵ����ռ�Ŀռ��С
		if (bytesNum % alignNum == 0)
		{
			 alignEndSpace = bytesNum;
		}
		else
		{
			alignEndSpace = ((bytesNum / alignNum) + 1) * alignEndSpace;
		}
		return alignEndSpace;
	}
	*/

	static inline size_t _RoundUp(const size_t bytes, const size_t alignNum)
	{
		/* bytes == 8  alignNum = 8
		   15      ��   001111
		   &       &               �� 001000 == 8
		  ~(7)     ��   111000
		*/
		return ((bytes + alignNum - 1) & ~(alignNum - 1));
	}

	/* ������������10%���ҵ�����Ƭ�˷�
	�����С��Χ             �����ֽ���		���������Ӧ��Ͱ�ķ�Χ
	[1,128]			   		8byte����	    freelist[0,16)
	[128+1,1024]			16byte����	    freelist[16,72)
	[1024+1,8*1024]			128byte����	    freelist[72,128)
	[8*1024+1,64*1024]		1024byte����     freelist[128,184)
	[64*1024+1,256*1024]	8*1024byte����   freelist[184,208)
	*/
	static size_t RoundUp(const size_t size) //�����������ʵ����ռ�ռ���
	{
		if (size <= 128)
		{
			return _RoundUp(size, 8);
		}
		else if (size <= 1024)
		{
			return _RoundUp(size, 16);
		}
		else if (size <= 8 * 1024)
		{
			return _RoundUp(size, 128);
		}
		else if (size <= 64 * 1024)
		{
			return _RoundUp(size, 1024);
		}
		else if (size <= 256 * 1024)
		{
			return _RoundUp(size, 8 * 1024);
		}
		else
		{
			return _RoundUp(size, 1 << PAGE_SHIFT);
		}
	}

	/*
	static inline size_t _GetIndex(const size_t bytes, const size_t alignNum)
	{
		return (bytes % alignNum == 0) ? (bytes / alignNum) - 1 : bytes / alignNum;
	}

	static size_t GetIndex(const size_t bytes)
	{
		assert(bytes <= MAX_BYTES);

		if (bytes <= 128)
		{
			return _GetIndex(bytes, 8);
		}
		else if (bytes <= 1024)
		{
			return _GetIndex(bytes, 16);
		}
		else if (bytes <= 8 * 1024)
		{
			return _GetIndex(bytes, 128);
		}
		else if (bytes <= 64 * 1024)
		{
			return _GetIndex(bytes, 1024);
		}
		else if (bytes <= 256 * 1024)
		{
			return _GetIndex(bytes, 8 * 1024);
		}
		else
		{
			assert(false);
			return -1;
		}
	}
	*/


	//�ڶ�������alignShift������Ƕ����ֽ�����2�ļ��η�
	static size_t _GetIndex(const size_t bytes, const size_t alignShift)
	{
		return ((bytes + (1 << alignShift) - 1) >> alignShift) - 1;
	}

	//�õ��������洢�ļ���Ͱ�±�
	static size_t GetIndex(const size_t bytes) 
	{
		assert(bytes <= MAX_BYTES);

		//ÿ���������ж��Ͱ������
		static int bucketNumArray[4] = { 16, 56, 56, 56 };
		
		if (bytes <= 128)
		{
			return _GetIndex(bytes, 3);
		}
		else if (bytes <= 1024)
		{
			return _GetIndex(bytes - 128, 4) + bucketNumArray[0];
		}
		else if (bytes <= 8 * 1024)
		{
			return _GetIndex(bytes - 1024, 7) + bucketNumArray[0] + bucketNumArray[1];
		}
		else if (bytes <= 64 * 1024)
		{
			return _GetIndex(bytes - 8 * 1024, 10) + bucketNumArray[2] 
					+ bucketNumArray[0] + bucketNumArray[1];
		}
		else if (bytes <= 256 * 1024)
		{
			return _GetIndex(bytes - 64 * 256, 13) + bucketNumArray[3] 
				+bucketNumArray[2] + bucketNumArray[1] + bucketNumArray[0];
		}
		else
		{
			assert(false);
			return -1;
		}
	}

	static size_t NumMoveSize(const size_t size) //�����㷨
	{
		assert(size > 0);

		/*
		[2,512],һ�������ƶ����ٸ����������ֵ
		С����һ���������޸�һ��
		�����һ���������޵�һ��
		*/
		size_t num = MAX_BYTES / size; 
		if (num < 2) //�½�
		{
			num = 2;
		}

		if (num > 512) //�Ͻ�
		{
			num = 512;
		}
		return num;
	}

	static size_t NumMovePage(const size_t size)
	{
		size_t num = NumMoveSize(size); //һ��������Ҫ���ٶ���
		size_t bytes = num * size; //���ٵ��ֽ���

		size_t pageSize = bytes >> PAGE_SHIFT;	//��������ֽ���ת����ҳ��,һҳ��8k��С��Ҫ����13λ
		if (pageSize == 0) //��֤����Ҫ����һҳ
		{
			pageSize = 1;
		}

		return pageSize;
	}

};


//����ڴ��Ƚṹ
class Span
{
public:
	Span() :_pageId(0), _num(0)
		,_prev(nullptr), _next(nullptr)
		,_useCount(0), _freeList(nullptr)
		,_isUse(false),_objSize(0)
	{}
public:
	PAGE_ID _pageId; //����ڴ����ʼҳ��ҳ��
	size_t _num;	//ҳ������

	//˫������ָ��
	Span* _prev;
	Span* _next;

	size_t _useCount;	//�к�С���ڴ汻�����ThreadCache�ļ���
	//һҳ���Ա����ֳɶ��С���ڴ棬���С���ڴ治����ȫ��һ���Ը��㣬ֻ����㲿��
	//��ôû�б������ȥ��С���ڴ�ͱ��ŵ����������й���ȴ�ThreadCache����ȡ
	void* _freeList;	//���кõ�С���ڴ����������
	size_t _objSize;		//�кõ�С����Ĵ�С
	bool _isUse; //�Ƿ���ʹ��
};


//��ͷ˫��ѭ������
class SpanList
{
public:
	SpanList()
	{
		//this->_head = new Span;
		this->_head = _spanPool.New();
		this->_head->_prev = this->_head;
		this->_head->_next = this->_head;
	}

	Span* Begin()  const
	{
		return this->_head->_next;
	}

	Span* End()  const
	{
		return this->_head;
	}

	void PushFront(Span* span)
	{
		this->Insert(this->Begin(), span);
	}

	Span* PopFront()
	{
		Span* front = this->_head->_next;
		Erase(front);
		return front;
	}

	void Insert(Span* position, Span* newSpan) //��ָ��λ�ò���
	{
		assert(position != nullptr);
		assert(newSpan != nullptr);

		Span* prev = position->_prev;
		newSpan->_prev = prev;
		prev->_next = newSpan;
		position->_prev = newSpan;
		newSpan->_next = position;
	}

	bool Empty() const
	{
		return this->_head->_next == _head;
	}

	void Erase(Span* position)
	{
		assert(position != this->_head);
		assert(position != nullptr);
		Span* prev = position->_prev;
		Span* next = position->_next;
		prev->_next = next;
		next->_prev = prev;
	}
	
	void Lock()
	{
		this->_mtx.lock();
	}

	void UnLock()
	{
		this->_mtx.unlock();
	}

private:
	Span* _head; //ͷ���
	std::mutex _mtx; //������---Ͱ��
};


