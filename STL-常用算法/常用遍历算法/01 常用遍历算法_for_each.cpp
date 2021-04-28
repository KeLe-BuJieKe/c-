#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;


//常用遍历算法 for_each
//函数原型
//for_each(iterator beg,iterator end,_func);
//beg 开始迭代器
//end 结束迭代器
//_func 函数或者函数对象
void print01(int val)
{
	cout << val << " ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//遍历算法
	//print01-----普通函数
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	//如果第三个参数传入的是匿名的仿函数对象
	for_each(v.begin(), v.end(), print02());
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}