#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//1.值传递
void mySwap01(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

//2.地址传递
void mySwap02(int*x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//3.引用传递
void mySwap03(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
int main()
{
	int a = 10;
	int b = 20;

	mySwap01(a, b);		//值传递，形参不会修饰实参
	cout << "值传递：a=" << a << endl;
	cout << "值传递：b=" << b << endl;

	mySwap02(&a, &b);	//地址传递，形参会修饰实参
	cout << "地址传递：a=" << a << endl;
	cout << "地址传递：b=" << b << endl;

	mySwap03(a, b);		//引用传递，形参会修饰实参
	cout << "引用传递：a=" << a << endl;
	cout << "引用传递：b=" << b << endl;

	system("pause");
	return 0;
}