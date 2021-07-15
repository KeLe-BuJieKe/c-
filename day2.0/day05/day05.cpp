#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、下列语句： int *p, a = 10; p = &a. 均表示地址的是（ D ）
	A: a , p , &a
	B: &*a , &a , *p
	C: *&p , *p , &a
	D: &a , p , &*p
	*/
}

void Question_2()
{
	/*
	2、 func(1) = ? ( D )
	int func(int a)
	{
		int b;
		switch (a)
		{
			case 1: b = 30;
			case 2: b = 20;
			case 3: b = 16;
			default: b = 0;
		} 
		return b;
	}
	A: 30 B: 20 C: 16 D: 0
	*/
}

void Question_3()
{
	/*
	3、下面哪一个表达式不能访问二维数组 b 的第 i 行第 j 列元素？ ( C )
		A: b[i][j]
		B: *(b[i]+j)
		C: *(*b+i)+j
		D: (*(b+i))[j]
	
	*/
}

//二、算法题
/*
4、给定一个整数数组，判断是否存在重复元素。如果任何值在数组中出现至少两次，函数返回 true。如果数组中每
个元素都不相同，则返回 false。
链接：https://leetcode-cn.com/problems/contains-duplicate/
*/
#include<vector>
#include<algorithm>
class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}
		return false;
	}
};

/*
5、你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入1次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
*/
class Solution
{
public:
	bool isLongPressedName(string name, string typed)
	{
		//思路：就是两个字符串进行比较，如果相同则它们的下标一起向后++，不相同时，就要考虑此时typed中的是不是该字符输入了两次
		//如果typed[j] == typed[j - 1]不成立，则表明typed中的不是对应的朋友名字
		for (int i = 0, j = 0;j < typed.size();)
		{
			if (i < name.size() && name[i] == typed[j])
			{
				i++;
				j++;
			}
			else if (j > 0 && typed[j] == typed[j - 1])
			{
				j++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
