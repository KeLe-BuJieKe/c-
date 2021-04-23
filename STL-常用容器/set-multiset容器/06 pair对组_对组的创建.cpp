#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using  namespace std;

//pair对组的创建
void test()
{
	//第一种方式
	pair<string, int>p1("张三", 20);
	cout << "姓名：" << p1.first << "  年龄：" << p1.second << endl;

	//第二钟方式
	pair<string, int>p2 = make_pair("李四", 30);
	cout << "姓名：" << p2.first << "  年龄：" << p2.second << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}