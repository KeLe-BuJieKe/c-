#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

/*标题：把字符串转换成整数 | 时间限制：1秒 | 内存限制：65536K | 
【把字符串转换成整数】将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0
输入描述：
输入一个字符串,包括数字字母符号,可以为空
输出描述：
如果是合法的数值表达则返回该数字，否则返回0
示例1：
输入
+2147483647
1a33
输出
2147483647
0

*/
class Solution
{
public:
    int StrToInt(string str)
    {
        int size = static_cast<int>(str.size());
        if (size == 0)
        {
            return 0;
        }
        int flag = 1;
        int i = 0;
        if (str[i] == '-')
        {
            flag = -1;
            ++i;
        }
        else if (str[i] == '+')
        {
            flag = 1;
            ++i;
        }
        int ret = 0;
        for (; i < size; ++i)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
            else
            {
                if ((ret == INT_MAX / 10 && (str[i] - '0') > (INT_MAX % 10))
                    || (ret == INT_MIN / 10 && (str[i] - '0') > (INT_MAX % 10) + 1))
                {
                    return 0;
                }
                ret = ret * 10 + (str[i] - '0') * flag;
            }
        }
        return ret;
    }
};

int main()
{
  return 0;
}
