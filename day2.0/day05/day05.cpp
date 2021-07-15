#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1��������䣺 int *p, a = 10; p = &a. ����ʾ��ַ���ǣ� D ��
	A: a , p , &a
	B: &*a , &a , *p
	C: *&p , *p , &a
	D: &a , p , &*p
	*/
}

void Question_2()
{
	/*
	2�� func(1) = ? ( D )
	int func(int a)
	{
		int b;
		switch (a)
		{
			case 1: b = 30;
			case 2: b = 20;
			case 3: b = 16;
			default: b = 0;
		} 
		return b;
	}
	A: 30 B: 20 C: 16 D: 0
	*/
}

void Question_3()
{
	/*
	3��������һ�����ʽ���ܷ��ʶ�ά���� b �ĵ� i �е� j ��Ԫ�أ� ( C )
		A: b[i][j]
		B: *(b[i]+j)
		C: *(*b+i)+j
		D: (*(b+i))[j]
	
	*/
}

//�����㷨��
/*
4������һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�����κ�ֵ�������г����������Σ��������� true�����������ÿ
��Ԫ�ض�����ͬ���򷵻� false��
���ӣ�https://leetcode-cn.com/problems/contains-duplicate/
*/
#include<vector>
#include<algorithm>
class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}
		return false;
	}
};

/*
5�������������ʹ�ü��������������� name��ż�����ڼ����ַ� c ʱ���������ܻᱻ���������ַ����ܱ�����1�λ��Ρ�
�㽫�������������ַ� typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ��� True��
*/
class Solution
{
public:
	bool isLongPressedName(string name, string typed)
	{
		//˼·�����������ַ������бȽϣ������ͬ�����ǵ��±�һ�����++������ͬʱ����Ҫ���Ǵ�ʱtyped�е��ǲ��Ǹ��ַ�����������
		//���typed[j] == typed[j - 1]�������������typed�еĲ��Ƕ�Ӧ����������
		for (int i = 0, j = 0;j < typed.size();)
		{
			if (i < name.size() && name[i] == typed[j])
			{
				i++;
				j++;
			}
			else if (j > 0 && typed[j] == typed[j - 1])
			{
				j++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
