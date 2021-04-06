#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Base
{
public:
	static void func()
	{
		cout << "Base -  static void func()�ĵ���" << endl;
	}
	static void func(int a)
	{
		cout << "Base -  static void func(int a)�ĵ���" << endl;
	}
	static int m_A;
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static void func()
	{
		cout << "Son -  static void func()�ĵ���" << endl;
	}
	static int m_A;
};
int Son::m_A = 200;
//ͬ����̬��Ա����
void test01()
{
	//1.ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	cout << "Son    ��  m_A =" << s.m_A << endl;
	cout << "Base   ��  m_A =" << s.Base::m_A << endl;

	//2.ͨ����������
	cout << "ͨ����������" << endl;
	cout << "Son    ��   m_A =" << Son::m_A << endl;
	//��һ��::����ͨ��������ʽ����  �ڶ���::������ʸ�����������
	cout << "Base   ��   m_A =" << Son::Base::m_A << endl;
}
//ͬ����̬��Ա����
void test02()
{
	//1.ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2.ͨ����������
	cout << "ͨ����������" << endl;
	Son::func();
	Son::Base::func();

	//������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ��������е�ͬ����̬��Ա����
	//�������ʸ����б����ص�ͬ����̬��Ա��������Ҫ��������
	Son::Base::func(100);
}
//�ܽ᣺
/*
1.����������ֱ�ӷ��ʵ�������ͬ����Ա
2.����������������Է��ʵ�����ͬ����Ա
3.�������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա�����������������ֱ�ӷ��ʵ�������ͬ������
*/
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}