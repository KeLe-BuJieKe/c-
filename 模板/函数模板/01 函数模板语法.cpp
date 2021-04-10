#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//函数模板
template<class T>
void mySwap(T &x,T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

void test()
{
	int a = 10;
	int b = 20;

	//利用函数模板交换
	//有俩种方式使用函数模板
	//1.自动类型推导
	mySwap(a, b);
	cout << "a=" << a <<"   " <<"b=" << b << endl;



	//2.显示指定类型
	mySwap<int>(a, b);
	cout << "a=" << a << "   ""b=" << b << endl;
	
}
//总结：
/*
1.函数模板利用关键字------template
2.使用函数模板有两种方式：自动类型推导、显示指定类型
3.模板的目的是为了提高代码的复用性，将类型参数化
*/
int main()
{
	test();
	system("pause");
	return 0;
}