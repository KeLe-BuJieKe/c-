#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>


//�������ļ�  ���ļ�
class Person
{
public:
	char m_Name[30];		//����
	int m_Age;				//����
	char m_Sex[10];			//�Ա�
};


void test()
{
	//1.����ͷ�ļ�

	//2.����������
	ifstream ifs;

	//3.���ļ�  �ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("Person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	//4.���ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.m_Name <<"  "<< "�Ա�" << p.m_Sex <<"  "<< "���䣺" << p.m_Age << endl;

	//�ر��ļ�
	ifs.close();

}

int main()
{
	test();
	system("pause");
	return 0;
}