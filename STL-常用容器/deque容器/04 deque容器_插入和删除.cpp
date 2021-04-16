#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>

/*
函数原型：
两端插入操作：
push_back(elem);		//在容器尾部添加一个数据
push_front(elem);		//在容器头部插入一个数据
pop_back();				//删除容器最后一个数据
pop_front();			//删除容器第一个数据

指定位置操作:
insert(pos,elem);		//在pos位置插入一个elem元素的拷贝，返回新数据的位置
insert(pos,n,elem);		//在pos位置插入n个elem数据,无返回值
insert(pos,begin,end);	//在pos位置插入[begin,end)区间的数据，无返回值
clear();				//清空容器中的所有数据
erase(begin,end);		//删除迭代器从begin到end之间的数据，返回下一个数据的位置。
erase(pos);				//删除pos位置的数据，返回下一个数据的位置
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

//deque容器插入和删除
void test01()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//头插
	d1.push_front(5);
	d1.push_front(4);
	//4 5 10 20 30 40
	printdeque(d1);

	//尾删
	d1.pop_back();
	//头删
	d1.pop_front();

	//5 10 20 30
	printdeque(d1);

}



void test02()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//头插
	d1.push_front(5);
	d1.push_front(4);

	//insert插入
	//insert(pos, elem);		//在pos位置插入一个elem元素的拷贝，返回新数据的位置
	d1.insert(d1.begin(), 3);
	//3 4 5 10 20 30 40
	printdeque(d1);

	
	//insert(pos, n, elem);		//在pos位置插入n个elem数据,无返回值
	d1.insert(d1.begin(), 2, 100);
	//100 100 3 4 5 10 20 30 40
	printdeque(d1);


	//insert(pos, begin, end);	//在pos位置插入[begin,end)区间的数据，无返回值
	deque<int>d2;
	d2.push_back(11);
	d2.push_back(22);
	d2.push_back(33);
	//100 11 22 33 100 3 4 5 10 20 30 40
	d1.insert(d1.begin()+1, d2.begin(), d2.end());
	printdeque(d1);


}

//删除
void test03()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//头插
	d1.push_front(5);
	d1.push_front(4);

	//删除
	d1.erase(d1.begin() + 1);
	//4 10 20 30 40
	printdeque(d1);


	//按照区间的方式删除
	//4  40
	d1.erase(d1.begin() + 1, d1.end()-1);
	printdeque(d1);

	//清空容器
	d1.clear();
	printdeque(d1);

}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}