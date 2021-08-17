#include<iostream>
using namespace std;
#include<vector>

/*输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。 */

class Solution 
{
public:
    /*思路：从左右两边分别找一个数，让它们相加，如果相加大于我们要找的target，我们让right往左走，
     * 如果相加小于我们要找的数target，让left往右走*/
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>ret;
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else
            {
                break;
            }
        }
        //如果两个相等说明就没找到，则不需要把任何元素插入到我们的结果数组中，使其返回一个空数组
        if(left!=right)
        {
            ret.push_back(nums[left]);
            ret.push_back(nums[right]);
        }

        return ret;
    }
};

//测试代码
void test()
{
    vector<int>v{2,7,11,15};
    auto e=Solution().twoSum(v,9);
    for(auto s:e)
    {
      cout<<s<<" ";
    }
    cout<<endl;
}

int main()
{
  test();
  return 0;
}

