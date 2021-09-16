#pragma once
#define _CRT_SECURE_NO_WARNINGS 1#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using  namespace std;
namespace ZJ
{
	template<class T>
	struct hashNode	//��ϣ�ڵ�
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

	template<class K, class T, class KOfVal, class Hash = _hash<K>>	//ǰ������
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
			if (m_node->m_next != nullptr)	//�����ǰ��Ͱû�����꣬����������Ͱ�ڵ�Ԫ��
			{
				m_node = m_node->m_next;
			}
			else
			{
				size_t length = static_cast<size_t>(m_ht->m_table.size());	
				size_t index = (m_ht->hash(m_ht->m_c(m_node->m_data))) % length;//�õ��������Ԫ��������ڵ��±�
				++index;	//Ȼ���������Ԫ�����ڵ�λ�ÿ�ʼѭ���������ҵ���һ��Ͱ
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
	//K---key����
	//T---ֵ����
	//KOfVal---����T�е�val
	//Hash---��ϣ��������Բ�ͬ���ͣ�ʹ�ò�ͬ�����õ�һ������ȡģ��keyֵ
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
			//����������ˣ��������Ǽ򵥴���һ��֮�䷵��һ��
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
			//����������ӵ���1�������ݣ���������Ĺ�ϣ��ͻ
			if (tableSize == m_size)
			{
				std::vector<node*>newtable(GetNextPrime(tableSize), nullptr);
				for (size_t i = 0; i < tableSize; ++i)
				{
					node* cur = m_table[i];
					//���ɱ��еĽڵ�ȡ�������¼������±��е�λ�ã��������ȥ
					while (cur != nullptr)	
					{
						node* next = cur->m_next;	//��¼��һ��Ҫ�����±�Ľڵ��ָ��
						size_t index = hash( m_c(cur->m_data) ) % newtable.size();
						cur->m_next = newtable[index];	//�������ͷ��
						newtable[index] = cur;
						cur = next;
					}
					m_table[i] = nullptr;
				}
				this->m_table.swap(newtable);	//����±�����ݽ���������ı�
			}
			tableSize = static_cast<int>(m_table.size());	//û����һ���Ļ�������index ģ��tableSize�Ĵ�С������ǰ�Ĵ�С
			size_t index = hash( m_c(data) ) % tableSize;
			node* cur = m_table[index];
			//1���Ȳ������Ԫ�ص�ֵ�ڲ��ڱ���
			while (cur != nullptr)
			{
				if (m_c(cur->m_data) == m_c(data))	//�ж��Ƿ���ȣ������ȵĻ�����˵�������֮ǰ�����������֮�䷵��cur�������Ԫ�����ڵ�λ��
				{
					return make_pair(iterator(cur, this), false);
				}
				else 
				{
					cur = cur->m_next;
				}
			}
			cur = new node(data);
			cur->m_next = m_table[index];	//��Ԫ��ͷ��
			m_table[index] = cur;
			++m_size;	//����Ԫ�ظ���
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
					if (prev == nullptr)	//ɾ����ͷ�ڵ����
					{
						m_table[index] = cur->m_next;
					}
					else
					{
						prev->m_next = cur->m_next;
					}
					delete cur;
					--this->m_size;	//���ٱ������ݵ�����
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
		std::vector<node*> m_table;	//��һ����̬����vector���洢�������൱��ָ������
		Hash hash;	//��ͬ������ͨ��Hash���õ�һ����������ȡģ�����֡�
		size_t m_size;	//��¼���д洢�����ݸ���
		KOfVal m_c;
	};
}
