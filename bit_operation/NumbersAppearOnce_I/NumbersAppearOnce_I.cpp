#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
/*剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。
 */

//方法一：利用哈希表来遍历数组得到结果，可以解决问题但不满足题目的要求
class Solution1 
{
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        unordered_map<int,int>hash;
        for(auto &e:nums)
        {
            ++hash[e];
        }
        vector<int>ret;
        for(auto &e:nums)
        {
            if(hash[e]==1)
            {
                ret.push_back(e);
            }
        }
        return ret;
    }
};


//方法二：分组异或
class Solution2 
{
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        vector<int>ret;
        int tempresult=0;
        for(const auto &e:nums)
        {
            tempresult^=e;
        }

        int pos=0;
        while(((tempresult>>pos)&0x1)!=1)
        {
            ++pos;
        }
        
        int x1=0,x2=0;
        int size=static_cast<int>(nums.size());
        for(int i=0;i<size;++i)
        {
            if((nums[i]>>pos)&0x1==1)
            {
                x1^=nums[i];
            }
            else
            {
                x2^=nums[i];
            }
        }
        ret.push_back(x1);
        ret.push_back(x2);
        return ret;
    }
};
int main()
{
  return 0;
}
