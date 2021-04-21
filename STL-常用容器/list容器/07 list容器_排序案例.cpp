#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using  namespace std;


//list容器  排序案例  对于自定义数据类型   做排序


//按照年龄进行升序，如果年龄相同按照升高进行降序
class Person
{
	friend void printPersonList(const list<Person>& L);
	friend bool comparePerson(const Person& p1, const Person& p2);
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
private:
	string m_Name;			//姓名
	int m_Age;				//年龄
	int m_Height;			//升高
};


void printPersonList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " <<it->m_Name<< "  年龄： "<< it->m_Age<< "  身高： "<< it->m_Height << endl;
	}
}

//回调函数
bool comparePerson(const Person&p1,const Person&p2)
{
	//按照年龄  升序
	if (p1.m_Age == p2.m_Age)
	{
		//若年龄相同  则按照升高降序排序
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}


void test()
{
	list<Person>L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);


	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "排序前:" << endl;
	printPersonList(L);

	cout << "---------------------------------------" << endl;
	L.sort(comparePerson);
	cout << "排序后:" << endl;
	printPersonList(L);

}

int main()
{
	test();
	system("pause");
	return 0;
}