#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
void test01()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//头插
	d1.push_front(5);
	d1.push_front(4);
	d1.push_front(3);

	//通过[]方式访问元素
	//3 4 5 10 20 30
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//通过at方式访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;


	//获取第一个元素
	cout << "第一个元素为: " << d1.front() << endl;

	//获取最后一个元素
	cout << "最后一个元素为: " << d1.back() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}