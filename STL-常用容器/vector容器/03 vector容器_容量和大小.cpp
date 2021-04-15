#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>
/*
函数原型：
resize(int num);		//重新指定容器的长度为num,若容器变长，则以默认值(0)填充新位置
						//如果容器变短 ，则末尾超出容器长度的元素被删除。
resize(int num,elem);	//重新指定容器的长度num，若容器边长，则以elem值填充新位置
						//如果容器变短，则末尾超出容量长度的元素被删除
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//vector容器的容量和大小操作
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())				//如果为空，返回true；不为空，返回false；
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为： " << v1.capacity() << endl;
		cout << "v1的大小为:  " << v1.size() << endl;
	}

	//重新指定大小
	//v1.resize(15);			//如果重新指定的比原来的长了，默认用0填充新的位置
	v1.resize(15, 100);			//利用重载版本，可以指定默认填充值，参数2
	printVector(v1);		


	v1.resize(5);				//如果重新指定的比原来短了，超出部分会删除掉
	printVector(v1);
}

/*
总结：
判断是否为空------empty
返回元素个数------size
返回容器容量------capacity
重新指定大小------resize
*/
int main()
{
	test01();
	system("pause");
	return 0;
}