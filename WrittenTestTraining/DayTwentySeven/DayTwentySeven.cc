/*
1.若一个用户进程通过read 系统调用读取一个磁盘文件中的数据，则下列关于此过程的叙述中，正确的是（ A ）。
Ⅰ． 若该文件的数据不在内存中，则该进程进入睡眠等待状态
Ⅱ． 请求 read 系统调用会导致 CPU 从用户态切换到核心态
Ⅲ． read 系统调用的参数应包含文件的名称
A 仅Ⅰ、 Ⅱ
B 仅Ⅰ、 Ⅲ
C 仅Ⅱ、 Ⅲ
D Ⅰ、 Ⅱ和Ⅲ


2.下列关于虚拟存储的叙述中，正确的是（ B ）。
A 虚拟存储只能基于连续分配技术
B 虚拟存储只能基于非连续分配技术
C 虚拟存储容量只受外存容量的限制
D 虚拟存储容量只受内存容量的限制

解析：装入程序时，只将程序的一部分装入内存，而将其余部分留在外存，就可以启动程序执行。
采用连续分配方式，会使相当一部分内存空间都处于暂时或“永久”的空闲状态，造成内存资源的严重浪费，
也无法从逻辑上扩大内存容量，因此虚拟内容的实现只能建立在离散分配的内存管理的基础上。
虚拟存储器容量既不受外存容量限制，又不受内存容量限制，而是由CPU的寻址范围决定的。


3.下列选项中，不可能在用户态发生的事件是（ C ）。
A 系统调用
B 外部中断
C 进程切换
D 缺页

解析：A：系统调用：pipe函数创建匿名管道
      B：外部中断：例如进程再运行的时候，ctrl+c、中断程序等
      C：进程切换：进程的切换是由操作系统内核来调度产生的，所以再用户态是不会发生的。
      D：缺页：访问某一块内存的时候，有可能导致缺页现象


4.在虚拟内存管理中，地址变换机构将逻辑地址变为物理地址，形成该逻辑地址的阶段是（ C ）。
A 编辑
B 编译
C 链接
D 装载


5.在缺页处理过程中，操作系统执行的操作可能是（ D ）。
Ⅰ．修改页表 Ⅱ．磁盘 I/O Ⅲ．分配页框
A 仅Ⅰ、 Ⅱ
B 仅Ⅱ
C 仅Ⅲ
D Ⅰ、 Ⅱ和Ⅲ

解析:缺页中断处理过程中，要调入新页面，肯定要分配页框和修改页表项，所以Ⅰ、Ⅲ可能发生；
同时要访问的页面不在内存，需要从外存读入，会发生磁盘I/O，所以Ⅱ会发生


6.下面选项中，满足短任务优先且不会发生饥饿现象的调度算法是（ B ）。
A 先来先服务
B 高响应比优先
C 时间片轮转
D 非抢占式短任务优先


7.下列选项中，降低进程优先级的合理时机是( A )
A 进程的时间片用完
B 进程刚完成I/O，进入就绪列队
C 进程持久处于就绪列队
D 进程从就绪状态转为运行态


8.在使用锁保证线程安全时，可能会出现活跃度失败的情况，活跃度失败主要包括( D )
A 死锁
B 饥饿
C 活锁
D 以上全部

解析：活跃度是指线程或进程长时间得不到CPU占用
仔使用锁保证现场安全时可能会出现活跃度失败得情况主要包括解饿、活锁、死锁等

9.下列选项中，导致创建新进程的操作是( C )
I用户登陆成功II设备分配III启动程序执行
A 仅I和II
B 仅II和III
C 仅I和III
D I、II和III


10.对进程和线程的描述,以下正确的是( D )
A 父进程里的所有线程共享相同的地址空间,父进程的所有子进程共享相同的地址空间
B 改变进程里面主线程的状态会影响到其他线程的行为,改变父进程的状态不会影响到其他子进程
C 多线程会引起死锁,而多进程不会
D 以上选项都不正确


11.标题：不用加减乘除做加法 | 时间限制：1秒 | 内存限制：65536K | 语言限制： [Kotlin, Typescript, Python, C++, Groovy, Rust, C#, Java, Go, Scala, Javascript,
Ruby, Swift, Php, Python 3]
【不用加减乘除做加法】
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
数据范围：两个数都满足 0 <= n <= 100
进阶：空间复杂度 O(1) 时间复杂度O(1)

class Solution 
{
public:
    int Add(int num1, int num2) 
    {
        int carry=0;
        int ret=0;
        while(num2!=0)
        {
            ret=num1^num2;
            carry=(num1&num2)<<1;
            num1=ret;
            num2=carry;
        }
        return num1;
    }
};


12.标题：三角形 | 时间限制：1秒 | 内存限制：32768K | 语言限制：不限
给定三条边，请你判断一下能不能组成一个三角形。
收起 
输入描述:
输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。
输出描述:
对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。
示例1
输入
1 2 3
2 2 2
输出
No
Yes


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//方法一：
int main()
{
    //1、由于输入的a、b、c的范围为1~10^100故普通的int、long、long long 已经存储不下了
    //这里我们可以改用double,而double的范围最大可以表示到10^308左右
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a+b>c&&a+c>b&&b+c>a)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

//方法二
//该题本质我认为考察的其实是大数相加
int GetCarry(int num)
{
    int carry=0;
    carry=num/10;
    return carry;
}

string strAdd(string &str1, string &str2)
{
    string ret;

    int i=str1.size()-1;
    int j=str2.size()-1;
    int carry=0;
    
    int temp=0;
    while(i>=0&&j>=0)
    {
        temp=carry+str1[i]+str2[j]-2*'0';
        ret.push_back(temp%10+'0');
        carry=GetCarry(temp);
        --i;
        --j;
    }
    while(i>=0)
    {
        temp=(str1[i]-'0')+carry;
        carry=GetCarry(temp);
        ret.push_back(temp%10+'0');
        --i;
    }
    while(j>=0)
    {
        temp=(str2[j]-'0')+carry;
        carry=GetCarry(temp);
        ret.push_back(temp%10+'0');
        --j;
    }
    if(carry!=0)
    {
        ret.push_back(carry+'0');
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

bool strCompare(string str1,string str2)
{
    if(str1.size()>str2.size())
    {
        return  true;
    }
    else if(str1.size()<str2.size())
    {
        return false;
    }
    else
    {
        return str1>str2;
    }
}

int main()
{
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        if( strCompare(strAdd(a, b), c) 
           &&( strCompare(strAdd(a, c), b))
           &&( strCompare(strAdd(b,c),a) ) )
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
*/

