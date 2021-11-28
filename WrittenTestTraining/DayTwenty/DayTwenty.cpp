/*
1.对于顺序存储的线性表，访问结点和增加结点的时间复杂度为（ C）。
A.O(n) O(n)
B.O(n) O(1)
C.O(1) O(n)
D.O(1) O(1)


2.若栈采用顺序存储方式存储，现两栈共享空间V[1..m]，top[i]代表第i个栈( i =1,2)栈顶，栈1的底在v[1]，栈2的底在V[m]，则栈满的条件是（ B ）。
A.top[1]+top[2]=m
B.top[1]+1=top[2]
C.top[2]-top[1]|=0
D.top[1]=top[2]


3.下述有关栈和队列的区别，说法错误的是？( D )
A.栈是限定只能在表的一端进行插入和删除操作。
B.队列是限定只能在表的一端进行插入和在另一端进行删除操作。
C.栈和队列都属于线性表
D.栈的插入操作时间复杂度都是o(1)，队列的插入操作时间复杂度是o(n)


4.从前有座山，山里有座庙，庙里有个老和尚，再给小和尚讲故事，故事内容是：从前有座山，山里有座庙，庙里有个老和尚，再给小和尚讲故事，故事内容是：
从前有座山，山里有座庙，庙里有个老和尚，再给小和尚讲故事，故事内容是……描述的(E)

A.贪心
B.回溯
C.穷举
D.分治
E.递归
答：递归指的是一个过程：函数不断引用自身，直到引用的对象已知。



5.某二叉树共有 399 个结点，其中有 199 个度为 2 的结点，则该二叉树中的叶子结点数为（ B ）
A.不存在这样的二叉树
B.200
C.198
D.199
根据二叉树的基本性质，对任何一棵二叉树，度为 0 的结点（即叶子结点）总是比度为 2 的结点多一个。题目中度为 2 的结点为 199 个，则叶子结点为 199+1=200 。故本题答案为 B 选项。


6.某二叉树的前序遍历序列与中序遍历序列相同，均为 ABCDEF ，则按层次输出（同一层从左到右）的序列为（ A）
A.ABCDEF
B.BCDEFA
C.FEDCBA
D.DEFABC
答：二叉树遍历可以分为 3 种：前序遍历（访问根结点在访问左子树和访问右子树之前）、中序遍历（访问根结点在访问左子树和访问右子树两者之间）、
后序遍历（访问根结点在访问左子树和访问右子树之后）。
二叉树的中序遍历序列和前序遍历序列均为 ABCDEF ，可知该树只有右子树结点，没有左子树结点， A 为根结点。
中序遍历序列与前序遍历序列相同说明该树只有右子树没有左子树，因此该树有 6 层，从顶向下从左向右依次为 ABCDEF 。故本题答案为 A 选项。


7.初始序列为1 8 6 2 5 4 7 3一组数采用堆排序，当建堆（小根堆）完毕时，堆所对应的二叉树中序遍历序列为：（ A）
A.8 3 2 5 1 6 4 7
B.3 2 8 5 1 4 6 7
C.3 8 2 5 1 6 7 4
D.8 2 3 5 1 4 7 6
答：堆排序：利用堆的性质进行的一种选择排序 答案：A


8.解决散列法中出现冲突问题常采用的方法是_D___。
A.数字分析法、除余法、平方取中法
B.数字分析法、除余法、线性探测法
C.数字分析法、线性探测法、多重散列法
D.线性探测法、多重散列法、链地址法
答：数字分析法、除余法、平方取中法都是常见的哈希函数
线性探测法、多重散列法、链地址法才是解决哈希冲突的常用方法


9.以下哪种排序算法对(1,3,2,4,5,6,7,8,9)进行的排序最快？( A )
A.冒泡
B.快排
C.归并
D.堆排


10.设无向图的顶点个数为n，则该图最多有多少条边？( C )
A.n-1
B.n（n+1）/2
C.n（n-1）/2
D.n
E.不同于以上答案




11.标题：字符串反转 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【字符串反转】
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
输入描述：
输入一行，为一个只包含小写字母的字符串。
输出描述：
输出该字符串反转后的字符串。
示例1：
输入
abcd
输出
dcba

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}





12.标题：公共子串计算 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【公共子串计算】
给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。
注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
数据范围：字符串长度：1<=s<=150
进阶：时间复杂度：时间复杂度O(n^3)  空间复杂度O(n)
输入描述：
输入两个只包含小写字母的字符串
输出描述：
输出一个整数，代表最大公共子串的长度
示例1：
输入
asdfas werasdfaswer
输出
6




方法一：利用KMP来暴力求解 时间复杂度O(n^3)  空间复杂度O(n)
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void GetNext(vector<int>& next, const string& s)
{
    next[0] = -1; //这个肯定是没有匹配的，这个是匹配的空字符串了，相当于没有匹配，没有匹配就随便设置一个数咯
    next[1] = 0; //显而易见的第一个匹配失败了就去回溯到0号下标
    int Ssize = static_cast<int>(s.size());

    int i = 1;
    int k = 0;
    while (i < Ssize - 1)
    {
        if (k == -1 || s[i] == s[k]) //相等就找真子串
        {
            next[i + 1] = k + 1;
            ++i;
            ++k;
        }
        else //如果t[i]!t[k],那么k我们就一直回溯
        {
            k = next[k];
        }
    }
}

bool KMP(string& t, string& s)
{
    
    int Tsize = static_cast<int>(t.size());
    int Ssize = static_cast<int>(s.size());
    if(Tsize==0||Ssize==0)
    {
        return false;
    }
    if (Ssize > Tsize)
    {
        return false;
    }
    int i = 0, j = 0;
    vector<int>next(Ssize+1);
    GetNext(next, s);
    while (i < Tsize && j < Ssize)
    {
        if (j == -1 || t[i] == s[j])
        {
            ++j;
            ++i;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= Ssize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    string t;
    int ret=0;
    cin >> s >> t;
    
    for (size_t i = 0; i <= s.size(); ++i)
    {
        for (size_t j = i + 1; j <= s.size(); ++j)
        {
            string str = s.substr(i, j - i);
            if (KMP(t, str))
            {
                int size = static_cast<int>(str.size());
                if (size > ret)
                {
                    ret = size;
                }
             }
         }
    }
    cout << ret << endl;
    return 0;
}



方法二：动态规划，时间复杂度O(n^2)  空间复杂度O(n^2)但可以优化到O(n)
nclude<iostream>
#include<string>
#include<vector>
using namespace std;

int GetMinSubStr(const string & str1, const string & str2)
{
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    vector<vector<int>> dp(len1 + 1 ,vector<int>(len2 + 1,0));
    
    int ret=0;
    for(size_t i = 1; i <= len1; ++i)
    {
        for(size_t j = 1; j <= len2; ++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;

                ret=max(dp[i][j],ret);
            }
        }
    }
    return ret;
}

int main()
{
    string str1;
    string str2;
    int ret=0;
    cin >> str1 >> str2;
    cout<<GetMinSubStr(str1, str2)<<endl;
    return 0;
}


*/
