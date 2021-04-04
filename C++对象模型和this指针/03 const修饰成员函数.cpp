#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//常函数
class Person
{
public:

	//this指针的本质  是指针常量  指针的指向是不可以修改的
	//在成员函数后面加const，修饰的其实是this指针，让指针指向的值不可以修改
	void showPerson() const		//常函数
	{
		//this->m_A = 100;	//error，
		//this=NULL;		//error，this指针不可以修改指针的指向

		this->m_B = 100;
	}

	void func()
	{
		cout << "func函数调用" << endl;
	}

	int m_A;
	//特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
	mutable int m_B;
};


void test01()
{
	Person p;
	p.showPerson();
}

//常对象
void test02()
{
	const Person p;			//在对象前加const，变为常对象
	//p.m_A=10;				//error
	p.m_B = 10;				//m_B是特殊值，在常对象下也哭修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func();				//error		常对象  不可以调用普通成员函数，是因为普通成员函数可以修改属性
}
int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}