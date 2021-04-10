#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//模板局限性
//模板并不是万能的，有些特定数据类型，需要用具体方式作特殊实现

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Person
{
	template<class T>
	friend bool myCompare(T& a, T& b);
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	string m_Name;		//姓名

	int m_Age;			//年龄
};




//利用具体化Person的版本实现代码，具体化优先调用
//也可以利用重载==号来实现判断
template<>bool myCompare(Person &p1, Person &p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test01()
{
	Person p1("张三", 18);
	Person p2("张三", 18);
	bool ret=myCompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}

//总结
/*
1.利用具体化的模板，可以解决自定义类型的通用化
2.学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
*/
int main()
{
	test01();
	system("pause");
	return 0;
}