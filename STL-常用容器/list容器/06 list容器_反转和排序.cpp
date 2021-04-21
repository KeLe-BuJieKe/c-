#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using  namespace std;

//list容器反转和排序
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//反转
void test01()
{
	list<int>L1;
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);

	cout << "反转前：" << endl;
	printList(L1);
	cout << "反转后：" << endl;
	L1.reverse();
	printList(L1);

}

bool myCompare(int v1, int v2)
{
	//降序  就返回第一个数是否>第二个数
	return v1 > v2;
}

//排序
void test02()
{
	list<int>L1;
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);

	cout << "排序前：" << endl;
	printList(L1);
	
	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应的一些算法

	cout << "排序后：" << endl;
	L1.sort();			//默认排序规则  从小到大  升序
	printList(L1);

	L1.sort(myCompare);	//从大到小排序
	printList(L1);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}