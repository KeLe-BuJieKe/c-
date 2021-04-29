#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//函数原型：
//bool binary_search(iterator beg,iterator end,value);
//查找指定的元素，查找 返回true 否则false
//注意：在无序序列中不可用
//beg 开始迭代器
//end 结束迭代器
//value 查找的元素

//常用查找算法 binary_search
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中是否有 9这个元素
	//注意：容器必须是有序的序列
	//如果是无序序列，结果未知

	bool result=binary_search(v.begin(), v.end(), 9);
	if (result)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}