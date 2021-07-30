#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>
#include<algorithm>

/*
题目：给出不同面额的硬币以及一个总金额. 
写一个方法来计算给出的总金额可以换取的最少的硬币数量. 如果已有硬币的任意组合均无法与总金额面额相等, 那么返回 -1.
链接：https://www.lintcode.com/problem/669
思路：运用动态规划dp
首先对于数组这一类的而言一般的操作是
1、考虑能否将问题规模减小
这里以amount==27   coins={2，5，7}为例
2、这里考虑数组上常用的思路：每次减少一个：
将子问题分为f（amount）=          min{f(amount-2)+1，f(amount-5)+1,f(amount-7)+1}
               ⬇                       ⬇ 
     拼出X所需最少的硬币数    拼出25所需的最少的硬币数，加上最后一枚硬币2，5和7同理
3、我们设状态f[x]=最少用多少枚硬币拼出 X
f[x]=min{f[x-2]+1,f[x-5]+1,f[x-7]+1};
4、最后我们就要考虑边界问题了。
X-2,X-5,X-7三种情况下所有的结果全小于0时，以及怎么停下来？
首先如果每个的钱数拼不出来就让定义为  f[y]=正无穷（整数的最大值）
所以f[1]= min{f[-1]+1,f[-4]+1,f[-6]+1}=正无穷，表示拼不出来
初始条件：f[0]=0;
*/
int coinChange(vector<int>& coins, int amount)
{
    vector<int> ret(amount+1, INT_MAX); //0元到27元需要28个int的空间，并把每个位置的值都初始化为INT_MAX
    ret[0] = 0;     //初始条件
        
    for (int i = 1; i <= amount; ++i)   //从一块钱开始到amount
    {
        for (int j = 0; j < coins.size(); ++j)  //amount分别减去给出的硬币的币值，如果大于就有可能可以拼出，小于则拼不出
        {
            if ((i - coins[j]) >= 0 && (ret[i - coins[j]] != INT_MAX))  
                //判断完大于0之后有可能拼出，在看看该硬币的子问题amount-coins[j]拼不拼的出来，如果为INT_MAX则拼不出，
                //如果子问题也拼凑不出，则说明该amount也拼凑不出来。
            {
                ret[i] = min(ret[i], (ret[i - coins[j]] + 1));
            }
        }
    }
    if (ret.back() == INT_MAX)  //由于我们要的结果是amount块钱，它的硬币所需数在最后一个位置，也就是back位置
                                //如果back()位置的值为INT_MAX，则说明该amount拼凑不出来
    {
        return -1;
    }
    else
    {
        return ret.back();
    }
}
