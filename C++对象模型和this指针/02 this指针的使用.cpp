#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ��  �����õĳ�Ա���� �����Ķ���
		this->m_Age = age;
	}

	//���ض���ı������Ҫ���ض��������
	Person& PersonAddAge(Person& p)
	{
		this->m_Age += p.m_Age;
		//thisָ��ָ��p2����*thisָ��ľ���p2�������ı���
		
		return *this;
	}
	int m_Age;
};

//1.������Ƴ�ͻ
void test01()
{
	Person p1(19);
	cout << "p1������Ϊ��" << p1.m_Age << endl;
}

//2.���ض�������*this
void test02()
{
	Person p1(10);
	Person p2(10);

	//��ʽ���˼��
	//��һ��û��ˬ����Ӽ���
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2������Ϊ��" << p2.m_Age << endl;		//40

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}