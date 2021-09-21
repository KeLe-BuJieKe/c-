#pragma once
#include"hashTable.h"

namespace ZJ
{
	template<class K,class V,class Hash=_hash<K>>
	class unordered_map
	{
	public:
		struct mapKey
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef class hashTable<K, pair<K,V>, mapKey, Hash>::iterator iterator;
		iterator begin()
		{
			return m_ht.begin();
		}

		iterator end()
		{
			return m_ht.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return m_ht.insert(kv);
		}
		V& operator[](const K&key)
		{
			pair<iterator, bool> ret = m_ht.insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		hashTable<K, pair<K, V>, mapKey, Hash>m_ht;
	};
}