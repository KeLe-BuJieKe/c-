#include<iostream>
using namespace std;
#include<vector>


/*请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 题目链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 * */
//滑动窗口
//时间复杂度 O(N) ： 其中 N 为字符串长度，动态规划需遍历计算 dp 列表。
//空间复杂度 O(1) ： 字符的 ASCII 码范围为 0 ~ 127 ，哈希表 index 最多使用 O(128) = O(1)大小的额外空间。
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>index(128,-1);
        int val=0;
        int left=-1;
        for(int i=0;i<s.size();++i)
        {
            if(index[s[i]]!=-1)
            {
              //碰到重复出现的字符了，就让left指向重复出现的字符的下标，
              //如果left>index[s[i]]，则说明在left位置到i这个位置有其他的重复字符
              //反之，则没有。使其更新为当前重复出现的字符的下标
                left=max(left,index[s[i]]);
            }
            index[s[i]]=i;  //存储每次出现的字符的下标
            val=max(val,i-left);  //得出每个窗口内的最大值不重复子字符串的个数
            
        }
        return val;
    }
};


void test()
{
  string s="arabcacfr"; 
  cout<<Solution().lengthOfLongestSubstring(s)<<endl;
}

int main()
{
  test();
  return 0;
}
