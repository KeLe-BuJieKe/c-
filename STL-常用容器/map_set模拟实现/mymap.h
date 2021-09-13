#pragma once
#include"RBTree.h"

namespace ZJ
{
	template<class K, class V>
	class map
	{
	public:
		class MapKeyOfCompare
		{
		public:
			const K& operator()(const pair<K,V>&kv)
			{
				return kv.first;
			}
		};
		typedef class RBTree<K, pair<K,V>, MapKeyOfCompare>::iterator iterator;

		iterator begin()
		{
			return m_tree.begin();
		}
		iterator end()
		{
			return m_tree.end();
		}
		pair<iterator,bool> insert(const pair<K,V>&kv)
		{
			return m_tree.insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool>  ret = m_tree.insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree <K, pair<K, V>, MapKeyOfCompare>m_tree;
	};
}

