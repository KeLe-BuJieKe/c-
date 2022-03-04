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

static const size_t NFREE_LIST = 208;        //开辟的桶的数量
static const size_t MAX_BYTES = 256 * 1024; //能存储下的对象的最大字节数
static const size_t PAGE_SHIFT = 13;	//代表的是字节数到页数的转换，即一个页我们定义为8k大小
static const size_t NPAGES = 129;	//代表的是页的数量
class Span;	//前置声明
static ObjectPool<Span> _spanPool;	//专门开辟Span类型的定长内存池

#ifdef _WIN64
	typedef unsigned long long PAGE_ID;
#elif _WIN32
	typedef unsigned int PAGE_ID;
#endif // _WIN64

	// 直接去堆上按页申请空间，这里设置每页8kb
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << PAGE_SHIFT, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等 
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
	// sbrk unmmap等
#endif
}


//用于获取对象的前四个字节的空间，用于存储下一个小对象的地址
static void*& NextObj(void* obj)
{
	return *(reinterpret_cast<void**>(obj));
}

//用于管理切分好的小对象的自由链表
class FreeList
{
public:
	FreeList() :_freeList(nullptr)
		, _maxSize(1)
		, _size(0)
	{}

	void Push(void* obj) //头插   为了给外部用来回收自由链表的空间
	{
		assert(obj != nullptr);
		//将下一个对象的地址放入到obj这个对象的前四个字节
		//*(reinterpret_cast<void**>(obj)) = _freeList;
		NextObj(obj) = _freeList;
		_freeList = obj;
		++_size;
	}

	void* Pop() //头删  为了给外部用来获取自由链表中剩余的空间
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

	bool Empty() const //判断是否为空
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
	void* _freeList;  //自由链表
	size_t _maxSize; 
	size_t _size;
};


//该类计算这些对象大小的对齐映射规则
//1、计算对象对齐后实际所占空间多大
//2、根据对齐后所占空间计算对齐后的对象归属于第几号桶内

class SizeClass
{
public:
	/*
	static inline size_t _RoundUp(const size_t bytesNum, const size_t alignNum) //子函数
	{
		size_t alignEndSpace = 0; //对齐完之后实际所占的空间大小
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
		   15      →   001111
		   &       &               → 001000 == 8
		  ~(7)     →   111000
		*/
		return ((bytes + alignNum - 1) & ~(alignNum - 1));
	}

	/* 整体控制在最多10%左右的内碎片浪费
	对象大小范围             对齐字节数		对齐后所对应的桶的范围
	[1,128]			   		8byte对齐	    freelist[0,16)
	[128+1,1024]			16byte对齐	    freelist[16,72)
	[1024+1,8*1024]			128byte对齐	    freelist[72,128)
	[8*1024+1,64*1024]		1024byte对齐     freelist[128,184)
	[64*1024+1,256*1024]	8*1024byte对齐   freelist[184,208)
	*/
	static size_t RoundUp(const size_t size) //计算对象对齐后实际所占空间多大
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


	//第二个参数alignShift代表的是对齐字节数是2的几次方
	static size_t _GetIndex(const size_t bytes, const size_t alignShift)
	{
		return ((bytes + (1 << alignShift) - 1) >> alignShift) - 1;
	}

	//得到这个对象存储的几号桶下标
	static size_t GetIndex(const size_t bytes) 
	{
		assert(bytes <= MAX_BYTES);

		//每个区间中有多个桶的数量
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

	static size_t NumMoveSize(const size_t size) //批量算法
	{
		assert(size > 0);

		/*
		[2,512],一次批量移动多少个对象的上限值
		小对象一次批量上限高一点
		大对象一次批量上限低一点
		*/
		size_t num = MAX_BYTES / size; 
		if (num < 2) //下界
		{
			num = 2;
		}

		if (num > 512) //上界
		{
			num = 512;
		}
		return num;
	}

	static size_t NumMovePage(const size_t size)
	{
		size_t num = NumMoveSize(size); //一次性批量要开辟多少
		size_t bytes = num * size; //开辟的字节数

		size_t pageSize = bytes >> PAGE_SHIFT;	//将算出的字节数转换成页数,一页是8k大小即要右移13位
		if (pageSize == 0) //保证至少要开辟一页
		{
			pageSize = 1;
		}

		return pageSize;
	}

};


//大块内存跨度结构
class Span
{
public:
	Span() :_pageId(0), _num(0)
		,_prev(nullptr), _next(nullptr)
		,_useCount(0), _freeList(nullptr)
		,_isUse(false),_objSize(0)
	{}
public:
	PAGE_ID _pageId; //大块内存的起始页的页号
	size_t _num;	//页的数量

	//双向链表指针
	Span* _prev;
	Span* _next;

	size_t _useCount;	//切好小块内存被分配给ThreadCache的计数
	//一页可以被划分成多个小块内存，这个小块内存不可能全部一次性给你，只会给你部分
	//那么没有被分配出去的小块内存就被放到自由链表中挂起等待ThreadCache来获取
	void* _freeList;	//被切好的小块内存的自由链表
	size_t _objSize;		//切好的小对象的大小
	bool _isUse; //是否再使用
};


//带头双向循环链表
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

	void Insert(Span* position, Span* newSpan) //在指定位置插入
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
	Span* _head; //头结点
	std::mutex _mtx; //互斥锁---桶锁
};


