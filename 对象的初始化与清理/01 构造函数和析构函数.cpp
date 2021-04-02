#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//对象的初始化和清理
//1、构造函数  进行初始化操作
class Person
{
public:
	//1、构造函数
	//没有返回值  不用写void
	//函数名与类名相同
	//构造函数可以有参数，可以发生重载
	//创建对象的时候，构造函数会自动调用，而且只调用一次
	Person()
	{
		cout << "Person构造函数的调用" << endl;
	}

	//2、析构函数 进行清理的操作
	//没有返回值 不写void
	//函数名和类名相同  在名称前加~
	//析构函数不可以有参数的，不可以发生重载
	//对象在销毁前会 自动 调用析构函数，并且只会调用一次
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

//构造函数和析构函数都是必须有的实现，如果我们自己不提供的话
//编译器会提供一个空实现的构造函数和析构函数
void test01()
{
	Person p;	//局部对象在栈上的数据，在test01执行完毕后，就会释放这个对象
}
int main()
{

	test01();
	system("pause");
	return 0;
}