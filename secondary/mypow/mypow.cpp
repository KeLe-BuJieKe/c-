#include<iostream>
using namespace std;


/*实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。*/

class Solution 
{
public:
    double _mypow(double x, long n)
    {
        if(n==0)
        {
            return static_cast<double>(1);
        }
        if(n==1)
        {
            return x;
        }
        //    {a^(n/2) * a^(n/2)        n为偶数时
        //a^n={
        //    {a^(n/2) * a^(n/2) * a    n为奇数时
        double val=myPow(x,n>>1);   //得到每一半的数
        val*=val;                   //再将每一半的数相乘
        //虽然%运算符也可以判断奇偶性，但是效率没有 位与&运算符效率更高
        if(n&0x1==1)                //判断是奇数还是偶数，奇数二进制的最右边一位一定是1，偶数是0
        {
            val*=x;
        }
        return val;
    }
    double myPow(double x, int n) 
    {
        long exp=static_cast<long>(n);
        if(n<0)
        {
            x=1/x;
            exp*=-1;
        }
        double val=_mypow(x,exp);
        return val;
    }
};


int main()
{
  return 0;
}
