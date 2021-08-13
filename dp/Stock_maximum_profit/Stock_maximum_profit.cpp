#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


/*
 *假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
  */

/*思路：一遍遍历动态规划  时间复杂度:O(n) 空间复杂度:O(1)
  我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：
  如果我是在历史最低点买进的，最高点卖出的那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最后的答案。
 */

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=INT_MAX;
        int money=0;
        for(size_t i=0;i<prices.size();++i)
        {
            //方法一：
            if(buy>prices[i])      
            {
                buy=prices[i];
            }
            else
            {
                money=max(money,prices[i]-buy);
            }
            //方法二：
            // buy=min(buy,prices[i]);
            // money=max(money,prices[i]-buy);
        }
        return money;
    }
};



int main()
{
  //测试代码
  vector<int>v{7,1,5,3,6,4};
  cout<<Solution().maxProfit(v)<<endl;
  return 0;
}
