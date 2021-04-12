#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//类模板中成员函数和普通类中成员函数创建时机是有区别的：
//1.普通类中的成员函数一开始就可以创建
//2.类模板中的成员函数在调用才创建
int main()
{
	system("pause");
	return 0;
}
//总结：
//类模板中的成员函数并不是一开始就创建的，在调用时才去创建