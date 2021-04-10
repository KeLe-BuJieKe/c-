#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ģ�������
//ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ�þ��巽ʽ������ʵ��

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Person
{
	template<class T>
	friend bool myCompare(T& a, T& b);
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	string m_Name;		//����

	int m_Age;			//����
};




//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
//Ҳ������������==����ʵ���ж�
template<>bool myCompare(Person &p1, Person &p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test01()
{
	Person p1("����", 18);
	Person p2("����", 18);
	bool ret=myCompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}

//�ܽ�
/*
1.���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
2.ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��
*/
int main()
{
	test01();
	system("pause");
	return 0;
}