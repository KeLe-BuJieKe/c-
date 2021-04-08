#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

void test()
{
	//1.先写头文件
	//#include<fstream>

	//2.创建流对象
	ofstream ofs;

	//3.打开文件
	ofs.open("test.txt", ios::out);

	//4.写数据
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：19" << endl;
	//5.关闭文件
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}