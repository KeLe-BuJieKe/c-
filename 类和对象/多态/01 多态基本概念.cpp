#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//多态
/*
静态多态：函数重载和运算符重载属于静态多态，复用函数名
动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态区别：
1.静态多态的函数地址早绑定------编译阶段确定函数地址
2.动态多态的函数地址晚绑定------运行阶段确定函数地址
*/
//动物类
class Animal
{
	
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	//重写：函数返回值类型  函数名  参数列表  要完全相同，这里子类中的virtual可以省略
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定  在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定


//动态多态曼珠条件
//1.有继承关系
//2.子类重写父类的虚函数


//动态多态使用
//父类的 指针  或者 引用   指向    子类对象
void doSpeak(Animal& animal)		//Animal &animal=cat;
{
	animal.speak();
}

void test()
{
	Cat cat;
	doSpeak(cat);
}
int main()
{
	test();

	system("pause");
	return 0;
}