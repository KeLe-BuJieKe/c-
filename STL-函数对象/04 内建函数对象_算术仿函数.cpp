#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
using  namespace std;

//内建函数对象  算术仿函数
/*
仿函数原型：	
templalte<class T>T plus<T>			 //加法仿函数
templalte<class T>T minus<T>		 //减法仿函数
templalte<class T>T multiplies<T>    //乘法仿函数
templalte<class T>T divides<T>		 //除法仿函数
templalte<class T>T modulus<T>		 //取模仿函数
templalte<class T>T negate<T>		 //取反仿函数

*/
//negate 一元仿函数   取反仿函数
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}
//plus	 二元仿函数	 加法仿函数
void test02()
{
	plus<int>p;
	cout << p(10, 30) << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}