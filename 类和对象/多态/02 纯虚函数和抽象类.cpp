#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���麯���ͳ�����
class Base
{
public:
	//���麯��
	//ֻҪ��һ�����麯����������Ϊ������
	//�������ص㣺
	//1.�޷�ʵ��������
	//2.�����������  ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};


class Son :public Base
{
public:
	void func()
	{
		cout << "func ��������" << endl;
	}
};
void test01()
{
	//Base b;    //�������޷�ʵ��������
	//new Base;	 //�������޷�ʵ��������


	Son s;
	s.func();
}
int main()
{
	test01();
	system("pause");
	return 0;
}