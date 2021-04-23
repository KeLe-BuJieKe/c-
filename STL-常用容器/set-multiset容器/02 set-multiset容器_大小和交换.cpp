#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

//set���� ��С�ͽ���
void printfSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//��С
void test01()
{
	set<int>s1;

	//��������
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	//��ӡ����
	printfSet(s1);

	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
	}
}

//����
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);


	set<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(0);

	cout << "����ǰ��" << endl;
	printfSet(s1);
	printfSet(s2);

	cout << "������" << endl;
	s1.swap(s2);
	printfSet(s1);
	printfSet(s2);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}