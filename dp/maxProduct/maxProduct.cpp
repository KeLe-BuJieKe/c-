/*152. 乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/
#include<iostream>
#include<vector>

class Solution 
{
public:
    //思路：就是利用dp来得到最大子数组乘积，由于数组中有可能是有负数的
    //如果负数乘了两次，然后最小乘积就会变成最大乘积，那么思路就变成
    //碰到一个负数就交换到前一个数之前的乘积
    //最后在和一个存储每次最大的结果数据来取得最大值
    int maxProduct(vector<int>& nums) 
    {
        size_t size = nums.size();
        vector<int>minDP(size,0),maxDP(size,0);
        minDP[0] = nums[0];
        maxDP[0] = nums[0];
        int retMax = maxDP[0];
        for(size_t i = 1; i < size; ++i)
        {
            if(nums[i] < 0)
            {
                std::swap(maxDP[i-1],minDP[i-1]);
            }
            maxDP[i] =  max(maxDP[i-1]*nums[i],nums[i]);
            minDP[i] =  min(minDP[i-1]*nums[i],nums[i]);
            retMax = max(maxDP[i],retMax);
        }
        return retMax;
    }
};
