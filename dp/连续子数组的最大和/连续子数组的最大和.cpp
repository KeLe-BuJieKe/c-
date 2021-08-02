#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;


class Solution
{
public:
    /*
    dp动态规划
    设f[i]表示以第i个数字结尾的子数组的最大和。
                  {    nums[i]                          i=0或者ret[i-1]+nums[i]<=nums[i]
    状态方程：f[i]={
                  {   ret[i]=nums[i]+ret[i-1]           ret[i-1]+nums[i]>nums[i]
    这个状态方程的意义：
    Ⅰ、当以第i-1个数字结尾的子数组中所有数字的和小于nums[i]时，如果把这个负数与第i个数累加，
    则得到的结果比第i个数字本身还要小，所以这种情况下以第i个数字结尾的子数组就是第i个数字本身。
    Ⅱ、如果以第i-1个数字结尾的子数组中所有数字的和大于nums[i]时，则于第i个数字累加就得到以
    第i个数字结尾的子数组中所有数字的和。
    */
    int maxSubArray(vector<int>& nums)
    {
        vector<int>ret(nums.size(), 0);
        int summax = INT_MIN;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (i == 0 || ret[i - 1] + nums[i] <= nums[i])
            {
                ret[i] = nums[i];
            }
            else    //(ret[i-1]+nums[i]>nums[i])
            {
                ret[i] = nums[i] + ret[i - 1];
            }
            summax = max(ret[i], summax);
        }
        return  summax;
    }
};

int main()
{
	system("pause");
	return 0;
}