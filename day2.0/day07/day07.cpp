#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、以下程序的输出结果是（ D ）？
	char *p="abcdefgh",*r;
	long *q;
	q=(long*)p;
	q++;
	r=(char*)q;
	printf("%s\n",r);
	A: abcd			B: bcde		 C: cdef		D: efgh
	*/
}

void Question_2()
{
	/*
	2、以下程序的输出结果是（ B ）
	char str[]="ABCD", *p=str;
	printf("%d\n", *(p+4));
	A: 68		B: 0		 C: 字符’D’的地址		D: 不确定的值
	*/
}

void Question_3()
{
	/*
	3、阅读如下C代码： (  )
	float func(float a, int b)
	{
		float m=1, n=1;
		int i;
		for (i=1; i <b; i ++)
		{
			m*= a/i;
			n+=m;
		} 
			return n;
	}
	A: a^b		B: e^a		C: ln(1+a)		 D: a^a
	*/
}

//二、算法题
/*
4、给定一个非负整数数组 A ，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素(注意：不是排序，只是偶数在前奇数在后哈！)
链接：https://leetcode-cn.com/problems/sort-array-by-parity/submissions/
*/
#include<vector>
class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& nums)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			//从左往右找奇数
			while (left < right && nums[left] % 2 == 0)
			{
				left++;
			}
			//从右往左找偶数
			while (left < right && nums[right] % 2 != 0)
			{
				right--;
			}
			swap(nums[left], nums[right]);
			left++;
			right--;
		}
		return nums;
	}
};

/*
5、给定一个整数类型的数组 nums ，请编写一个能够返回数组“中心索引”的方法。我们是这样定义数组中心索引
的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。如果数组不存在中心索引，那么我们应该返
回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个.
链接：https://leetcode-cn.com/problems/find-pivot-index/
*/
class Solution
{
public:
	int pivotIndex(vector<int>& nums)
	{
		//1.计算nums中的全部的值，然后每次比较前 i 项和和后 i项和(前项和与后项和均包含nums[i]`)。
		//如果相等就返回 i。不相等进行下次循环直到最后。
		int Rightval = 0;
		for (auto e : nums)
		{
			Rightval += e;
		}
		int Leftval = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			Leftval += nums[i];
			if (Leftval == Rightval)
			{
				return i;
			}
			Rightval -= nums[i];
		}
		return -1;
	}
};
