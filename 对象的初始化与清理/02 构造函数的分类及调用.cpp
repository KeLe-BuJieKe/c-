#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1.���캯���ķ��༰�����
//���ࣺ
//���ղ������ࣺ�޲ι���Ҳ������Ĭ�Ϲ��죩���вι���
//�������ͷ��ࣺ��ͨ����Ϳ������캯��
class Person
{
public:
	//�޲ι��캯��
	Person()
	{
		cout << "Person�޲ι��캯���ĵ���" << endl;
	}
	//�вι��캯��
	Person(int age)
	{
		cout << "Person�вι��캯���ĵ���" << endl;
		this->m_age = age;
	}

	//�������캯��
	Person(const Person& p)
	{
		//������������ϵ��������ԣ�������������
		this->m_age = p.m_age;
		cout << "Person�������캯���ĵ���" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}
	int m_age;
};

//����
void test01()
{
	//1.���ŷ�
	Person p1;				//Ĭ�Ϲ��캯������
	Person p2(10);			//�вι��캯��
	Person p3(p2);			//�������캯��

	//ע������1
	//����Ĭ�Ϲ��캯��ʱ�򣬲�Ҫ�ӣ���
	//��Ϊ�������д��룬����������Ϊ��һ��������������������Ϊ�ڴ�������
	Person p4();
	cout << "p2������Ϊ��" << p2.m_age <<endl;
	cout << "p3������Ϊ��" << p3.m_age <<endl;

	cout << "-------------------�ָ���--------------------" << endl;
	//2.��ʾ��
	Person p5;
	Person p6 = Person(20);					//�вι���
	Person p7 = Person(p6);					//��������

	Person(20);		//��������  �ص㣺��ǰ��ִ�н����ϵͳ���������յ���������
	cout << "aaaaaaa" << endl;

	//ע������2													   �ȼ���
	//��Ҫ���ÿ������캯��  ��ʼ����������   ����������Ϊ  Person (p7) <==>  Person p7;��������
	//Person (p7);

	cout << "-------------------�ָ���--------------------" << endl;
	//3.��ʽת����
	Person p8 = 10;			//�൱��  д��  Person p8=Person(10);		�вι���
	Person p9 = p8;			//��������
	cout << "-------------------�ָ���--------------------" << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}