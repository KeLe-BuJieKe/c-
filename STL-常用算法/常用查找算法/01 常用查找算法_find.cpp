#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using  namespace std;

//常用查找算法   find
//函数原型：
//find(iterator beg,iterator end,value);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg 开始迭代器
//end 结束迭代器
//value 查找的元素
//查找  内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找 容器中 是否有5这个元素
	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "找到：" << *it << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};
//查找 自定义数据类型
void test02()
{
	vector<Person>v;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it != v.end())
	{
		cout << "找到 姓名:" << it->m_Name << "  年龄:" << it->m_Age << endl;
	}
	else
	{
		cout << "没有找到！" << endl;
	}
}
//总结：利用find可以在容器中找到指定的元素，返回值是迭代器
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}