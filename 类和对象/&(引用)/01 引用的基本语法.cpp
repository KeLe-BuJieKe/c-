#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	//���õĻ����﷨
	//�������� &����=ԭ��;
	int a = 10;

	//����һ������
	int& b = a;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}