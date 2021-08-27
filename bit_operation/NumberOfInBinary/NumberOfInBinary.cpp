#include<iostream>
using namespace std;


//方法一：如果形参是有符号且是负数时，会造成死循环
class Solution1 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int size=0;
        while(n)
        {
            
            if(n&0x1==1)
            {
                 ++size;

            }
            n>>=1;
        }
        return size;
    }
};

//方法二：
class Solution2 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int size=0;
        size_t flag=1;
        while(flag)
        {
            if(n&flag)
            {
                 ++size;
            }
            flag<<=1;
        }
        return size;
    }
};


//方法三：
class Solution3 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int size=0;
        while(n)
        {
            ++size;
            n=n&(n-1);
        }
        return size;
    }
};

int main()
{
  return 0;
}
