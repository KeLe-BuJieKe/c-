#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���õı���
//���ʣ����õı�����C++�ڲ�ʵ����һ��ָ�볣��

//�����β�ref��һ�����ã�ת��Ϊint*const ref=&a;
void func(int& ref)
{
	ref = 100;	//ref��һ�����ã���ת��Ϊ*ref=100��
}

int main()
{
	int a = 10;

	int& ref = a;
	//��ʱ��仰���Զ�ת���� int*const ret=&a;
	//ָ�볣����ָ��ָ���ָ�򲻿��Ըı䣬�����е�ֵ���Ըı䣬������Ҳ�Ϳ��Է���Ϊʲô���ò����Ը�����
	ref = 20;	//�ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref=20��

	cout << "a=" << a << endl;
	cout << "ref=" << ref << endl;


	func(a);
	cout << "func()��a=" << a << endl;
	cout << "func()��ref=" << ref << endl;
	system("pause");
	return 0;
}