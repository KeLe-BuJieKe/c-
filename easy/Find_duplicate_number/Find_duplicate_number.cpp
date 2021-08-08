#include<iostream>
#include<vector>
using namespace std;

/*
 *找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的
，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
 * */
//方法一:
int findRepeatNumber1(vector<int>& nums)   //时间复杂度为：O（n） 空间复杂度O（n）
{
  /*思路：利用一个简单的哈希表，这题由于是有限定数字的范围，如果没有限定下面这种哈希不可取，此时就得用unordered_map即可
   *先创建一个等大的数组，将nums中的元素放进ret数组充当下标，如果为true了，说明该位置数字是重复的
   * */
    vector<bool>ret(nums.size(),false);

    for(size_t i=0;i<nums.size();++i)
    {
        if(ret[nums[i]]==false)
        {
            ret[nums[i]]=true;
        }
        else
        {
            return nums[i];
        }
    }
    return -1;
}


//方法二：
//由于该题目的限制：在一个长度为 n 的数组 nums 里的所有数字都在 0 ~ n-1 的范围内
//这说明该数组元素的 索引 和 值 是 一对多 的关系。
//因此，可遍历数组并通过交换操作，使元素的 索引 与 值 一一对应（即 nums[i] = i ）

int findRepeatNumber2(vector<size_t>&nums)   //时间复杂度为：O（n） 空间复杂度：O（1）
{
    for(size_t i=0;i<nums.size();)
    {
        if(nums[i]==i)
        {
            ++i;
            continue;
        }
        else
        {
            if(nums[i]==nums[nums[i]])
            {
                return nums[i];
            }
            else
            {
                swap(nums[i],nums[nums[i]]);
            }
        }
    }
    return -1; 
}

//测试代码
void test()
{
  vector<size_t>v{2, 3, 1, 0, 2, 5, 3};
  cout<<findRepeatNumber2(v)<<endl;
}


int main()
{
  test();
  return 0;
}
