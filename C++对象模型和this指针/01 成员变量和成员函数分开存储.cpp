#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//成员变量  和   成员函数   是分开存储的
class Person
{
	int m_A;				//非静态成员变量   属于类的对象上
	static int m_B;			//静态成员变量	  不属于类的对象上

	void func1()			//非静态成员函数	  不属于类的对象上
	{

	}

	static void func2()		//静态成员函数	  不属于类的对象上
	{

	}
};

//静态成员变量的初始化
int Person::m_B = 10;


void test01()
{
	Person p;
	//空对象占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分对象占内存的位置
	//每个空对下也应该有一个独一无二的内存地址
	cout << "size of p=" << sizeof(p) << endl;		//1
}


void test02()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;	//4

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}