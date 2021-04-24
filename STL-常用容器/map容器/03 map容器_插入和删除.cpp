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

	//第一种插入
	m.insert(pair<int, int>(1, 10));

	//第二种插入
	m.insert(make_pair(2, 20));

	//第三种插入
	m.insert(map<int, int>::value_type(3, 30));		

	//第四种
	//不建议使用此种[]方式插入   用途:可以利用key访问到value
	m[4] = 40;			

	printMap(m);


	//删除
	m.erase(m.begin());
	printMap(m);

	//按照key删除
	m.erase(3);
	printMap(m);


	//按照区间删除
	//清空
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