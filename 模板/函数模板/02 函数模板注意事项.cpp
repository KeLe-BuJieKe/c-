#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����ģ��ע������
template<class T>   //typename �����滻��class
void mySwap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

//1.�Զ������Ƶ��������Ƶ���һ�µ���������   T   �ſ���ʹ��
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b);		//��ȷ
	//mySwap(a, c);		//���� �Ƶ�����һ�µ���������T
	cout << "a=" << a << "   " << "b=" << b << endl;

}


//2.ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
	cout << "func �ĵ���" << endl;
}
void test02()
{
	//func();	//���󣬱���ʹ����ʾָ������
	func<void>();		//����ȷ����һ��ָ������T�����һ��������
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}