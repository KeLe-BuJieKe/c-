#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、在一般系统中,设 float x[8] ,假设数组x开始于内存 1000 单元,则 x[2] 的存储始于( D )
	A: 1002			B: 1004			 C: 1006			D: 1008
	*/
}

void Question_2()
{
	/*
	2、下面程序运行的结果是：（ C ）
	#define N 2
	#define M N+1
	#define NUM (M+1)*M/2

	printf("%d\n",NUM);
	A: 4		 B: 9		 C: 8		D: 6
	*/
}

void Question_3()
{
	/*
	3、函数是一种特殊的数据类型，这句话是否正确？( A )
	A： 正确 B: 错误
	*/
}

//二、算法题
/*
4、给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
链接：https://leetcode-cn.com/problems/length-of-last-word/
*/
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
            {
                length++;
            }
            //这一步是防止出现类似"hello "这种情况
            else if (s[i] == ' ' && length != 0)
            {
                break;
            }
        }
        return length;
    }
};


/*
5、给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
链接：https://leetcode-cn.com/problems/merge-sorted-array/
*/
#include<vector>
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        nums1.resize(m + n);   //把这个数组扩充到m+n
        int i = nums1.size() - 1;
        m -= 1;
        n -= 1;
        //思路是：两个有序数组，从后往前比较，然后把大的数放进扩容好的nums1内
        while (m >= 0 || n >= 0)
        {
            if (n == -1)
            {
                nums1[i] = nums1[m];
                m--;
            }
            else if (m == -1)
            {
                nums1[i] = nums2[n];
                n--;
            }
            else if (nums1[m] > nums2[n])
            {
                nums1[i] = nums1[m];
                m--;
            }
            else
            {
                nums1[i] = nums2[n];
                n--;
            }
            i--;
        }
    }

};