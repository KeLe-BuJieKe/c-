#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	//���� ==��
	bool operator ==(Person& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//���� ��=��
	bool operator!=(Person& p)
	{
		if (this->m_Age != p.m_Age || this->m_Name != p.m_Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string m_Name;
	int m_Age;
};
void test01()
{
	Person p1("�ܽ�", 19);
	Person p2("�ܽ�", 19);
	if (p1 == p2)
	{
		cout << "p1��p2����ȵģ�" << endl;
	}
	else
	{
		cout << "p1��p2�ǲ���ȵģ�" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1��p2�ǲ���ȵģ�" << endl;
	}
	else
	{
		cout << "p1��p2����ȵģ�" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}