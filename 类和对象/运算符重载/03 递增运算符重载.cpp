#define _CRT_SECURE_NO_WARNINGS 1
//重载递增运算符
#include<iostream>
using namespace std;
class MyInteger
{
	friend ostream& operator<<(ostream& cout, const MyInteger& myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符     前置++返回引用    返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		//先进行++运算符
		++m_Num;
		//再将自身做返回，以达到链式编程，一直往后追加
		return *this;
	}
	//重载后置++运算符    后置++返回值     int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后将记录结果做返回
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, const MyInteger& myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

//总结：
//前置递增返回引用，后置递增返回值
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}