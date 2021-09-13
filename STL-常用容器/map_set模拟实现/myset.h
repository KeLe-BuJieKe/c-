#pragma once
#include"RBTree.h"

namespace ZJ
{
	template<class K>
	class set
	{
	public:
		class SetKeyOfCompare
		{
		public:
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef class RBTree<K, K, SetKeyOfCompare>::iterator iterator;

		iterator begin()
		{
			return m_tree.begin();
		}
		iterator end()
		{
			return m_tree.end();
		}
		pair<iterator, bool> insert(const K& k)
		{
			return m_tree.insert(k);
		}
	private:
		RBTree <K, K, SetKeyOfCompare>m_tree;
	};
}

