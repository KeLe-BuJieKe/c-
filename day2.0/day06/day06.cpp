#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1��DOS ����չ��Ϊ.BAK���ļ���Ϊ( D )
	A: �������ļ� B: BASIC�ļ� C:��ʱ�ļ� D:�����ļ�
	*/
}

void Question_2()
{
	/*
	2������ѡ���кϷ����ַ������ǣ� C ��
	A: 'ab'			B: '\101'		C: "A"		D: PI
	*/
}

void Question_3()
{
	/*
	3�� �����ͱ���n��ֵΪ2��ִ����䡰n+=n-=n*n����n��ֵ�ǣ� A ��
	A: -4		B: 2		C: -1		D: 4
	*/
}

//�����㷨��
#include<vector>
/*
4������һ�����ǵݼ�˳��������������� A ������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
(ע�⣺�ǵݼ�˳�򼴵���������������ע�⸺��������
���ӣ�https://leetcode-cn.com/problems/squares-of-a-sorted-array/
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int begin = 0;
        int end = nums.size() - 1;
        //����һ�����飬����ʼ�����Ĵ�СΪnums.size()
        vector<int>ret(nums.size());
        for (int i = ret.size() - 1; i >= 0; --i)
        {
            //˫ָ�룬һ����ͷ��һ����β��
            //�ж��Ǹ�ͷ��β�Ǹ����ľ���ֵ�����ǰѴ��ƽ������������ǵ�Ŀ������ret��
            if (abs(nums[end]) - abs(nums[begin]) >= 0)
            {
                ret[i] = nums[end] * nums[end];
                end--;
            }
            else
            {
                ret[i] = nums[begin] * nums[begin];
                begin++;
            }
        }
        return ret;
    }
};

/*
5������һ���ַ��� S ������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
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
