#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��Ա����  ��   ��Ա����   �Ƿֿ��洢��
class Person
{
	int m_A;				//�Ǿ�̬��Ա����   ������Ķ�����
	static int m_B;			//��̬��Ա����	  ��������Ķ�����

	void func1()			//�Ǿ�̬��Ա����	  ��������Ķ�����
	{

	}

	static void func2()		//��̬��Ա����	  ��������Ķ�����
	{

	}
};

//��̬��Ա�����ĳ�ʼ��
int Person::m_B = 10;


void test01()
{
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ��1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֶ���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p=" << sizeof(p) << endl;		//1
}


void test02()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;	//4

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}