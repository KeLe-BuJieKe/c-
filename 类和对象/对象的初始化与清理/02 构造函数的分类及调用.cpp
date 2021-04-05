#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.构造函数的分类及其调用
//分类：
//按照参数分类：无参构造也叫做（默认构造）和有参构造
//按照类型分类：普通构造和拷贝构造函数
class Person
{
public:
	//无参构造函数
	Person()
	{
		cout << "Person无参构造函数的调用" << endl;
	}
	//有参构造函数
	Person(int age)
	{
		cout << "Person有参构造函数的调用" << endl;
		this->m_age = age;
	}

	//拷贝构造函数
	Person(const Person& p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		this->m_age = p.m_age;
		cout << "Person拷贝构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int m_age;
};

//调用
void test01()
{
	//1.括号法
	Person p1;				//默认构造函数调用
	Person p2(10);			//有参构造函数
	Person p3(p2);			//拷贝构造函数

	//注意事项1
	//调用默认构造函数时候，不要加（）
	//因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
	Person p4();
	cout << "p2的年龄为：" << p2.m_age <<endl;
	cout << "p3的年龄为：" << p3.m_age <<endl;

	cout << "-------------------分隔线--------------------" << endl;
	//2.显示法
	Person p5;
	Person p6 = Person(20);					//有参构造
	Person p7 = Person(p6);					//拷贝构造

	Person(20);		//匿名对象  特点：当前行执行结果后，系统会立即回收掉匿名对象
	cout << "aaaaaaa" << endl;

	//注意事项2													   等价于
	//不要利用拷贝构造函数  初始化匿名对象   编译器会认为  Person (p7) <==>  Person p7;对象声明
	//Person (p7);

	cout << "-------------------分隔线--------------------" << endl;
	//3.隐式转换法
	Person p8 = 10;			//相当于  写了  Person p8=Person(10);		有参构造
	Person p9 = p8;			//拷贝构造
	cout << "-------------------分隔线--------------------" << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}