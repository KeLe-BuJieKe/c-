#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//二元谓词
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);

	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//使用函数对象  改变算法策略，变为排序规则从大到小
	//第三个位置要传入函数对象  MyCompare()是匿名对象
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it  << "  ";
	}
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}