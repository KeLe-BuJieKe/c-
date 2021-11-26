#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

namespace ZJ
{

	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashNode
	{
		pair<K, V>  m_kv;
		Status m_status = Status::EMPTY;
	};

	template<class K,class V>
	class Hash
	{
	public:
		Hash() :m_num(0)
		{
			this->m_hash.resize(10);
			this->m_loadFactor = m_num / m_hash.size();
		}

		bool Insert(const pair<K,V>  kv)
		{
			if (Find(kv.first) != nullptr)
			{
				return  false;
			}
			if (m_loadFactor > 0.7)
			{
				Hash<K, V>newTable;
				newTable.m_hash.resize(m_hash.size()*2);
				for (auto& e : m_hash)
				{
					if (e.m_status == EXIST)
					{
						newTable.Insert(e.m_kv);
					}
				}
				m_hash.swap(newTable.m_hash);
			}
			//����ȡģΪʲô�õĲ���capacity�أ���Ϊ������ʹ��reserve������ǰ���ÿռ䣬���Ǻ���Ŀ��õĿռ䲢��������ֱ��ȥ����
			//�����ͻ�ʹ�ó����������Ҫ % ����capacity�͵ñ��뱣֤ size��capacityһ�¡�
			//�����黹��ʹ�� % size()
			size_t index = kv.first % m_hash.size();
			
			//̽������λ��  --����̽��
			size_t i = 1;
			while (m_hash[index].m_status == EXIST)
			{
				index += i;
				index %= m_hash.size();
			}

			m_hash[index].m_kv = kv;
			m_hash[index].m_status = EXIST;
			++m_num;
			m_loadFactor=(double)m_num/m_hash.size();
			return true;
		}

		HashNode<K,V>* Find(const K& key)
		{
			size_t index = key % m_hash.size();
			size_t i = 1;
			while(m_hash[index].m_status!=EMPTY)
			{
				if (m_hash[index].m_kv.first == key&& m_hash[index].m_status == EXIST)
				{
					return &m_hash[index];
				}
				index += i;
				index %= m_hash.size();
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashNode<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->m_status = DELETE;
				--m_num;
				return true;
			}

		}
	private:
		vector<HashNode<K, V>> m_hash;
		size_t m_num; //��Ч���ݵĸ���
		double m_loadFactor;
	};
}