#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//手机类
class Phone
{
public:
	Phone(string pname="  ")
	{
		this->m_pname = pname;
		cout << "Phone的有参构造函数调用" << endl;

	}
	string showPhone()
	{
		return this->m_pname;
	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
private:
	string m_pname;	//手机品牌名称
};

//人类
class Person
{
public:
	Person(string name, Phone phone)
	{
		this->m_name = name;
		this->m_Phone= phone;
		cout << "Person的有参构造函数调用" << endl;

	}
	void show()
	{
		cout << this->m_name <<"     "<<this->m_Phone.showPhone()<< endl;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
private:
	string m_name;			//姓名
	Phone m_Phone;			//手机
};

//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构的顺序与构造相反
void test()
{
	Phone name("苹果xs");
	Person p("张三", name);
	p.show();
}
int main()
{
	test();
	system("pause");
	return 0;
}