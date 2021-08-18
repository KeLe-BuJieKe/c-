#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


//方法一：利用哈希表，时间复杂度：O（n）空间复杂度:O（n）
class Solution1 
{
public:
    //首先将数组中的每个元素存入到nums中
    //再遍历数组，因为缺失的数字一定是在[1,nums.size()+1]这个前闭后也闭的区间内，
    //那个hash[i]位置最先不等于i,则这个位置的下标就为我们要找的第一个缺失的正正数
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_map<int,int>hash;
        for(size_t i=0;i<nums.size();++i)
        {
            hash[nums[i]]=nums[i];
        }

        for(size_t i=1;i<=nums.size();++i)
        {
            if(hash[i]!=i)
            {
                return i;
            }
        }
        //如果到这里还没有返回，则证明缺失的数字为nums.size()+1
        return nums.size()+1;
    }
};


//方法二：原地哈希 时间复杂度O（n）空间复杂度O（1）
class Solution2 
{
public:

  //首先将所有的负数都让其等于nums.size()+1，因为我们的缺失的数字的范围在[1，n+1]
  //在将每个数字对应的下标位置上的数字改为负数
  //最后我们判断第一个出现的正数，是在那个下标下，该下标+1就是我们要找的缺失的数字
    int firstMissingPositive(vector<int>& nums) 
    {
        for(auto &e:nums)
        {
            if(e<=0)
            {
                e=nums.size()+1;
            }
        }

        for(size_t i=0;i<nums.size();++i)
        {
            int temp=abs(nums[i]);
            if(temp<=nums.size())
            {
                nums[temp-1]=-abs(nums[temp-1]);
            }
        }

        for(size_t i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

//测试代码
void test()
{
  vector<int>v{7,8,9,10,11,12};
  cout<<Solution1().firstMissingPositive(v)<<endl;
  cout<<Solution2().firstMissingPositive(v)<<endl;
}

int main()
{
  test();
  return 0;
}
