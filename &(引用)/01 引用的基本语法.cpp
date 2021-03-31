#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	//引用的基本语法
	//数据类型 &别名=原名;
	int a = 10;

	//创建一个引用
	int& b = a;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}