/*45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。

 

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
提示:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

#include<iostream>
#include<vector>
using std::vector;

class Solution1 
{
public:
    /*暴力dp
     我们从左到右遍历数组，判断该位置是否能到达，如果能到达，判断i这个位置到j这个位置的步数
     是否i+1小于j这个位置的步骤，那么就更新
    */
    int jump(vector<int>& nums) 
    {
        size_t size = nums.size();
        vector<size_t>dp(size,INT_MAX);
        dp[0]=0;
        for(size_t i = 0; i < size; ++i)
        {
            for(size_t j = 1; j <= nums[i]; ++j)
            {
                if(i+j>=size)
                {
                    break;
                }
                dp[i+j] = min(dp[i]+1,dp[i+j]);
            }
        }
        return  dp[size-1];
    }
};



class Solution2 
{
public:
    //优化上面的暴力dp
    //我们从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。

    /*在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，
    * 否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，
    * 我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。
    */
    int jump(vector<int>& nums) 
    {
        size_t size = nums.size();

        int step = 0;//步数
        int end = 0;//边界
        size_t maxFar = 0;//目没越过边界能跳到的最远距离

        for(size_t i = 0; i < size - 1; ++i)
        {
            maxFar = max(maxFar,i+nums[i]);
            // 到达上次跳跃能到达的右边界了
            if(end == i)
            {
                end = maxFar; //目前能跳到的最远位置变成了下次起跳位置的有边界
                ++step;  // 进入下一次跳跃
            }
        }
        return step;
    }
};

