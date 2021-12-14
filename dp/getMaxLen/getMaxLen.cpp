/*1567. 乘积为正数的最长子数组长度
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。
一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组
请你返回乘积为正数的最长子数组长度。
示例  1：
输入：nums = [1,-2,-3,4]
输出：4
解释：数组本身乘积就是正数，值为 24 。

示例 2:
输入：nums = [0,1,-2,-3,-4]
输出：3
解释：最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。
注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。

示例 3：
输入：nums = [-1,-2,-3,0,1]
输出：2
解释：乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。

示例 4：
输入：nums = [-1,2]
输出：1

示例 5：
输入：nums = [1,2,3,5,-6,4,0,10]
输出：4
提示：
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

/*可以使用动态规划得到乘积为正数的最长子数组长度。定义两个数组 positive 和 negative，
 * 其中positive[i]表示以下标i为结尾的乘积为正数的最长子数组长度
 * negative[i]表示以下标i为结尾的乘积为负数的最长子数组长度
 * 当i=0时，以下标 i 结尾的子数组的长度为 1，因此当nums[0]>0时，positive[0]=1 
 * 当nums[0] < 0 时，negative[0]=1
 * 当i > 1时，根据nums[i]的值计算positive[i]和negative[i]的值
 * 当nums[i] >0 之前的乘积诚意nums[i]不会改变乘积的正负性 
 * positive[i]的计算为：positive[i] = positive[i-1]+1
 *
 * negative[i]的计算为：             negative[i-1]+1   negative[i-1]>0
 *                    negative[i] = 0                  negative[i-1]=0
 *这是因为当negative[i-1]=0时，negative[i]本身无法形成一个乘积为负数的子数组，所以要特殊判断
 *
 * 当nums[i] < 0 时，之前的乘积乘以nums[i]会改变乘积的正负性
 positive[i]的计算为： positive[i] = negative[i-1]+1        negative[i-1]>0
                                      0                     negative[i-1]=0
  这是因为当negative[i-1]=0时，positive[i]本身无法形成一个乘积为正数的子数组，所以要特殊判断
  negative[i]的计算为：negative[i] = positive[i-1]+1
 * */

//方法一：动态规划时间复杂度O(n) 空间复杂度O(n)
//我们可以利用这种思想进一步优化，利用滑动窗口来实现O(1)的空间复杂度
#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    int getMaxLen(vector<int>& nums) 
    {
        size_t size = nums.size();
        vector<int>positive(size); //用于存储计算乘积为正数的最长子数组的长度
        vector<int>negative(size); //用于存储计算乘积为负数的最长子数组的长度
        if(nums[0] > 0)
        {
            positive[0] = 1;
            negative[0] = 0;
        }
        else if(nums[0] < 0)
        {
            positive[0] = 0;
            negative[0] = 1;
        }
        else
        {
            positive[0] = 0;
            negative[0] = 0;
        }

        int retMax = positive[0];
        for(size_t i = 1; i < size; ++i)
        {
            if(nums[i] > 0)
            {
                positive[i] = positive[i-1] + 1;
                negative[i] = negative[i-1] > 0 ? negative[i-1]+1 : 0;
            }
            else if(nums[i] < 0)
            {
                positive[i] = negative[i-1] > 0 ? negative[i-1]+1 : 0;
                negative[i] = positive[i-1] + 1;
            }
            else
            {
                positive[0] = 0;
                negative[0] = 0;
            }
            retMax = max(retMax,positive[i]);
        }
        return retMax;
    }
};
