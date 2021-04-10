#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//函数模板注意事项
template<class T>   //typename 可以替换成class
void mySwap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

//1.自动类型推导，必须推导出一致的数据类型   T   才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b);		//正确
	//mySwap(a, c);		//错误！ 推导不出一致的数据类型T
	cout << "a=" << a << "   " << "b=" << b << endl;

}


//2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
	cout << "func 的调用" << endl;
}
void test02()
{
	//func();	//错误，必须使用显示指定类型
	func<void>();		//必须确定出一个指定类型T，随便一个都可以
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}