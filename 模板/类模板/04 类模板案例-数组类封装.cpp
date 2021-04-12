#define _CRT_SECURE_NO_WARNINGS 1
#include"MyArray.hpp"
void test01()
{
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);

	MyArray<int>arr3(100);
	arr3 = arr1;
}
int main()
{
	test01();
	system("pause");
	return 0;
}