#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using  namespace std;

//���ò����㷨   find
//����ԭ�ͣ�
//find(iterator beg,iterator end,value);
//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg ��ʼ������
//end ����������
//value ���ҵ�Ԫ��
//����  ������������
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//���� ������ �Ƿ���5���Ԫ��
	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "�ҵ���" << *it << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};
//���� �Զ�����������
void test02()
{
	vector<Person>v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it != v.end())
	{
		cout << "�ҵ� ����:" << it->m_Name << "  ����:" << it->m_Age << endl;
	}
	else
	{
		cout << "û���ҵ���" << endl;
	}
}
//�ܽ᣺����find�������������ҵ�ָ����Ԫ�أ�����ֵ�ǵ�����
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}