#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��̬��Ա����
//���Զ�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person
{
public:
	//��̬��Ա����
	static void func1()
	{
		m_A = 100;		//��̬��Ա�������Է���  ��̬��Ա����
		//m_B = 200;	//���󣬾�̬��Ա���� �����Է��� �Ǿ�̬��Ա�������޷����ֵ��� ���Ǹ������m_B����
		cout << "static void func1�ĵ���" << endl;
	}

private:
	static int m_A;		//��̬��Ա����
	int m_B;			//�Ǿ�̬��Ա����
	//��̬��Ա����Ҳ���з���Ȩ�޵�	
	static void func2()
	{
		cout << "static void func2�ĵ���" << endl;

	}
};
int Person::m_A=0;


//�����ַ��ʷ�ʽ
void test()
{
	//1.ͨ���������
	Person p;
	p.func1();

	//2.ͨ����������
	Person::func1();

	//��������ʲ���˽�о�̬��Ա����
	//Person::func2();	�����
}
int main()
{
	test();
	system("pause");
	return 0;
}