#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	//1.���ñ����ʼ��
	//int& b;	//��������ʹ��ǰ�����ʼ��
	int& b = a;


	//2.�����ڳ�ʼ���󣬲����Ըı�
	int c = 20;

	b = c;	//�����Ǹ�ֵ�������������Ǹ�������

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}