#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//������
class Person
{
public:

	//thisָ��ı���  ��ָ�볣��  ָ���ָ���ǲ������޸ĵ�
	//�ڳ�Ա���������const�����ε���ʵ��thisָ�룬��ָ��ָ���ֵ�������޸�
	void showPerson() const		//������
	{
		//this->m_A = 100;	//error��
		//this=NULL;		//error��thisָ�벻�����޸�ָ���ָ��

		this->m_B = 100;
	}

	void func()
	{
		cout << "func��������" << endl;
	}

	int m_A;
	//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ���mutable
	mutable int m_B;
};


void test01()
{
	Person p;
	p.showPerson();
}

//������
void test02()
{
	const Person p;			//�ڶ���ǰ��const����Ϊ������
	//p.m_A=10;				//error
	p.m_B = 10;				//m_B������ֵ���ڳ�������Ҳ���޸�

	//������ֻ�ܵ��ó�����
	p.showPerson();
	//p.func();				//error		������  �����Ե�����ͨ��Ա����������Ϊ��ͨ��Ա���������޸�����
}
int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}