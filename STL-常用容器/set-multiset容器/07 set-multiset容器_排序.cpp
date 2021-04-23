#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

//set��������
class MyCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};
void test01()
{
	set<int>s1;
	//����
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;


	//ָ���������Ϊ�Ӵ�С
	set<int, MyCompare>s2;
	s2.insert(40);
	s2.insert(30);
	s2.insert(20);
	s2.insert(20);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


//set�������򣬴���Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};
class PersonCompare
{
public:
	bool operator()(Person p1, Person p2) const
	{
		//����
		return p1.m_Age < p2.m_Age;

		//����
		//return p1.m_Age >p2.m_Age;
	}
};
void test02()
{
	//�Զ�����������  ����ָ���������
	set<Person, PersonCompare>s;

	Person p1("����", 25);
	Person p2("����", 15);
	Person p3("����", 30);
	Person p4("����", 20);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, PersonCompare>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������" << it->m_Name << "���䣺" << it->m_Age << endl;
	}
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}