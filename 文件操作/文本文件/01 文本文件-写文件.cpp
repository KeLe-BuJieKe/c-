#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<fstream>

void test()
{
	//1.��дͷ�ļ�
	//#include<fstream>

	//2.����������
	ofstream ofs;

	//3.���ļ�
	ofs.open("test.txt", ios::out);

	//4.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺19" << endl;
	//5.�ر��ļ�
	ofs.close();
}
int main()
{
	test();
	system("pause");
	return 0;
}