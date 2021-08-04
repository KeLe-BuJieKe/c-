#include<iostream>
using namespace std;
#include <vector>

/*
 * 题目：消失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof
*/


/*
境界一：
采用异或的方法：从0到n与nums中的元素异或最后得到的就是我们所要的消失的数字
因为同一个数异或两次变为0;
*/
class Solution1 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int ret=0;
        int i=0;
        for(;i<=nums.size();++i)
        {
            ret^=nums[i]^i;
        }
        return  ret;
    }
};


/*
*境界二：遍历一遍数组，当下标与该数字不相等时，则这个数为我们要找的消失的数字
*/
class Solution2 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int i=0;
        for(;i<nums.size();++i)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return  i;
    }
};


/*
境界三：由于题目中的题眼  递增排序数组这个条件 我们一直没用到，看到排序数组我们首先想到的是是否能用二分查找
如果我们的mid值与数组的mid下标位置相等，则说明从0到mid位置没有我们要找消失的元素，故我们要把范围缩小left=mid+1
如果我们的mid值与数组的mid下标位置不相等，则说明该位置可能就是我们要找的元素但不一定是，故我们可以把范围继续缩小right=mid-1
直到我们的right==left执行完之后，此时我们的left与right相等的下标值就是我们要找的消失的元素值
*/
class Solution3 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        //首先看到题眼：排序数组我们这个时候就得往2分查找上去想
        int left=0,right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(nums[mid]==mid)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
};

int main()
{

  Solution3 m;
  vector<int>v;

  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
 
  cout<<m.missingNumber(v)<<endl;
  return 0;
}
