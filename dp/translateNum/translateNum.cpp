/*剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
提示
0 <= num < 2^31
*/

class Solution 
{
public:

    
    int translateNum(int num) 
    {
        string numstirng=to_string(num);    // 将数字转化成字符串
        int len=numstirng.size();   
        vector<int>dp(len+1, 0);
        // 当前两个数字能组合翻译时，dp[2] = dp[1] + dp[0],
        // 结果应该是2，dp[1]已知等于1，所以dp[0]也等于1
        // 如果前2个数不能组合翻译时，那么dp[2]=dp[1]
        dp[0]=1;
        dp[1]=1;
         /*
        注意：这个循环的i代表的是动态规划数组的索引
        也就是说，i表示的是数字字符串中第i-1个数字
        因为第一个数字明显只有一种翻译方法，所以从第二个数字开始遍历字符串
        */
        for(size_t i = 2;i < dp.size(); ++i)
        {
            /*
            判断当前遍历到的数字（索引i-1）能否和前一个数字（索引i-2）组合起来翻译
            只有当两个数字组合起来在[10,25]区间时才可以一起翻译
            */
            int curdigit=numstirng[i-1]-'0';
            int prevdigit=numstirng[i-2]-'0';
            int combine=curdigit+prevdigit*10;
            if(combine >= 10 && combine <= 25)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1];
            }
        }
        // 动态规划数组最后一个元素即是整个数字的所有翻译方法个数
        return dp[len];
    }
};
