#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

//set/multiset属于关联式容器，底层结构是二叉树实现
//所有元素都会再插入时自动被排序
/*
set和multiset区别：
set不允许容器中有重复的元素
multiset允许容器中有重复的元素
*/
void printfSet(const set<int>&s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}



//set容器构造和赋值
void test()
{
	set<int>s1;

	//插入数据  只有 insert方式
	//
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);

	//遍历容器
	//set容器特点：所有元素插入时候自动被排序
	//set容器不允许插入重复值，虽然不给你报错，但插入不进去
	printfSet(s1);

	//拷贝构造
	set<int>s2(s1);
	printfSet(s2);


	//赋值
	set<int>s3 = s2;
	printfSet(s3);


}

int main()
{
	test();
	system("pause");
	return 0;
}