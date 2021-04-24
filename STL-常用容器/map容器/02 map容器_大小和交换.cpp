#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

//map容器 大小和交换
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
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为：" << m.size() << endl;
	}


	map<int, int>m1;
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(1, 20));
	m1.insert(pair<int, int>(0, 30));
	cout << "交换前" << endl;
	printMap(m);
	cout << "---------------------------" << endl;
	printMap(m1);
	cout << "交换后" << endl;
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