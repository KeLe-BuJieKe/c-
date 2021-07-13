#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1������ά����a��m�У����� a[i][j] ǰ��Ԫ�ظ���Ϊ�� B ��
	A: j*m+i		 B: i*m+j		C: i*m+j-1		D: i*m+j+1
	*/
}

void Question_2()
{
	/*
	2�� int (*s[10])(int) ��ʾ����ʲô��( D )
	A:ָ�����飬ÿ��ָ��ָ�򳤶�Ϊ1�� int ����
	B:ָ�����飬ÿ��ָ��ָ�򳤶�Ϊ10�� int ����
	C:����ָ�����飬ÿ��ָ��ָ��һ�� int func(int* param) �ĺ�����
	D:����ָ�����飬ÿ��ָ��ָ��һ�� int func(int param) �ĺ���
	*/
}

void Question_3()
{
	/*
	3�����³�����������ǣ� B ����
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

//�����㷨��
/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�
������Թ��ɣ����� true �����򷵻� false��
(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)
���ӣ�https://leetcode-cn.com/problems/ransom-note
*/

class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		int strarrSrc[26] = { 0 };      //�洢��־�еĸ����ַ����ֵĴ�������ֵ
		int strarrDest[26] = { 0 };     //������еĸ����ַ����ֵĴ�������ֵ
		for (int i = 0; i < magazine.size(); ++i)
		{

			strarrSrc[magazine[i] - 'a']++;

		}

		for (int j = 0; j < ransomNote.size(); ++j)
		{
			strarrDest[ransomNote[j] - 'a']++;
		}

		//�Ƚ�ÿһ��δ֪�ĳ��ִ���
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
5���ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
���ӣ�https://leetcode-cn.com/problems/palindrome-number/
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

