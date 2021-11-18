/*
1.在嵌套使用if语句时，C语言规定else总是__C____。
A 和之前与其具有相同缩进位置的if配对
B 和之前与其最近的if配对
C 和之前与其最近的且不带else的if配对
D 和之前的第一个if配对


2.以下系统中，int类型占几个字节，指针占几个字节，操作系统可以使用的最大内存空间是多大：( C )
A 32位下：4,4,2^32 64位下：8,8,2^64
B 32位下：4,4,不限制 64位下：4,8,不限制
C 32位下：4,4,2^32 64位下：4,8,2^64
D 32位下：4,4,2^32 64位下：4,4,2^64

3.以下程序的输出结果是__C____。
#include <stdio.h>
int main()
{
    int i, a[10];
    for (i = 9; i >= 0; i--) a[i] = 10 - i;
    printf("%d%d%d", a[2], a[5], a[8]);
    return 0;
}
A 258
B 741
C 852
D 369

4.下面C程序的输出结果:( A )
int i = 0, a = 1, b = 2, c = 3;
i = ++a || ++b || ++c;
printf("%d %d %d %d", i, a, b, c);

A 1 2 2 3
B 1 2 3 4
C 3 2 3 4
D 3 3 3 4
答:先判断a，但在此之前a要先++，a就变为了2，然后就为true了，然后由于后面两个都是||,b和c就不会判断,也不会改变
故a=2，b=2,c=3,i=1

5.下面代码不能正确输出hello的选项为( B )
nclude<stdio.h>
struct str_t 
{
    long long len;
    char data[32];
};
struct data1_t 
{
    long long len;
    int data[2];
};
struct data2_t 
{
    long long len
        char* data[1];
};
struct data3_t 
{
    long long len;
    void* data[];
};
int main(void)
{
    struct str_t str;
    memset((void*)&str, 0, sizeof(struct str_t));
    str.len = sizeof(struct str_t) - sizeof(int);
    snprintf(str.data, str.len, "hello");//VS下为_snprintf
    ____________________________________;
    ____________________________________;
    return 0;
}
A struct data3_t *pData=(struct data3_t*)&str; printf("data:%s%s\n",str.data,(char*)(&(pData->data[0])));
B struct data2_t *pData=(struct data2_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data[0]));
C struct data1_t *pData=(struct data1_t*)&str;printf("data:%s%s\n",str.data,(char*)(pData->data));
D struct str_t *pData=(struct str_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data));

答：为什么B不行呢？
因为data2_t的这个结构体的大小是小于str_t这个类的结构体大小的，故强转过去会有部分的值给丢失了


6.哪个操作符不能被重载?( C )
A , (逗号)
B ()
C . (点)
D []
E ->


7.下列对重载函数的描述中，_______A_____是错误的。
A 重载函数中不允许使用默认参数
B 重载函数中编译时根据参数表进行选择
C 构造函数重载将会给初始化带来多种方式
D 不要使用重载函数来描述毫无相干的函数

8.下列关于多态性说法不正确的是（ B ）。
A 多态性是指同名函数对应多种不同的实现
B 重载方式仅有函数重载
C 重载方式包含函数重载和运算符重载
D 多态性表现为静态和动态两种方式


9.分析一下这段程序的输出( A )
#include<iostream>
using namespace std;
class B
{
public:
    B()
    {
        cout << "default constructor" << " ";
    }
    ~B()
    {
        cout << "destructed" << " ";
    }
    B(int i) : data(i)
    {
        cout << "constructed by parameter" << data << " ";
    }
private: int data;
};
B Play(B b)
{
    return b;
}
int main(int argc, char* argv[])
{
    B temp = Play(5);
    return 0;
}

A constructed by parameter5 destructed destructed
B constructed by parameter5 destructed
C default constructor" constructed by parameter5 destructed
D default constructor" constructed by parameter5 destructed destructed

10.求输出结果( B )
#include <iostream>
using namespace std;
class A
{
public:
    virtual void print()
    {
        cout << "A::print()" << "\n";
    }
};
class B : public A
{
public: virtual void print()
{
    cout << "B::print()" << "\n";
}
};
class C : public A
{
public: virtual void print()
{
    cout << "C::print()" << "\n";
}
};
void print(A a)
{
    a.print();
}
int main()
{
    A a, * aa, * ab, * ac;
    B b;
    C c;
    aa = &a;
    ab = &b;
    ac = &c;
    a.print();
    b.print();
    c.print();
    aa->print();
    ab->print();
    ac->print();
    print(a);
    print(b);
    print(c);
}

A C::print() B::print() A::print() A::print() B::print() C::print() A::print() A::print() A::print()
B A::print() B::print() C::print() A::print() B::print() C::print() A::print() A::print() A::print()
C A::print() B::print() C::print() A::print() B::print() C::print() B::print() B::print() B::print()
D C::print() B::print() A::print() A::print() B::print() C::print() C::print() C::print() C::print()


11.标题：参数解析 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【参数解析】
在命令行输入如下命令：
xcopy /s c:\\ d:\\e，
各个参数如下：
参数1：命令字xcopy
参数2：字符串/s 
参数3：字符串c:\\
参数4: 字符串d:\\e 请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则：
1.参数分隔符为空格
2.对于用""包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s "C:\\program files" "d:\"时，参数仍然是4个，第3个参数应该是
字符串C:\\program files，而不是C:\\program，注意输出参数时，需要将""去掉，引号不存在嵌套情况。
3.参数不定长
4.输入由用例保证，不会出现不符合要求的输入
数据范围：字符串长度：1<=s<=1000
进阶：时间复杂度O(n),空间复杂度O(n)
输入描述：
输入一行字符串，可以有空格
输出描述：
输出参数个数，分解后的参数，每个参数都独占一行
示例1：
输入
xcopy /s c:\\ d:\\
输出
4
xcopy
/s
c:\\
d:\\

#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    queue<string>q;
    string temp;
    bool flag = false;
    for (int i = 0; i <= str.size(); ++i)
    {
        if (str[i] == '"')
        {
            flag = !flag;
            continue;
        }
        if (flag == false && str[i] == ' ')
        {
            q.push(temp);
            temp.clear();
        }
        else
        {
            temp += str[i];
        }
    }
    q.push(temp);
    int size = static_cast<int>(q.size());
    cout << size << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}


12.标题：跳石板 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【跳石板】小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身
的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述：
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 10)
输出描述：
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1：
输入
4 24
输出
5



#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int>dp(M + 1, INT_MAX); //大小为m+1，初始赋值为最大值
    dp[N] = 0; //n到n为0步
    for (int i = N; i <= M; ++i)
    {
        if (dp[i] == INT_MAX) //如果当前点不可到达，则跳过本次循环
        {
            continue;
        }
        for (int j = 2; j <= sqrt(i); ++j)     //找到从i这个位置的数的约数，然后加上这个约数看能到的那个数
        {
            if (i % j == 0) //说明j为i的约数
            {
                if (i + j <= M) //修改第一个加约数后的位置，说明该位置可以到达
                {
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                }
                if ((i + i / j) <= M) //修改第二个加约数后的位置，说明该位置可以到达
                {
                    dp[i + (i / j)] = min(dp[i] + 1, dp[i + (i / j)]);
                }
            }
        }
    }
    if (dp[M] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[M] << endl;
    }
    return 0;
}
*/
