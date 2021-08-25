#include<iostream>
using namespace std;

/*求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。*/

//c++ 方法一：利用构造函数

class Solution1
{
public:
    static int temp;
    static int sum;

    Solution1()
    {
        ++temp;
        sum+=temp;
    }
    static void again()
    {
        temp=0;
        sum=0;
    }
    int sumNums(int n) 
    {
        again();    //这里是为了防止它创建一个对象时，会自动的调用构造函数，从而导致多加了一次错误
                    //并且在多次调用得到不同的n对应的sum的时候会出错。在这里我们要防止这种情况
        Solution1*arr=new Solution1[n];
        delete[] arr;
        return sum;
    }
};
int Solution1::temp=0;
int Solution1::sum=0;




//方法二：利用虚函数来求解

class A;
A*arr[2];

class A
{
public:
    virtual int sum(int n)
    {
        return 0;
    }
};

class B:public A
{
public:
    virtual int sum(int n)
    {
        return n+arr[!!n]->sum(n-1);
    }
};
class Solution2 
{
public:
    int sumNums(int n) 
    {
        A a;
        B b;
        arr[0]=&a;
        arr[1]=&b;
        int ret=arr[1]->sum(n);
        return ret;
    }
};



//方法三：纯C代码，利用函数指针与函数指针数组

int temp1(int n)
{
    return 0;
}

int temp2(int n)
{
    int (*pf[2])(int)={temp1,temp2};
    return n+pf[!!n](n-1);
}

class Solution3 
{
public:
    int sumNums(int n) 
    {
        return temp2(n); 
    }
};


int main()
{
  return 0;
}
