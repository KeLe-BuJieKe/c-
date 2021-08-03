#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <assert.h>
#include<iostream>
using namespace std;

namespace ZJ
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		vector()	//Ĭ�Ϲ��캯��
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)
		{}

		//n---Ԫ�ظ���  value---Ĭ�ϳ�ʼ����ֵ����ʼֵΪ0
		vector(size_t n, const T& value=T())		//��ȱʡֵ�Ĺ��캯��
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)		
		{
			assert(n > 0);
			reserve(n);
			while (n--)
			{
				//push_back(value);

				*this->m_finish = value;
				++this->m_finish;
			}

		}

		vector(long n, const T& value = T())		//��ȱʡֵ�Ĺ��캯��
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)
		{
			assert(n > 0);
			reserve(n);
			while (n--)
			{
				//push_back(value);

				*this->m_finish = value;
				++this->m_finish;
			}

		}

		vector(int n, const T& value = T())		//��ȱʡֵ�Ĺ��캯��
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)
		{
			assert(n > 0);
			reserve(n);
			while (n--)
			{
				//push_back(value);

				*this->m_finish = value;
				++this->m_finish;
			}

		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)
		{
			//reserve(last - first);
			//while (first != last)
			//{
			//	push_back(*first);
			//	++first;
			//}

			reserve(last - first);

			while (first != last)
			{
				*this->m_finish = *first;
				++first;
				++this->m_finish;
			}
		}

		vector(const vector<T>& x)	//�������캯��
		{
			this->m_start = new T[x.capacity()];
			
			//������memcpy ԭ������Ϊ����������������ͻ����Զ��������д���ָ��ģ������ǳ��������
			for (size_t i = 0; i < x.size(); ++i)
			{
				this->m_start[i] = x[i];
			}
			this->m_finish = this->m_start + x.size();
			this->m_endofstorage = this->m_start + x.capacity();

		}
		vector<T>& operator=(const vector<T>& x)	//��ֵ��������
		{
			if (this != &x)
			{
				vector<T>temp(x);
				this->swap(temp);
			}
			return *this;
		}

		~vector()	//��������	
		{
			if (this->m_start != nullptr)
			{
				delete[] this->m_start;
				this->m_start = this->m_endofstorage = this->m_finish = nullptr;
			}
		}
		
		void swap(vector<T>& x)	//����vector��������
		{
			std::swap(this->m_start, x.m_start);
			std::swap(this->m_finish, x.m_finish);
			std::swap(this->m_endofstorage, x.m_endofstorage);
		}

		size_t capacity() const		//�õ�������С����
		{
			return this->m_endofstorage - this->m_start;
		}

		size_t size() const			//�õ�Ԫ�ظ�������
		{
			return this->m_finish - this->m_start;
		}

		T& front()
		{
			assert(!this->empty());

			return *(this->m_start);
		}

		const T& front()const
		{
			assert(!this->empty());

			return *(this->m_start);
		}

		T& back()
		{
			assert(!this->empty());
			return *(this->m_finish-1);
		}

		const T& back() const
		{
			assert(!this->empty());
			return *(this->m_finish - 1);
		}

		iterator begin()		//��ʼ������
		{
			return this->m_start;
		}

		iterator end()		//����������
		{
			return this->m_finish;
		}

		const_iterator begin() const	//����ʼ������
		{
			return this->m_start;
		}

		const_iterator end() const		//������������
		{
			return this->m_finish;
		}

		bool empty() const		//�ж��Ƿ�Ϊ��
		{
			return this->m_start == this->m_finish;
		}

		T& at(const size_t& index)
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		T& at(const size_t& index) const
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		const T& operator[](const size_t& index)		//����operator[]���Ա�������һ��ʹ��
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		const T& operator[](const size_t& index) const
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		//β��  val----Ҫ�����ֵ
		void push_back(const T&val)
		{
			if (this->m_finish == this->m_endofstorage)
			{
				size_t newCapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newCapacity);
			}

			*this->m_finish = val;
			++this->m_finish;

		}
		
		//βɾ  
		void pop_back()
		{
			assert(!this->empty());
			--this->m_finish;
		}

		//newsize---Ҫ���䵽��������С
		void reserve(const size_t newsize)
		{
			if (this->capacity() < newsize)		//�ж��Ƿ���ڵ�ǰ����ֵ�������������Ҫ����
			{
				T* temp = new T[newsize];
				int size = this->size();	//�����ʱ����size�洢����ǰ�����ݸ���
											//������洢size�������m_finish+this->size()����ִ���
											//��Ϊ���ǵ�size()����this->m_finish - this->m_start�õ���
											//��Ϊ���������ȸı���m_start�ĵ�ַ����ʱm_finish�ĵ�ַ��û�иı䣬��������õ�����һ���µ�size()
											//����size()������һ���ܴ����������Ĳ�����ܻ���ɿ�ָ����ʴ���
				if (this->m_start != nullptr)
				{
					//memcpy(temp, this->m_start, sizeof(T) * size);	
					//������memcpy ԭ������Ϊ����������������ͻ����Զ��������д���ָ��ģ������ǳ��������
					for (size_t i = 0; i < this->size(); ++i)
					{
						temp[i] = this->m_start[i];
					}
					delete[] this->m_start;
				}
				this->m_start = temp;
				this->m_finish = this->m_start+size;
				this->m_endofstorage = this->m_start + newsize;
			}
		}

		//newsize---ָ���Ĵ�С   val----���newsize�������ǵ�size��������ֵ��Ϊval��Ĭ��ֵΪ0
		/*
		�����������
		1��newsize<size()����ʱ����ֻ��Ҫ�����ǵ���Чλm_finish����m_start+newsize����
		2��newsize>size()&&newsize<capacity(),��ʱ����ֻ��Ҫ��m_finish�����newsize��Ԫ�ظ���ֵval����
		3��newsize>size()&&newsize>capacity(),��ʱ������Ҫ���ݣ�������֮���m_finish�����newsize��Ԫ�ظ���ֵval����
		*/
		void resize(const size_t newsize, const T &val = T())
		{
			if (this->size() < newsize)		
			{
				if (newsize > capacity())
				{
					reserve(newsize);
				}

				while (this->m_finish < this->m_start + newsize)
				{
					*this->m_finish = val;
					++this->m_finish;
				}
				
			}
			else
			{
				this->m_finish = this->m_start + newsize;
			}
		}

		//position---�����λ�ã����뷶Χ[m_start,m_finish]     val-----Ҫ�����ֵ   ����ֵ---���ز����val�ĵ�����λ��
		iterator insert(iterator position, const T& val)
		{
			assert(this->m_start<=position&&position<=this->m_finish);		//�жϲ����λ���Ƿ����
			if (this->m_finish == this->m_endofstorage)		//�ж��Ƿ�Ҫ����
			{
				size_t len = position - this->m_start;	//��¼����Ҫ�����λ�ã���ֹ���ݺ������ʧЧ������
				size_t newCapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newCapacity);
				// ����position��������ݺ�positionʧЧ������
				position = this->m_start + len;		//�õ����ݺ���Ҫ����Ķ�Ӧλ��
			}
			
			iterator end = this->m_finish-1;
			while (end>=position)
			{
				*(end + 1) = *end;
				--end;
			}
			*position = val;
			++this->m_finish;
			return position;		//���ز����val�ĵ�����λ��
		}

		//position---Ҫɾ����λ��  ����ֵ---ɾ��λ�ú���Ԫ�صĵ�����
		iterator erase(const iterator position)
		{
			assert(this->m_start <= position && position < this->m_finish);		//�ж�ɾ����λ���Ƿ�Խ��

			iterator end = const_cast<iterator>(position);
			while (end < this->m_finish)
			{
				*end = *(end + 1);
				++end;
			}
			--this->m_finish;
			return position;
		}

		//first---ɾ����ʼλ��	last---ɾ���Ľ���λ��  ǰ�պ󿪵�����
		iterator erase(iterator first, iterator last)
		{
			assert(first<last&&this->m_start <= first && last <= this->m_finish);	//�ж�ɾ����λ���Ƿ�Խ��

			iterator begin = first;
			iterator end = last;
			while (end < this->m_finish)
			{
				*begin = *last;
				++begin;
				++end;
			}
			this->m_finish =begin;
			if (this->empty())		//����ÿռ�û������ʱ����ʱ�ÿռ������Ϊ�ղ��ܱ�����ֱ�ӷ���nullptrָ��
			{
				return nullptr;
			}
			else
			{
				return first;
			}
		}

		void clear()		//���
		{
			this->m_finish = this->m_start;
		}

	private:
		iterator m_start;
		iterator m_finish;
		iterator m_endofstorage;
	};
}
