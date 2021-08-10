#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    //这里其实创建这两个变量在类中其实不太好，建议还是放在全局或者形参上，不然全部的Solution的对象都有这两个
    vector<vector<int>>ret;     //存储最终结果
    vector<int>temp;            //存储每一个子集的结果
    void dfs(vector<int>& nums,size_t start)
    {
        ret.push_back(temp);
        for(size_t i=start;i<nums.size();++i)
        {
            if(i>start&&nums[i]==nums[i-1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums,i+1);
            
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());  //去重
        dfs(nums,0);
        return ret;
    }
};


void test()
{
  Solution s;
  vector<int>v{1,2,2};
  vector<vector<int>>ret=s.subsetsWithDup(v);
  vector<vector<int>>::iterator it=ret.begin();
  while(it!=ret.end())
  {
    vector<int>::iterator _it=(*it).begin();
    while(_it!=(*it).end())
    {
      cout<<*_it<<"   ";
      ++_it;
    }
    cout<<endl;
    ++it;
  }
}

int main()
{

  test();
  return 0;
}
