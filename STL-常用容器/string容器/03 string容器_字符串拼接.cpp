#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//string�ַ���ƴ��   append
//����ԭ��
/*
string& operator+=(const char* str);                //����+=������
string& operator+=(const char c);                   //����+=������
string& operator+=(const string& str);              //����+=������
string& append(const char* s);                      //���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char*s,int n);                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string& s);                    //ͬoperator+=��const string& str��
string& append(const string &s��int pos,int n);     //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/

void test01()
{
	string str1 = "��";
	//string& operator+=(const char* str);                //����+=������
	str1 += "������Ϸ";
	cout << "str1=" << str1 << endl;

	//string& operator+=(const char c);                   //����+=������
	str1 += ':';
	cout << "str1=" << str1 << endl;

	//string& operator+=(const string & str);              //����+=������
	string str2 = "LOL��PUBG";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	//string& append(const char* s);                      //���ַ���s���ӵ���ǰ�ַ�����β
	string str3 = "I";
	str3.append(" Love ");
	cout << "str3=" << str3 << endl;

	//string& append(const char* s, int n);                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
	str3.append("Game abcdefg", 4);
	cout << "str3=" << str3 << endl;

	//string& append(const string & s);                    //ͬoperator+=��const string& str��
	str3.append(str2);
	cout << "str3=" << str3 << endl;

	//string& append(const string & s��int pos, int n);     //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
	str3.append(str2, 0, 3);         //ֻ��ȡ����LOL  ����2 ���ĸ�λ�ÿ�ʼ��ȡ������3�ǽ�ȡ�ĸ���
	cout << "str3=" << str3 << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}