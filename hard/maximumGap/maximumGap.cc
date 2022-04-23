/*164. 最大间距
给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0
您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
示例 1:
输入: nums = [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。

示例 2:
输入: nums = [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
提示:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
*/


class Solution {
public:
    void InitBucket(int* arr, const int val, int size){
        for (int i = 0; i < size; ++i){
            arr[i] = val;
        }
    }
    int maximumGap(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        if (size < 2)
        {
            return 0;
        }
        //找出最大值与最小值
        int max_num = -1, min_num = INT_MAX;
        for (int i = 0; i < size; ++i){
            max_num = max_num < nums[i] ? nums[i] : max_num;
            min_num = min_num > nums[i] ? nums[i] : min_num;
        }
        if (max_num - min_num == 0){   //全部相同的情况
            return 0;
        }

        int* max_bucket = new int[size];
        int* min_bucket = new int[size];
        //初始化桶
        InitBucket(max_bucket, -1, size);
        InitBucket(min_bucket, INT_MAX, size);

        int interval = std::ceil((max_num - min_num) / static_cast<float>(size));
        int pos = 0;
        for (int j = 0; j < size; ++j){
            pos = (nums[j] - min_num) / interval;
            if (nums[j] == min_num || nums[j] == max_num){
                continue;
            }
            else{
                //求出每隔桶的最大间距
                max_bucket[pos] = std::max(max_bucket[pos], nums[j]);
                min_bucket[pos] = std::min(min_bucket[pos], nums[j]);
            }             
        }//for end

        int max_gap = 0; //最大间隔
        int prevMax = min_num; //前一个桶的最大值
        for (int k = 0; k < size; ++k){
            if (max_bucket[k] == -1){
                continue;
            }
            else{
                //计算当前桶的最小值减去上一个桶的最大值的差值，与之前算出来的最大的间距
                max_gap = std::max(max_gap, min_bucket[k] - prevMax);
                prevMax = max_bucket[k];
            }
        }
        //防止出现[1, 100]这种类似的情况
        max_gap = std::max(max_gap, max_num - prevMax);
        return max_gap;
    }
};
