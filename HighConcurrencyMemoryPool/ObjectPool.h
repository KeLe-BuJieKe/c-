#pragma once
#include<iostream>

#ifdef _WIN32
#include<windows.h>
#else

#endif 

// ֱ��ȥ���ϰ�ҳ����ռ䣬��������ÿҳ8kb
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux��brk mmap�� 
#endif
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}
	return ptr;
}

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

#include<vector>
#include<ctime>
struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

void TestObjectPool()
{
	// �����ͷŵ��ִ�
	const size_t Rounds = 5;

	// ÿ�������ͷŶ��ٴ�
	const size_t N = 100000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "new cost time:" << end1 - begin1 << std::endl;
	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}
