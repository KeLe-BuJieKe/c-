#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//�������������ַ����л�ȡ��Ҫ���Ӵ�
/*
string substr(int pos=0,int n=npos)const;      //������pos��ʼ��n���ַ���ɵ��ַ���
*/
//string���Ӵ�
void test01()
{
	string str1 = "abcdefg";
	string Substr = str1.substr(1, 3);
	cout << "Substr = " << Substr << endl;
}
void  test02()
{
	//�������ַ�� ��ȡ�û�����Ϣ
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