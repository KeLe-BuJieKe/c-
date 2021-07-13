#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、若二维数组a有m列，则在 a[i][j] 前的元素个数为（ B ）
	A: j*m+i		 B: i*m+j		C: i*m+j-1		D: i*m+j+1
	*/
}

void Question_2()
{
	/*
	2、 int (*s[10])(int) 表示的是什么？( D )
	A:指针数组，每个指针指向长度为1的 int 数组
	B:指针数组，每个指针指向长度为10的 int 数组
	C:函数指针数组，每个指针指向一个 int func(int* param) 的函数。
	D:函数指针数组，每个指针指向一个 int func(int param) 的函数
	*/
}

void Question_3()
{
	/*
	3、以下程序的输出结果是（ B ）。
	int i=0,a=0;
	while(i<20)
	{
		for(;;)
		{
			if((i%10)==0)
			{
				break;
			}
			else 
			{
				i--;
			}
		} 
		i+=11; 
		a+=i;
	}
	printf("%d\n",a);
	A: 21		 B: 32		 C: 33		D: 11
	*/
}

//二、算法题
/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
链接：https://leetcode-cn.com/problems/ransom-note
*/

class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		int strarrSrc[26] = { 0 };      //存储杂志中的各个字符出现的次数的数值
		int strarrDest[26] = { 0 };     //赎金信中的各个字符出现的次数的数值
		for (int i = 0; i < magazine.size(); ++i)
		{

			strarrSrc[magazine[i] - 'a']++;

		}

		for (int j = 0; j < ransomNote.size(); ++j)
		{
			strarrDest[ransomNote[j] - 'a']++;
		}

		//比较每一个未知的出现次数
		for (int k = 0; k < 26; ++k)
		{
			if (strarrDest[k] > strarrSrc[k])
			{
				return false;
			}
		}
		return true;
	}
};



/*
5、判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
链接：https://leetcode-cn.com/problems/palindrome-number/
*/

class Solution
{
public:
	bool isPalindrome(int x)
	{
		long long temp = 0;
		long long val = x;

		while (x > 0)
		{
			temp = temp * 10 + x % 10;
			x /= 10;
		}
		if (temp == val)
		{
			return true;
		}
		return false;
	}
};

