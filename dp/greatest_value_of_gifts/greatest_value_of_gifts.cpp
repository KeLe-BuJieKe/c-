#include<iostream>
#include<vector>
using namespace std;

/*在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，
 * 并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
*/

class Solution 
{
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        size_t n=grid.size();
        size_t m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));  //空间复杂度O（m*n） 时间复杂度 O（m*n）
        for(size_t i=1;i<=n;++i)
        {
            for(size_t j=1;j<=m;++j)
            {
                dp[i][j]=grid[i-1][j-1]+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


void test()
{
  vector<vector<int>>v{{1,3,1},{1,5,1},{4,2,1}};
  cout<< Solution().maxValue(v)<<endl;
}

int main()
{
  test();
  return 0;
}
