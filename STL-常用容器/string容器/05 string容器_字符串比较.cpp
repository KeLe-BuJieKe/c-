#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�����������ַ���֮��ıȽ�  compare
//�ȽϷ�ʽ���ַ����Ƚ��ǰ����ַ���ASCII����жԱ�
//= ���� 0
//> ���� 1
//< ���� -1	
/*
����ԭ��
int compare(const string& s)const;        //���ַ���s�Ƚ�
int compare(const char* s)const;          //���ַ���s�Ƚ�
*/
void test01()
{
	string str1 = "abcd";
	string str2 = "abc";
	if (str1.compare(str2) == 0)
	{
		cout << "str1��str2���" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1����str2" << endl;
	}
	else
	{
		cout << "str1С��str2" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}