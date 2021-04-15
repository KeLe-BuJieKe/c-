#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>

//vector容器互换

//1.基本使用

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "交换前：" << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i>0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	cout << "-------------------------------" << endl;
	cout << "交换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//2.实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为:  " << v.size() << endl;

	cout << "-------------------------------" << endl;
	v.resize(3);		//重新指定大小
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为:  " << v.size() << endl;
	cout << "-------------------------------" << endl;

	//巧用swap收缩内存
	//vector<int>(v)	//这里用v创建一个匿名对象   相当于调用了拷贝构造函数来创建一个新的对象
	//按照v的元素个数来创建这个匿名对象
	//.swap(v);			//容器交换  匿名对象与v进行交换
	//匿名对象当前行执行完后，系统会自动回收空间
	//此时这个匿名对象的容量为3，因为它是拿v来创建
	vector<int>(v).swap(v);
	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为:  " << v.size() << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}