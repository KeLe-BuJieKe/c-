#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
using  namespace std;

//�ڽ���������  �����º���
/*
�º���ԭ�ͣ�	
templalte<class T>T plus<T>			 //�ӷ��º���
templalte<class T>T minus<T>		 //�����º���
templalte<class T>T multiplies<T>    //�˷��º���
templalte<class T>T divides<T>		 //�����º���
templalte<class T>T modulus<T>		 //ȡģ�º���
templalte<class T>T negate<T>		 //ȡ���º���

*/
//negate һԪ�º���   ȡ���º���
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}
//plus	 ��Ԫ�º���	 �ӷ��º���
void test02()
{
	plus<int>p;
	cout << p(10, 30) << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}