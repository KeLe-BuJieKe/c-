#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//�ֻ���
class Phone
{
public:
	Phone(string pname="  ")
	{
		this->m_pname = pname;
		cout << "Phone���вι��캯������" << endl;

	}
	string showPhone()
	{
		return this->m_pname;
	}
	~Phone()
	{
		cout << "Phone��������������" << endl;
	}
private:
	string m_pname;	//�ֻ�Ʒ������
};

//����
class Person
{
public:
	Person(string name, Phone phone)
	{
		this->m_name = name;
		this->m_Phone= phone;
		cout << "Person���вι��캯������" << endl;

	}
	void show()
	{
		cout << this->m_name <<"     "<<this->m_Phone.showPhone()<< endl;
	}
	~Person()
	{
		cout << "Person������������" << endl;
	}
private:
	string m_name;			//����
	Phone m_Phone;			//�ֻ�
};

//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������������˳���빹���෴
void test()
{
	Phone name("ƻ��xs");
	Person p("����", name);
	p.show();
}
int main()
{
	test();
	system("pause");
	return 0;
}