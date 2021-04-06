#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Base
{
public:
	static void func()
	{
		cout << "Base -  static void func()的调用" << endl;
	}
	static void func(int a)
	{
		cout << "Base -  static void func(int a)的调用" << endl;
	}
	static int m_A;
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static void func()
	{
		cout << "Son -  static void func()的调用" << endl;
	}
	static int m_A;
};
int Son::m_A = 200;
//同名静态成员属性
void test01()
{
	//1.通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	cout << "Son    下  m_A =" << s.m_A << endl;
	cout << "Base   下  m_A =" << s.Base::m_A << endl;

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son    下   m_A =" << Son::m_A << endl;
	//第一个::代表通过类名方式访问  第二个::代表访问父类作用域下
	cout << "Base   下   m_A =" << Son::Base::m_A << endl;
}
//同名静态成员函数
void test02()
{
	//1.通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();

	//子类出现和父类同名静态成员函数，也会隐藏父类中所有的同名静态成员函数
	//如果想访问父类中被隐藏的同名静态成员函数，需要加作用域
	Son::Base::func(100);
}
//总结：
/*
1.子类对象可以直接访问到子类中同名成员
2.子类对象加作用域可以访问到父类同名成员
3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以直接访问到父类中同名函数
*/
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}