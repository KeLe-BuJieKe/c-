/*238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

*/
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = static_cast<int>(nums.size());
        vector<int>left(size,0);
        vector<int>right(size,0);

        left[0] =  1;
        for(int i = 1; i < size; ++i)
        {
            left[i] = nums[i-1] *left[i-1];
        }

        right[size-1] = 1;
        for(int j = size-2; j >=0; --j)
        {
            right[j] = nums[j+1] * right[j+1];
        }

        for(int k = 0; k < size; ++k)
        {
            nums[k] = left[k] * right[k];
        }
        return nums;
    }
};
