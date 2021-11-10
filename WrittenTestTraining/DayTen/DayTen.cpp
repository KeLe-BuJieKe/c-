/*
1.32位系统中，定义int **a[3][4],则变量占用内存空间为( B )。
A 4
B 48
C 192
D 12

2.二维数组X按行顺序存储，其中每个元素占1个存储单元。若X[4][4]的存储地址为Oxf8b82140,X[9][9]的存储地址为Oxf8b8221c,则X[7][7]的存储地址为( A )。
A Oxf8b821c4
B Oxf8b821a6
C Oxf8b82198
D Oxf8b821c0
答：x[9][9]的地址 - x[4][4]的地址 =DC(H)=220(O)
然后有X行，而4-9之间就可以列一个方程 x-4+9+4x=220  x=43


3.求函数返回值，输入x=9999,返回值为( A )
int func(int x) {
    int count = 0;
    while (x)
    {
        count++;
        x = x & (x - 1);//与运算
    }
    return count;
    }
A 8
B 9
C 10
D 12



4.根据下面递归函数：调用函数Fun（2），返回值是多少（ D ）
int Fun(int n)
{
    if (n == 5)
        return 2;
    else
        return 2 * Fun(n + 1);
}
A 2
B 4
C 8
D 16



5.执行下面语句后的输出为( A )
int I = 1;
if (I <= 0)
    printf("****\n");
else
    printf("%%%%\n");

A %%
B ****
C 有语法错，不能正确执行
D %%%%
答：第一个%将第二个%当成转义字符了，最后就打印了%%


6.在C++，下列哪一个可以做为对象继承之间的转换( C )
A static_cast
B reinterpret_cast
C dynamic_cast
D const_cast


7.类模板的使用实际上是类模板实例化成一个具体的____  A______。
A 类
B 函数
C 模板类
D 对象

8.有如下C++代码：
struct A {
    void foo() { printf("foo"); }
    virtual void bar() { printf("bar"); }
    A() { bar(); }
};
struct B :A {
    void foo() { printf("b_foo"); }
    void bar() { printf("b_bar"); }
};
那么
A *p=new B;
p->foo();
p->bar();
输出为：( A )
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp
答：foo函数不是虚函数，而bar是虚函数。
这里先用父类指针去new一个子类对象，然后先调用父类的构造函数，在调用子类的构造函数
在调用父类的构造函数时，这里要调用bar函数，由于此时还是初始化阶段，虽然是虚函数，但是调用的还是父类的虚函数 故先打印 bar
故父类指针去指向继承关系中的函数，永远调用的父类自己的函数 故打印的是父类的 foo
最后p->bar()此时由于是B的对象，且是虚函数，故调用的就是子类的bar 故打印 b_bar


9.下面的程序输出可能是什么?( C )
class Printer {
public:
    Printer(std::string name) { std::cout << name; }
};
class Container {
public:
    Container() : b("b"), a("a") {}
    Printer a;
    Printer b;
};
int main() {
    Container c;
    return 0;
}
A 可能是 "ab" 或 "ba"。 依赖于具体的实现
B 一直都是 "ba"
C 一直都是 "ab"
答：按定义的顺序构造


10.代码可以通过编译吗？如果不能应该如何修改？( D )
template<class T> class Foo {
    T tVar;
public:
    Foo(T t) : tVar(t) { }
};
template<class T> class FooDerived :public Foo<T>
{
};
int main()
{
    FooDerived<int> d(5);
    return 0;
}
A 代码可以正确通过编译。
B 编译错误，FooDerived是一个继承模板类的非模板类，它的类型不能改变。
C 编译错误，tVal变量是一个不确定的类型。
D 编译错误，可以在FooDerived类中添加一个构造函数解决问题。


11.标题：井字棋 | 时间限制：3秒 | 内存限制：32768K | 语言限制： [Python, C++, C#, Java]
【井字棋】
给定一个二维数组board，代表棋盘，其中元素为1的代表是当前玩家的棋子，0表示没有棋子，-1代表是对方玩家的棋子。当一方棋子在横竖斜方向上有连成排的及
获胜（及井字棋规则），返回当前玩家是否胜出。
测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

class Board
{
public:
    bool checkWon(vector<vector<int> > board)
    {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 1)
        {
            return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 1)
        {
            return true;
        }
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == 1)
            {
                return true;
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == 1)
            {
                return true;
            }
        }
        return false;
    }
};


12.标题：密码强度等级 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【密码强度等级】
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符
二、字母:
0 分: 没有字母
10 分: 全都是小（大）写字母
20 分: 大小写混合字母
三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字
四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号
五、奖励:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号
最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0: 非常弱
对应输出为：
VERY_SECURE
SECURE
VERY_STRONG
STRONG
AVERAGE
WEAK
VERY_WEAK
请根据输入的密码字符串，进行安全评定。
注：
字母：a-z, A-Z
数字：0-9
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./ (ASCII码：0x21~0x2F)
:;<=>?@ (ASCII码：0x3A~0x40)
[\]^_` (ASCII码：0x5B~0x60)
{|}~ (ASCII码：0x7B~0x7E)
提示:
1 <= 字符串的长度<= 300
输入描述：
本题含有多组输入样例。
每组样例输入一个string的密码
输出描述：
每组样例输出密码等级
示例1：
输入
38$@NoNoNo
输出
VERY_SECURE

#include<iostream>
#include<ctype.h>
using namespace std;
int checkstr(string& key) //符号
{
    int count = 0;
    for (auto& e : key)
    {
        if ((0x21 <= e && e <= 0x2F) || (0x3A <= e && e <= 0x40) || (0x5B <= e && e <= 0x60) || (0x7B <= e && e <= 0x7E))
        {
            ++count;
        }
        if (count > 1)
        {
            return 25;
        }
    }
    return count == 1 ? 10 : 0;
}
int checkdigit(string& key) //数字
{
    int count = 0;
    for (auto& e : key)
    {
        if (isdigit(e))
        {
            ++count;
        }
        if (count > 1)
        {
            return 20;
        }
    }
    return count == 1 ? 10 : 0;
}
int checkletter(string& key) //字母
{
    bool big = false;
    bool small = false;
    for (auto& e : key)
    {
        if (isalpha(e))
        {
            if (isupper(e))
            {
                big = true;
            }
            else
            {
                small = true;
            }
            if (big && small)
            {
                return 20;
            }
        }
    }
    return small || big ? 10 : 0;
}
int checklen(string& key) //长度
{
    size_t size = key.size();
    if (size <= 4)
    {
        return 5;
    }
    else if (size <= 7)
    {
        return 10;
    }
    else
    {
        return 25;
    }
}
int checkreward(int& letterGrade, int& digitGrade, int& StrGrade) //奖励
{
    if (letterGrade == 20 && digitGrade > 0 && StrGrade > 0)
    {
        return 5;
    }
    else if (letterGrade == 10 && digitGrade > 0 && StrGrade > 0)
    {
        return 3;
    }
    else if (letterGrade > 0 && digitGrade > 0)
    {
        return 2;
    }
    return 0;
}
void level(int& ret)
{
    if (ret >= 90)
    {
        cout << "VERY_SECURE" << endl;
    }
    else if (ret >= 80)
    {
        cout << "SECURE" << endl;
    }
    else if (ret >= 70)
    {
        cout << "VERY_STRONG" << endl;
    }
    else if (ret >= 60)
    {
        cout << "STRONG" << endl;
    }
    else if (ret >= 50)
    {
        cout << "AVERAGE" << endl;
    }
    else if (ret >= 25)
    {
        cout << "WEAK" << endl;
    }
    else
    {
        cout << "VERY_WEAK" << endl;
    }
}
int main()
{
    string strkey;
    while (cin >> strkey)
    {
        int ret = checklen(strkey);
        int letterGrade = checkletter(strkey);
        int digitGrade = checkdigit(strkey);
        int StrGrade = checkstr(strkey);
        ret += checkreward(letterGrade, digitGrade, StrGrade);
        ret += letterGrade;
        ret += digitGrade;
        ret += StrGrade;
        level(ret);
    }
    return 0;
}
*/
