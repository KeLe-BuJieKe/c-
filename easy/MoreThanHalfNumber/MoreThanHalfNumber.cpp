#include<iostream>
using namespace std;
#include<vector>


/*剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
*/

class Solution          //投票法  时间复杂度O(n),空间复杂度O(1)
{
public:
    /*
    思路:我们遍历数组nums的所有元素对于每个元素 x，在判断 x 之前，如果 majorcount 的值为 0，我们先将 x 的值赋予 majornum，随后我们判断 x：
    如果 x 与 majornum 相等，那么计数器 majorcount 的值增加 1；
    如果 x 与 majornum 不等，那么计数器 majorcount 的值减少 1。
    例如 [1, 2, 3, 2, 2, 2, 5, 4, 2]，作为例子，首先写下它在每一步遍历时 majornum 和 majorcount 的值：
    [1, 2, 3, 2, 2, 2, 5, 4, 2]
     1, 0, 1, 0, 1, 2, 1, 0, 1 
    */
    int majorityElement(vector<int>& nums)
    {
        int majornum = 0;
        int majorcount = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (majorcount == 0)        //判断majorcount 的值是否为 0，nums[i]的值赋予 majornum，
            {
                majornum = nums[i];
                ++majorcount;
                continue;
            }
            if (majornum == nums[i])    //如果相等majornum，majorcount++，不相等--
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


int main()
{
  return 0;
}
