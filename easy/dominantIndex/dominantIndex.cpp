/*747. 至少是其他数字两倍的最大数
给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。
如果是，则返回 最大元素的下标 ，否则返回 -1 。
示例 1：
输入：nums = [3,6,1,0]
输出：1
解释：6 是最大的整数，对于数组中的其他整数，6 大于数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。

示例 2：
输入：nums = [1,2,3,4]
输出：-1
解释：4 没有超过 3 的两倍大，所以返回 -1 。

示例 3：
输入：nums = [1]
输出：0
解释：因为不存在其他数字，所以认为现有数字 1 至少是其他数字的两倍。
提示：
1 <= nums.length <= 50
0 <= nums[i] <= 100
nums 中的最大元素是唯一的
*/


//方法一：使用优先级队列
//时间复杂度O(n)+O(logn) 空间复杂度O(1)
class Solution1 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        size_t size = nums.size();
        if(size == 1)
        {
            return 0;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push(make_pair(nums[0],0));
        pq.push(make_pair(nums[1],1));
        for(size_t i = 2; i < size; ++i)
        {
            pair<int,int> temp = pq.top();
            if(nums[i] > temp.first)
            {
                pq.pop();
                pq.push(make_pair(nums[i],i));
            }
        }
        auto x = pq.top();
        pq.pop();
        auto y = pq.top();
        if(x.first == 0)
        {
            return y.second;
        }
        return (y.first / x.first) >= 2 ? y.second : -1;
    }
};


//方法二：就一次遍历即可
//时间复杂度O(n) 空间复杂度O(1)
class Solution2 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        size_t size = nums.size();
        if(size == 1)
        {
            return 0;
        }

        int max = nums[0];
        int index = 0;
        int second = -1;
        for(size_t i = 1; i < size; ++i)
        {
            if(nums[i] > max)
            {
                second = max;
                max = nums[i];
                index = i;
            }
            else if(nums[i] > second)
            {
                second = nums[i];
            }
        }

        return max >= 2*second ? index : -1;
    }
};
