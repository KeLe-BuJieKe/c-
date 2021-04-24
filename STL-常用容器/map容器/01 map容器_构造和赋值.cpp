#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;
/*
map中所有元素都是pair
pair中第一个元素为key(键值)，起到索引作业，第二个元素为value（实值）
所有元素都会根据元素的键值自动排序

本质：
map/multimap属于关联式容器，底层结构是用二叉树实现

优点：
可以根据key值快速找到value

map和multimap区别：
map不允许容器中有重复key值元素
multimap允许容器中重复key值元素
*/

//map容器  构造和赋值
void printMap(const map<int,int>m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first <<"\t"<< "   value=" << it->second << endl;
	}
	cout << "---------------------------" << endl;
}

void test01()
{
	//创建map容器
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(0, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(-1, 40));

	printMap(m);

	//拷贝构造
	map<int, int>m2(m);
	printMap(m2);


	map<int, int>m3 = m2;
	printMap(m2);

}

//总结：map中所有元素都是成对出现的，插入数据时候要使用对组
int main()
{
	test01();
	system("pause");
	return 0;
}