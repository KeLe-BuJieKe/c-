/*
1.对两个字符a和b进行初始化:char a[]="ABCDEF";char b[]={'A','B','C','D','E','F'};则以下叙述正确的是：( A )
A a数组比b数组长度长
B a与b长度相同
C a与b数组完全相同
D a和b中都存放字符串

2.x是一个行列数均为1000二维数组，下面代码效率执行最高的是( D )
A for(int j=0;j<1000;j++) for(int i=0;i<1000;i++) x[i][j]+=x[j][i];
B for(int i=0;i<1000;j++) for(int j=0;j<1000;j++) x[i][j]+=x[j][i];
C for(int i=0;i<1000;j++) for(int j=0;j<1000;j++) x[j][i]+=x[j][i];
D for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) x[i][j]+=x[i][j];

3.C++中关于堆和栈的说法，哪个是错误的:( C )
A 堆的大小仅受操作系统的限制，栈的大小一般一般较小
B 在堆上频繁的调用new/delete容易产生内存碎片，栈没有这个问题
C 堆和栈都可以静态分配
D 堆和栈都可以动态分配


4.下面程序会输出什么：( B )
static int a = 1;
void fun1(void) { a = 2; }
void fun2(void) { int a = 3; }
void fun3(void) { static int a = 4; }
int main(int argc, char** args) {
    printf("% d", a);
    fun1();
    printf("% d", a);
    fun2();
    printf(" % d",a);
    fun3();
    printf("% d", a);
}

A 1 2 3 4
B 1 2 2 2
C 1 2 2 4
D 1 1 1 4


5.In the main() function, after ModifyString(text) is called, what’s the value of ‘text( C )
int FindSubString(char* pch)
{
    int count = 0;
    char* p1 = pch;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] - 1)
        {
            p1++;
            count++;
        }
        else {
            break;
        }
    }
    int count2 = count;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] + 1)
        {
            p1++;
            count2--;
        }
        else {
            break;
        }
    }
    if (count2 == 0)
        return(count);
    return(0);
}
void ModifyString(char* pText)
{
    char* p1 = pText;
    char* p2 = p1;
    while (*p1 != '\0')
    {
        int count = FindSubString(p1);
        if (count > 0)
        {
            *p2++ = *p1;
            sprintf(p2, "%i", count);
            while (*p2 != '\0')
            {
                p2++;
            }
            p1 += count + count + 1;
        }
        else {
            *p2++ = *p1++;
        }
    }
}
void main(void)
{
    char text[32] = "XYBCDCBABABA";
    ModifyString(text);
    printf(text);
}

A XYBCDCBABABA
B XYBCBCDA1BAA
C XYBCDCBA1BAA
D XYBCDDBA1BAB

6.所谓数据封装就是将一组数据和与这组数据有关操作组装在一起，形成一个集合，这集合也就是（ A ）
A 类
B 对象
C 函数体
D 数据块


7.关于以下代码，哪个说法是正确的？( B )
myClass::foo() {
    delete this;
}
..
void func() {
    myClass* a = new myClass();
    a->foo();
}
A 它会引起栈溢出
B 都不正确
C 它不能编译
D 它会引起段错误


8.假定CSomething是一个类，执行下面这些语句之后，内存里创建了_E___个CSomething对象。
CSomething a();
CSomething b(2);
CSomething c[3];
CSomething &ra = b;
CSomething d=b;
CSomething *pA = c;
CSomething *p = new CSomething(4);

A 10
B 9
C 8
D 7
E 6
F 5

9.下面这段代码运行时会出现什么问题？( B )
class A
{
public:
    void f()
    {
        printf("A\n");
    }
};
class B : public A
{
public:
    virtual void f()
    {
        printf("B\n");
    }
};
int main()
{
    A* a = new B;
    a->f();
    delete a;
    return 0;
}

A 没有问题，输出B
B 不符合预期的输出A
C 程序不正确
D 以上答案都不正确

10.下面这段代码会打印出什么？( A )
class A
{
public:
    A()
    {
        printf("A ");
    }
    ~A()
    {
        printf("deA ");
    }
};
class B
{
public:
    B()
    {
        printf("B ");
    }
    ~B()
    {
        printf("deB ");
    }
};
class C : public A, public B
{
public:
    C()
    {
        printf("C ");
    }
    ~C()
    {
        printf("deC ");
    }
};
int main()
{
    A* a = new C();
    delete a;
    return 0;
}

A A B C deA
B C A B deA
C A B C deC
D C A B deC


11.标题：查找输入整数二进制中1的个数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【查找输入整数二进制中1的个数】
输入一个正整数，计算它在二进制下的1的个数。
注意多组输入输出！！！！！！
数据范围：
1<=2^31-1
输入描述：
输入一个整数
输出描述：
计算整数二进制中1的个数
示例1：
输入
5
输出
2

#include<iostream>
using namespace std;
int main()
{
    int num;
    while (cin >> num)
    {
        int count = 0;
        while (num)
        {
            ++count;
            num &= (num - 1);
        }
        cout << count << endl;
    }
    return 0;
}


12.标题：手套 | 时间限制：3秒 | 内存限制：32768K | 语言限制： [Python, C++, C#, Java]
【手套】
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他
无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才
能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种
合法方案。
测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)

  
思路：我们先找一个规律，就是能涵盖所有情况的方案
比如说：我们将某一边中除了0个手套的颜色，全部拿出来，这样一样会满足，但是不是最少的，
所以我们在此基础上想到，只要我们将某一边手套非0的最小值手套数，将该种手套数只拿出一个，这样就是满足最小涵盖所有的情况，至少每一种手套都会有一只
所有我们把左右两边都取得一个最小值和一个减去最小值+1的手套数之后取它们之间的最小值，
加上0个手套的颜色数，当手套个数为0，则必须要要拿完

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int leftmin = INT_MAX, rightmin = INT_MAX;
        int leftsum = 0, rightsum = 0;
        int notgroup = 0;
        for (int i = 0; i < n; ++i)
        {
            //这里就代表着该种手套没有配对的情况，所以必须拿完该种颜色的手套数，不然刚刚我们的分析会覆盖不了这种情况
            if (left[i] == 0 || right[i] == 0) 
            {
                notgroup += (left[i] + right[i]);
            }
            else
            {
                //这里就把有配对的左右手套全部分别加起来
                //并且要得到左右数组中一个最小的数手套数（不包括0）
                leftsum += left[i];
                rightsum += right[i];
                leftmin = min(leftmin, left[i]);
                rightmin = min(rightmin, right[i]);
            }
        }
        //前面这里是得到的是左右某一边去掉非0之后的最小值的手套数，此时最后要将最小值的颜色的手套要加上1，表示拿这一种颜色的一只
        //就可以涵盖所有的情况
        return min(leftsum - leftmin + 1, rightsum - rightmin + 1) + notgroup + 1;
    }
};
*/
