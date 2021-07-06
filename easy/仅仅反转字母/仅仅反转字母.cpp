#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

/*
������ת��ĸ
����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
ʾ�� 1��
���룺"ab-cd"
�����"dc-ba"

ʾ�� 2��
���룺"a-bC-dEf-ghIj"
�����"j-Ih-gfE-dCba"

ʾ�� 3��
���룺"Test1ng-Leet=code-Q!"
�����"Qedo1ct-eeLg=ntse-T!"
���ӣ�https://leetcode-cn.com/problems/reverse-only-letters/
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