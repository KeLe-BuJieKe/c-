#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>


//二进制文件  写文件
class Person
{
public:
	char m_Name[30];		//姓名
	int m_Age;				//年龄
	char m_Sex[10];			//性别
};

void test()
{
	//1.包含头文件

	//2.创建流对象
	ofstream ofs;

	//3.打开文件
	ofs.open("Person.txt", ios::out | ios::binary);

	//4.写文件
	Person p = {"张三",18,"男"};
	ofs.write((const char*)&p, sizeof(Person));

	//5.关闭文件
	ofs.close();

}
int main()
{
	test();
	system("pause");
	return 0;
}