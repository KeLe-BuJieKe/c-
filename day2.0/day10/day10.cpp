#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、以下程序的输出结果是 （ B ）
	int a, b;
	void fun()
	{
		a = 100;
		b = 200;
	} 
	int main()
	{
		int a = 5, b = 7;
		fun();
		printf("%d%d", a, b);
		return 0;
	}
	A: 100200		B: 57		 C: 200100		D: 75
	*/
}

void Question_2()
{
	/*
	2、以下程序的输出是（ D ）
	struct HAR { int x,y;struct HAR *p;} h[2];
	void main()
	{
		h[0].x=1;h[0].y=2;
		h[1].x=3;h[1].y=4;
		h[0].p=&h[1];h[1].p=h;
		printf("%d,%d \n",(h[0].p)->x,(h[1].p)->y);
	}
	A: 1,2		B: 2,3		C: 1,4		D: 3,2
	*/
}

void Question_3()
{
	/*
	3、十进制数268转换成十六进制数是（ B ）。
	A: 10B		 B: 10C		 C: 10D			D: 10E
	*/
}

//二、算法题
/*
4、字符串转换整数 (atoi)
链接：
*/
class Solution
{
public:
    int myAtoi(string s)
    {
        int index = 0;    //下标
        //1.丢弃无用的前导空格
        while (index < s.size() && s[index] == ' ')
        {
            index++;
        }
        //2.判断其是否出现全是空格的情况，防止越界
        if (index == s.size())
        {
            return 0;
        }

        //3.检查下一个字符是正号还是负号
        int sign = 1;
        if (s[index] == '-')
        {
            index++;
            sign = -1;
        }
        else if (s[index] == '+')
        {
            index++;
            sign = 1;
        }
        int result = 0;
        while (index < s.size())
        {
            //4.检查是不是字符
            //如果是字符就得判断该字符是否可能出现溢出的情况，由于我们是在32位系统下，不能使用long long这种类型的变量
            //所以我们就反向判断，那么就把该数和 INT_MAX（INT_MIN） 除以 10 进行比较。
            //当result等于INT_MAX/10时，这时如果最后一位的数字大于 7 也就是 INT_MAX % 10 时，这说明该数字溢出了
            //同理负数情况相同
            if (s[index] >= '0' && s[index] <= '9')
            {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[index] - '0') > INT_MAX % 10))
                {
                    return INT_MAX;
                }
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && (s[index] - '0') > (INT_MAX % 10) + 1))
                {
                    return INT_MIN;
                }
                result = result * 10 + sign * (s[index] - '0');
            }
            else
            {
                break;
            }
            index++;
        }
        return result;
    }
};

/*
5、给定一个按照升序排列的整数数组 nums ，和一个目标值 target 。找出给定目标值在数组中的开始位置和结束
位置。你的算法时间复杂度必须是 O(log n) 级别。如果数组中不存在目标值，返回 [-1, -1] .
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
#include<vector>
//时间复杂度为：O(2*logn)=O(logn)
class Solution
{
public:
    int search(vector<int>& nums, int target, bool sign = false)
    {
        int left = 0;
        int right = nums.size() - 1;
        //2.这里我们使用二分查找target值
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                //sign==false找的是开始位置，sign==true找的结束位置
                if (sign == false)
                {
                    //此时相等时，这个位置并不一定就是我们要找的开始边界
                    //开始边界有两种情况：
                    //①此时mid==0，就是最左边的位置，此时mid这个位置就是我们的开始边界
                    //②mid-1就是mid左边这个位置等不等与target，如果不相等，则证明该位置是开始边界
                    if (mid == 0 || nums[mid - 1] != target)
                    {
                        return mid;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    //同理，这里我们找结束边界位置，此时也有两种情况
                    //①此时mid==nums.size()-1，就是最左边的位置，此时mid这个位置就是我们的开始边界
                    //②mid+1就是mid左边这个位置等不等与target，如果不相等，则证明该位置是开始边界
                    if (mid == nums.size() - 1 || nums[mid + 1] != target)
                    {
                        return mid;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
        }
        //3.如果没找到返回-1
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        //创建一个大小为2的数组，第一个位置存放开始位置，第二个位置存放结束位置
        vector<int>ret(2);
        ret[0] = search(nums, target);
        ret[1] = search(nums, target, true);
        return ret;
    }
};