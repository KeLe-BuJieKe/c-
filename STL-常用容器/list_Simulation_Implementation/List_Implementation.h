#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using  namespace std;

namespace ZJ
{
	template<class T>	
	class list_node		//���
	{
	public:
		list_node(T val=T())		//���캯��
			:m_val(val)
			,m_prev(nullptr)
			,m_next(nullptr)
		{}
	public:
		T m_val;		//ֵ
		list_node<T>* m_prev;	//ָ��ǰһ����ָ��
		list_node<T>* m_next;	//ָ����һ����ָ��

	};

	template<class T,class Ref,class Ptr>		//��װһ��node��ָ�룬�����ɵ�������
	class list_iterator
	{
	public:
		typedef list_node<T> node;
		typedef list_iterator<T, Ref, Ptr>myself;
		list_iterator(node* pnode)
			:m_pnode(pnode)
		{}

		Ref operator* ()		//����  *
		{
			return this->m_pnode->m_val;
		}

		Ptr operator->()		//���� ->
		{
			return &this->m_pnode->m_val;
		}

		bool operator!=(const myself&obj) const		//���أ�=��
		{
			return this->m_pnode != obj.m_pnode;
		}

		bool operator==(const myself& obj) const	//����==��
		{
			return this->m_pnode == obj.m_pnode;
		}

		myself& operator++()		//����ǰ��++
		{
			this->m_pnode = this->m_pnode->m_next;
			return *this;
		}

		myself operator++(int)		//���غ���++
		{
			const myself temp(*this);
			this->m_pnode = this->m_pnode->m_next;
			return temp;
		}

		myself& operator--()		//����ǰ��--
		{
			this->m_pnode = this->m_pnode->m_prev;
			return *this;
		}

		myself operator--(int)		//���غ���--
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
		typedef list_iterator<T,T&,T*> iterator;		//��ͨ������
		typedef list_iterator<T,const T&,const T*> const_iterator;	//����������

	public:
		list()		//�޲�Ĭ�Ϲ��캯��
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
		}

		list(size_t size, const T& val=T())	//n��Ԫ�ع��캯��
		{
			this->m_head = new node(T());
			this->m_head->m_next = this->m_head;
			this->m_head->m_prev = this->m_head;
			while (size--)
			{
				this->push_back(val);
			}
		}

		list(long size, const T& val = T())	//n��Ԫ�ع��캯��
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

		list(int size, const T& val = T())	//n��Ԫ�ع��캯��
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
		list(InputIterator first, InputIterator last)		//���乹��
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
		
		list(const list<T>& obj)		//�������캯��
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

		list<T>& operator=(const list<T>& obj)		//��ֵ���������
		{
			if (this != &obj)
			{
				list<T>temp(obj);
				this->swap(temp);
			}
			return *this;
		}


		~list()		//��������
		{
			iterator it = this->begin();

			while (it != this->end())	//��������д��ͷɾ��һ��һ����ɾ������ȻҲ���Ը���βɾpop_back()��erase()
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

		bool empty()	const		//�п�
		{
			return this->begin() == this->end();	//����begin()��end()ͬʱָ��ͷ���ʱ�����
		}

		//����һ���������õ�Ԫ�ظ�����Ϊʲôʹ�ñ���һ�������أ�
		//������Ϊ����ʹ������ʱ���ٻ�ȥ֪������Ԫ�ظ����������Ƶ���ĵ��øýӿڻ�������ܵ��½�
		//��ʱ����Ӧ����list���н�����һ����¼Ԫ�ظ����ı���size
		//�����Ԫ�ز�������ӣ�ɾ���ͼ���
		size_t size()	const	//���Ԫ�ظ���
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

		void push_front(const T& val)	//ͷ��
		{
			node* newnode = new node(val);
			node*  next = this->m_head->m_next;
			newnode->m_next = next;
			this->m_head->m_next = newnode;
			newnode->m_prev = this->m_head;
			next->m_prev = newnode;
		}

		void push_back(const T& val)	//β��
		{
			node* tail = this->m_head->m_prev;
			node* newnode = new node(val);
			newnode->m_next = tail->m_next;
			newnode->m_prev = tail;
			tail->m_next = newnode;
			this->m_head->m_prev = newnode;
		}


		//����Ԫ�ص�ָ��λ�ã����ص��ǲ����Ԫ�صĵ�����
		iterator insert(iterator pos, const T& val)
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
			node* newnode = new node(val);		//�����½��

			node* cur = pos.m_pnode;		//��¼��ǰ����ָ��
			node* prev = cur->m_prev;		//��¼��ǰ����ǰһ������ָ��

			newnode->m_next = cur;
			newnode->m_prev = prev;
			prev->m_next = newnode;
			cur->m_prev = newnode;

			return iterator(newnode);		//����һ���õ�ǰ�Ĳ����Ԫ�صĽ�㹹������������ĵ�����
		}

		void insert(iterator pos, size_t n, const T& val)	//����n��val
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
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

		void insert(iterator pos, int n, const T& val)	//����n��val
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
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

		void insert(iterator pos, long n, const T& val)	//����n��val
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
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
		void insert(iterator pos, InputIterator first, InputIterator last)	//�������
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
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

		void pop_front()	//ͷɾ
		{
			assert(!empty());	//���� ���list�Ѿ�Ϊ�գ���ɾ������
			node* delnode = this->m_head->m_next;
			node* next = delnode->m_next;
			this->m_head->m_next = next;
			next->m_prev = this->m_head;
			delnode->m_next = delnode->m_prev = nullptr;
			delnode->m_val = T();
			delete delnode;
		}

		void pop_back()		//βɾ
		{
			assert(!empty());	//���� ���list�Ѿ�Ϊ�գ���ɾ������
			node* tail = this->m_head->m_prev;
			node* prev = tail->m_prev;
			this->m_head->m_prev = prev;
			prev->m_next = this->m_head;
			tail->m_next = tail->m_prev = nullptr;
			tail->m_val = T();
			delete tail;
		}


		//ɾ��ָ��λ�õ�Ԫ�أ�������һ��Ԫ�صĵ���������Ҫע����ǣ�
		//���ɾ�������һ��Ԫ�أ���ʱ���ص���ͷ���Ҳ����end()λ�õĵ�����
		iterator erase(iterator pos)			
		{
			assert(pos.m_pnode != nullptr);		//���� �������Ƿ�Ϊ��ָ�����
			assert(pos != end());				//���� list��Ԫ��Ϊ�ռ�ɾ��ͷ�������
			
			node* next = pos.m_pnode->m_next;
			node* prev = pos.m_pnode->m_prev;

			prev->m_next = next;
			next->m_prev = prev;

			pos.m_pnode->m_next = pos.m_pnode->m_prev = nullptr;
			pos.m_pnode->m_val = T();
			delete pos.m_pnode;

			return iterator(next);		
		}

		iterator erase(iterator first, iterator last)		//����ɾ��
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

		void clear()		//���Ԫ�أ������ǰ���������ɾ����
		{
			iterator it = this->begin();	

			while (it != this->end())	//��������д��ͷɾ��һ��һ����ɾ������ȻҲ���Ը���βɾpop_back()��erase()
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
		node* m_head;		//ͷָ��
	};
}
