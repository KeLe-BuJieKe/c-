#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//Ĭ�ϵĹ��캯��
	Person()
	{
		cout << "PersonĬ�ϵĹ��캯������" << endl;
	}
	//�вι��캯��
	Person(int age,string name)
	{
		cout << "Person���вι��캯������" << endl;
		this->m_age = age;
		this->m_name = name;
	}
	//�������캯��
	Person(const Person&p)
	{
		cout<<"Person�Ŀ������캯������"<<endl;
		this->m_age = p.m_age;
		this->m_name = p.m_name;
	}
	//��������
	~Person()
	{
		cout << "Person������������" << endl;
	}

	void showPerson()
	{
		cout << "����Ϊ��" << this->m_name << "  " << "����Ϊ��" << this->m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(20,"����");
	Person p2(p1);

	p2.showPerson();
}

//2.ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p)
{

}

void test02()
{
	Person p;		//���ù��캯��
	//�ֲ�����p�����βε�p
	//ֵ���ݵı��ʻ´��һ����ʱ�����ĳ�����������ڵ��ÿ������캯��������һ���µĶ���
	doWork(p);
}


//3.ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;						//����Ĭ�Ϲ���
	cout << (int*)&p1 << endl;		
	return p1;
}

void test03()
{
	Person p = doWork2();			//�൱��Person p=p"�������˿������캯��
	cout << (int*)&p << endl;
	//���ǿ��ԴӴ�ӡ�ĵ�ַ�Ͼ��ܿ���p1�ĵ�ַ��p�ĵ�ַ����ͬ
}
int main()
{
	test01();
	cout << "-------------------�ָ���--------------------" << endl;

	test02();
	cout << "-------------------�ָ���--------------------" << endl;

	test03();
	cout << "-------------------�ָ���--------------------" << endl;

	system("pause");
	return 0;
}