#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//��ͨ�����뺯��ģ����ù���
//1���������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//3.����ģ��Ҳ���Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void  myPrint(int x, int y)
{
	cout << "������ͨ����" << endl;
}

template<class T>
void  myPrint(T x, T y)
{
	cout << "����ģ�庯��" << endl;
}


template<class T>
void  myPrint(T x, T y,T z)
{
	cout << "�������ص�ģ�庯��" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//���ȵ�����ͨ����
	myPrint(a, b);

	//ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);

	//����ģ��Ҳ���Է�������
	myPrint(a, b, 100);

	//�������ģ��������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1,c2);
}

//�ܽ᣺�����ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����

int main()
{
	test01();
	system("pause");
	return 0;
}