#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		//½µÐò
		return v1 > v2;
	}
};
void printMap(const map<int, int, MyCompare>&m) 
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << "\t" << "   value=" << it->second << endl;
	}
	cout << endl;
}
//mapÈÝÆ÷  ÅÅÐò
void test()
{
	map<int, int, MyCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	printMap(m);	
}
int main()
{
	test();
	system("pause");
	return 0;
}