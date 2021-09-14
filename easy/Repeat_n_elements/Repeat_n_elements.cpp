#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
/*
961. 重复 N 次的元素
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
返回重复了 N 次的那个元素。
示例 1：
输入：[1,2,3,3]
输出：3

示例 2：
输入：[2,1,2,5,3,2]
输出：2

示例 3：
输入：[5,1,5,2,5,3,5,4]
输出：5
*/

/*
  error idea
  一开始我想着利用排序，然后之间返回中间那个数，但那样会出现错误。
  当出现[1,2,3,3] 、[3,3,2,1]这种情况时会出现错误
 */

//思路一：暴力统计，统计每个字符出现的次数，如果该元素出现的次数等于总元素个数的一半时，之间返回
//时间复杂度O(n/2) 空间复杂度O(1)
//i最多等于numsSize的一半就会返回结果了，j那个for循环从头到尾循环是O(n),乘上二分之一
int repeatedNTimes(int* nums, int numsSize)
{
    for(size_t i=0; i<numsSize; i++)
    {
        int count=0;
        for(size_t j=i; j<numsSize; j++)
        {
            if(nums[i]==nums[j])
            {
                count++;
            }
        }
        if(count==numsSize/2)
        {
            return nums[i];
        }
    }
    return -1;
}


//思路二：利用哈希表 时间复杂度O(n) 空间复杂度O(n)
class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int,int>hash;
        for(auto &e:nums)
        {
            hash[e]++;
            if(hash[e]==nums.size()/2)
            {
                return e;
            }
        }
        return -1;
    }
};


int main()
{

  return 0;
}
