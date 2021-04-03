#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//静态成员变量
class Person
{
public:
	//1.所以对象都共享同一份数据
	//2.编译截断就分配内存
	//3.类内声明，类外初始化操作
	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};

//初始化静态成员变量
int Person::m_A = 100;
int Person::m_B = 1;


void test01()
{
	Person p1;
	cout << p1.m_A << endl;		//100

	Person p2;
	p2.m_A = 200;
	cout << p1.m_A << endl;		//200
	//从中我们就可以发现所以对象都共享同一份数据这一个特点


}


void test02()
{
	//静态成员变量  不属于某个对象上，所以对象都共享同一份数据
	//因此静态成员变量有两种访问方式

	//1.通过对象进行访问
	Person p;
	cout << p.m_A << endl;

	//2.通过类名进行访问
	cout << Person::m_A << endl;

	//类外访问不到私有静态成员变量
	//cout << Person::m_B << endl;		//错误

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}