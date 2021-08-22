#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
//2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

class Solution 
{
public:
    bool isStraight(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int king=0;
        for(int i=0;i<4;++i)
        {
            if(nums[i]==0)    //统计大小王的数量
            {
                ++king;
            }
            else if(nums[i]==nums[i+1]) //防止有对子的情况
            {
                return false;
            }
        }
        return nums[4]-nums[king]<5;  //最大数减最小数
    }
};


void test()
{
  vector<int>nums{0,1,0,2,5};
  cout<<Solution().isStraight(nums)<<endl;
}
int main()
{

  test();
  return 0;
}
