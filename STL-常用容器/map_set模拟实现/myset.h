#pragma once
#include"RBTree.h"

namespace ZJ
{
	template<class K>
	class set
	{
	public:
		class SetKeyOfCompare   //ÄÚ²¿Àà
		{
		public:
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef class RBTree<K, K, SetKeyOfCompare>::iterator iterator;
		typedef class RBTree<K, K, SetKeyOfCompare>::reverse_iterator reverse_iterator;


		iterator begin()
		{
			return m_tree.begin();
		}
		iterator end()
		{
			return m_tree.end();
		}

		reverse_iterator rbegin()
		{
			return m_tree.rbegin();
		}
		reverse_iterator rend()
		{
			return m_tree.rend();
		}
		pair<iterator, bool> insert(const K& k)
		{
			return m_tree.insert(k);
		}

	private:
		RBTree <K, K, SetKeyOfCompare>m_tree;
	};
}

