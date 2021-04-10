#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//实现通用：对数组进行排序的函数
//规则：从大到小排序
//算法：选择排序
//测试：char数组、int数组

//交换的模板
template<class T>
void mySwap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}


//排序算法模板
template<class T>
void mySort(T array[],int len)
{
	for (int i = 0; i < len; i++)
	{	
		int max = i;	//认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值 遍历出的数值 ，说明j下标的元素才是真正的最大值
			if (array[max] < array[j])
			{
				max = j;		//更新最大值下标
			}
		}
		if (max!=i)
		{
			mySwap(array[max], array[i]);
		}
	}
}


//打印的模板
template<class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArray[] = "badcfe";
	int len = sizeof(charArray) / sizeof(charArray[0]);
	mySort(charArray, len);
	myPrint(charArray, len);
}

void test02()
{
	//测试int数值
	int intArray[] = { 1,2,3,4,5,6,9,8,7};
	int len = sizeof(intArray) / sizeof(intArray[0]);
	mySort(intArray, len);
	myPrint(intArray, len);
}
int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}