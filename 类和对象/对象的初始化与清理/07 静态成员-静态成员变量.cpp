#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��̬��Ա����
class Person
{
public:
	//1.���Զ��󶼹���ͬһ������
	//2.����ضϾͷ����ڴ�
	//3.���������������ʼ������
	static int m_A;

	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static int m_B;
};

//��ʼ����̬��Ա����
int Person::m_A = 100;
int Person::m_B = 1;


void test01()
{
	Person p1;
	cout << p1.m_A << endl;		//100

	Person p2;
	p2.m_A = 200;
	cout << p1.m_A << endl;		//200
	//�������ǾͿ��Է������Զ��󶼹���ͬһ��������һ���ص�


}


void test02()
{
	//��̬��Ա����  ������ĳ�������ϣ����Զ��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ

	//1.ͨ��������з���
	Person p;
	cout << p.m_A << endl;

	//2.ͨ���������з���
	cout << Person::m_A << endl;

	//������ʲ���˽�о�̬��Ա����
	//cout << Person::m_B << endl;		//����

}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}