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
		vector()	//默认构造函数
			:m_start(nullptr)
			,m_finish(nullptr)
			,m_endofstorage(nullptr)
		{}

		//n---元素个数  value---默认初始化的值，初始值为0
		vector(size_t n, const T& value=T())		//带缺省值的构造函数
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

		vector(long n, const T& value = T())		//带缺省值的构造函数
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

		vector(int n, const T& value = T())		//带缺省值的构造函数
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

		vector(const vector<T>& x)	//拷贝构造函数
		{
			this->m_start = new T[x.capacity()];
			
			//不能用memcpy 原因是因为如果碰到是内置类型或者自定义类型中带有指针的，会出现浅拷贝错误
			for (size_t i = 0; i < x.size(); ++i)
			{
				this->m_start[i] = x[i];
			}
			this->m_finish = this->m_start + x.size();
			this->m_endofstorage = this->m_start + x.capacity();

		}
		vector<T>& operator=(const vector<T>& x)	//赋值函数重载
		{
			if (this != &x)
			{
				vector<T>temp(x);
				this->swap(temp);
			}
			return *this;
		}

		~vector()	//析构函数	
		{
			if (this->m_start != nullptr)
			{
				delete[] this->m_start;
				this->m_start = this->m_endofstorage = this->m_finish = nullptr;
			}
		}
		
		void swap(vector<T>& x)	//两个vector交换函数
		{
			std::swap(this->m_start, x.m_start);
			std::swap(this->m_finish, x.m_finish);
			std::swap(this->m_endofstorage, x.m_endofstorage);
		}

		size_t capacity() const		//得到容量大小函数
		{
			return this->m_endofstorage - this->m_start;
		}

		size_t size() const			//得到元素个数函数
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

		iterator begin()		//起始迭代器
		{
			return this->m_start;
		}

		iterator end()		//结束迭代器
		{
			return this->m_finish;
		}

		const_iterator begin() const	//常起始迭代器
		{
			return this->m_start;
		}

		const_iterator end() const		//常结束迭代器
		{
			return this->m_finish;
		}

		bool empty() const		//判断是否为空
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

		const T& operator[](const size_t& index)		//重载operator[]，以便向数组一样使用
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		const T& operator[](const size_t& index) const
		{
			assert(index < this->size());
			return this->m_start[index];
		}

		//尾插  val----要插入的值
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
		
		//尾删  
		void pop_back()
		{
			assert(!this->empty());
			--this->m_finish;
		}

		//newsize---要扩充到的容量大小
		void reserve(const size_t newsize)
		{
			if (this->capacity() < newsize)		//判断是否大于当前容量值，如果大于这需要扩容
			{
				T* temp = new T[newsize];
				int size = this->size();	//这个临时遍历size存储扩容前的数据个数
											//如果不存储size，后面的m_finish+this->size()会出现错误
											//因为我们的size()是用this->m_finish - this->m_start得到的
											//因为下面我们先改变了m_start的地址，此时m_finish的地址并没有改变，这里相减得到的是一个新的size()
											//并且size()可能是一个很大的数，后面的插入可能会造成空指针访问错误
				if (this->m_start != nullptr)
				{
					//memcpy(temp, this->m_start, sizeof(T) * size);	
					//不能用memcpy 原因是因为如果碰到是内置类型或者自定义类型中带有指针的，会出现浅拷贝错误
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

		//newsize---指定的大小   val----如果newsize大于我们的size，则后面的值都为val，默认值为0
		/*
		有三种情况：
		1、newsize<size()，此时我们只需要把我们的有效位m_finish改至m_start+newsize即可
		2、newsize>size()&&newsize<capacity(),此时我们只需要把m_finish后面的newsize个元素赋予值val即可
		3、newsize>size()&&newsize>capacity(),此时我们需要扩容，扩完容之后把m_finish后面的newsize个元素赋予值val即可
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

		//position---插入的位置，插入范围[m_start,m_finish]     val-----要插入的值   返回值---返回插入的val的迭代器位置
		iterator insert(iterator position, const T& val)
		{
			assert(this->m_start<=position&&position<=this->m_finish);		//判断插入的位置是否给错
			if (this->m_finish == this->m_endofstorage)		//判断是否要扩容
			{
				size_t len = position - this->m_start;	//记录我们要插入的位置，防止扩容后迭代器失效的问题
				size_t newCapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newCapacity);
				// 更新position，解决增容后position失效的问题
				position = this->m_start + len;		//得到扩容后所要插入的对应位置
			}
			
			iterator end = this->m_finish-1;
			while (end>=position)
			{
				*(end + 1) = *end;
				--end;
			}
			*position = val;
			++this->m_finish;
			return position;		//返回插入的val的迭代器位置
		}

		//position---要删除的位置  返回值---删除位置后面元素的迭代器
		iterator erase(const iterator position)
		{
			assert(this->m_start <= position && position < this->m_finish);		//判断删除的位置是否越界

			iterator end = const_cast<iterator>(position);
			while (end < this->m_finish)
			{
				*end = *(end + 1);
				++end;
			}
			--this->m_finish;
			return position;
		}

		//first---删除起始位置	last---删除的结束位置  前闭后开的区间
		iterator erase(iterator first, iterator last)
		{
			assert(first<last&&this->m_start <= first && last <= this->m_finish);	//判断删除的位置是否越界

			iterator begin = first;
			iterator end = last;
			while (end < this->m_finish)
			{
				*begin = *last;
				++begin;
				++end;
			}
			this->m_finish =begin;
			if (this->empty())		//如果该空间没有数据时，此时该空间的内容为空不能被访问直接返回nullptr指针
			{
				return nullptr;
			}
			else
			{
				return first;
			}
		}

		void clear()		//清空
		{
			this->m_finish = this->m_start;
		}

	private:
		iterator m_start;
		iterator m_finish;
		iterator m_endofstorage;
	};
}
