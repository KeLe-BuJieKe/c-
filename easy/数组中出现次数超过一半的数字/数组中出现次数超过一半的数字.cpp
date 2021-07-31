#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;

/*
��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�
ʾ�� 1:
����: [1, 2, 3, 2, 2, 2, 5, 4, 2]
���: 2
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
*/
class Solution          //ͶƱ��  ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
{
public:
    /*
    ˼·:���Ǳ�������nums������Ԫ�ض���ÿ��Ԫ�� x�����ж� x ֮ǰ����� majorcount ��ֵΪ 0�������Ƚ� x ��ֵ���� majornum����������ж� x��
    ��� x �� majornum ��ȣ���ô������ majorcount ��ֵ���� 1��
    ��� x �� majornum ���ȣ���ô������ majorcount ��ֵ���� 1��
    ���� [1, 2, 3, 2, 2, 2, 5, 4, 2]����Ϊ���ӣ�����д������ÿһ������ʱ majornum �� majorcount ��ֵ��
    [1, 2, 3, 2, 2, 2, 5, 4, 2]
     1, 0, 1, 0, 1, 2, 1, 0, 1 
    */
    int majorityElement(vector<int>& nums)
    {
        int majornum = 0;
        int majorcount = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (majorcount == 0)        //�ж�majorcount ��ֵ�Ƿ�Ϊ 0��nums[i]��ֵ���� majornum��
            {
                majornum = nums[i];
                ++majorcount;
                continue;
            }
            if (majornum == nums[i])    //������majornum��majorcount++�������--
            {
                ++majorcount;
            }
            else
            {
                --majorcount;
            }
        }
        return majornum;
    }
};