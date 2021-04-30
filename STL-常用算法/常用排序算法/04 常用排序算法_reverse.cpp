#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*函数原型：
reverse(iterator beg,iterator end);
反转指定范围的元素
beg 开始迭代器
end 结束迭代器
*/

//常用排序算法 reverse
class MyPrint
{
public:
	void operator ()(const int& val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	reverse(v.begin(), v.end());
	cout << "反转后：" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

}

//模拟实现reverse
template<class T>
void MySwap(T&x, T&y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
void MyReverse(T*array, int begin, int end)
{
	while ((begin != end) && (begin!=--end))
	{
		MySwap(array[begin], array[end]);
		begin++;
	}

}
int main()
{
	test();
	//-------------测试代码-------------
	char array[5] = {'A','B','C','D','E'};
	MyReverse(array,0,5);
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] <<"  ";
	}
	system("pause");
	return 0;
}