#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//���ң�����ָ���ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���
//����ԭ��
/*
���õļ���
int find(const string& str,int pos=0)const;           //����str��һ�γ���λ�ã���pos��ʼ����
int find(const char* s,int pos=0)const;               //����str��һ�γ���λ�ã���pos��ʼ����
int rfind(const string& str,int pos=npos)const;       //����str���һ��λ�ã���pos��ʼ����
int rfind(const char* s,int pos=npos)const;           //����str���һ��λ�ã���pos��ʼ����
string& replace(int pos,int n,const string& str);     //�滻��pos��ʼn���ַ�Ϊ�ַ���str

*/
//1.����
void test01()
{
	//int find(const char* s, int pos = 0)const;               //����str��һ�γ���λ�ã���pos��ʼ����
	string str1 = "�ܽ� ������ �ܽ�";
	int pos = str1.find("�ܽ�", 0);
	if (pos == -1)
	{
		cout << "Ϊ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����pos=" << pos << endl;
	}

	//rfind��find����
	//rfind�����������  find�������Ҳ���
	//int rfind(const char* s, int pos = npos)const;           //����str���һ��λ�ã���pos��ʼ����
	pos = str1.rfind("�ܽ�");
	if (pos == -1)
	{
		cout << "Ϊ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����pos=" << pos << endl;
	}
}
//2.�滻
void test02()
{
	//string& replace(int pos, int n, const string & str);     //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	string str1 = "������ �ܽ�";
	str1.replace(0, 6, "���Ժ�");                      //��0��λ����6���ַ��滻Ϊ"���Ժ�"
	cout << "str1=" << str1 << endl;
}
int main()
{
	test02();
	test01();
	system("pause");
	return 0;
}