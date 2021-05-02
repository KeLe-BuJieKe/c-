#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型：
set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
求两个集合的差集
注意：两个集合必须是有序序列
beg1 容器1开始迭代器
end1 容器1结束迭代器
beg2 容器2开始迭代器
end2 容器2结束迭代器
dest 目标容器开始迭代器
*/
void myPrint(const int& val)
{
	cout << val << " ";
}


//常用集合算法  set_difference
void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	//0`9
		v2.push_back(i + 5);	//5~14
	}

	vector<int>vTarget;


	//目标容器需要提前开辟空间
	vTarget.resize(max(v1.size(), v2.size()));

	cout << "v1和v2的差集为：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

	cout << "v2和v1的差集为：" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}