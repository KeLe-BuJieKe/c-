#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << "  age=" << this->m_Age << endl;
	}
private:
	NameType m_Name;
	AgeType m_Age;
};

//1.指定传入类型
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("孙悟空", 1000);
	printPerson1(p);
}

//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p)
{
	p.showPerson();
}

void test02()
{
	Person<string, int>p("猪八戒", 1000);
	printPerson2(p);
}


//3.整个类模板化
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
}
void test03()
{
	Person<string, int>p("沙悟净", 1000);
	printPerson3(p);
}

//总结:
/*
1.通过类模板创建的对象，可以有三种方式想函数中进行传参
2.使用比较广泛的是第一种：指定传入的类型
*/
int main()
{
	test01();

	test02();

	test03();
	system("pause");
	return 0;
}