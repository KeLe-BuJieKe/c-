#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//功能描述：字符串之间的比较  compare
//比较方式：字符串比较是按照字符的ASCII码进行对比
//= 返回 0
//> 返回 1
//< 返回 -1	
/*
函数原型
int compare(const string& s)const;        //与字符串s比较
int compare(const char* s)const;          //与字符串s比较
*/
void test01()
{
	string str1 = "abcd";
	string str2 = "abc";
	if (str1.compare(str2) == 0)
	{
		cout << "str1与str2相等" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}