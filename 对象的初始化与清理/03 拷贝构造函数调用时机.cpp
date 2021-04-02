#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	//默认的构造函数
	Person()
	{
		cout << "Person默认的构造函数调用" << endl;
	}
	//有参构造函数
	Person(int age,string name)
	{
		cout << "Person的有参构造函数调用" << endl;
		this->m_age = age;
		this->m_name = name;
	}
	//拷贝构造函数
	Person(const Person&p)
	{
		cout<<"Person的拷贝构造函数调用"<<endl;
		this->m_age = p.m_age;
		this->m_name = p.m_name;
	}
	//析构函数
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}

	void showPerson()
	{
		cout << "姓名为：" << this->m_name << "  " << "年龄为：" << this->m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20,"张三");
	Person p2(p1);

	p2.showPerson();
}

//2.值传递的方式给函数参数传值
void doWork(Person p)
{

}

void test02()
{
	Person p;		//调用构造函数
	//局部变量p传给形参的p
	//值传递的本质会拷贝一个零时副本的出来，这就是在调用拷贝构造函数来创建一个新的东西
	doWork(p);
}


//3.值方式返回局部对象
Person doWork2()
{
	Person p1;						//调用默认构造
	cout << (int*)&p1 << endl;		
	return p1;
}

void test03()
{
	Person p = doWork2();			//相当于Person p=p"，调用了拷贝构造函数
	cout << (int*)&p << endl;
	//我们可以从打印的地址上就能看出p1的地址与p的地址不相同
}
int main()
{
	test01();
	cout << "-------------------分隔线--------------------" << endl;

	test02();
	cout << "-------------------分隔线--------------------" << endl;

	test03();
	cout << "-------------------分隔线--------------------" << endl;

	system("pause");
	return 0;
}