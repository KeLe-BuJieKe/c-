#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

//map���� ��С�ͽ���
void printMap(const map<int, int>&m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << "\t" << "   value=" << it->second << endl;
	}
	
}


void test()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��" << endl;
		cout << "m�Ĵ�СΪ��" << m.size() << endl;
	}


	map<int, int>m1;
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(1, 20));
	m1.insert(pair<int, int>(0, 30));
	cout << "����ǰ" << endl;
	printMap(m);
	cout << "---------------------------" << endl;
	printMap(m1);
	cout << "������" << endl;
	m.swap(m1);
	printMap(m);
	cout << "---------------------------" << endl;
	printMap(m1);

}
int main()
{
	test();
	system("pause");
	return 0;
}