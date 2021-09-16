#pragma once
#define _CRT_SECURE_NO_WARNINGS 1#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using  namespace std;
namespace ZJ
{
	template<class T>
	struct hashNode	//哈希节点
	{
		T m_data;
		hashNode<T>* m_next;
		hashNode(const T&data):m_data(data),m_next(nullptr)
		{}
	};

	template<class K>
	struct _hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct _hash<string>
	{
		const size_t& operator()(const string& key)
		{
			size_t size = key.size();
			size_t ret = 0;
			for (size_t i = 0; i < size; ++i)
			{
				ret *= 131;
				ret += key[i];
			}
			return  ret;
		}
	};
	const int PRIMECOUNT = 28;
	const size_t primeList[PRIMECOUNT] =
	{
	 53ul, 97ul, 193ul, 389ul, 769ul,
	 1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	 49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	 1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	 50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	 1610612741ul, 3221225473ul, 4294967291ul
	};

	template<class K, class T, class KOfVal, class Hash = _hash<K>>	//前置声明
	class hashTable;
	template<class K,class T,class KOfVal,class Hash>
	class hashIterator
	{
	public:
		typedef hashIterator<K, T, KOfVal, Hash> self;
		typedef class hashTable<K, T, KOfVal, Hash> HT;
		HT* m_ht;

		typedef hashNode<T> Node;
		Node* m_node;
		hashIterator(Node*node, HT* ht) :m_node(node), m_ht(ht)
		{}
		T& operator*()
		{
			return m_node->m_data;
		}
		T* operator->()
		{
			return &m_node->m_data;
		}

		bool operator!=(const self&s)
		{
			return m_node != s.m_node;
		}

		self& operator++()
		{
			if (m_node->m_next != nullptr)	//如果当前的桶没有走完，则继续走这个桶内的元素
			{
				m_node = m_node->m_next;
			}
			else
			{
				size_t length = static_cast<size_t>(m_ht->m_table.size());	
				size_t index = (m_ht->hash(m_ht->m_c(m_node->m_data))) % length;//得到现在这个元素所存放在的下标
				++index;	//然后跳过这个元素所在的位置开始循环迭代，找到下一个桶
				for (; index < length; ++index)
				{
					Node* cur = m_ht->m_table[index];
					if (cur != nullptr)
					{
						m_node = cur;
						return *this;
					}
				}
				m_node = nullptr;
			}
			return *this;
		}
	};
	//K---key类型
	//T---值类型
	//KOfVal---返回T中的val
	//Hash---哈希函数，针对不同类型，使用不同方法得到一个可以取模的key值
	template<class K,class T,class KOfVal,class Hash=_hash<K>>
	class hashTable
	{
	public:
		typedef hashNode<T> node;
		typedef hashIterator<K, T, KOfVal, Hash> iterator;
		template<class K, class T, class KOfVal, class Hash>
		friend class hashIterator;
		hashTable():m_size(0)
		{
			m_table.resize(10, nullptr);
		}
		~hashTable()
		{
			clear();
		}
		iterator begin()
		{
			size_t length = static_cast<size_t>(m_table.size());
			for (size_t i = 0; i < length; ++i)
			{
				if (m_table[i] != nullptr)
				{
					return iterator(m_table[i], this);
				}
			}
			//如果不存在了，这里我们简单处理一下之间返回一个
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		size_t GetNextPrime(size_t prime)
		{
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
				{
					return primeList[i];
				}
			}

			return primeList[i];
		}
		pair<iterator,bool> insert(const T&data)
		{
			size_t tableSize = static_cast<size_t>(m_table.size());
			//如果负载因子等于1，则增容，避免大量的哈希冲突
			if (tableSize == m_size)
			{
				std::vector<node*>newtable(GetNextPrime(tableSize), nullptr);
				for (size_t i = 0; i < tableSize; ++i)
				{
					node* cur = m_table[i];
					//将旧表中的节点取下来重新计算在新表中的位置，并插入进去
					while (cur != nullptr)	
					{
						node* next = cur->m_next;	//记录下一个要传给新表的节点的指针
						size_t index = hash( m_c(cur->m_data) ) % newtable.size();
						cur->m_next = newtable[index];	//单链表的头插
						newtable[index] = cur;
						cur = next;
					}
					m_table[i] = nullptr;
				}
				this->m_table.swap(newtable);	//最后将新表的数据交换给自身的表
			}
			tableSize = static_cast<int>(m_table.size());	//没有这一步的话，下面index 模的tableSize的大小是增容前的大小
			size_t index = hash( m_c(data) ) % tableSize;
			node* cur = m_table[index];
			//1、先查找这个元素的值在不在表中
			while (cur != nullptr)
			{
				if (m_c(cur->m_data) == m_c(data))	//判断是否相等，如果相等的话，就说明这个数之前插入过，我们之间返回cur。即这个元素所在的位置
				{
					return make_pair(iterator(cur, this), false);
				}
				else 
				{
					cur = cur->m_next;
				}
			}
			cur = new node(data);
			cur->m_next = m_table[index];	//将元素头插
			m_table[index] = cur;
			++m_size;	//更新元素个数
			return make_pair(iterator(cur,this),true);
		}

		iterator find(const K&key)
		{
			size_t index = hash(key) % m_table.size();
			node* cur = m_table[index];
			while (cur != nullptr)
			{
				if (m_c(cur->m_data) == key)
				{
					return iterator(cur,this);
				}
				else
				{
					cur = cur->m_next;
				}
			}
			return iterator(nullptr,this);
		}

		bool erase(const K&key)
		{
			size_t index = hash(key) % m_table.size();
			node* cur = m_table[index];
			node* prev = nullptr;
			while (cur != nullptr)
			{
				if (m_c(cur->m_data) == key)
				{
					if (prev == nullptr)	//删除是头节点情况
					{
						m_table[index] = cur->m_next;
					}
					else
					{
						prev->m_next = cur->m_next;
					}
					delete cur;
					--this->m_size;	//减少表中数据的数量
					cur = nullptr;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->m_next;
				}
			}
			return false;
		}

		void clear()
		{
			size_t length = static_cast<size_t>(m_table.size());
			for (size_t i = 0; i < length; ++i)
			{
				node* cur = m_table[i];
				while (cur != nullptr)
				{
					node* next = cur->m_next;
					delete cur;
					cur = next;
				}
				m_table[i] = nullptr;
			}
			this->m_size = 0;
		}
	private:
		std::vector<node*> m_table;	//拿一个动态数组vector来存储单链表，相当于指针数组
		Hash hash;	//不同的类型通过Hash来得到一个可以用来取模的数字。
		size_t m_size;	//记录表中存储的数据个数
		KOfVal m_c;
	};
}
