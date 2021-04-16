#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>

/*
函数原型：
deque&operator=(const deque&deq);		//重载等号操作符
assign(begin,end);						//将[begin,end）区间中的数据拷贝赋值给本身
assign(n,elem);							//将n个elem拷贝赋值给本身
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

//deque容器赋值操作
void test()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);


	//operator = 赋值
	deque<int>d2 = d1;
	printdeque(d2);


	//assign 赋值
	deque<int>d3;
	d3.assign(d1.begin(),d1.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);

}
int main()
{
	test();
	system("pause");
	return 0;
}