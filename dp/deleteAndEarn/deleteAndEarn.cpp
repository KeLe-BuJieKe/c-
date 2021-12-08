/*740. 删除并获得点数
给你一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
示例 1：
输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。

示例 2：
输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
提示：
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int rob(vector<int>&nums)
    {
        size_t size =nums.size();

        if(size == 1)
        {
            return nums[0];
        }

        vector<int> dp (size+1,0);
        dp[1] = nums[0];
        dp[2] = nums[1];
        int retMax = max(dp[1],dp[2]);
        for(size_t i =3; i <= size; ++i)
        {
            dp[i] = max(dp[i-3],dp[i-2])+nums[i-1];
            retMax = max(dp[i],retMax);
        }
        return retMax;
    }

    int deleteAndEarn(vector<int>& nums) 
    {
        int Max = 0;
        for(auto &e : nums)
        {
            Max = max(e,Max);
        }
        vector<int>sum(Max+1,0);    //按打家劫舍得思路

        for(auto &e: nums)
        {
            sum[e]+=e;
        }
        
        return rob(sum);
    }
};
