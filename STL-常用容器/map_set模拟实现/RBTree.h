#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//�ڵ����ɫ
enum class Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode	//������
{
	RBTreeNode<T>* m_left;	//��ڵ�
	RBTreeNode<T>* m_right;   //�ҽڵ�
	RBTreeNode<T>* m_parent;  //�ڵ�ĸ����(�������Ҫ ��ת ��Ϊ��ʵ�ּ򵥸����ĸ��ֶ�)

	T m_data; //�ڵ�����
	Colour m_c;	//�ڵ���ɫ


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
			while (parent != nullptr&& parent->m_right == cur )
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

//������������
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

	RBTree(const RBTree<K, T, KOfCompare>& obj)
	{
		m_root = copy(obj.m_root, nullptr);
	}

	RBTree<K, T, KOfCompare>& operator=(const RBTree<K, T, KOfCompare>& obj)
	{
		if (this != &obj)
		{
			RBTree<K, T, KOfCompare>temp = obj;	//���ÿ�������
			std::swap(temp.m_root, this->m_root);
		}
		return *this;
	}

	~RBTree() //���ú������ͷŽ��
	{
		if (m_root == nullptr)
		{
			return;
		}
		node* cur = m_root;
		node* prev = nullptr;
		stack<node*>s;
		while (cur != nullptr || !s.empty())
		{
			while (cur != nullptr)	//һֱ������Ž�ջ��
			{
				s.push(cur);
				cur = cur->m_left;
			}
			cur = s.top();
			s.pop();
			//cur->m_right==prev ����жϺ���Ҫ����ֹ�������ҽ��ʱ�����غ���
			if (cur->m_right == nullptr || cur->m_right == prev)
			{
				prev = cur;
				cur->m_left = nullptr;
				cur->m_parent = nullptr;
				cur->m_right = nullptr;
				delete cur;
				cur = nullptr;
			}
			else
			{
				s.push(cur);
				cur = cur->m_right;
			}
		}
	}

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
	


	pair<iterator,bool> insert(const T& data)
	{
		if (m_root == nullptr)
		{
			m_root = new node(data);
			m_root->m_c = Colour::BLACK;	//���ڵ����ɫ����Ϊ��
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

			cur = new node(data);	//Ĭ�Ϲ��캯����ɫ��ʼ��ΪRED��
			node* newnode = cur;
			if ( m_com(parent->m_data)> m_com(data))  //�ж��²���Ľڵ���Ҫ���뵽���ǵ���߻����ұߣ����ø��ڵ��ָ����������
			{
				parent->m_left = cur;
				cur->m_parent = parent;
			}
			else
			{
				parent->m_right = cur;
				cur->m_parent = parent;
			}


			while (parent != nullptr && parent->m_c == Colour::RED)	//��Ϊ���ǲ������ɫ�Ǻ�ɫ�������ǵĸ��׽ڵ����ɫҲΪ��ʱ��Ҫһֱ���ϵ�����ɫ
			{
				//�������˻����ɻ���������游�ڵ�Ϊʲô���ж���Ϊ��ָ����������������ǿ�ָ�룬��������ǲ��ǻ���ɿ�ָ����ʱ����أ�
				//��ʵ��Ȼ��������ǵĽڵ��в���ǰֻ��ͷ�ڵ�һ������ô���Ͳ�����뵽���ѭ������
				//��Ϊ���ڵ����ɫΪ ��
				//�����ʱ�����������������ڵ㣬�ڶ����ڵ㲻�����ڸ��ڵ����߻����ұߡ�
				//��ʱ��ô���Ǽ�������һ���ڵ��ڸ��������
				//��ô�������Ҫ�����Ԫ���ǲ��뵽�������ұߣ���ô��ʱ���Ǻ�����ͬ������������������ѭ������
				//������뵽�ڶ����ڵ�����棬��ô��ʱ��Ȼparent����ɫΪ�գ��������ǵ� �游�ڵ�(grandfather)����Ϊ��
				//���������������ﲻ��Ҫ�ж����Ƿ�Ϊ��ָ����������������ɿ�ָ���������
				node* grandfather=parent->m_parent;	//�游

				//Ҫ���ʲô��ɫ�ؼ�������uncle�����������ҵ������λ����������
				if (grandfather->m_left == parent)  //�ж�
				{
					node* uncle = grandfather->m_right;
					//��һ�������������� ��Ϊ ��
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						//Ϊʲô��cur=grandfather��������parent�أ�
						//������Ϊ��ʱ���������parent����ɫ��ɺ�ɫ����ɫʱ������ڵ�Ͳ���Ҫ�ж��ˡ�
						//�����parent��ʼ���Ͳ��ܼ������ϸ����ˡ���ֱ����ֹѭ����
						//���Ǵ����Ǹոձ�ɺ�ɫ��grandfather�ڵ㿪ʼ���п��ܴ�ʱgrandfather�ڵ��Ϊ��
						//�����ϲ�ÿ��·���ĺ�ɫ�ڵ���Ŀ��ͬ��������
						cur = grandfather;			//�������ϸ�����ɫ
						parent = cur->m_parent;
					}
					//�ڶ� ��������������岻���� �� ���������Ϊ ��
					else
					{
						//˫�� -> ����
						if (parent->m_right == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
						{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
							RotateL(parent);
							std::swap(parent, cur);
						}

						//�����п����ǵ������������ת������
						RotateR(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
						break;	//����дҲ���Բ�д
					}
				}
				else
				{
					//��ʱuncle�����壩�ڵ������ǵ����
					node* uncle = grandfather->m_left;
					//��һ�������������� ��Ϊ ��
					if (uncle != nullptr && uncle->m_c == Colour::RED)
					{
						grandfather->m_c = Colour::RED;
						parent->m_c = uncle->m_c = Colour::BLACK;

						cur = grandfather;			//�������ϸ�����ɫ
						parent = cur->m_parent;
					}
					//�ڶ� ��������������岻���� �� ���������Ϊ ��
					else
					{
						//˫�� -> ����
						if (parent->m_left == cur)	//�ж�·���Ƿ������ߣ���������߾���Ҫ��������������
						{						//������ɺ󣬽�parentָ����curָ���ָ����ģ���Ϊcur��parent����Դ����ˣ���Ȼ����ִ���
							RotateR(parent);
							std::swap(parent, cur);
						}

						//�����п����ǵ������������ת������
						RotateL(grandfather);
						grandfather->m_c = Colour::RED;
						parent->m_c = Colour::BLACK;

						//��Ϊ������������ ��ɫ���Ǻ�ɫ��֮�󶼲���Ӱ����ÿ��·���ĺ�ɫ�ڵ����
						break;	//����дҲ���Բ�д
					}
				}
			}
			m_root->m_c = Colour::BLACK;	//ʼ����ͷ�ڵ����ɫΪ��
			return make_pair(iterator(newnode), true);
		}
	}

	//ɾ������ ɾ�����ֵ�
	bool erase(const K& key)
	{
		//���ڱ���������
		node* parent = nullptr;
		node* cur = m_root;
		//���ڱ��ʵ�ʵĴ�ɾ����㼰�丸���
		node* delParentPos = nullptr;
		node* delPos = nullptr;
		while (cur != nullptr)
		{
			if (key < m_com(cur->m_data)) //����keyֵС�ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->m_left;
			}
			else if (key > m_com(cur->m_data)) //����keyֵ���ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->m_right;
			}
			else //�ҵ��˴�ɾ�����
			{
				if (cur->m_left == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == m_root) //��ɾ������Ǹ����
					{
						m_root = m_root->m_right; //�ø�������������Ϊ�µĸ����
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_c = Colour::BLACK; //�����Ϊ��ɫ
						}
						delete cur; //ɾ��ԭ�����
						return true;
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
				else if (cur->m_right == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == m_root) //��ɾ������Ǹ����
					{
						m_root = m_root->m_left; //�ø�������������Ϊ�µĸ����
						if (m_root)
						{
							m_root->m_parent = nullptr;
							m_root->m_c = Colour::BLACK; //�����Ϊ��ɫ
						}
						delete cur; //ɾ��ԭ�����
						return true;
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
				else //��ɾ������������������Ϊ��
				{
					//�滻��ɾ��
					//Ѱ�Ҵ�ɾ���������������keyֵ��С�Ľ����Ϊʵ��ɾ�����
					node* minParent = cur;
					node* minRight = cur->m_right;
					while (minRight->m_left != nullptr)
					{
						minParent = minRight;
						minRight = minRight->m_left;
					}
					cur->m_data = minRight->m_data; 
					delParentPos = minParent; //���ʵ��ɾ�����ĸ����
					delPos = minRight; //���ʵ��ɾ���Ľ��
					break; //���к�����ĵ����Լ�����ʵ��ɾ��
				}
			}
		}

		if (delPos == nullptr) //delPosû�б��޸Ĺ���˵��û���ҵ���ɾ�����
		{
			return false;
		}

		//��¼��ɾ����㼰�丸��㣨���ں���ʵ��ɾ����
		node* del = delPos;
		node* delP = delParentPos;

		//��������� Ϊ��ɾ����ɫ�������ָ������������
		if (delPos->m_c == Colour::BLACK) //ɾ�����Ǻ�ɫ���
		{
			if (delPos->m_left != nullptr) //��ɾ�������һ����ɫ�����ӣ��������Ǻ�ɫ��
			{
				delPos->m_left->m_c = Colour::BLACK; //�������ɫ�����ӱ�ڼ���
			}
			else if (delPos->m_right != nullptr) //��ɾ�������һ����ɫ���Һ��ӣ��������Ǻ�ɫ��
			{
				delPos->m_right->m_c = Colour::BLACK; //�������ɫ���Һ��ӱ�ڼ���
			}
			else //��ɾ���������Ҿ�Ϊ��
			{
				while (delPos != m_root) //����һֱ�����������
				{
					if (delPos == delParentPos->m_left) //��ɾ��������丸��������
					{
						node* brother = delParentPos->m_right; //�ֵܽ�����丸�����Һ���
						//���һ��brotherΪ��ɫ
						if (brother->m_c == Colour::RED)
						{
							delParentPos->m_c = Colour::RED;
							brother->m_c = Colour::BLACK;
							RotateL(delParentPos);
							//��Ҫ��������
							brother = delParentPos->m_right; //����brother�������ڱ�ѭ����ִ����������Ĵ�������
						}

						//�������brotherΪ��ɫ���������Һ��Ӷ��Ǻ�ɫ������ һ��Ϊ��һ��Ϊ��ʱ
						//�������߶�ΪNIL���������߶�Ϊ��ʱ
						if (((brother->m_left == nullptr) || (brother->m_left->m_c == Colour::BLACK))
							&& ((brother->m_right == nullptr) || (brother->m_right->m_c == Colour::BLACK)))
						{
							brother->m_c = Colour::RED;
							if (delParentPos->m_c == Colour::RED)
							{
								delParentPos->m_c = Colour::BLACK;
								break;
							}
							else
							{
								//��Ҫ��������
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//�������brotherΪ��ɫ�����������Ǻ�ɫ��㣬�Һ����Ǻ�ɫ����Ϊ��
							if ((brother->m_right == nullptr) || (brother->m_right->m_c == Colour::BLACK))
							{
								brother->m_left->m_c = Colour::BLACK;
								brother->m_c = Colour::RED;
								RotateR(brother);
								//��Ҫ��������
								brother = delParentPos->m_right; //����brother������ִ����������ĵĴ�������
							}

							//����ģ�brotherΪ��ɫ�������Һ����Ǻ�ɫ���
							brother->m_c = delParentPos->m_c;
							delParentPos->m_c = Colour::BLACK;
							brother->m_right->m_c = Colour::BLACK;
							RotateL(delParentPos);
							break; //�����ִ����Ϻ����һ������
						}
					}
					else //delPos == delParentPos->m_right //��ɾ��������丸�����Һ���
					{
						node* brother = delParentPos->m_left; //�ֵܽ�����丸��������
						//���һ��brotherΪ��ɫ
						if (brother->m_c == Colour::RED) //brotherΪ��ɫ
						{
							delParentPos->m_c = Colour::RED;
							brother->m_c = Colour::BLACK;
							RotateR(delParentPos);
							//��Ҫ��������
							brother = delParentPos->m_left; //����brother�������ڱ�ѭ����ִ����������Ĵ�������
						}

						//�������brotherΪ��ɫ���������Һ��Ӷ��Ǻ�ɫ����Ϊ��
						if (((brother->m_left == nullptr) || (brother->m_left->m_c == Colour::BLACK))
							&& ((brother->m_right == nullptr) || (brother->m_right->m_c == Colour::BLACK)))

						{
							brother->m_c = Colour::RED;
							if (delParentPos->m_c == Colour::RED)
							{
								delParentPos->m_c = Colour::BLACK;
								break;
							}
							else
							{
								//��Ҫ��������
								delPos = delParentPos;
								delParentPos = delPos->m_parent;
							}
						}
						else
						{
							//�������brotherΪ��ɫ�������Һ����Ǻ�ɫ��㣬�����Ǻ�ɫ����Ϊ��
							if ((brother->m_left == nullptr) || (brother->m_left->m_c == Colour::BLACK))
							{
								brother->m_right->m_c = Colour::BLACK;
								brother->m_c = Colour::RED;
								RotateL(brother);
								//��Ҫ��������
								brother = delParentPos->m_left; //����brother������ִ����������ĵĴ�������
							}

							//����ģ�brotherΪ��ɫ�����������Ǻ�ɫ���
							brother->m_c = delParentPos->m_c;
							delParentPos->m_c = Colour::BLACK;
							brother->m_left->m_c = Colour::BLACK;
							RotateR(delParentPos);
							break; //�����ִ����Ϻ����һ������
						}
					}
				}
			}
		}

		//����ɾ�����ĺ�����ɾ����㸸�׵����ӹ�ϵ
		if (del->m_left == nullptr) //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->m_left) //ʵ��ɾ��������丸��������
			{
				delP->m_left = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->m_right = del->m_right;
				if (del->m_right != nullptr)
				{
					del->m_right->m_parent = delP;
				}
			}
		}
		else //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->m_left) //ʵ��ɾ��������丸��������
			{
				delP->m_left = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->m_right = del->m_left;
				if (del->m_left != nullptr)
				{
					del->m_left->m_parent = delP;
				}
			}
		}

		//��󽫽��ɾ��
		delete del;
		return true;
	}

private:
	//���������ǲ�ƽ��Ľ���ָ��
	void RotateL(node* parent)	//����
	{
		node* subR = parent->m_right;	//��������ҽ��
		node* subRL = subR->m_left;		//��������ҽ�������

		parent->m_right = subRL;		//�����Ƚ����ǵ�parent����ָ��subRL
		if (subRL != nullptr)			//�ٽ�subRL�ĸ���ָ��parent��㣬������Ҫ�ж�һ���Ƿ��ǿ�ָ�룬���subRL�ǿ�ָ��Ļ���
										//��ô�����������������
		{
			subRL->m_parent = parent;
		}

		node* curParent = parent->m_parent;	//��һ�����洢parent�ĸ���
		parent->m_parent = subR;			//��ʹ��parent�ĸ���ָ��ָ����ԭ�ȵ��ҽ��(subR)

		subR->m_left = parent;				//����subR����ָ��parent
		if (parent == m_root)				//��������ж�һ�����Ƿ�Ϊ�������parentΪ���Ļ�����ô���ǵĸ����ָ��Ҳ�øı�
											//���ҽ�subR�ĸ���ָ����Ϊ�գ���ʱsubR��ʱΪ�����
		{
			m_root = subR;
			subR->m_parent = nullptr;
		}
		else
		{									//�����Ϊͷ�ڵ㣬��ô����ֻ��Ҫ��subR�ĸ���ָ��ָ��parent֮ǰ�ĸ��׽��
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


	void RotateR(node* parent)	//����
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


	node* copy(node* root, node* parent)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		node* copyNode = new node(root->m_data);
		copyNode->m_c = root->m_c;
		copyNode->m_parent = parent;
		copyNode->m_left = copy(root->m_left, copyNode);
		copyNode->m_right = copy(root->m_right, copyNode);
		return copyNode;
	}


private:
	node* m_root;	//�����
	KOfCompare m_com;	//���øö�����÷º������Ƚϴ�С
};
