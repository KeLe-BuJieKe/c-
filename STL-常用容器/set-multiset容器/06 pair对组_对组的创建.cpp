#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using  namespace std;

//pair����Ĵ���
void test()
{
	//��һ�ַ�ʽ
	pair<string, int>p1("����", 20);
	cout << "������" << p1.first << "  ���䣺" << p1.second << endl;

	//�ڶ��ӷ�ʽ
	pair<string, int>p2 = make_pair("����", 30);
	cout << "������" << p2.first << "  ���䣺" << p2.second << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}