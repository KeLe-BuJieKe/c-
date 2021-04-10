#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//普通函数与函数模板区别
/*
1.普通函数调用可以发生隐式类型转换
2.函数模板用 自动类型推导，不可以发生隐式类型转换
3.函数模板用 显示指定类型，可以发生隐式类型转换
*/

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl;
}

//函数模板
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//自动类型推导
	//cout << myAdd02(a, c) << endl;		//错误

	//显示指定类型
	cout << myAdd02<int>(a, c) << endl;
}


//总结：建议使用显式指定类型的方式，调用函数模板，因为可以自己确定通用类型T
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}