#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
函数原型:
swap(container c1,container c2)
互换两个容器的元素
c1	容器1
c2	容器2
*/
class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};
void test()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;


	cout << "交换后：" << endl;
	swap(v1, v2);
		for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

}
//总结：swap交换容器时，注意交换的容器要同种类型
int main()
{
	test();
	system("pause");
	return 0;
}