#include<iostream>
using namespace std;
#include<queue>
#include<vector>

/*215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
*/

class Solution 
{
public:
  //时间复杂度O(nlogK) 空间复杂度O(K)
  //topK问题
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>small_heap;

        for(int i=0;i<k;++i)
        {
            small_heap.push(nums[i]);
        }

        int size=static_cast<int>(nums.size());
        for(int j=k;j<size;++j)
        {
            if(nums[j]>small_heap.top())
            {
                small_heap.pop();
                small_heap.push(nums[j]);
            }
        }

        return small_heap.top();
    }
};

int main()
{
  return 0;
}
