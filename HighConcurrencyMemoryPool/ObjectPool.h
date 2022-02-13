#pragma once
#include"Common.h"

inline static void* SystemAlloc(size_t kpage);//��������


template<class T>
class ObjectPool
{
public:
	//���ù��캯������ʼ��
	ObjectPool():_memory(nullptr)
				,_freeList(nullptr)
				,_remainBytes(0)
	{}

	T* New()
	{
		T* obj = nullptr;
		if (this->_freeList != nullptr) //����ͷ������ﲻΪ�գ���ô����ֱ��ʹ���ͷ�������Ŀռ䣬�����ֱ�Ӽ����з�
		{
			//��ȡ����һ������ĵ�ַ
			void* next = *(reinterpret_cast<void**>((this->_freeList)));
			obj = reinterpret_cast<T*>(this->_freeList);
			this->_freeList = next;
		}
		else
		{
			//���С��һ������Ĵ�Сʱ�����Ǿ���Ҫ���¿���һ�����Ŀռ�
			if (this->_remainBytes < sizeof(T))
			{
				this->_remainBytes = 128 * 1024; //��16ҳ��С��ÿҳ8kb

				//this->_memory = reinterpret_cast<char*>(malloc(_remainBytes));
				this->_memory = reinterpret_cast<char*>(SystemAlloc(this->_remainBytes >> 13));
				if (this->_memory == nullptr)  //���ٿռ�ʧ��
				{
					throw std::bad_alloc();
				}
			}

			//�жϵ�ǰ�������Ƿ����һ��ָ��Ĵ�С��
			//���С����ô������Ҫ���俪����4���ֽڵĴ�С������ʽ�洢��һ��δʹ�ÿռ�ĵ�ַ
			size_t objSize = sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);
			obj = reinterpret_cast<T*>(_memory); //�����ٵĿռ���׵�ַ��obj��������������
			_remainBytes -= objSize;  //��ȥ�������ʹ�õĿռ��С
			_memory += objSize; //���´���ڴ��ָ����׵�ַ
		}

		new(obj)T; //���ö�λnew����ȥ���ù��캯�������г�ʼ��
		return obj; //���ؿ��ٵĿռ���׵�ַ
	}

	void Delete(T* obj)
	{
		obj->~T(); //����������������ֹ��string���͵Ķ����ڲ����жѿ��ٵĿռ�û��ȥ�ͷţ�����ڴ�й©������
		*(reinterpret_cast<void**>(obj)) = this->_freeList;
		this->_freeList = obj;
	}

	~ObjectPool()  //��������������ǲ���Ҫȥ�ͷŵ�����ڴ棬��������̽�����֮����Զ�����Դ����ϵͳ
	{}
private:
	char* _memory;  //ָ��Ĵ���ڴ���׵�ַ
	void* _freeList; //���������������ӵ����������ͷָ��
	size_t _remainBytes; //����ڴ�����зֹ����е�ʣ���ֽ���
};

