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

	//��������
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//�� arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}


	//����operator =��ֹǳ��������
	MyArray& operator =(const MyArray&arr)
	{
		//���ж�ԭ�������Ƿ������ݣ���������ͷŸɾ�
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[arr.m_Capacity];
		//�� arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ�����
		if (this->m_Capacity == this->m_Size)
		{
			cout << "�ռ�����" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;		//������ĩβ ��������
		this->m_Size++;							//���������С
	}

	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
		{
			cout << "û��Ԫ�أ�ɾ��ʧ��" << endl;
			return;
		}
		this->m_Size--;
	}

	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index)
	{
		//������Խ�磬���û��Լ�ȥ����
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//���������С
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
	T* pAddress;	//ָ��ָ��������ٵ���ʵ����

	int m_Capacity;	//��������


	int m_Size;		//Ԫ�ظ���
};