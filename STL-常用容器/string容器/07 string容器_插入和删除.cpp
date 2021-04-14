#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
/*
功能描述：对string字符串进行插入（insert）和删除字符（erase）操作
函数原型：
string& insert(int pos,const char*s );               //插入字符串    pos代表的是位置的意思
string& insert(int pos,const string& str );          //插入字符串
string& insert(int pos,int n,char c);                //在指定位置插入n个字符c
string& erase(int pos,int n=npos);                   //删除从pos开始的n个字符
*/
//字符串 插入和删除
//总结：插入和删除的起始下标都是从0开始
void test01()
{
	string str1 = "我周杰";           //一个中文占俩个字节
	//插入
	str1.insert(2, "叫");
	cout << "str1 =" << str1 << endl;

	//删除
	//string& erase(int pos, int n = npos);                   //删除从pos开始的n个字符
	str1.erase(2, 2);
	cout << "str1 =" << str1 << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}