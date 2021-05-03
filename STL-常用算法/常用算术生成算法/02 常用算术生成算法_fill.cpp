#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using  namespace std;

/*
函数原型：
fill(iterator beg,iterator end,value);
向容器中填充元素
beg 开始迭代器
end 结束迭代器
value 填充的值
*/

//常用算术生成算法 fill
void MyPrint(const int& val)
{
	cout << val << "  ";
}

void test()
{
	vector<int>v;
	v.resize(10);

	//后期重新填充
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

//总结：利用fill可以将容器区元素填充为 指定的值
int main()
{
	test();
	system("pause");
	return 0;
}