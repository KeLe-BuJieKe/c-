#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//静态成员函数
//所以对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person
{
public:
	//静态成员函数
	static void func1()
	{
		m_A = 100;		//静态成员函数可以访问  静态成员变量
		//m_B = 200;	//错误，静态成员函数 不可以访问 非静态成员变量，无法区分到底 是那个对象的m_B属性
		cout << "static void func1的调用" << endl;
	}

private:
	static int m_A;		//静态成员变量
	int m_B;			//非静态成员变量
	//静态成员函数也是有访问权限的	
	static void func2()
	{
		cout << "static void func2的调用" << endl;

	}
};
int Person::m_A=0;


//有两种访问方式
void test()
{
	//1.通过对象访问
	Person p;
	p.func1();

	//2.通过类名访问
	Person::func1();

	//在类外访问不到私有静态成员函数
	//Person::func2();	错误的
}
int main()
{
	test();
	system("pause");
	return 0;
}