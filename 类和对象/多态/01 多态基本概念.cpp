#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��̬
/*
��̬��̬���������غ�������������ھ�̬��̬�����ú�����
��̬��̬����������麯��ʵ������ʱ��̬

��̬��̬�Ͷ�̬��̬����
1.��̬��̬�ĺ�����ַ���------����׶�ȷ��������ַ
2.��̬��̬�ĺ�����ַ���------���н׶�ȷ��������ַ
*/
//������
class Animal
{
	
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

//è��
class Cat :public Animal
{
public:
	//��д����������ֵ����  ������  �����б�  Ҫ��ȫ��ͬ�����������е�virtual����ʡ��
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

//ִ��˵���ĺ���
//��ַ���  �ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���


//��̬��̬��������
//1.�м̳й�ϵ
//2.������д������麯��


//��̬��̬ʹ��
//����� ָ��  ���� ����   ָ��    �������
void doSpeak(Animal& animal)		//Animal &animal=cat;
{
	animal.speak();
}

void test()
{
	Cat cat;
	doSpeak(cat);
}
int main()
{
	test();

	system("pause");
	return 0;
}