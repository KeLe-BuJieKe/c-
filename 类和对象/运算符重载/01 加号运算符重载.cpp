#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Person
{
public:
	//成员函数重载+号
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

//全局函数重载+号
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
	cout << "p3.m_A的值为：" << p3.m_A << endl;
	cout << "p3.m_B的值为：" << p3.m_B << endl;
}


//总结：
/*
1.对于内置的数据类下的表达式的运算符是不可能改变的
2.不要滥用运算符重载（比如，重载加号运算符，但其内部实现的却是相减的操作）
*/
int main()
{
	test();
	return 0;
}
