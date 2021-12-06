#include<iostream>
#include<vector>
using namespace std;


/*198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统
，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

     示例 2：
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
提示：
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/


//第一种dp
class Solution1 
{
public:
    int rob(vector<int>& nums) 
    {
        size_t size = nums.size();
        if(size < 2)
        {
            return nums[0];
        }
        int maxRet = 0;
        vector<int>dp(size+1,0);
        dp[1] = nums[0];
        dp[2] = nums[1];
        maxRet=max(dp[1], dp[2]);
        //dp[i]的定义为到i这个房子位置最多能偷窃到的金额，并且要隔着才能偷
        for(size_t i = 3; i <= size; ++i)
        {
            dp[i] = nums[i-1] + max( dp[i-2], dp[i-3]);
            maxRet = max(dp[i],maxRet);
        }
        return maxRet;
    }
};


//第二种dp
class Solution2 
{
public:
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        //定义dp[i]的定义为到该位置能偷窃到的最高金额
        vector<int> dp(size,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) 
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};

