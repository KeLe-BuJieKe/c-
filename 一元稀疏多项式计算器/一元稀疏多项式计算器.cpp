#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct ListNode
{
	float _coef;		//ϵ��
	float _exp;		//ָ��
	ListNode* _next;
};


//����һ���µĽ��
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
	//���캯����ʼ������
	Polynomial()
	{
		this->m_head = new ListNode;
		this->m_head->_coef = 0;
		this->m_head->_exp = 0;
		this->m_head->_next = nullptr;
	}
	//�������캯��
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

	void CreatPolyn(int& size);  //��������ʽ
	void PrintPolyn();			//��ӡ����ʽ
	Polynomial& AddPolyn(Polynomial& A,Polynomial& B);				 //����ʽ�ӷ�
	Polynomial& subPolyn(Polynomial& A, Polynomial& B);			     //����ʽ����

	//��������
	~Polynomial()
	{
		delete this->m_head;
	}
	ListNode* m_head;  //ͷָ��
};





void Polynomial::CreatPolyn(int& size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "�������" << i+1 << "��ϵ����ָ��" << endl;
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
	
	ListNode* pA = A.m_head->_next;    //��¼����ʽ A ��ʼ����Чλ��
	ListNode* pB = B.m_head->_next;	   //��¼����ʽ B ��ʼ����Чλ��
	ListNode* tail =this->m_head;      //��¼���ǵĽ����β��

	/*˼·��pA��pB����һ��Ϊ��ʱ�����Ǿ�����ѭ����*/
	while (pA!=nullptr&&pB!=nullptr)   
	{
		//1.���������ȴ���һ����㣬�ý���������洢��Ӧ��pA+pBλ�õ�ֵ
		ListNode* newNode = CreatNode();

		//2.���������
		/*�ٵ�pA��ָ��λ�õ�ָ����pB��ָ��λ�õ�ָ�����ʱ���ſ��Խ���ϵ���ļӼ�
		��ʱ�п��ܻ�������֮��ϵ��Ϊ 0 ���������ʱ���ǵĽ���Ķ���ʽ�оͲ���Ҫ�������´����Ľ�� newnode,������������ʹ��
		continue �ؼ��� �����������ѭ��������ݣ�ʹ�䲻��������
		�����pA��ָ��λ�õ�ָ������pB��ָ��λ�õ�ָ��ʱ������ֱ�ӽ�pA��ָλ�õ�ֵ����newnode������βָ�뽫�´�����newnode��������
		������ tail ����ָ���µ�β��
		��ͬ�����pB��ָ��λ�õ�ָ������pA��ָ��λ�õ�ָ��ʱ������ֱ�ӽ�pA��ָλ�õ�ֵ����newnode������βָ�뽫�´�����newnode��������
		������ tail ����ָ���µ�β��*/
		if (pA->_exp == pB->_exp)
		{
			newNode->_coef = pA->_coef + pB->_coef;
			if (newNode->_coef == 0)     //���֮��ָ��Ϊ0�����������Ҫ�������µĽ�㣬��ʹ��continue ���������ѭ��������
			{
				delete newNode;
				pA = pA->_next;
				pB = pB->_next;
				continue;
			}
			else   //���֮��ָ����Ϊ0�������������Ҫ�������µĽ�㣬��tailҪ����ָ���µ�β��
			{
				newNode->_exp = pA->_exp;
				pA = pA->_next;
				pB = pB->_next;
			}

		}
		else if (pA->_exp > pB->_exp)   //pA��ָ��λ�õ�ָ������pB��ָ��λ�õ�ָ��
		{
			newNode->_coef = pA->_coef;
			newNode->_exp = pA->_exp;
			pA = pA->_next;

		}
		else    //pB��ָ��λ�õ�ָ������pA��ָ��λ�õ�ָ��
		{
			newNode->_coef = pB->_coef;
			newNode->_exp = pB->_exp;
			pB = pB->_next;
		}

		//�������´����Ľ�㣬����tailָ���µ�β��
		tail->_next = newNode;
		tail=tail->_next;
	}

	//3.������ǳ���ѭ���������ǣ�����һ��Ϊ nullptr ��һ����Ϊ��
	//��ʱ������Ҫ��û�пյ������ֵ����ֵ���´����Ľ�㣬����tail->next�������´����Ľ��
	//������βָ��
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

//�˵�
void menu()
{
	cout << "1.����ʽ������������" << endl;
	cout << "2.����ʽ������������" << endl;
	cout << "0.�˳�����������" << endl;
}

int main()
{
	bool flag = true;
	while (flag)
	{
		Polynomial A;
		cout << "�������һ������ʽ������" << endl;
		int size1;
		cin >> size1;
		A.CreatPolyn(size1);

		Polynomial B;
		cout << "������ڶ�������ʽ������" << endl;
		int size2;
		cin >> size2;
		B.CreatPolyn(size2);

		Polynomial C;		//�洢�����Ķ���ʽ�Ľ��
ff:
		menu();
		cout << "��ѡ����Ҫ���еĲ���" << endl;
		int select;
		cin >> select;
		switch (select)
		{
			case 0:
				cout << "�����˳�����ӭ�´�ʹ��" << endl;
				flag = false;
				break;
			case 1:   //����ʽ�ӷ�
				C = C.AddPolyn(A, B);
				cout << "���Ϊ��";
				C.PrintPolyn();
				break;
			case 2:	  //����ʽ����
				C = C.subPolyn(A, B);
				cout << "���Ϊ��";
				C.PrintPolyn();
				break;
			default:
				cout << "ѡ���������������ѡ��" << endl;
				goto ff;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

