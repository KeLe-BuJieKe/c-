/*
1.请声明一个指针，其所指向的内存地址不能改变，但内存中的值可以被改变。( B  )
A const int const *x = &y;
B int * const x = &y;
C const int *x = &y;
D int const *x = &y;
E const int * const x = &y; 
答：题目要求所指向的地址不能改变，但内存的值可以被改变。说明叫你声明一个指针常量

2.以下说法中正确的是（ B ）。
A C++程序中的main()函数必须放在程序的开始部分
B C++程序的入口函数是main函数
C 在C++程序中，要调用的函数必须在main()函数中

3.下面哪个指针表达式可以用来引用数组元素a[i][j][k][l]( B  )
A (((a+i)+j)+k)+l)
B *(*(*(*(a+i)+j)+k)+l)
C (((a+i)+j)+k+l)
D D ((a+i)+j+k+l)

4.fun(21)运行结果是( A )
int fun(int a){
  a^=(1<<5)-1;
  return a;
}
A 10
B 5
C 3
D 8

5.以下程序的输出结果是：( A )
#include <iostream>
using namespace std;
void func(char** m) {
    ++m;
    cout << *m << endl;
}
int main() {
    static char* a[] = { "morning", "afternoon", "evening" };
    char** p;
    p = a;
    func(p);
    return 0;
}
A afternoon
B 字符o的起始地址
C 字符o
D 字符a的起始地址


6.下面对析构函数的正确描述是：( C )
A 系统不能提供默认的析构函数
B 析构函数必须由用户定义
C 析构函数没有参数
D 析构函数可以设置默认参数

7.某函数申明如下：
void Func(int &nVal1);
有int a,下面使用正确的为：( A )
A Func(a)
B Func(&a)
C Func(*a)
D Func(&(*a))


8.当一个类的某个函数被说明为virtual，则在该类的所有派生类中的同原型函数_ D____?
A 只有 被重新说明时才识虚函数
B 只有被重新说明为virtual时才是虚函数
C 都不是虚函数
D 都是虚函数


9.有如下程序：
#include<iostream>
using namespace std;
class MyClass {
public:
    MyClass(int i = 0) { cout << 1; }
    MyClass(const MyClass& x) { cout << 2; }
    MyClass& operator=(const MyClass& x) { cout << 3; return*this; }
    ~MyClass() { cout << 4; }
};
int main() {
    MyClass obj1(1), obj2(2), obj3(obj1);
    return 0;
}
运行时的输出结果是( B )
A 121,444
B 112,444
C 11,114,444
D 11,314,445
E 11,314,444

10.代码执行后，a和b的值分别为?( A )
class Test {
public:
    int a;
    int b;
    virtual void fun() {}
    Test(int temp1 = 0, int temp2 = 0)
    {
        a = temp1;
        b = temp2;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};
int main()
{
    Test obj(5, 10);
    // Changing a and b
    int* pInt = (int*)&obj;
    *(pInt + 0) = 100;
    *(pInt + 1) = 200;
    cout << "a = " << obj.getA() << endl;
    cout << "b = " << obj.getB() << endl;
    return 0;
}
A 200 10
B 5 10
C 100 200
D 100 10




11.标题：另类加法 | 时间限制：3秒 | 内存限制：32768K | 语言限制： [Python, C++, C#, Java]
【另类加法】
给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。
测试样例：
1,2
返回：3


//利用 ^ 来得到两个数加的为进位的部分
//再利用&来得到进位的部位，然后再向左移得到进位后的部分的结果

class UnusualAdd {
public:
    int addAB(int A, int B) {
        int ret;  //不管进位的加的部分
        int carry; //只有进位的部分
        while (B != 0)
        {
            ret = A ^ B;
            carry = static_cast<int>(A & B) << 1;
            A = ret;
            B = carry;
        }
        return ret;
    }
};


12.标题：走方格的方案数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【走方格的方案数】
请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往
下走，不能往左和往上走。
本题含有多组样例输入。
输入描述：
输入两个正整数
输出描述：
返回结果
示例1：
输入
2
2
输出
6


//运用动态规划dp[i][j]的方案数等于dp[i-1][j]与dp[i][j-1]的值的和
#include<iostream>
#include<vector>
using namespace std;
int planNum(int& n, int& m)
{
    if (n == 0 || m == 0)
    {
        return 1;
    }
    vector<vector<int>>arr(n + 1, vector<int>(m + 1, 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[n][m];
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << planNum(n, m) << endl;
    }
    return 0;
}
*/
