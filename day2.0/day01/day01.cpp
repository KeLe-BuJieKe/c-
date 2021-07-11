#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一：选择题
void Question_1()
{
	//1、若以下变量均是整型，且 num=sum=7 ；则执行表达式： sum=num++ ， sum++ , ++num 后 sum 的值为（B ）。
	//		A:  7			B : 8			C : 9			 D : 10
}

void Question_2()
{
	//2、 int i=10 ，j= 10 ，k= 3 ； k*=i+j k最后的值是？ (A )
	//		A: 60			B: 40			 C: 50 			D: 23

}

void Question_3()
{
	//3、 int i,j,a[2][3] ;按照数组 a 的元素在内存的排列次序,不能将数1,2,3,4,5,6存入 a 数组的是（ D ）。
	//A: for (i = 0; i < 2; i++) for (j = 0; j < 3; j++)a[i][j] = i * 3 + j + 1;
	//B: for (i = 0; i < 3; i++) for (j = 0; j < 2; j++)a[j][i] = j * 3 + i + 1;
	//C: for (i = 0; i < 6; i++) a[i / 3][i % 3] = i + 1;
	//D: for (i = 1; i <= 6; i++) a[i][i] =i;
}

//二、算法题
/*
4、实现函数 ToLowerCase() ，该函数接收一个字符串参数 str ，并将该字符串中的大写字母转换成小写字母，之
后返回新的字符串 。
链接：https://leetcode-cn.com/problems/to-lower-case/
*/
class Solution
{
public:
	string toLowerCase(string s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
		return s;
	}
};


/*
5、给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
链接：https://leetcode-cn.com/problems/rotate-array/
*/
#include<vector>
class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		int move = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + move);
		reverse(nums.begin() + move, nums.end());
	}
};