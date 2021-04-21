#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using  namespace std;

//list������ת������
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//��ת
void test01()
{
	list<int>L1;
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);

	cout << "��תǰ��" << endl;
	printList(L1);
	cout << "��ת��" << endl;
	L1.reverse();
	printList(L1);

}

bool myCompare(int v1, int v2)
{
	//����  �ͷ��ص�һ�����Ƿ�>�ڶ�����
	return v1 > v2;
}

//����
void test02()
{
	list<int>L1;
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(50);
	L1.push_back(10);
	L1.push_back(40);

	cout << "����ǰ��" << endl;
	printList(L1);
	
	//���в�֧��������ʵ��������������������ñ�׼�㷨
	//��֧��������ʵ��������������ڲ����ṩ��Ӧ��һЩ�㷨

	cout << "�����" << endl;
	L1.sort();			//Ĭ���������  ��С����  ����
	printList(L1);

	L1.sort(myCompare);	//�Ӵ�С����
	printList(L1);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}