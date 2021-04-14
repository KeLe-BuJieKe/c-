#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//查找：查找指定字符串是否存在
//替换：在指定的位置替换字符串
//函数原型
/*
常用的几个
int find(const string& str,int pos=0)const;           //查找str第一次出现位置，从pos开始查找
int find(const char* s,int pos=0)const;               //查找str第一次出现位置，从pos开始查找
int rfind(const string& str,int pos=npos)const;       //查找str最后一次位置，从pos开始查找
int rfind(const char* s,int pos=npos)const;           //查找str最后一次位置，从pos开始查找
string& replace(int pos,int n,const string& str);     //替换从pos开始n个字符为字符串str

*/
//1.查找
void test01()
{
	//int find(const char* s, int pos = 0)const;               //查找str第一次出现位置，从pos开始查找
	string str1 = "周杰 王正鑫 周杰";
	int pos = str1.find("周杰", 0);
	if (pos == -1)
	{
		cout << "为找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，pos=" << pos << endl;
	}

	//rfind和find区别
	//rfind从右往左查找  find从左往右查找
	//int rfind(const char* s, int pos = npos)const;           //查找str最后一次位置，从pos开始查找
	pos = str1.rfind("周杰");
	if (pos == -1)
	{
		cout << "为找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，pos=" << pos << endl;
	}
}
//2.替换
void test02()
{
	//string& replace(int pos, int n, const string & str);     //替换从pos开始n个字符为字符串str
	string str1 = "王正鑫 周杰";
	str1.replace(0, 6, "温自豪");                      //从0号位置起6个字符替换为"温自豪"
	cout << "str1=" << str1 << endl;
}
int main()
{
	test02();
	test01();
	system("pause");
	return 0;
}