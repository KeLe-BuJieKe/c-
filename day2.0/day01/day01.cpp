#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	//1�������±����������ͣ��� num=sum=7 ����ִ�б��ʽ�� sum=num++ �� sum++ , ++num �� sum ��ֵΪ��B ����
	//		A:  7			B : 8			C : 9			 D : 10
}

void Question_2()
{
	//2�� int i=10 ��j= 10 ��k= 3 �� k*=i+j k����ֵ�ǣ� (A )
	//		A: 60			B: 40			 C: 50 			D: 23

}

void Question_3()
{
	//3�� int i,j,a[2][3] ;�������� a ��Ԫ�����ڴ�����д���,���ܽ���1,2,3,4,5,6���� a ������ǣ� D ����
	//A: for (i = 0; i < 2; i++) for (j = 0; j < 3; j++)a[i][j] = i * 3 + j + 1;
	//B: for (i = 0; i < 3; i++) for (j = 0; j < 2; j++)a[j][i] = j * 3 + i + 1;
	//C: for (i = 0; i < 6; i++) a[i / 3][i % 3] = i + 1;
	//D: for (i = 1; i <= 6; i++) a[i][i] =i;
}

//�����㷨��
/*
4��ʵ�ֺ��� ToLowerCase() ���ú�������һ���ַ������� str ���������ַ����еĴ�д��ĸת����Сд��ĸ��֮
�󷵻��µ��ַ��� ��
���ӣ�https://leetcode-cn.com/problems/to-lower-case/
*/
class Solution
{
public:
	string toLowerCase(string s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
		return s;
	}
};


/*
5������һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
���ӣ�https://leetcode-cn.com/problems/rotate-array/
*/
#include<vector>
class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		int move = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + move);
		reverse(nums.begin() + move, nums.end());
	}
};