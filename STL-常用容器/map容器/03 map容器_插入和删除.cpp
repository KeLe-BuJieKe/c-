#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

void printMap(const map<int, int>&m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << "\t" << "   value=" << it->second << endl;
	}
	cout << endl;
}
void test()
{
	map<int, int>m;

	//��һ�ֲ���
	m.insert(pair<int, int>(1, 10));

	//�ڶ��ֲ���
	m.insert(make_pair(2, 20));

	//�����ֲ���
	m.insert(map<int, int>::value_type(3, 30));		

	//������
	//������ʹ�ô���[]��ʽ����   ��;:��������key���ʵ�value
	m[4] = 40;			

	printMap(m);


	//ɾ��
	m.erase(m.begin());
	printMap(m);

	//����keyɾ��
	m.erase(3);
	printMap(m);


	//��������ɾ��
	//���
	//m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);

}
int main()
{
	test();
	system("pause");
	return 0;
}