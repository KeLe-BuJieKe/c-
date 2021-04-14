#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
string中单个字符存取方式有两种
char& operator[](int n);           //通过[]方式取字符
char& at(int n);	               //通过at方式获取字符
*/
void test01()
{
	//通过[]方式访问单个字符
	string str1 = "Hello World";
	for (int i = 0; i < str1.size(); i++)              //str1.size()计算str1的字符串个数
	{
		cout << str1[i] << " ";
	}
	cout << endl;
	//通过at方式访问单个字符
	for (int i = 0; i < str1.size(); i++)              //str1.size()计算str1的字符串个数
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str1[0] = 'x';
	cout << "str1=" << str1 << endl;

	str1.at(1) = 'x';
	cout << "str1=" << str1 << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}