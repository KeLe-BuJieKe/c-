/*1.十进制变量i的值为100，那么八进制的变量i的值为:( C  )
A 146
B 148
C 144
D 142
答：100/8=12  100%8=4  12个10 然后在封8进1，然后就144

2.有一个如下的结构体：
struct A{
	long a1;
	short a2;
	int a3;
	int *a4;
};
请问在64位编译器下用sizeof(struct A)计算出的大小是多少？( A )
A 24
B 28
C 16
D 18
答：考察结构体内存对齐，然后是64位int*类型是8个字节了

3.对于下面的C语言声明描述正确的一项是( C )
char (*p)[16];

A p是长度为16的字符指针数组
B p是包含16个字符的字符串
C p是指向长度为16的字符数组的指针
D p是长度为16的字符数组

4.有以下程序
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int m=0123, n = 123;
	printf("%o %o\n", m, n);
	return 0;
}
程序运行后的输出结果是( C  )
A 0123 0173
B 0123 173
C 123 173
D 173 173
答：这题考察的是十进制转八进制，m由于赋值的时候就是用八进制赋值的，所以以八进制打印自然也是123
n的话，由于赋值的时候是以十进制赋值的，然后在以八进制打印，123/8=15 123%8=3  然后15个10也就是170+3=173

5.以下程序运行时，若输入1abcedf2df<回车>输出结果是？( C  )
#include<stdio.h>
int main()
{
  char a=0,ch;
  while((ch=getchar())!='\n')
  {
    if(a%2!=0&&(ch>= 'a' &&ch<='z'))
    ch=ch- 'a'+ 'A';
    a++;
    putchar(ch);
  }
  printf( "\n");
}

A 1abcedf2df
B 1ABCEDF2DF
C 1AbCeDf2dF
D 1abceDF2DF
答：这题考察getchar函数以及英文字母的大小转换。

6.关于内联函数说法错误的是:( C )
A 不是任何一个函数都可定义成内联函数
B 内联函数的函数体内不能含有复杂的结构控制语句
C 递归函数可以被用来作为内联函数
D 内联函数一般适合于只有1~5行语句的小函数

7.关于"深拷贝"，下列说法正确的是( A  )
A 会拷贝成员数据的值和会拷贝静态分配的成员对象
B 只会拷贝成员数据的值
C 只会拷贝静态分配的成员对象
D 只会拷贝动态分配的成员对象

8.若要对data类中重载的加法运算符成员函数进行声明，下列选项中正确的是？( A  )
A Data operator+(Data);
B Data operator(Data);
C operator+(Data,Data);
D Data+(Data);

9.有以下程序运行结果为:( D  )
#include<iostream>
using namespace std;
char fun(char x, char y) 
{
  if (x < y)
    return x;
  else
   return y;
}
int main() 
{
  int a = '1', b = '1', c = '2';
  cout << fun(fun(a, b), fun(b, c));
  return 0;
}

A 运行出错
B 2
C 3
D 1

10.#include <iostream>
using namespace std;
int f(int n)
{
  if (n==1)
    return 1;
  else
    return (f(n-1)+n*n*n);
}
int main()
{
  int s=f(3);
  cout<<s<<endl;
  return 0;
}
运行结果是？( D  )
A 8
B 9
C 27
D 36


11.标题：不要二 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【不要二】二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能
等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
输入描述：
每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
输出描述：
输出一个最多可以放的蛋糕数
示例1：
输入
3 2
输出
4

#include<iostream>
#include<vector>
using namespace std;
bool ispushcake(const vector<vector<bool>>& arr, int& x, int& y, int& W, int& H)
{
    if (x - 2 >= 0 && arr[x - 2][y] != false)
    {
        return false;
    }
    if (x + 2 < W && arr[x + 2][y] != false)
    {
        return false;
    }
    if (y - 2 >= 0 && arr[x][y - 2] != false)
    {
        return false;
    }
    if (y + 2 < H && arr[x][y + 2] != false)
    {
        return false;
    }
    return true;
}
int main()
{
    int W;
    int H;
    cin >> W >> H;
    vector<vector<bool>>arr(W, vector<bool>(H, false));
    int count = 0;
    for (int i = 0; i < W; ++i)
    {
        for (int j = 0; j < H; ++j)
        {
            if (ispushcake(arr, i, j, W, H) == true)
            {
                ++count;
                arr[i][j] = true;
            }
        }
    }
    cout << count;
    return 0;
}

12.标题：把字符串转换成整数 | 时间限制：1秒 | 内存限制：65536K | 语言限制： [Kotlin, Typescript, Python, C++, Groovy, Rust, C#, Java, Go, Scala, Javascript,
Ruby, Swift, Php, Python 3]
【把字符串转换成整数】将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
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
*/
