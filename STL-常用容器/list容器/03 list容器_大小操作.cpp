#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<list>

/*
函数原型：
resize(int num);		//重新指定容器的长度为num,若容器变长，则以默认值(0)填充新位置
						//如果容器变短 ，则末尾超出容器长度的元素被删除。
resize(int num, elem);	//重新指定容器的长度num，若容器边长，则以elem值填充新位置
						//如果容器变短，则末尾超出容量长度的元素被删除
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_front(30);
	L1.push_front(40);
	printList(L1);

	//判断容器是否为空
	if (L1.empty())
	{
		cout << "链表L1为空" << endl;
	}
	else
	{
		cout << "链表L1不为空" << endl;
		cout << "链表L1的元素个数为：" << L1.size() << endl;
	}


	//重新指定大小
	L1.resize(10,100);
	printList(L1);


	L1.resize(2);
	printList(L1);

}
int main()
{
	test01();
	system("pause");
	return 0;
}