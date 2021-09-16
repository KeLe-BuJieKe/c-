#pragma once
#include"hashTable.h"

namespace ZJ
{
	template<class K,class Hash = _hash<K>>
	class unordered_set
	{
	public:
		struct setKey
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef class hashTable<K, K, setKey, Hash>::iterator iterator;
		iterator begin()
		{
			return m_ht.begin();
		}

		iterator end()
		{
			return m_ht.end();
		}
		K insert(const K& k)
		{
			return m_ht.insert(k);
		}

	private:
		hashTable<K, K, setKey, Hash>m_ht;
	};
}