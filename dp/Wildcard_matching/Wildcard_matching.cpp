#include<iostream>
using namespace std;
#include<vector>


/*给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
题目链接：https://leetcode-cn.com/problems/wildcard-matching
*/

class Solution 
{
public:
    // 状态转移方程：
    //      1. 当 s[i] == p[j]，或者 p[j] == ? 那么 dp[i][j] = dp[i - 1][j - 1];
    //      2. 当 p[j] == * 那么 dp[i][j] = dp[i][j - 1] || dp[i - 1][j]    
    // 其中:dp[i][j - 1] 表示 * 代表的是空字符，例如 a, *
    //      dp[i - 1][j] 表示 * 代表的是非空字符，例如 abc, ab*
    // 初始化：
    //      1. dp[0][0] 表示什么都没有，其值为 true
    //      2. 第一行 dp[0][j]，换句话说，s 为空，与 p 匹配，所以只要 p 开始为 * 才为 true
    //      3. 第一列 dp[i][0]，当然全部为 false
    bool isMatch(string s, string p) 
    {
        size_t S_size=s.size();
        size_t P_size=p.size();

        // 状态定义：dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配
        vector<vector<bool> > dp(S_size + 1, vector<bool>(P_size + 1,false));
        // 1.初始化 空字符串与空字符串是匹配的
        dp[0][0]=true;
        for(size_t i=1;i<=P_size;++i)
        {
            if(p[i - 1]=='*')       //2.空字符串和*是匹配的
            {
                dp[0][i]=dp[0][i-1];
            }
        }
        
        for (size_t i = 1; i <= S_size; ++i) //状态转移
        {
            for (size_t j = 1; j <= P_size; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[S_size][P_size];
    }
};

void test()
{
   string s="adceb";
   string p="*a*b";
   cout<<Solution().isMatch(s,p)<<endl;
   string r="acdcb";
   string x="a*c?b";
   cout<<Solution().isMatch(r,x)<<endl;
}

int main()
{
  test();
  return 0;
}
