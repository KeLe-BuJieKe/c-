#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>


//�������ļ�  д�ļ�
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
	ofstream ofs;

	//3.���ļ�
	ofs.open("Person.txt", ios::out | ios::binary);

	//4.д�ļ�
	Person p = {"����",18,"��"};
	ofs.write((const char*)&p, sizeof(Person));

	//5.�ر��ļ�
	ofs.close();

}
int main()
{
	test();
	system("pause");
	return 0;
}