#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
	friend void test();         //ȫ�ֺ�������Ԫ
private:
	//���ó�Ա�������� ��������� p.operator<<(cout)  �򻯰汾p<<cout
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ�� cout�����
	int m_A;
	int m_B;
};
//ֻ������ȫ�ֺ�������<<�����
//ostream����ֻ����һ��
ostream& operator<<(ostream& cout, Person& p)    //���� operator<<(cout,p) ��cout<<p
{
	cout << "m_A = " << p.m_A << "   " << "m_B=" << p.m_B;
	return cout;
}
void test()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	cout << p << endl;            //��ʽ���,����һֱ����cout����������һֱ׷��
}

//�ܽ᣺������������������Ԫ����ʵ������Զ�����������
int main()
{
	test();
	system("pause");
	return 0;
}