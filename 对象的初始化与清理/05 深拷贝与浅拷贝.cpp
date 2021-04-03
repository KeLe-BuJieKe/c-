#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = new int(age);
		cout << "Person的有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数来解决浅拷贝带来的问题
	Person(const Person& p)
	{
		this->m_name = p.m_name;
		//下面这行代码就是编译器默认给你的拷贝构造函数代码
		//this->m_age = p.m_age;		//浅拷贝

		//深拷贝操作
		this->m_age=new int(*p.m_age);
		cout << "Person的拷贝构造函数调用" << endl;
	}
	~Person()
	{
		//析构代码，将堆区开辟数据做释放操作
		if (this->m_age != NULL)
		{
			delete this->m_age;
		}
		cout << "Person的析构函数调用" << endl;
	}

	void showPerson()
	{
		cout << "姓名为：" << this->m_name << "  " << "年龄为：" << *this->m_age << endl;
	}
private:
	string m_name;		//姓名
	int* m_age;			//年龄

};


void test()
{
	Person p1("张三",18);
	p1.showPerson();

	Person p2(p1);
	p2.showPerson();
}
//总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
int main()
{
	test();
	system("pause");
	return 0;
}