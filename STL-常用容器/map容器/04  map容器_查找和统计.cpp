#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

//map容器  查找和统计
void test()
{
	//查找
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "查到了元素 key= " << pos->first << "  " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}


	//统计
	//map不允许插入重复key元素，count统计而言  结果要么是0，要么是1
	//multimap的count统计可能大于1
	int num = m.count(3);
	cout<<"num = "<<num<<endl;	
}
int main()
{
	test();
	system("pause");
	return 0;
}