#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//string�ĸ�ֵ����  assign
/*
//����ԭ��
string& operator=(const char*s);              //char*�����ַ���  ��ֵ����ǰ���ַ���
string& operator=(const string &s);           //���ַ���s������ǰ���ַ���
string& operator=(char c);                    //�ַ���ֵ����ǰ���ַ���
string& assign(const char*s);                 //���ַ���s������ǰ���ַ���
string& assign(const char*s,int n);           //���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);              //���ַ���s������ǰ�ַ���
string& assign(int n,char c);                 //��n���ַ�c������ǰ�ַ���
*/
void test01()
{
	//string& operator=(const char*s);              //char*�����ַ���  ��ֵ����ǰ���ַ���
	string str1;
	str1 = "Hello World";
	cout << "str1=" << str1 << endl;

	//string& operator=(const string & s);           //���ַ���s������ǰ���ַ���
	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;

	//string& operator=(char c);                    //�ַ���ֵ����ǰ���ַ���
	string str3;
	str3 = 'a';
	cout << "str3=" << str3 << endl;

	//string& assign(const char* s);                 //���ַ���s������ǰ���ַ���
	string str4;
	str4.assign("Hello C++");
	cout << "str4=" << str4 << endl;

	//string& assign(const char* s, int n);           //���ַ���s��ǰn���ַ�������ǰ���ַ���
	string str5;
	str5.assign("Hellow c++", 5);
	cout << "str5=" << str5 << endl;

	//string& assign(const string & s);              //���ַ���s������ǰ�ַ���
	string str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;

	//string& assign(int n, char c);                 //��n���ַ�c������ǰ�ַ���	
	string str7;
	str7.assign(10, 'W');
	cout << "str7=" << str7 << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}