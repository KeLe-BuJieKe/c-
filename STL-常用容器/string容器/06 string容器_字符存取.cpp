#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
string�е����ַ���ȡ��ʽ������
char& operator[](int n);           //ͨ��[]��ʽȡ�ַ�
char& at(int n);	               //ͨ��at��ʽ��ȡ�ַ�
*/
void test01()
{
	//ͨ��[]��ʽ���ʵ����ַ�
	string str1 = "Hello World";
	for (int i = 0; i < str1.size(); i++)              //str1.size()����str1���ַ�������
	{
		cout << str1[i] << " ";
	}
	cout << endl;
	//ͨ��at��ʽ���ʵ����ַ�
	for (int i = 0; i < str1.size(); i++)              //str1.size()����str1���ַ�������
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//�޸ĵ����ַ�
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