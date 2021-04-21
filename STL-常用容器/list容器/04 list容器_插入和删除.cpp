#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using  namespace std;

//list容器插入和删除

/*
push_back(elem);			//在容器尾部插入一个元素
pop_back();					//删除容器中最后一个元素
push_front();				//在容器头部插入一个元素
pop_front();				//从容器开头移除第一个元素
insert(pos,elem);			//在pos位置插elem元素的拷贝，返回新数据的位置
insert(pos,n,elem);			//在pos位置插入n个elem数据，无返回值
insert(pos,beg,end);		//在pos位置插入[beg,end)区间的数据，无返回值
clear();					//移除容器的所有数据
erase(beg,end);				//删除[beg,end)区间的数据，返回下一个数据的位置
erase(pos);					//删除pos位置的数据，返回下一个数据的位置
remove(elem);				//删除容器中所有与elem值匹配的元素
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test()
{
	list<int>L1;

	//尾插
	L1.push_back(0);
	L1.push_back(10);
	L1.push_back(20);


	//头插
	L1.push_front(30);
	L1.push_front(40);
	L1.push_front(50);

	//50 40 30 0 10 20
	printList(L1);


	//尾删
	L1.pop_back();

	//头删
	L1.pop_front();
	//40 30 0 10
	printList(L1);


	//insert插入
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	//40 1000 30 0 10
	printList(L1);


	//erase删除
	it= L1.begin();
	L1.erase(++it);
	//40 30 0 10
	printList(L1);


	//移除
	L1.push_back(1000);
	L1.push_back(1000);
	L1.push_back(1000);
	//40 30 0 10 1000 1000 1000 
	printList(L1);

	L1.remove(1000);		//删除容器中所有与elem值匹配的元素
	//40 30 0 10
	printList(L1);

	L1.clear();
	if (L1.empty())
	{
		cout << "链表L1为空" << endl;
	}
	else
	{
		cout << "链表L1不为空" << endl;
		cout << "链表L1的元素个数为：" << L1.size() << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}