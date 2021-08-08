#include<iostream>
#include<vector>
using namespace std;

//方法一：暴力求解，一个一个的求对比，但是就没有使用到题目给的题眼：排序数组，且非递减也就是递增的
int search1(vector<int>& nums, int target)   //时间复杂度：O（n） 空间复杂度：O（1）
{
    int val=0;
    for(size_t i=0;i<nums.size();++i)
    {
        if(nums[i]==target)
        {
            ++val;
        }
    }
    return val;
}

//方法二：二分查找，找到target的区间所在区间
int binarysearchleft(vector<int>&nums,int &target)  //找左
{
    int left=0,right=nums.size()-1;
    while(left<right)
    {
        int mid=left+((right-left)>>1);
        if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    if(nums[left]==target)
    {
        return left;
    }
    else
    {
            return -1;
    }
}


int binarysearchright(vector<int>&nums,int &target)  //找左
{
    int left=0,right=nums.size()-1;
    while(left<right)
    {
        int mid=left+((right-left+1)>>1);
        if(nums[mid]<=target)
        {
            left=mid;
        }
        else
        {
            right=mid-1;
        }
    }
    if(nums[left]==target)
    {
        return left;
    }
    else
    {
        return -1;
    }
}
int search2(vector<int>& nums, int target) //时间复杂度O（logn）空间复杂度O（1）
{
    if(nums.size()==0)      //防止访问空数组错误
    {
        return 0;
    }
    int leftindex=binarysearchleft(nums,target);
    if(leftindex==-1)   //如果该数组内没有这个target直接提前返回
    {
        return 0;
    }
    int rightindex=binarysearchright(nums,target);
    return rightindex-leftindex+1;
}


void test()
{
  vector<int>v{5,7,7,8,8,10};
  cout<<search2(v,8)<<endl;
}

int main()
{
  test();
  return 0;
}
