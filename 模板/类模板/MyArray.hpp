#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

template <class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将 arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}


	//重载operator =防止浅拷贝问题
	MyArray& operator =(const MyArray&arr)
	{
		//先判断原来堆区是否有数据，如果有先释放干净
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将 arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否已满
		if (this->m_Capacity == this->m_Size)
		{
			cout << "空间已满" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;		//在数组末尾 插入数据
		this->m_Size++;							//更新数组大小
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			cout << "没有元素，删除失败" << endl;
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中的元素
	T& operator[](int index)
	{
		//不考虑越界，让用户自己去处理
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;	
		}
	}
private:
	T* pAddress;	//指针指向堆区开辟的真实数组

	int m_Capacity;	//数组容量


	int m_Size;		//元素个数
};