#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
#include<algorithm>

void  printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; 容器中的数据不可以修改了
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);

	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	//300 200 100 10 20 30 40
	cout << "排序前: " << endl;
	printdeque(d1);


	//排序  默认排序规则  从小到大  升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用 sort进行排序
	sort(d1.begin(), d1.end());
	cout << "排序后: " << endl;
	printdeque(d1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}