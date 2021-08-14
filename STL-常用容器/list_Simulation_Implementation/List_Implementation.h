#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using  namespace std;

namespace ZJ
{
	template<class T>	
	class list_node		//结点
	{
	public:
		list_node(T val=T())		//构造函数
			:m_val(val)
			,m_prev(nullptr)
			,m_next(nullptr)
		{}
	public:
		T m_val;		//值
		list_node<T>* m_prev;	//指向前一个的指针
		list_node<T>* m_next;	//指向下一个的指针

	};

	template<class T,class Ref,class Ptr>		//封装一个node型指针，制作成迭代器类
	class list_iterator
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr>myself;
		list_iterator(node* pnode)
			:m_pnode(pnode)
		{}

		Ref operator* ()		//重载  *
		{
			return this->m_pnode->m_val;
		}

		Ptr operator->()		//重载 ->
		{
			return &this->m_pnode->m_val;
		}

		bool operator!=(const myself&obj) const		//重载！=号
		{
			return this->m_pnode != obj.m_pnode;
		}

		bool operator==(const myself& obj) const	//重载==号
		{
			return this->m_pnode == obj.m_pnode;
		}

		myself& operator++()		//重载前置++
		{
			this->m_pnode = this->m_pnode->m_next;
			return *this;
		}

		myself operator++(int)		//重载后置++
		{
			const myself temp(*this);
			this->m_pnode = this->m_pnode->m_next;
			return temp;
		}

		myself& operator--()		//重载前置--
		{
			this->m_pnode = this->m_pnode->m_prev;
			return *this;
		}

		myself operator--(int)		//重载后置--
		{
			const myself temp(*this);
			this->m_pnode = this->m_pnode->m_prev;
			return temp;
		}

	public:
		node* m_pnode;
	};

	template<class T>
	class list
	{
	public:
		typedef list_node<T> node;		
		typedef list_iterator<T,T&,T*> iterator;		//普通迭代器
		typedef list_iterator<T,const T&,const T*> const_iterator;	//常量迭代器

	public:
		list()		//无参默认构造函数
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
		}

		list(size_t size, const T& val=T())	//n个元素构造函数
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			while (size--)
			{
				this->push_back(val);
			}
		}

		list(long size, const T& val = T())	//n个元素构造函数
		{
			assert(size > 0);
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			while (size--)
			{
				this->push_back(val);
			}
		}

		list(int size, const T& val = T())	//n个元素构造函数
		{
			assert(size > 0);
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			while (size--)
			{
				this->push_back(val);
			}
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)		//区间构造
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			while (first != last)
			{
				node* newnode = new node(*first);
				node* tail = this->m_head->m_prev;
				tail->m_next = newnode;
				newnode->m_prev = tail;
				newnode->m_next = this->m_head;
				this->m_head->m_prev = newnode;
				++first;
			}
		}
		
		list(const list<T>& obj)		//拷贝构造函数
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			const_iterator it = obj.begin();
			while (it != obj.end())
			{
				node* newnode = new node(it.m_pnode->m_val);

				node* tail = this->m_head->m_prev;
				tail->m_next = newnode;
				newnode->m_prev = tail;
				newnode->m_next = this->m_head;
				this->m_head->m_prev = newnode;
				++it;
			}
		}

		list<T>& operator=(const list<T>& obj)		//赋值运算符重载
		{
			if (this != &obj)
			{
				list<T>temp(obj);
				this->swap(temp);
			}
			return *this;
		}


		~list()		//析构函数
		{
			iterator it = this->begin();

			while (it != this->end())	//复用我们写的头删，一个一个的删除，当然也可以复用尾删pop_back()和erase()
			{
				++it;
				this->pop_front();
			}

			delete this->m_head;
			this->m_head = nullptr;
		}

		iterator begin()
		{
			return iterator(this->m_head->m_next);
		}

		const_iterator begin()	const
		{
			return const_iterator(this->m_head->m_next);
		}

		iterator end()
		{
			return iterator(this->m_head);
		}

		const_iterator end()	const
		{
			return const_iterator(this->m_head);
		}

		bool empty()	const		//判空
		{
			return this->begin() == this->end();	//就是begin()与end()同时指向头结点时的情况
		}

		//遍历一遍链表来得到元素个数，为什么使用遍历一遍链表呢？
		//这是因为我们使用链表时很少会去知道它的元素个数，但如果频繁的调用该接口会造成性能的下降
		//此时我们应该在list类中将增加一个记录元素个数的变量size
		//如果有元素插入就增加，删除就减少
		size_t size()	const	//获得元素个数
		{
			size_t size = 0;
			const_iterator it = this->begin();
			while(it!=this->end())
			{
				++it;
				++size;
			}
			return size;
		}

		T& back()
		{
			assert(!this->empty());
			return this->m_head->m_prev->m_val;
		}

		const T& back()   const
		{
			assert(!this->empty());
			return this->m_head->prev->m_val;
		}

		T& front()
		{
			assert(!this->empty());
			return  this->m_head->m_next->m_val;
		}

		const T& front() const
		{
			assert(!this->empty());
			return this->m_head->m_next->m_val;
		}

		void push_front(const T& val)	//头插
		{
			node* newnode = new node(val);
			node*  next = this->m_head->m_next;
			newnode->m_next = next;
			this->m_head->m_next = newnode;
			newnode->m_prev = this->m_head;
			next->m_prev = newnode;
		}

		void push_back(const T& val)	//尾插
		{
			node* tail = this->m_head->m_prev;
			node* newnode = new node(val);
			newnode->m_next = tail->m_next;
			newnode->m_prev = tail;
			tail->m_next = newnode;
			this->m_head->m_prev = newnode;
		}


		//插入元素到指定位置，返回的是插入的元素的迭代器
		iterator insert(iterator pos, const T& val)
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			node* newnode = new node(val);		//创建新结点

			node* cur = pos.m_pnode;		//记录当前结点的指针
			node* prev = cur->m_prev;		//记录当前结点的前一个结点的指针

			newnode->m_next = cur;
			newnode->m_prev = prev;
			prev->m_next = newnode;
			cur->m_prev = newnode;

			return iterator(newnode);		//返回一个用当前的插入的元素的结点构建的匿名对象的迭代器
		}

		void insert(iterator pos, size_t n, const T& val)	//插入n个val
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			while (n--)
			{
				node* newnode = new node(val);

				node* cur = pos.m_pnode;
				node* prev = cur->m_prev;

				newnode->m_prev = prev;
				prev->m_next = newnode;
				newnode->m_next = cur;
				cur->m_prev = newnode;
			}
		}

		void insert(iterator pos, int n, const T& val)	//插入n个val
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			assert(n > 0);
			while (n--)
			{
				node* newnode = new node(val);

				node* cur = pos.m_pnode;
				node* prev = cur->m_prev;

				newnode->m_prev = prev;
				prev->m_next = newnode;
				newnode->m_next = cur;
				cur->m_prev = newnode;
			}
		}

		void insert(iterator pos, long n, const T& val)	//插入n个val
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			assert(n > 0);
			while (n--)
			{
				node* newnode = new node(val);

				node* cur = pos.m_pnode;
				node* prev = cur->m_prev;

				newnode->m_prev = prev;
				prev->m_next = newnode;
				newnode->m_next = cur;
				cur->m_prev = newnode;
			}
		}

		template <class InputIterator>
		void insert(iterator pos, InputIterator first, InputIterator last)	//区间插入
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			while (first != last)
			{
				node* newnode = new node(*first);

				node* cur = pos.m_pnode;
				node* prev = cur->m_prev;

				newnode->m_prev = prev;
				prev->m_next = newnode;
				newnode->m_next = cur;
				cur->m_prev = newnode;
				++first;
			}
		}

		void pop_front()	//头删
		{
			assert(!empty());	//断言 如果list已经为空，则删除不了
			node* delnode = this->m_head->m_next;
			node* next = delnode->m_next;
			this->m_head->m_next = next;
			next->m_prev = this->m_head;
			delnode->m_next = delnode->m_prev = nullptr;
			delnode->m_val = T();
			delete delnode;
		}

		void pop_back()		//尾删
		{
			assert(!empty());	//断言 如果list已经为空，则删除不了
			node* tail = this->m_head->m_prev;
			node* prev = tail->m_prev;
			this->m_head->m_prev = prev;
			prev->m_next = this->m_head;
			tail->m_next = tail->m_prev = nullptr;
			tail->m_val = T();
			delete tail;
		}


		//删除指定位置的元素，返回下一个元素的迭代器，但要注意的是：
		//如果删除的最后一个元素，此时返回的是头结点也就是end()位置的迭代器
		iterator erase(iterator pos)			
		{
			assert(pos.m_pnode != nullptr);		//断言 迭代器是否为空指针错误
			assert(pos != end());				//断言 list内元素为空及删除头结点的情况
			
			node* next = pos.m_pnode->m_next;
			node* prev = pos.m_pnode->m_prev;

			prev->m_next = next;
			next->m_prev = prev;

			pos.m_pnode->m_next = pos.m_pnode->m_prev = nullptr;
			pos.m_pnode->m_val = T();
			delete pos.m_pnode;

			return iterator(next);		
		}

		iterator erase(iterator first, iterator last)		//区间删除
		{
			node* prev = first.m_pnode->m_prev;
			node* next = last.m_pnode;

			while (first != last)
			{
				node* cur = first.m_pnode;
				++first;
				cur->m_next = cur->m_prev = nullptr;
				cur->m_val = T();
				delete cur;
				cur = nullptr;
			}

			prev->m_next = next;
			next->m_prev = prev;

			return iterator(next);
		}

		void resize(size_t size,const T &val=T())
		{
			if (size > this->size())
			{
				size_t cur = size - this->size();
				push_back(val);
			}
			else
			{
				
				size_t cur = this->size()-size;
				while (cur--)
				{
					pop_back();
				}
			}
		}

		void clear()		//清空元素，而不是把整个链表删除掉
		{
			iterator it = this->begin();	

			while (it != this->end())	//复用我们写的头删，一个一个的删除，当然也可以复用尾删pop_back()和erase()
			{
				++it;
				this->pop_front();
			}
		}

		void swap(list<T>& obj)
		{
			node* temp = this->m_head;
			this->m_head = obj.m_head;
			obj.m_head = temp;
		}
	private:
		node* m_head;		//头指针
	};
}
