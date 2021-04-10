#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//普通函数与函数模板调用规则
//1、如果函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板也可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

void  myPrint(int x, int y)
{
	cout << "调用普通函数" << endl;
}

template<class T>
void  myPrint(T x, T y)
{
	cout << "调用模板函数" << endl;
}


template<class T>
void  myPrint(T x, T y,T z)
{
	cout << "调用重载的模板函数" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//优先调用普通函数
	myPrint(a, b);

	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a, b);

	//函数模板也可以发生重载
	myPrint(a, b, 100);

	//如果函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1,c2);
}

//总结：既让提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

int main()
{
	test01();
	system("pause");
	return 0;
}