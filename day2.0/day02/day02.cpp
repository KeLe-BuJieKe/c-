#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1��������a�� int ���ͣ���ִ������� a=��A'+1.6 ������ȷ�������ǣ� D ����
	A: a��ֵ���ַ�C
	B: a��ֵ�Ǹ�����
	C: �������ַ��ͺ͸��������
	D: a��ֵ���ַ���A����ASC��ֵ����1
	*/
}

void Question_2()
{
	/*
	2���������ε����н�������� linux ƽ̨, g++ ��������( C )
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d", x, y);
	return 0;
	A: 10 11		B: 11 10		C: 11 11		D: 10 10
	*/
}

void Question_3()
{
	/*
	3���ֲ�����ֻ��main���������ã���ȫ�ֱ��������к��������� �� B ����
	A�� ��ȷ B: ����
	*/
}

//�����㷨��
/*
4������һ������ nums ��һ��ֵ val ������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
���ӣ�https://leetcode-cn.com/problems/remove-element/
*/
#include<vector>
class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int slow = 0;     //��ָ��
		int fast = 0;     //��ָ��
		while (fast < nums.size())
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++slow;

			}
			++fast;
		}
		return slow;
	}
};


/*
5������һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У���������
�ᱻ��˳������λ��,����Լ������������ظ�Ԫ��
���ӣ�https://leetcode-cn.com/problems/search-insert-position/
*/
class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int i = 0;
		for (; i < nums.size(); ++i)
		{
			if (nums[i] >= target)
			{
				break;
			}
		}
		return i;
	}
};