#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//引用的本质
//本质：引用的本质在C++内部实现是一个指针常量

//发现形参ref是一个引用，转换为int*const ref=&a;
void func(int& ref)
{
	ref = 100;	//ref是一个引用，被转换为*ref=100；
}

int main()
{
	int a = 10;

	int& ref = a;
	//此时这句话被自动转换成 int*const ret=&a;
	//指针常量：指针指向的指向不可以改变，但其中的值可以改变，从这里也就可以发现为什么引用不可以更改了
	ref = 20;	//内部返现ref是引用，自动帮我们转换为：*ref=20；

	cout << "a=" << a << endl;
	cout << "ref=" << ref << endl;


	func(a);
	cout << "func()：a=" << a << endl;
	cout << "func()：ref=" << ref << endl;
	system("pause");
	return 0;
}