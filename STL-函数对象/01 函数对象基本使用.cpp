#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using  namespace std;

//�������󣨷º�����
/*
����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
�������󳬳���ͨ�����ĸ����������������Լ���״̬
�������������Ϊ��������
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
	MyAdd myAdd;
	cout<< myAdd(10, 10) << endl;
}

//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->m_Count =0;
	}
	void operator()(string test)
	{
		cout<<test<<endl;
		this->m_Count++;
	}
	int m_Count;		//�ڲ��Լ���״̬
};
void test02()
{
	MyPrint myprint;
	myprint("Hello world");
	myprint("Hello world");
	myprint("Hello world");
	myprint("Hello world");
	cout << "myprint���õĴ���Ϊ��" << myprint.m_Count << endl;
}


//3.�������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myprint;
	doPrint(myprint, "Hello C++");
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}