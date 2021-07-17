#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1�����³�����������ǣ� D ����
	char *p="abcdefgh",*r;
	long *q;
	q=(long*)p;
	q++;
	r=(char*)q;
	printf("%s\n",r);
	A: abcd			B: bcde		 C: cdef		D: efgh
	*/
}

void Question_2()
{
	/*
	2�����³�����������ǣ� B ��
	char str[]="ABCD", *p=str;
	printf("%d\n", *(p+4));
	A: 68		B: 0		 C: �ַ���D���ĵ�ַ		D: ��ȷ����ֵ
	*/
}

void Question_3()
{
	/*
	3���Ķ�����C���룺 (  )
	float func(float a, int b)
	{
		float m=1, n=1;
		int i;
		for (i=1; i <b; i ++)
		{
			m*= a/i;
			n+=m;
		} 
			return n;
	}
	A: a^b		B: e^a		C: ln(1+a)		 D: a^a
	*/
}

//�����㷨��
/*
4������һ���Ǹ��������� A ������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ��(ע�⣺��������ֻ��ż����ǰ�����ں����)
���ӣ�https://leetcode-cn.com/problems/sort-array-by-parity/submissions/
*/
#include<vector>
class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& nums)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			//��������������
			while (left < right && nums[left] % 2 == 0)
			{
				left++;
			}
			//����������ż��
			while (left < right && nums[right] % 2 != 0)
			{
				right--;
			}
			swap(nums[left], nums[right]);
			left++;
			right--;
		}
		return nums;
	}
};

/*
5������һ���������͵����� nums �����дһ���ܹ��������顰�����������ķ�������������������������������
�ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�������鲻����������������ô����Ӧ�÷�
�� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ��.
���ӣ�https://leetcode-cn.com/problems/find-pivot-index/
*/
class Solution
{
public:
	int pivotIndex(vector<int>& nums)
	{
		//1.����nums�е�ȫ����ֵ��Ȼ��ÿ�αȽ�ǰ i ��ͺͺ� i���(ǰ��������;�����nums[i]`)��
		//�����Ⱦͷ��� i������Ƚ����´�ѭ��ֱ�����
		int Rightval = 0;
		for (auto e : nums)
		{
			Rightval += e;
		}
		int Leftval = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			Leftval += nums[i];
			if (Leftval == Rightval)
			{
				return i;
			}
			Rightval -= nums[i];
		}
		return -1;
	}
};
