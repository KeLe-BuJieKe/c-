#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型：
set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
求两个集合的并集
两个集合必须是有序序列
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

//常用集合算法 set_union
void test01()
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
	//最特殊的情况  两个容器没有交集，并集就是两个容器size相加
	vTarget.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}

//总结：
//求并集的两个容器集合必须是有序序列
//目标容器开辟空间需要两个容器相加
//set_union返回值是并集中最后一个元素的位置
int main()
{
	test01();
	system("pause");
	return 0;
}