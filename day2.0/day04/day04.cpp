#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1����һ��ϵͳ��,�� float x[8] ,��������x��ʼ���ڴ� 1000 ��Ԫ,�� x[2] �Ĵ洢ʼ��( D )
	A: 1002			B: 1004			 C: 1006			D: 1008
	*/
}

void Question_2()
{
	/*
	2������������еĽ���ǣ��� C ��
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
	3��������һ��������������ͣ���仰�Ƿ���ȷ��( A )
	A�� ��ȷ B: ����
	*/
}

//�����㷨��
/*
4������һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�������������һ�����ʣ��뷵�� 0 ��
���ӣ�https://leetcode-cn.com/problems/length-of-last-word/
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
            //��һ���Ƿ�ֹ��������"hello "�������
            else if (s[i] == ' ' && length != 0)
            {
                break;
            }
        }
        return length;
    }
};


/*
5���������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
���ӣ�https://leetcode-cn.com/problems/merge-sorted-array/
*/
#include<vector>
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        nums1.resize(m + n);   //������������䵽m+n
        int i = nums1.size() - 1;
        m -= 1;
        n -= 1;
        //˼·�ǣ������������飬�Ӻ���ǰ�Ƚϣ�Ȼ��Ѵ�����Ž����ݺõ�nums1��
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