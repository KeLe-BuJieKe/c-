#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//打印数据函数
void showValue(const int& val)
{
	//val=1000; 此时就会发生错误
	cout << "val=" << val << endl;
}

int main()
{
	//常量引用
	//它的使用场景：用来修饰形参，防止误操作
	int a = 10;

	//那么我们能不能写成下面这种情况呢？
	//int& b = 10;	//答案是不行的
	//但是在这一句的前面加上const之后就可以，代码如下
	const int& b = 10;		//引用必须引一块合法的内存空间
	//加上const为什么可以呢？这是由于编译器将代码修改为
	//int temp=10;
	//const int &ref=temp;

	//-----------------分界线-----------------------
	int c = 100;
	showValue(c);
	cout << "c=" << c << endl;
	system("pause");
	return 0;
}