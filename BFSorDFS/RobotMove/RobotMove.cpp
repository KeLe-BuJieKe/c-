#include<iostream>
using namespace std;
#include<vector>

/*地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
*/


class Solution 
{
public:
    int dfs(int m,int n,int k,vector<vector<bool>>&ret)
    {
      //先进行边界的限定，传进来的m和n不能越界，并且ret[m][n]的状态必须是false
        if(m<0 ||m>=ret.size() || n<0 ||n>=ret[0].size() ||ret[m][n]==true)
        {
            return 0;
        }
        ret[m][n]=true;

        //如果该位置没有被走过，并且该位置的下标的每一位的和都小于k，我们就认为该位置合法
        //并且是我们要找的格子之一，并继续递归它的上、下、左、右四个方位
        if(check(m,n,k))
        {
            return 1+dfs(m-1,n, k,ret)
                +dfs(m+1,n, k,ret)
                +dfs(m,n-1, k,ret)
                +dfs(m,n+1, k,ret);
        }

        return 0;
    }
    int movingCount(int m, int n, int k) 
    {
        //该二维数组存储的是一个状态表，被访问过则为true，没有为false    
        vector<vector<bool>>ret(m,vector<bool>(n,false));
        
        return dfs(0,0,k,ret);;
    }

    bool check(int i,int j,int k) //检查是否可以进入
    {
        if((GetDigitSum(i)+GetDigitSum(j))<=k)
        {
            return true;
        }
        return false;
    }
    int GetDigitSum(int val)    //得到下标每一位的和
    {
        int num=0;
        while(val>0)
        {
            num+=val%10;
            val/=10;
        }
        return num;
    }
};

void test()
{
  cout<<Solution().movingCount(16,8,4)<<endl;
}

int main()
{

  test();
  return 0;
}

