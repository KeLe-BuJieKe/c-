#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1�����ڽṹ�����Ĳ�����������һ��˵���Ǵ���ģ� ( B )
	A:������ͬ���͵Ľṹ����֮����Ը�ֵ�����Ǹ���ȫ����Ա��ֵ
	B:�����ṹ����֮�䲻�ܽ��й�ϵ����
	C:������ cin ����һ���ṹ������ȫ����Ա��
	D:������һ�� cout ���һ���ṹ������ȫ����Ա��ֵ
	*/
}

void Question_2()
{
	/*
	2���ڶ���������������У���������һ��ͨ���� D ����ʵ�֡�
	A:ԭ������Ķ����Ƽ�����
	B:��������Ķ����Ƽ�����
	C:ԭ�������ʮ���Ƽӷ�����
	D:��������Ķ����Ƽӷ���
	*/
}

void Question_3()
{
	/*
	3���ַ��ͳ������ڴ��д�ŵ���:�� A ��
	A:ASCII��
	B:BCD��
	C:�ڲ���
	D:ʮ������
	*/
}
//�����㷨��
/*
4������һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ�����λ���ִ�����������λ�� ����
��ÿ��Ԫ��ֻ�洢��������
���ӣ�https://leetcode-cn.com/problems/plus-one/submissions/
*/
#include<vector>
class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			//һ��ʼ�����һλ�������൱����+1��
			//�жϸ�λ�� ģ10 ���Ƿ���� 0
			//�������0�ˣ���˵���������н�λ�ͼ�����ǰһλ���ж�ǰһλ+�Ͻ�λģ10���Ƿ����0����������
			digits[i]++;
			digits[i] %= 10;
			if (digits[i] != 0)
			{
				return digits;
			}
		}
		//�����ﻹû�г�����������ͱ�����999+1�������������������Ҫ����ͷ������ 1
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

/*
5������һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
���ӣ�https://leetcode-cn.com/problems/third-maximum-number/
*/
class Solution
{
public:
	int thirdMax(vector<int>& nums)
	{
		long long max = -0xfffffffff, mid = -0xfffffffff, min = -0xfffffffff;
		for (int i = 0; i < nums.size(); ++i)
		{
			// �����Ƿ���max��mid��min��ȣ������Ⱦ�˵����������ظ����ֹ���
			if (nums[i] == max || nums[i] == mid || nums[i] == min)
			{
				continue;
			}
			
			if (nums[i] > max)
			{
				min = mid;
				mid = max;
				// ���� max
				max = nums[i];
			}
			else if (nums[i] > mid)
			{
				min = mid;
				// ���� mid
				mid = nums[i];

			}
			else if (nums[i] > min)
			{
				// ���� min
				min = nums[i];
			}
		}
		return min == -0xfffffffff ? max : min;
	}
};