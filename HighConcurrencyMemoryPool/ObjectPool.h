#pragma once
#include"Common.h"

inline static void* SystemAlloc(size_t kpage);//函数声明


template<class T>
class ObjectPool
{
public:
	//利用构造函数来初始化
	ObjectPool():_memory(nullptr)
				,_freeList(nullptr)
				,_remainBytes(0)
	{}

	T* New()
	{
		T* obj = nullptr;
		if (this->_freeList != nullptr) //如果释放链表里不为空，那么我们直接使用释放链表里的空间，否则就直接继续切分
		{
			//获取到下一个对象的地址
			void* next = *(reinterpret_cast<void**>((this->_freeList)));
			obj = reinterpret_cast<T*>(this->_freeList);
			this->_freeList = next;
		}
		else
		{
			//如果小于一个对象的大小时，我们就需要重新开辟一个大块的空间
			if (this->_remainBytes < sizeof(T))
			{
				this->_remainBytes = 128 * 1024; //开16页大小，每页8kb

				//this->_memory = reinterpret_cast<char*>(malloc(_remainBytes));
				this->_memory = reinterpret_cast<char*>(SystemAlloc(this->_remainBytes >> 13));
				if (this->_memory == nullptr)  //开辟空间失败
				{
					throw std::bad_alloc();
				}
			}

			//判断当前的类型是否大于一个指针的大小，
			//如果小于那么我们需要将其开辟至4个字节的大小用来链式存储下一个未使用空间的地址
			size_t objSize = sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);
			obj = reinterpret_cast<T*>(_memory); //将开辟的空间的首地址给obj，待会用来返回
			_remainBytes -= objSize;  //减去这个对象使用的空间大小
			_memory += objSize; //更新大块内存的指针的首地址
		}

		new(obj)T; //调用定位new让它去调用构造函数来进行初始化
		return obj; //返回开辟的空间的首地址
	}

	void Delete(T* obj)
	{
		obj->~T(); //调用析构函数，防止像string类型的对象内部含有堆开辟的空间没有去释放，造成内存泄漏等问题
		*(reinterpret_cast<void**>(obj)) = this->_freeList;
		this->_freeList = obj;
	}

	~ObjectPool()  //这个析构函数我们不需要去释放掉这个内存，当这个进程结束了之后会自动把资源还给系统
	{}
private:
	char* _memory;  //指向的大块内存的首地址
	void* _freeList; //还回来过程中链接的自由链表的头指针
	size_t _remainBytes; //大块内存存在切分过程中的剩余字节数
};

