#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
	friend void test();         //全局函数做友元
private:
	//利用成员函数重载 左移运算符 p.operator<<(cout)  简化版本p<<cout
	//不会利用成员函数重载<<运算符，因为无法实现 cout在左侧
	int m_A;
	int m_B;
};
//只能利用全局函数重载<<运算符
//ostream对象只能有一个
ostream& operator<<(ostream& cout, Person& p)    //本质 operator<<(cout,p) 简化cout<<p
{
	cout << "m_A = " << p.m_A << "   " << "m_B=" << p.m_B;
	return cout;
}
void test()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	cout << p << endl;            //链式编程,让它一直返回cout，才能往后一直追加
}

//总结：重载左移运算符配合友元可以实现输出自定义数据类型
int main()
{
	test();
	system("pause");
	return 0;
}