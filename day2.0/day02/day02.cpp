#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、若变量a是 int 类型，并执行了语句 a=’A'+1.6 ；则正确的叙述是（ D ）。
	A: a的值是字符C
	B: a的值是浮点型
	C: 不允许字符型和浮点型相加
	D: a的值是字符’A’的ASCⅡ值加上1
	*/
}

void Question_2()
{
	/*
	2、下面代码段的运行结果（环境 linux 平台, g++ 编译器）( C )
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d", x, y);
	return 0;
	A: 10 11		B: 11 10		C: 11 11		D: 10 10
	*/
}

void Question_3()
{
	/*
	3、局部变量只对main函数起作用，而全局变量对所有函数起作用 （ B ）。
	A： 正确 B: 错误
	*/
}

//二、算法题
/*
4、给定一个数组 nums 和一个值 val ，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
链接：https://leetcode-cn.com/problems/remove-element/
*/
#include<vector>
class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int slow = 0;     //慢指针
		int fast = 0;     //快指针
		while (fast < nums.size())
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++slow;

			}
			++fast;
		}
		return slow;
	}
};


/*
5、给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将
会被按顺序插入的位置,你可以假设数组中无重复元素
链接：https://leetcode-cn.com/problems/search-insert-position/
*/
class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int i = 0;
		for (; i < nums.size(); ++i)
		{
			if (nums[i] >= target)
			{
				break;
			}
		}
		return i;
	}
};