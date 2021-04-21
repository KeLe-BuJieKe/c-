#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using  namespace std;


//list����  ������  �����Զ�����������   ������


//������������������������ͬ�������߽��н���
class Person
{
	friend void printPersonList(const list<Person>& L);
	friend bool comparePerson(const Person& p1, const Person& p2);
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
private:
	string m_Name;			//����
	int m_Age;				//����
	int m_Height;			//����
};


void printPersonList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " <<it->m_Name<< "  ���䣺 "<< it->m_Age<< "  ��ߣ� "<< it->m_Height << endl;
	}
}

//�ص�����
bool comparePerson(const Person&p1,const Person&p2)
{
	//��������  ����
	if (p1.m_Age == p2.m_Age)
	{
		//��������ͬ  �������߽�������
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}


void test()
{
	list<Person>L;
	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);


	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "����ǰ:" << endl;
	printPersonList(L);

	cout << "---------------------------------------" << endl;
	L.sort(comparePerson);
	cout << "�����:" << endl;
	printPersonList(L);

}

int main()
{
	test();
	system("pause");
	return 0;
}