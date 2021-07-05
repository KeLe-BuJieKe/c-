#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct ListNode
{
	float _coef;		//系数
	float _exp;		//指数
	ListNode* _next;
};


//创建一个新的结点
ListNode* CreatNode()
{
	ListNode* newNode = new ListNode;
	newNode->_coef = 0;
	newNode->_exp = 0;
	newNode->_next = nullptr;
	return newNode;
}

class Polynomial
{
public:
	//构造函数初始化对象
	Polynomial()
	{
		this->m_head = new ListNode;
		this->m_head->_coef = 0;
		this->m_head->_exp = 0;
		this->m_head->_next = nullptr;
	}
	//拷贝构造函数
	Polynomial(const Polynomial& obj)
	{
		this->m_head = new ListNode;
		this->m_head->_coef = 0;
		this->m_head->_exp = 0;
		this->m_head->_next = nullptr;

		ListNode* source = obj.m_head->_next;
		ListNode* dest = this->m_head;
		while (source != nullptr)
		{
			dest->_next = CreatNode();
			dest = dest->_next;
			dest->_coef = source->_coef;
			dest->_exp = source->_exp;

			source = source->_next;
		}
	}

	void CreatPolyn(int& size);  //创建多项式
	void PrintPolyn();			//打印多项式
	Polynomial& AddPolyn(Polynomial& A,Polynomial& B);				 //多项式加法
	Polynomial& subPolyn(Polynomial& A, Polynomial& B);			     //多项式减法

	//析构函数
	~Polynomial()
	{
		delete this->m_head;
	}
	ListNode* m_head;  //头指针
};





void Polynomial::CreatPolyn(int& size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "请输入第" << i+1 << "个系数和指数" << endl;
		ListNode* newNode = CreatNode();
		cin >> newNode->_coef >> newNode->_exp;
		if (newNode->_coef != 0)
		{
			if (this->m_head->_next==nullptr)
			{
				this->m_head->_next = newNode;
			}
			else
			{
				ListNode* prev = this->m_head;
				ListNode* cur = prev->_next;
				while (cur!=nullptr && cur->_exp > newNode->_exp)
				{
					prev = cur;
					cur = cur->_next;
				}

				if (cur != nullptr&&cur->_exp == newNode->_exp)
				{
					cur->_coef += newNode->_coef;
					if (cur->_coef == 0)
					{
						prev->_next = cur->_next;
						delete cur;
					}
					delete newNode;
				}
				else
				{
					prev->_next = newNode;
					newNode->_next = cur;
				}

			}
		}
	}
}

void Polynomial::PrintPolyn()
{
	ListNode* cur = this->m_head->_next;
	if (cur == nullptr)
	{
		cout << "0";
	}
	while (cur!= nullptr)
	{
		if (cur->_exp == 0)
		{
			cout << cur->_coef;
		}
		else
		{
			cout << cur->_coef << "x^" << cur->_exp;
		}
		cur = cur->_next;
		if (cur != nullptr && cur->_coef > 0)
		{
			cout << "+";
		}
	}
	cout << endl;
}

Polynomial& Polynomial::AddPolyn(Polynomial& A,Polynomial& B)
{
	
	ListNode* pA = A.m_head->_next;    //记录多项式 A 开始的有效位置
	ListNode* pB = B.m_head->_next;	   //记录多项式 B 开始的有效位置
	ListNode* tail =this->m_head;      //记录我们的结果的尾部

	/*思路：pA或pB当有一个为空时，我们就跳出循环体*/
	while (pA!=nullptr&&pB!=nullptr)   
	{
		//1.首先我们先创立一个结点，该结点是用来存储对应的pA+pB位置的值
		ListNode* newNode = CreatNode();

		//2.分三种情况
		/*①当pA所指的位置的指数与pB所指的位置的指数相等时，才可以进行系数的加减
		此时有可能会出现相加之后系数为 0 的情况，此时我们的结果的多项式中就不需要链接上新创建的结点 newnode,所以我们这里使用
		continue 关键字 来跳过下面的循环体的内容，使其不让它链接
		②如果pA所指的位置的指数大与pB所指的位置的指数时，我们直接将pA所指位置的值赋给newnode，并用尾指针将新创建的newnode链接起来
		，并让 tail 重新指向新的尾部
		③同理，如果pB所指的位置的指数大与pA所指的位置的指数时，我们直接将pA所指位置的值赋给newnode，并用尾指针将新创建的newnode链接起来
		，并让 tail 重新指向新的尾部*/
		if (pA->_exp == pB->_exp)
		{
			newNode->_coef = pA->_coef + pB->_coef;
			if (newNode->_coef == 0)     //相加之后，指数为0的情况，不需要链接上新的结点，故使用continue 跳过后面的循环体内容
			{
				delete newNode;
				pA = pA->_next;
				pB = pB->_next;
				continue;
			}
			else   //相加之后，指数不为0的情况，我们需要链接上新的结点，和tail要重新指向新的尾部
			{
				newNode->_exp = pA->_exp;
				pA = pA->_next;
				pB = pB->_next;
			}

		}
		else if (pA->_exp > pB->_exp)   //pA所指的位置的指数大与pB所指的位置的指数
		{
			newNode->_coef = pA->_coef;
			newNode->_exp = pA->_exp;
			pA = pA->_next;

		}
		else    //pB所指的位置的指数大与pA所指的位置的指数
		{
			newNode->_coef = pB->_coef;
			newNode->_exp = pB->_exp;
			pB = pB->_next;
		}

		//链接上新创建的结点，并将tail指向新的尾部
		tail->_next = newNode;
		tail=tail->_next;
	}

	//3.最后我们出了循环的条件是，其中一个为 nullptr ，一个不为空
	//此时我们需要把没有空的链表的值，赋值给新创立的结点，并让tail->next链接上新创建的结点
	//最后更新尾指针
	while (pA != nullptr)
	{
		ListNode* newNode = CreatNode();
		newNode->_coef = pA->_coef;
		newNode->_exp = pA->_exp;
		tail->_next = newNode;
		tail = tail->_next;
		pA = pA->_next;
	}

	while (pB != nullptr)
	{
		ListNode* newNode = CreatNode();
		newNode->_coef = -pB->_coef;
		newNode->_exp = pB->_exp;
		tail->_next = newNode;
		tail = tail->_next;
		pB = pB->_next;
	}
	return *this;
}

Polynomial& Polynomial::subPolyn(Polynomial& A, Polynomial& B)
{
	ListNode* pA = A.m_head->_next;
	ListNode* pB = B.m_head->_next;
	ListNode* tail = this->m_head;
	while (pA != nullptr && pB != nullptr)
	{
		ListNode* newNode = CreatNode();
		if (pA->_exp == pB->_exp)
		{
			newNode->_coef = pA->_coef - pB->_coef;
			if (newNode->_coef == 0)
			{
				delete newNode;
				pA = pA->_next;
				pB = pB->_next;
				continue;
			}
			else
			{
				newNode->_exp = pA->_exp;
				pA = pA->_next;
				pB = pB->_next;
			}
		}
		else if (pA->_exp > pB->_exp)
		{
			newNode->_coef = pA->_coef;
			newNode->_exp = pA->_exp;
			pA = pA->_next;
		}
		else
		{
			newNode->_coef = -pB->_coef;
			newNode->_exp = pB->_exp;
			pB = pB->_next;
		}
		tail->_next = newNode;
		tail = tail->_next;
	}

	while (pA != nullptr)
	{
		ListNode* newNode = CreatNode();
		newNode->_coef = pA->_coef;
		newNode->_exp = pA->_exp;
		tail->_next = newNode;
		tail = tail->_next;
		pA = pA->_next;
	}

	while (pB != nullptr)
	{
		ListNode* newNode = CreatNode();
		newNode->_coef = pB->_coef;
		newNode->_exp = pB->_exp;
		tail->_next = newNode;
		tail = tail->_next;
		pB=pB->_next;
	}
	return *this;
}

//菜单
void menu()
{
	cout << "1.多项式加运算请输入" << endl;
	cout << "2.多项式减运算请输入" << endl;
	cout << "0.退出程序请输入" << endl;
}

int main()
{
	bool flag = true;
	while (flag)
	{
		Polynomial A;
		cout << "请输入第一个多项式的项数" << endl;
		int size1;
		cin >> size1;
		A.CreatPolyn(size1);

		Polynomial B;
		cout << "请输入第二个多项式的项数" << endl;
		int size2;
		cin >> size2;
		B.CreatPolyn(size2);

		Polynomial C;		//存储计算后的多项式的结果
ff:
		menu();
		cout << "请选择你要进行的操作" << endl;
		int select;
		cin >> select;
		switch (select)
		{
			case 0:
				cout << "您已退出，欢迎下次使用" << endl;
				flag = false;
				break;
			case 1:   //多项式加法
				C = C.AddPolyn(A, B);
				cout << "结果为：";
				C.PrintPolyn();
				break;
			case 2:	  //多项式减法
				C = C.subPolyn(A, B);
				cout << "结果为：";
				C.PrintPolyn();
				break;
			default:
				cout << "选择操作有误，请重新选择" << endl;
				goto ff;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

