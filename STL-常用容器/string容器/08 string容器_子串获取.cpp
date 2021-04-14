#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//功能描述：从字符串中获取想要的子串
/*
string substr(int pos=0,int n=npos)const;      //返回由pos开始的n个字符组成的字符串
*/
//string求子串
void test01()
{
	string str1 = "abcdefg";
	string Substr = str1.substr(1, 3);
	cout << "Substr = " << Substr << endl;
}
void  test02()
{
	//从邮箱地址中 获取用户名信息
	string Email = "1941286082@qq.com";
	int pos = Email.find("@");
	string QQ = Email.substr(0, pos);
	cout << "QQ =" << QQ << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}