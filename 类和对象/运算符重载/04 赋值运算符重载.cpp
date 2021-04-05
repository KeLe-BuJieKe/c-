#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Person
{
	friend void test();
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person& operator=(Person& p)
	{
		//���������ṩǳ����
		//m_Age=p.m_Age;

		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//���
		m_Age = new int(*p.m_Age);
		//���ض�����
		return *this;
	}
private:
	//�����ָ��
	int* m_Age;
};
void test()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1;           //���ȸ�ֵ����
	cout << "p1������Ϊ�� " << *p1.m_Age << endl;
	cout << "p2������Ϊ�� " << *p2.m_Age << endl;
	cout << "p3������Ϊ�� " << *p3.m_Age << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}