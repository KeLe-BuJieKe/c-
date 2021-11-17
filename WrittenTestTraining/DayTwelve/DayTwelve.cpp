/*
1.以下不能正确定义二维数组的选项是__D____。
A int a[2][2]={{1},{2}};
B int a[][2]={1,2,3,4};
C int a[2][2]={{1},2,3};
D int a[2][]={{1,2},{3,4}};


2.代码生成阶段的主要任务是：( C )
A 把高级语言翻译成机器语言
B 把高级语言翻译成汇编语言
C 把中间代码变换成依赖具体机器的目标代码
D 把汇编语言翻译成机器语言

3.下面程序的输出结果是？( C )
#include<iostream.h>
void main() {
    int n[][3] = { 10,20,30,40,50,60 };
    int(*p)[3];
    p = n;
    cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
}
A 10,30,60
B 10,30,50
C 10,20,30
D 20,40,60

4.下面程序的输出结果是____D______。
#include < iostream.h>
#define SQR(A) A*A
void main() 
{
    int x = 6, y = 3, z = 2;
    x /= SQR(y + z) / SQR(y + z);
    cout < < x < < endl;
}
A 5
B 6
C 1
D 0

5.在一个64位的操作系统中定义如下结构体：
struct st_task
{
  uint16_t id;
  uint32_t value;
  uint64_t timestamp;
};
同时定义fool函数如下：
void fool()
{
  st_task task = {};
  uint64_t a = 0x00010001;
  memcpy(&task, &a, sizeof(uint64_t));
  printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
上述fool()程序的执行结果为（ A ）
A 1，0，0
B 1，1，0
C 0，1，1
D 0，0，1

6.STL中的一级容器有:( D )
A vector, deque, list, set, multiset, map, multimap.
B 序列容器，关联容器，容器适配器
C set, multiset, map, multimap.
D vector, deque, list.

7.如果有一个类是 myClass , 关于下面代码正确描述的是:( C )
myClass::~myClass(){
delete this;
this = NULL;
}
A 正确，我们避免了内存泄漏
B 它会导致栈溢出
C 无法编译通过
D 这是不正确的，它没有释放任何成员变量。

8.如果类B继承类A，A::x()被声明为虚函数，B::x()重载了A::x()方法，在下述语句中哪个x()方法会被调用：( B )
B b;
b.x();

A A::x()
B B::x()
C A::x() B::x()
D B::x() A::x()

9.函数func的定义如下：
void func(const int& v1, const int& v2)
{
  std::cout << v1 << ' ';
  std::cout << v2 << ' ';
}

以下代码在vs中输出结果为 _D___。
int main (int argc, char* argv[])
{
  int i=0;
  func(++i,i++);
  return 0;
}

A 0 1
B 1 2
C 2 1
D 2 0
E 程序强制终止并报错
F 结果与编译器有关

10.下列一段C++代码的输出是?( B )
#include "stdio.h"
class Base
{
public:
    int Bar(char x)
    {
        return (int)(x);
    }
    virtual int Bar(int x)
    {
        return (2 * x);
    }
};
class Derived : public Base
{
public:
    int Bar(char x)
    {
        return (int)(-x);
    }
    int Bar(int x)
    {
        return (x / 2);
    }
};
int main(void)
{
    Derived Obj;
    Base* pObj = &Obj;
    printf("%d,", pObj->Bar((char)(100)));
    printf("%d,", pObj->Bar(100));
}
A 100，-100
B 100，50
C 200，-100
D 200，50



11.标题：二进制插入 | 时间限制：3秒 | 内存限制：32768K | 语言限制： [Python, C++, C#, Java]
【二进制插入】
给定两个32位整数n和m，同时给定i和j，将m的二进制数位插入到n的二进制的第j到第i位,保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1，其中二进制
的位数从0开始由低到高。
测试样例：
1024，19，2，6
返回：1100

//方法一：
class BinInsert
{
public:
    int binInsert(int n, int m, int j, int i)
    {
        vector<bool>arrn(32, false);
        for (int k = 0; k < 32; ++k)
        {
            arrn[k] = ((1 << k) & n);
        }
        vector<bool>arrm(32, false);
        for (int k = 0; k < 32; ++k)
        {
            arrm[k] = ((1 << k) & m);
        }
        int p = 0;
        while (j <= i)
        {
            arrn[j] = (arrn[j] || arrm[p]);
            j++;
            p++;
        }
        reverse(arrn.begin(), arrn.end());
        int ret = 0;
        for (auto e : arrn)
        {
            ret = ((ret << 1) | e);
        }
        return ret;
    }
};

//方法二：
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        for(int k=0;k<=i-j;++k)
        {
          //先将m的每一位的二进制出来在左移到要 | 上的位置
            n|=((m>>k)&1)<<(j+k);
        }
        return n;
    }
};


//方法三：
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n|(m<<j);
    }
};


标题：查找组成一个偶数最接近的两个素数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【查找组成一个偶数最接近的两个素数】
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
本题含有多组样例输入。
输入描述：
输入一个偶数
输出描述：
输出两个素数
示例1：
输入
20
输出
7
13

//方法一：
#include<iostream>
using namespace std;
bool isprime(int num)
{
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int even;
    int x1;
    int x2;
    while (cin >> even)
    {
        int sub = even;
        int i = 3;
        int j;
        while (i < even)
        {
            j = even - i;
            if (isprime(i) && isprime(j))
            {
                if (i <= j && sub > j - i)
                {
                    sub = j - i;
                    x1 = i;
                    x2 = j;
                }
            }
            ++i;
        }
        cout << x1 << endl;
        cout << x2 << endl
    }
    return 0;
}



//方法二：
#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num)
{
    for(int i=2;i<=sqrt(num);++i)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    //从这个偶数的中间部分来开始查找，一个数一直减1，那么组成这个偶数的另外一个数
    //num这个数就会有i和num-i组成，然后i一直--，从中间向两边扩展
    //那么第一个找到的两个素数就是我们要找的两个最近的素数
    while(cin>>num)
    {
        for(int i=num/2;i>0;--i)
        {
            if(isPrime(i)&&isPrime(num-i))
            {
                cout<<i<<endl<<num-i<<endl;
                break;
            }
        }
    }
    return 0;
}
*/
