#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型：
replace(iterator beg,iterator end,oldvalue,newvalue);
将区间内旧元素  替换成  新元素
beg 开始迭代器
end 结束迭代器
oldvalue 旧元素
newvalue 新元素
*/


class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};
//常用拷贝和替换算法  replace

void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//将所有的20 替换成 2000
	replace(v.begin(), v.end(), 20, 2000);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}