#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = new int(age);
		cout << "Person���вι��캯������" << endl;
	}
	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	Person(const Person& p)
	{
		this->m_name = p.m_name;
		//�������д�����Ǳ�����Ĭ�ϸ���Ŀ������캯������
		//this->m_age = p.m_age;		//ǳ����

		//�������
		this->m_age=new int(*p.m_age);
		cout << "Person�Ŀ������캯������" << endl;
	}
	~Person()
	{
		//�������룬�����������������ͷŲ���
		if (this->m_age != NULL)
		{
			delete this->m_age;
		}
		cout << "Person��������������" << endl;
	}

	void showPerson()
	{
		cout << "����Ϊ��" << this->m_name << "  " << "����Ϊ��" << *this->m_age << endl;
	}
private:
	string m_name;		//����
	int* m_age;			//����

};


void test()
{
	Person p1("����",18);
	p1.showPerson();

	Person p2(p1);
	p2.showPerson();
}
//�ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
int main()
{
	test();
	system("pause");
	return 0;
}