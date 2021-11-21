#pragma once
#include<iostream>
using namespace std;

//节点的颜色
enum class Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode	//三叉链
{
	RBTreeNode<T>* m_left;	//左节点
	RBTreeNode<T>* m_right;   //右节点
	RBTreeNode<T>* m_parent;  //节点的父结点(红黑树需要 旋转 ，为了实现简单给出的该字段)

	T m_data; //节点数据
	Colour m_c;	//节点颜色


	RBTreeNode(const T& data)
		: m_left(nullptr), m_right(nullptr), m_parent(nullptr)
		, m_data(data),m_c(Colour::RED)
	{}
};

template<class T,class Ref,class Ptr>
class Treeiterator
{
public:
	typedef RBTreeNode<T>node;
	typedef Ref reference;
	typedef Ptr pointer;
public:


	Treeiterator(node* Pnode):m_node(Pnode)
	{}

	Ref operator*()
	{
		return m_node->m_data;
	}
	Ptr operator->()
	{
		return &m_node->m_data;
	}


	Treeiterator<T,Ref,Ptr> operator++()
	{
		if (m_node->m_right != nullptr)
		{
			node* subLeft = m_node->m_right;
			while (subLeft->m_left != nullptr)
			{
				subLeft=subLeft->m_left;
			}
			m_node = subLeft;
		}
		else
		{
			node* cur = m_node;
			node* parent = cur->m_parent;
			while (parent != nullptr&&parent->m_right== cur )
			{
				cur = parent;
				parent = parent->m_parent;
			}
			m_node = parent;
		}
		return *this;
	}

	Treeiterator<T, Ref, Ptr> operator--()
	{
		if (m_node->m_left != nullptr)
		{
			node* subright = m_node->m_left;
			while (subright->m_right != nullptr)
			{
				subright = subright->m_right;
			}
			m_node = subright;
		}
		else
		{
			node* cur = m_node;
			node* parent = cur->m_parent;
			while (parent != nullptr && parent->m_left == cur)
			{
				cur = parent;
				parent = parent->m_parent;
			}
			m_node = parent;
		}
		return *this;
	}

	bool operator!=(const Treeiterator<T,Ref,Ptr>& obj)
	{
		return m_node != obj.m_node;
	}

	bool operator==(const Treeiterator<T, Ref, Ptr>& obj)
	{
		return m_node == obj.m_node;
	}
private:
	node* m_node;

};

//迭代器适配器
template<class iterator>
class reverseIterator
{
public:
	typedef typename iterator::reference Ref;
	typedef typename iterator::pointer Ptr;
public:
	
	reverseIterator(iterator it) :m_it(it)
	{}
	
	Ref operator *()
	{
		return *m_it;
	}

	Ptr operator->()
	{
		return m_it.operator->();
	}

	reverseIterator<iterator>& operator++()
	{
		--m_it;
		return *this;
	}

	reverseIterator<iterator>& operator--()
	{
		++m_it;
		return *this;
	}

	bool operator!=(const reverseIterator<iterator>& obj)
	{
		return m_it!=obj.m_it;
	}

	bool operator==(const reverseIterator<iterator>& obj)
	{
		return m_it == obj.m_it;
	}

private:
	iterator m_it;
};

template<class K,class T,class KOfCompare>
class RBTree
{
public:
	typedef RBTreeNode<T> node;
	typedef Treeiterator<T,T&,T*> iterator;
	typedef Treeiterator<T, const T&, const T*> const_iterator;
	typedef  reverseIterator< iterator > reverse_iterator;
	RBTree() :m_root(nullptr)
	{}

	reverse_iterator rbegin()
	{
		node* cur = m_root;
		while (cur != nullptr && cur->m_right != nullptr)
		{
			cur = cur->m_right;
		}
		return reverse_iterator(iterator(cur));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(iterator(nullptr));
	}

	iterator begin()
	{
		node* cur = m_root;
		while (cur != nullptr&&cur->m_left!=nullptr)
		{
			cur = cur->m_left;
		}
		return iterator(cur);
	}
	iterator end()
	{
		return iterator(nullptr);
	}

	//传进来的是不平衡的结点的指针
	void RotateL(node* parent)	//左旋
	{
		node* subR = parent->m_right;	//出问题的右结点
		node* subRL = subR->m_left;		//出问题的右结点的左结点

		parent->m_right = subRL;		//首先先将我们的parent的右指向subRL
		if (subRL != nullptr)			//再将subRL的父亲指向parent结点，但这样要判断一下是否是空指针，如果subRL是空指针的话，
										//那么解引用它会出现问题
		{
			subRL->m_parent = parent;
		}

		node* curParent = parent->m_parent;	//拿一个结点存储parent的父亲
		parent->m_parent = subR;			//再使得parent的父亲指针指向它原先的右结点(subR)

		subR->m_left = parent;				//在让subR的左指向parent
		if (parent == m_root)				//在这里得判断一下它是否为根，如果parent为根的话，那么我们的根结点指针也得改变
											//并且将subR的父亲指针置为空，此时subR此时为根结点
		{
			m_root = subR;
			subR->m_parent = nullptr;
		}
		else
		{									//如果不为头节点，那么我们只需要将subR的父亲指针指向parent之前的父亲结点
			if (curParent->m_left == parent)
			{
				curParent->m_left = subR;
			}
			else
			{
				curParent->m_right = subR;
			}
			subR->m_parent = curParent;
		}
	}



	void RotateR(node* parent)	//右旋
	{
		node* subL = parent->m_left;
		node* subLR = subL->m_right;

		parent->m_left = subLR;
		if (subLR != nullptr)
		{
			subLR->m_parent = parent;
		}

		node* curParent = parent->m_parent;
		parent->m_parent = subL;

		subL->m_right = parent;
		if (parent == m_root)
		{
			m_root = subL;
			subL->m_parent = nullptr;
		}
		else
		{
			if (curParent->m_left == parent)
			{
				curParent->m_left = subL;
			}
			else
			{
				curParent->m_right = subL;
			}
			subL->m_parent = curParent;
		}

	}


	pair<iterator,bool> insert(const T& data)
	{
		if (m_root == nullptr)
		{
			m_root = new node(data);
			m_root->m_c = Colour::BLACK;	//根节点的颜色必须为黑
			return make_pair(iterator(m_root),true);
		}
		else
		{
			node* parent = nullptr;	
			node* cur = m_root;
			while (cur!=nullptr)
			{
				if ( m_com( cur->m_data ) < m_com(data))
				{
					parent = cur;
					cur = cur->m_right;
				}
				else if (m_com(cur->m_data) > m_com(data))
				{
					parent = cur;
					cur = cur->m_left;
				}
				else
				{
					return make_pair(iterator(cur), true);
				}
			}

			cur = new node(data);	//默认构造函数颜色初始化为RED了
			node* newnode = cur;
			if ( m_com(parent->m_data)> m_com(data))  //判断新插入的节点是要插入到我们的左边还是右边，并用父节点的指针连接起来
			{
				parent->m_left = cur;
				cur->m_parent = parent;
			}
			else
			{
				parent->m_right = cur;
				cur->m_parent = parent;
			}


			while (parent != nullptr && parent->m_c == Colour::RED)	//因为我们插入的颜色是红色，当我们的父亲节点的颜色也为红时，要一直向上调整颜色
			{
				//可能有人会有疑惑，这里这个祖父节点为什么不判断它为空指针的情况，并且如果是空指针，下面访问是不是会造成空指针访问崩溃呢？
				//其实不然，如果我们的节点中插入前只有头节点一个，那么它就不会进入到这个循环体里
				//因为根节点的颜色为 黑
				//如果此时这个红黑树中有两个节点，第二个节点不管它在根节点的左边还是右边。
				//此时那么我们假设另外一个节点在根结点的左边
				//那么如果我们要插入的元素是插入到根结点的右边，那么此时我们和上面同样的情况，进步来这个循环体里
				//如果插入到第二个节点的下面，那么此时虽然parent的颜色为空，但是我们的 祖父节点(grandfather)并不为空
				//综上所诉所以这里不需要判断它是否为空指针访问情况，不会造成空指针崩溃现象。
				node* grandfather=parent->m_parent;	//祖父

				//要变成什么颜色关键看叔叔uncle，所以我们找到叔叔的位置在左还是右
				if (grandfather->m_left == parent)  //判断
				{
					node* uncle = grandfather->m_right;
					//第一种情况：叔叔存在 且为 红
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						//为什么让cur=grandfather，而不是parent呢？
						//这是因为此时这种情况，parent的颜色变成黑色，黑色时，这个节点就不需要判断了。
						//如果从parent开始，就不能继续往上更新了。会直接终止循环。
						//而是从我们刚刚变成红色的grandfather节点开始，有可能此时grandfather节点变为红
						//导致上层每条路径的黑色节点数目不同发生错误。
						cur = grandfather;			//继续往上更新颜色
						parent = cur->m_parent;
					}
					//第二 第三种情况：叔叔不存在 或 叔叔存在且为 黑
					else
					{
						//双旋 -> 单旋
						if (parent->m_right == cur)	//判断路径是否是折线，如果是折线就需要先左旋，在右旋
						{						//左旋完成后，将parent指针与cur指针的指向更改，因为cur与parent的相对次序反了，不然会出现错误
							RotateL(parent);
							std::swap(parent, cur);
						}

						//这里有可能是第三种情况左旋转换而来
						RotateR(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//因为不管你上面是 红色还是黑色，之后都不会影响其每条路径的黑色节点个数
						break;	//可以写也可以不写
					}
				}
				else
				{
					//此时uncle（叔叔）节点在我们的左边
					node* uncle = grandfather->m_left;
					//第一种情况：叔叔存在 且为 红
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						cur = grandfather;			//继续往上更新颜色
						parent = cur->m_parent;
					}
					//第二 第三种情况：叔叔不存在 或 叔叔存在且为 黑
					else
					{
						//双旋 -> 单旋
						if (parent->m_left == cur)	//判断路径是否是折线，如果是折线就需要先右旋，在左旋
						{						//右旋完成后，将parent指针与cur指针的指向更改，因为cur与parent的相对次序反了，不然会出现错误
							RotateR(parent);
							std::swap(parent, cur);
						}

						//这里有可能是第三种情况右旋转换而来
						RotateL(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//因为不管你上面是 红色还是黑色，之后都不会影响其每条路径的黑色节点个数
						break;	//可以写也可以不写
					}
				}
			}
			m_root->m_c = Colour::BLACK;	//始终让头节点的颜色为黑
			return make_pair(iterator(newnode), true);
		}
	}

	void _Inorder(node*& root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->m_left);
		cout << root->m_kv.first << " : " << root->m_kv.second << endl;
		_Inorder(root->m_right);
	}
	void Inorder()
	{
		_Inorder(m_root);
		cout << endl;
	}

	bool IsValidRBTree()
	{
		node* pRoot = m_root;
		// 空树也是红黑树
		if (nullptr == pRoot)
		{
			return true;
		}
		// 检测根节点是否满足情况
		if (Colour::BLACK != pRoot->m_c)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		node* pCur = pRoot;
		while (pCur!=nullptr)
		{
			if (Colour::BLACK == pCur->m_c)
			{
				blackCount++;
			}
			pCur = pCur->m_left;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(node* pRoot, size_t k, const size_t blackCount)
	{
		//走到nullptr之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (Colour::BLACK == pRoot->m_c)
		{
			k++;
		}
		// 检测当前节点与其双亲是否都为红色
		node* pParent = pRoot->m_parent;
		if (pParent && Colour::RED == pParent->m_c && Colour::RED == pRoot->m_c)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->m_left, k, blackCount) &&
			_IsValidRBTree(pRoot->m_right, k, blackCount);
	}
private:
	node* m_root;	//根结点
	KOfCompare m_com;	//利用该对象调用仿函数来比较大小
};
