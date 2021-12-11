/*918. 环形子数组的最大和
给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。
在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）
此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，
不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）
示例 1：
输入：[1,-2,3,-2]
输出：3
解释：从子数组 [3] 得到最大和 3

示例 2：
输入：[5,-3,5]
输出：10
解释：从子数组 [5,5] 得到最大和 5 + 5 = 10

示例 3：
输入：[3,-1,2,-1]
输出：4
解释：从子数组 [2,-1,3] 得到最大和 2 + (-1) + 3 = 4

示例 4：
输入：[3,-2,2,-3]
输出：3
解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3

示例 5：
输入：[-2,-3,-1]
输出：-1
解释：从子数组 [-1] 得到最大和 -1
提示：
-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/


class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        size_t size = nums.size();
        vector<int>dp(size,0);
        int maxRet = INT_MIN;
        for(size_t i =0; i < size; ++i)
        {
            if(i == 0 ||nums[i]+dp[i-1] <= nums[i])
            {
                dp[i] = nums[i];
            }
            else
            {
                dp[i] = nums[i]+dp[i-1];
            }
            maxRet = max(dp[i],maxRet);
        }
        return maxRet;
    }
    int minSubArray(vector<int>& nums) 
    {
        size_t size = nums.size();
        vector<int>dp(size,0);
        int minRet = INT_MAX;
        for(size_t i =0; i < size; ++i)
        {
            if(i == 0 ||nums[i]+dp[i-1] > nums[i])
            {
                dp[i] = nums[i];
            }
            else
            {
                dp[i] = nums[i]+dp[i-1];
            }
            minRet = min(dp[i],minRet);
        }
        return minRet;
    }
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int sum = 0;
        for(auto &e:nums)
        {
            sum+=e;
        }
        //逆向思维，既然最大子数组和我们不好求出，那么可以利用整个数组的和减去最小子数组和来得到最大子数组和
        //但这里会有一种特殊情况就是，当自小子数组和是其整个数组的本身，即整个数组都是负数
        //那么此时整个数组的和就等于子数组和，那么这里得判断一下，如果是相等的，那么我们得到最大子数组和就是最大子数组和
        //整个数组的和 = 最大子数组的和 + 最小子数组的和
        //最大子数组的和 = 整个数组的和 - 最小子数组的和
        int maxRet = maxSubArray(nums);
        //vector<int>temp(nums.begin()+1,nums.end()-1);
        int minRet = minSubArray(nums);
        if(minRet == sum)
        {
            return maxRet;
        }
        return max(sum-minRet,maxRet);
    }
};
