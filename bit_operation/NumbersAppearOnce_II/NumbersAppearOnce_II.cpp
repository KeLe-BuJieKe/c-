#include<vector>
#include<iostream>
using namespace std;

//方法一：排序，时间复杂度O(nlogn) 空间复杂度O(n)
int cmp_int(const void*e1,const void*e2)
{
    return (*(int *)e1)-(*(int*)e2);
}
int singleNumber(int* nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(int),cmp_int);
    for(int i=0;i<numsSize-2;i+=3)
    {
        // 三个里面都要相等，一旦不符合该规则就结束
        if(nums[i]!=nums[i+2])
        {
            return nums[i];
        }
    }
    //当最后一个元素是只出现一次的情况
    return nums[numsSize-1];
}


//方法二：利用哈希表遍历数组得到结果，时间复杂度O(n) 空间复杂度O(n)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int>hash;

        for(const auto &e:nums)
        {
            ++hash[e];
        }
        int ret=0;
        for(const auto&e:nums)
        {
            if(hash[e]==1)
            {
                ret=e;
            }
        }
        return ret;
    }
};


//方法三：利用位运算 时间复杂度O(n) 空间复杂度O(1)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        vector<int>bitSum(32,0);

        for(auto e:nums)
        {
            for(int i=31;i>=0;--i)
            {
                int bit=e&0x1;
                if(bit!=0)
                {
                    ++bitSum[i];
                }
                e>>=1;
            }
        }
        int ret=0;
        for(const auto&e:bitSum)
        {
            ret=ret<<1;
            ret+=(e%3);
        }
        return ret;
    }
};


int main()
{
  return 0;
}
