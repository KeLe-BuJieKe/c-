#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using  namespace std;

//内建函数对象 _关系仿函数
/*
仿函数原型：
template<class T> bool equal_to<T>			//等于
template<class T> bool not_equal_to<T>		//不相等
template<class T> bool greater<T>			//大于
template<class T> bool greater_equal<T>		//大于等于
template<class T> bool less<T>				//小于
template<class T> bool less_equal<T>		小于等于
*/
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};
void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//降序
	//sort(v.begin(), v.end(), MyCompare());
	//greater<int>()  内建函数对象
	//头文件  #include<functional>
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}