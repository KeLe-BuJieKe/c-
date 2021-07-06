#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
仅仅反转字母
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
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