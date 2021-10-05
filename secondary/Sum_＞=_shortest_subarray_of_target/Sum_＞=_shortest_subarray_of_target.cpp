#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


/*剑指 Offer II 008. 和大于等于 target 的最短子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
提示：
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

class Solution 
{
public:
  //双指针滑动窗口法 
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int size=nums.size();
        int i=-1,j=0;
        int window=0;
        int ret=INT_MAX;
        while(j<size)
        {
            window+=nums[j];
            while(window>=target)
            {
                ret=min(ret,j-i);
                ++i;
                window-=nums[i];
            }
            ++j;
        }
        if(ret==INT_MAX)
        {
            return 0;
        }
        else
        {
            return ret;   
        }
    }
};




int main()
{
  return 0;
}
