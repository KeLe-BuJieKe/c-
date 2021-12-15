/*1014. 最佳观光组合
给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离。
返回一对观光景点能取得的最高分。
示例 1：
输入：values = [8,1,5,2,6]
输出：11
解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

示例 2：
输入：values = [1,2]
输出：2
提示：
2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution1
{
public:
    //时间复杂度O(n) 空间复杂度O(n)
    //dp[i]定义为：表示到i位置之前观光景点中最大的valuse[i]+i的值 这样我们就能得到每次最大的values[i]+i
    //然后在进行一次O(n)的遍历就可以确定最大的values[i]-i的值，然后它们之和就是我们要的答案
    int maxScoreSightseeingPair(vector<int>& values)
    {
        size_t size = values.size();
        vector<int>dp(size);
        dp[0] = values[0] + 0;
        int retMax = 0;
        for (size_t i = 1; i < size; ++i)
        {
            dp[i] = max<int>(dp[i-1], values[i]+i);
            retMax = max<int>(retMax,dp[i-1]+values[i]-i);
        }
        return retMax;
    }
};

//优化上面的dp  时间复杂度O(n) 空间复杂度O(1) 
class Solution2
{
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        size_t size = values.size();
        int maxSightseeing = values[0]+0;
        int retMax = 0;
        for (size_t i = 1; i < size; ++i)
        {
            retMax = max<int>(retMax,maxSightseeing+values[i]-i);
            maxSightseeing = max<int>(maxSightseeing, values[i]+i);
        }
        return retMax;
    }
};
