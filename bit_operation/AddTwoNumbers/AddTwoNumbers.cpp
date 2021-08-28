#include<iostream>
using namespace std;

/*剑指 Offer 65. 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则
示例:
输入: a = 9, b = 1
输出: 10
*/


class Solution 
{
public:
    //先用^异或得到没有进位的数的结果
    //再用&位与运算得到产生进位的位置，再将其左移使其移动到进位的位置。此时得到的两个数
    //将其分别赋值给a与b
    int add(int a, int b) 
    {
        int carry;
        int Sum;
        while(b!=0)
        {
            Sum=a^b;
            carry=static_cast<size_t>(a&b)<<1;
            a=ret;
            b=carry;
        }
        return a;
    }
};


int main()
{
  return 0;
}
