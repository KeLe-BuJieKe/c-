#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����ģ��
template<class T>
void mySwap(T &x,T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

void test()
{
	int a = 10;
	int b = 20;

	//���ú���ģ�彻��
	//�����ַ�ʽʹ�ú���ģ��
	//1.�Զ������Ƶ�
	mySwap(a, b);
	cout << "a=" << a <<"   " <<"b=" << b << endl;



	//2.��ʾָ������
	mySwap<int>(a, b);
	cout << "a=" << a << "   ""b=" << b << endl;
	
}
//�ܽ᣺
/*
1.����ģ�����ùؼ���------template
2.ʹ�ú���ģ�������ַ�ʽ���Զ������Ƶ�����ʾָ������
3.ģ���Ŀ����Ϊ����ߴ���ĸ����ԣ������Ͳ�����
*/
int main()
{
	test();
	system("pause");
	return 0;
}