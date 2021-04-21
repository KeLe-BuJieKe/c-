#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using  namespace std;

//list容器  数据存取

void test()
{
	list<int>L1;

	L1.push_back(0);
	L1.push_back(10);
	L1.push_back(20);

	//L1[0]	   不可以用[]访问list容器中的元素

	//L1.at(0) 不可以用at方式访问list容器中的元素
	//原有是因为list的本质是带头结点的双向循环链表，不是用连续线性空间存储数据
	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	it++;		//支持双向
	it--;

	//it = it + 1;		//错误,因为不支持随机访问	

}
int main()
{
	test();
	system("pause");
	return 0;
}