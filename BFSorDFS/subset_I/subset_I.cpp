#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    //nums为题目中的给的数组
    //path为路径结果，要把每一条 path 加入结果集
    //ret是我们要返回的结果
    void backtrack(vector<vector<int>>& ret,vector<int>& nums,vector<int>& path,int start)
    {
        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            backtrack(ret,nums,path,i+1);
            ret.push_back(path);
            path.pop_back();
        }
    }
    //思路
    /*1.找结束条件，这里比较特殊所有路径都应该加入结果集，所以不存在结束条件。
    或者说当 start 参数越过数组边界的时候，程序就自己跳过下一层递归了，因此不需要手写结束条件,直接加入结果集
    2.找选择列表，选择列表为，是上一条选择路径之后的剩下的数
    3.判断是否需要减枝，由于这题目所说nums中的元素互不相同，故不需要
    4.做出选择，进行下一层选择，递归
    5.撤销选择
    */
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ret;
        ret.push_back({});
        for(size_t i=0;i<nums.size();i++)
        {
            vector<int>path;
            path.push_back(nums[i]);
            ret.push_back(path);
            backtrack(ret,nums,path,i+1);
        }
        return ret;
    }
};


void test()
{
  Solution s;
  vector<int>v{1,2,3};
  vector<vector<int>>ret=s.subsets(v);
  vector<vector<int>>::iterator it=ret.begin();
  while(it!=ret.end())
  {
    vector<int>::iterator _it=(*it).begin();

    while(_it!=(*it).end())
    {
      cout<<(*_it)<<"  ";
      ++_it;
    }
    ++it;
    cout<<endl;
  }
}

int main()
{
  test();
  return 0;
}
