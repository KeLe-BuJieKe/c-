#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

//set容器 大小和交换
void printfSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//大小
void test01()
{
	set<int>s1;

	//插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	//打印容器
	printfSet(s1);

	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}
}

//交换
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);


	set<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(0);

	cout << "交换前：" << endl;
	printfSet(s1);
	printfSet(s2);

	cout << "交换后：" << endl;
	s1.swap(s2);
	printfSet(s1);
	printfSet(s2);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}