#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//1.ֵ����
void mySwap01(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

//2.��ַ����
void mySwap02(int*x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//3.���ô���
void mySwap03(int &x,int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
int main()
{
	int a = 10;
	int b = 20;

	mySwap01(a, b);		//ֵ���ݣ��ββ�������ʵ��
	cout << "ֵ���ݣ�a=" << a << endl;
	cout << "ֵ���ݣ�b=" << b << endl;

	mySwap02(&a, &b);	//��ַ���ݣ��βλ�����ʵ��
	cout << "��ַ���ݣ�a=" << a << endl;
	cout << "��ַ���ݣ�b=" << b << endl;

	mySwap03(a, b);		//���ô��ݣ��βλ�����ʵ��
	cout << "���ô��ݣ�a=" << a << endl;
	cout << "���ô��ݣ�b=" << b << endl;

	system("pause");
	return 0;
}