#include<iostream>
using namespace std;
#include<vector>

/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。*/

class Solution 
{
public:
    //思想，从左、右两边分别找一个数，右边找偶数，左边找奇数，找到了就交换
    vector<int> exchange(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            while(left<right&&(nums[right]%2)!=1)
            {
                right--;
            }
            while(left<right&&(nums[left]%2==1))
            {
                left++;
            }
            swap(nums[left],nums[right]);
        }
        return nums;
    }
};




//测试代码
void test()
{
  vector<int>v{1,2,3,4};

  Solution().exchange(v);
  for(auto e:v)
  {
    cout<<e<<" ";
  }
  cout<<endl;
}


int main()
{
  test();
  return 0;
}
