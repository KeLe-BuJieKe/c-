#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Person
{
public:
	//��Ա��������+��
	Person operator + (Person& p)
	{
		Person Temp;
		Temp.m_A = this->m_A + p.m_A;
		Temp.m_B = this->m_B + p.m_B;
		return Temp;
	}
	int m_A;
	int m_B;
};

//ȫ�ֺ�������+��
//Person operator + (Person &p1, Person& p2)
//{
//	Person Temp;
//	Temp.m_A = p1.m_A + p2.m_A;
//	Temp.m_B = p1.m_B + p2.m_B;
//	return Temp;
//}

void test()
{
	Person p1;
	p1.m_A = 10, p1.m_B = 10;
	Person p2;
	p2.m_A = 20, p2.m_B = 30;
	Person p3;
	p3 = p1 + p2;
	cout << "p3.m_A��ֵΪ��" << p3.m_A << endl;
	cout << "p3.m_B��ֵΪ��" << p3.m_B << endl;
}


//�ܽ᣺
/*
1.�������õ��������µı��ʽ��������ǲ����ܸı��
2.��Ҫ������������أ����磬���ؼӺ�������������ڲ�ʵ�ֵ�ȴ������Ĳ�����
*/
int main()
{
	test();
	return 0;
}
