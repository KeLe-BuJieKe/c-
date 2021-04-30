#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
	#include<vector>
	#include<algorithm>
using  namespace std;

/*函数原型：
replace_if(iterator beg,iterator end,_pred,newvalue);
按条件替换元素，满足条件的替换成指定元素
beg 开始迭代器
end 结束迭代器
_pred 谓词
newvalue 替换的新元素
*/

class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};

class Greater30
{
public:
	bool operator()(const int& val)
	{
		return val >= 30;
	}
};
//常用拷贝和替换算法 replace_if
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	//将大于等于30 替换成3000
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());

	replace_if(v.begin(), v.end(), Greater30(), 2000);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
//总结：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件
int main()
{
	test();
	system("pause");
	return 0;
}