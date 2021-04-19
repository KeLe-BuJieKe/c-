#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<queue>
#include<string>
//队列queue
class Person
{
	friend void test();
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
private:
	string m_name;
	int m_age;
};

void test()
{
	//创建队列
	queue<Person>q;
	
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙悟净", 800);


	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "队列大小为：" << q.size() << endl;
	
	//判断只要队列不为空，查看队头，查看队尾，出队
	while (!q.empty())
	{
		//查看队头
		cout << "队头元素---姓名:" << q.front().m_name << "年龄：  " << q.front().m_age << endl;

		//查看队尾
		cout << "队头元素---姓名:" << q.back().m_name << "年龄：  " << q.back().m_age << endl;

		//出队
		q.pop();
	}

	cout << "队列大小为：" << q.size() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}