#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
/*
������������string�ַ������в��루insert����ɾ���ַ���erase������
����ԭ�ͣ�
string& insert(int pos,const char*s );               //�����ַ���    pos�������λ�õ���˼
string& insert(int pos,const string& str );          //�����ַ���
string& insert(int pos,int n,char c);                //��ָ��λ�ò���n���ַ�c
string& erase(int pos,int n=npos);                   //ɾ����pos��ʼ��n���ַ�
*/
//�ַ��� �����ɾ��
//�ܽ᣺�����ɾ������ʼ�±궼�Ǵ�0��ʼ
void test01()
{
	string str1 = "���ܽ�";           //һ������ռ�����ֽ�
	//����
	str1.insert(2, "��");
	cout << "str1 =" << str1 << endl;

	//ɾ��
	//string& erase(int pos, int n = npos);                   //ɾ����pos��ʼ��n���ַ�
	str1.erase(2, 2);
	cout << "str1 =" << str1 << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}