#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
/*
函数原型：
deque<T>deq T;			//默认构造形式
deque(degin,end);		//构造函数将[begin,end)区间中的元素拷贝给本身
deque(n,elem);			//构造函数将n个elem拷贝给本身
deque(const deque &deq);//拷贝构造函数
*/


void  printdeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; 容器中的数据不可以修改了
		cout << *it << "  ";
	}
	cout << endl;
}

void test()
{
	//deque<T>deq T;			//默认构造形式
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);


	//deque(degin,end);		//构造函数将[begin,end)区间中的元素拷贝给本身
	deque<int>d2(d1.begin(), d1.end());
	printdeque(d2);


	//deque(n,elem);			//构造函数将n个elem拷贝给本身
	deque<int>d3(10, 100);
	printdeque(d3);
	

	//deque(const deque &deq);//拷贝构造函数
	deque<int>d4(d3);
	printdeque(d4);

}
int main()
{
	test();
	system("pause");
	return 0;
}