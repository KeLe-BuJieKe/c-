#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型：
copy(iterator beg,iterator end,iterator dest);
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
beg 开始迭代器
end 结束迭代器
dest 目标起始迭代器
*/
void Myprint(const int val)
{
	cout << val << "  ";
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	//拷贝也可以直接用==号
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), Myprint);
	cout << endl;
}
//总结：利用copy算法在拷贝时，目标容器记得提前开辟空间
int main()
{
	test();
	system("pause");
	return 0;
}