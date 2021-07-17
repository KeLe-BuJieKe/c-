#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、DOS 中扩展名为.BAK的文件称为( D )
	A: 批处理文件 B: BASIC文件 C:临时文件 D:备份文件
	*/
}

void Question_2()
{
	/*
	2、以下选项中合法的字符常量是（ C ）
	A: 'ab'			B: '\101'		C: "A"		D: PI
	*/
}

void Question_3()
{
	/*
	3、 设整型变量n的值为2，执行语句“n+=n-=n*n”后，n的值是（ A ）
	A: -4		B: 2		C: -1		D: 4
	*/
}

//二、算法题
#include<vector>
/*
4、给定一个按非递减顺序排序的整数数组 A ，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
(注意：非递减顺序即递增，并且这里你注意负数哈！）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array/
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int begin = 0;
        int end = nums.size() - 1;
        //创建一个数组，并初始化它的大小为nums.size()
        vector<int>ret(nums.size());
        for (int i = ret.size() - 1; i >= 0; --i)
        {
            //双指针，一个从头，一个在尾，
            //判断那个头、尾那个数的绝对值大，我们把大的平方逆序放入我们的目标数组ret中
            if (abs(nums[end]) - abs(nums[begin]) >= 0)
            {
                ret[i] = nums[end] * nums[end];
                end--;
            }
            else
            {
                ret[i] = nums[begin] * nums[begin];
                begin++;
            }
        }
        return ret;
    }
};

/*
5、给定一个字符串 S ，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
链接：https://leetcode-cn.com/problems/reverse-only-letters/
*/
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isalpha(s[begin]))
            {
                begin++;
            }

            while (begin < end && !isalpha(s[end]))
            {
                end--;
            }

            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};
