/*
1.以下代码
char *ptr;
char myString[] = "abcdefg";
ptr = myString;
ptr += 5;
代码执行之后ptr指向的内容是？( B )
A Compiler error
B f
C efg
D defg


2.已知int a[]={1,2,3,4,5}；int*p[]={a,a+1,a+2,a+3}；int **q=p；表达式*(p[0]+1)+**(q+2)的值是_A___。
A 5
B 6
C 7
D 8
E 4
F 9


3.以下代码的输出结果是？( D )
char *p="abc";
char *q="abc123";
while(*p=*q)
print("%c %c",*p,*q);

A aabbcc
B aabbcc123
C abcabc123
D 代码段错误


4.假设在一个 32 位 little endian 的机器上运行下面的程序，结果是多少？( B )
#include <stdio.h>
int main() {
    long long a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);
    return 0;
}
A 1,2,3
B 1,0,2
C 1,3,2
D 3,2,1

答：由于是一个小端机，假设左边是低地址，右边是高地址，那么存储模式如下
03 00 00 00
02 00 00 00
01 00 00 00
然后printf是从右往左传参的
然后是以%d来打印的，所以每次取4个字节来打印，即先取前4个字节01 00给a，在取00 00给b，最后在将02 00 给c


5.下列给定程序中，函数fun的功能是:求ss所指字符串数组中长度最短的字符串所在的行下标，作为函数值返回，并把其串长放在形参n所指的变量中。ss所指字符串
数数组中共有M个字符串，且串长小于N。
请在程序的下画线处填入正确的内容并将下画线删除，使程序得出正确的结果。( C )
试题程序。
#define M 5
#define N 20
int fun(char(*ss)[N], int* n)
{
    int i, k = 0, len = N;
    for (i = 0; i < ______; i++)
    {
        len = strlen(ss[i]);
        if (i == 0)
            *n = len;
        if (len ____ * n)
        {
            *n = len;
            k = i;
        }
    }
    return (_____);
}
main()
{
    char ss[M][N] = { "shanghai", "guangzhou", "beijing", "tianjing", "chongqing" };
    int n, k, i;
    printf("\nThe originalb stringsare:\n");
    for (i = 0; i < M; i++)
        puts(ss[i]);
    k = fun(ss, &n);
    printf("\nThe length of shortest string is: % d\n", n);
    printf("\nThe shortest string is: % s\n", ss[k]);
}

A N，< ，k
B N， >，k
C M，<，k
D M，>，k


6.调用一成员函数时, 使用动态联编的情况是？( B )
A 通过对象调用一虚函数
B 通过指针或引用调用一虚函数
C 通过对象调用静态函数
D 通过指针或应用调用一静态函数


7.如何捕获异常可以使得代码通过编译？( B )
class A {
public:
    A() {}
};
void foo() {
    throw new A;
}

A catch (A && x)
B catch (A * x)
C catch (A & x)
D 以上都是


8.下列代码可以通过编译吗？如何修改使其通过编译？( C )
template <class T>
struct sum {
    static void foo(T op1, T op2) {
        cout << op1 << op2;
    }
};
sum::foo(1, 3);

A 编译通过
B 应该去掉static关键字
C 调用应该如下： sum<int>:: foo(1,3)
D 调用应该如下： sum:: <int>foo(1,3)


9.下面这段程序的输出是什么?( D )
class A {
public:
    A() { p(); }
    virtual void p() { print("A") }
    virtual ~A() { p(); }
};
class B :public A {
public:
    B() { p(); }
    void p() { print("B") }
    ~B() { p(); }
};
int main(int, char**) {
    A* a = new B();
    delete a;
}

A AABB
B BBAA
C ABAB
D ABBA


10.有如下程序段：
#include <iostream>
using namespace std;
class A {
public:
    ~A() {
        cout << "~A()";
    }
};
class B {
public:
    virtual ~B() {
        cout << "~B()";
    }
};
class C : public A, public B {
public:
    ~C() {
        cout << "~C()";
    }
};
int main() {
    C* c = new C;
    B* b1 = dynamic_cast<B*>(c);
    A* a2 = dynamic_cast<A*>(b1);
    delete a2;
}


则程序输出：( D )
A ~C()~B()~A()
B ~C()~A()~B()
C A)B)都有可能
D 以上都不对



11.标题：杨辉三角的变形 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【杨辉三角的变形】
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
数据范围：1<=N<=10^9
本题有多组输入数据
输入描述：
输入一个int整数
输出描述：
输出返回的int值
示例1：
输入
4
输出
3

*/
