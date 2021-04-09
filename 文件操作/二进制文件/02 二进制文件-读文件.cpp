#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>


//二进制文件  读文件
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
	ifstream ifs;

	//3.打开文件  判断文件是否打开成功
	ifs.open("Person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//4.读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_Name <<"  "<< "性别：" << p.m_Sex <<"  "<< "年龄：" << p.m_Age << endl;

	//关闭文件
	ifs.close();

}

int main()
{
	test();
	system("pause");
	return 0;
}