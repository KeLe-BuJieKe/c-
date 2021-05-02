#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型：
set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
求两个集合的交集
注意：两个集合必须是有序序列
beg1 容器1开始迭代器
end1 容器1结束迭代器
beg2 容器2开始迭代器
end2 容器2结束迭代器
dest 目标容器开始迭代器
*/
//常用集合算法 set_intersection

void myPrint(const int& val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	//0`9
		v2.push_back(i+5);	//5~14
	}

	vector<int>vTarget;	 
	//目标容器需要提前开辟空间
	//最特殊的情况 大容器包含小容器  开辟空间  取小容器的size即可
	//取小容器时的大小时，大多数情况会造成空间的浪费，for_each的第二个参数就得用它们返回回来的结束迭代器的位置
	vTarget.resize(min(v1.size(), v2.size()));
	//获取交集
	vector<int>::iterator itEnd=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
}
//总结：
//求交集的两个集合必须是有序序列
//目标容器开辟空间需要从两个容器中取小值
//set_intersection返回值是交集中最后一个元素的位置
int main()
{
	test01();
	system("pause");
	return 0;
}