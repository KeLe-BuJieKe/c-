/*55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
提示：
1 <= nums.length <= 3 * 104
0 <= nums[i] <= 10^5
*/



//方法一：暴力dp，但很容易超时
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        size_t size = nums.size();
        if(size == 1)
        {
            return true;
        }
        vector<bool>dp(size,false);
        
        dp[0] = true;
        
        for(size_t i = 0; i < size; ++i)
        {
            for(size_t j = 1; j <= nums[i]; ++j)
            {
                if(i+ j < size)
                {
                    dp[i+j] = dp[i+j-1];
                }
                else
                {
                    break;
                }
                if(dp[size-1]  == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};


//方法二：简单dp，思路：每次找一个能跳到的最远的距离，如果能到达的最远距离大于等于数组的元素个数了
//这证明是能到到达数组最后一个元素的下标
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        size_t size = nums.size();
        size_t maxDistance = 0;

        for(size_t i =0; i < size; ++i)
        {
            if(i > maxDistance)
            {
                return false;
            }
            maxDistance = max(maxDistance,i+nums[i]);
        } 
        return true;
    }
};
