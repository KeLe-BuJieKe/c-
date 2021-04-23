#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;


/*
函数原型：
insert(elem);			//再容器中插入元素
clear();				//清空所有元素
erase(pos);				//删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(begin,end);		//删除区间[begin,end)前闭后开区间的所有元素，返回下一个元素的迭代器
erase(elem);			//删除容器中值为elem的元素
*/
//set容器 插入和删除
void printfSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	//插入
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);
	s1.insert(100);

	printfSet(s1);

	//删除
	s1.erase(s1.begin());	//20 30 40
	printfSet(s1);

	//删除重载版本
	s1.erase(30);			//20 40
	printfSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printfSet(s1);
}
int main()
{
	test01();
	system("pause");
	return 0;
}