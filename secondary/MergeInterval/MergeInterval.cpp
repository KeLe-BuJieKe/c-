/*
56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2： 
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]] 
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间 
提示：
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        //这里数组需要有序的,按照每个一维数组的第一个元素的值排序
        //排序好后，我们就可以知道了要得到的合并的区间的左边界
        //那么我们的目标变成了找到最大的重叠区间的最右边界
        sort(intervals.begin(),intervals.end());
        size_t size = intervals.size();
        vector<vector<int>>ret;
        //这里需要注意一下，不需要i++
        for(size_t i =0; i < size; )
        {   
            size_t j =i+1;
            //将数组的最后一个数值赋值给临时变量temp
            int temp = intervals[i][1];
            //j往后比i多一位，指向后面的数组
            //将一连串的重叠子区间一起合并
            while(j < size && intervals[j][0] <= temp)
            {
                //去第二个数组和第一个数组的第二个数值的最大值
                temp = max(intervals[j][1],temp);
                //j指向下一个数组
                ++j;
            }
            ret.push_back({intervals[i][0],temp});
            i = j;
        }
        return ret;
    }
};
