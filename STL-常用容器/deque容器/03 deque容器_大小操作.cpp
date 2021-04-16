#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
/*
函数原型：
resize(int num);		//重新指定容器的长度为num,若容器变长，则以默认值(0)填充新位置
						//如果容器变短 ，则末尾超出容器长度的元素被删除。
resize(int num, elem);	//重新指定容器的长度num，若容器边长，则以elem值填充新位置
						//如果容器变短，则末尾超出容量长度的元素被删除
*/
void  printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; 容器中的数据不可以修改了
		cout << *it << "  ";
	}
	cout << endl;
}

//deque容器大小操作
void test()
{

	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	if (d1.empty())		//如果为空，返回true；相反，返回false
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为: " << d1.size() << endl;
		//deque容器没有容量概念
	}

	//重新指定大小
	//d1.resize(15);				//如果重新指定的比原来的长了，默认用0填充新的位置
	d1.resize(15, 100);				//利用重载版本，可以指定默认填充值，参数2
	printdeque(d1);
	cout << "d1的大小为: " << d1.size() << endl;


	d1.resize(5);					//如果重新指定的比原来短了，超出部分会删除掉
	printdeque(d1);
	cout << "d1的大小为: " << d1.size() << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}