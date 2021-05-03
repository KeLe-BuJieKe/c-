#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<numeric>
using  namespace std;

/*
函数原型：
accumulate(iterator beg,iterator end,value);
计算容器元素累计总和
beg 开始迭代器
end 结束迭代器
value 起始值
*/
//常见算术生成算法
void test()
{
	vector<int>v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//第三个参数为起始累加值
	int total=accumulate(v.begin(), v.end(), 0);
	cout << "total=" << total << endl;
}
//总结：accumulate使用时头文件注意是numeric
int main()
{
	test();
	system("pause");
	return 0;
}