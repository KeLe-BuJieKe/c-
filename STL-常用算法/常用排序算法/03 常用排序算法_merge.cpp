#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//功能描述：
//两个容器元素合并，并存储到另一容器中

//函数原型：
//merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//容器元素合并，并存储到另一容器中
//注意：两个容器必须是有序的
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器

//常用排序算法 merge
class MyPrint
{
public:
	void operator ()(const int& val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//目标容器
	vector<int>vTarget;
	//提前给目标容器分配空间

	//vTarget.reserve(v1.size() + v2.size());	//error


	vTarget.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint());

}
//总结;merge合并的两个容器必须的是两个相同的有序序列
int main()
{
	test01();
	system("pause");
	return 0;
}