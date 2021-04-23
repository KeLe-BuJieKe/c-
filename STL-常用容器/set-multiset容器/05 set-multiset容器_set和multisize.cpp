#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

/*
区别：
1.set不可以插入重复数据，而multisize可以
2.set插入数据的同时会返回插入结果，表示插入是否成功
3.multisize不会检测数据，因此可以插入重复数据
*/

void test()
{
	set<int>s1;
	pair<set<int>::iterator,bool> ret=s1.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功!" << endl;
	}
	else
	{
		cout << "第一次插入失败!" << endl;
	}
	ret=s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功!" << endl;
	}
	else
	{
		cout << "第二次插入失败!" << endl;
	}


	multiset<int>ms;
	//允许插入重复值
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}