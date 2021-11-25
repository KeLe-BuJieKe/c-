/*
1.使用printf函数打印一个double类型的数据，要求：输出为10进制，输出左对齐30个字符，4位精度。以下哪个
选项是正确的？( C )
A %-30.4e
B %4.30e
C %-30.4f
D %-4.30f


2.malloc函数进行内存分配是在什么阶段?( D )
A 编译阶段
B 链接阶段
C 装载阶段
D 执行阶段


3.函数作用：将整型数组p中n个数据增大
void increment_ints(int p[], int n)
{
    assert(p != NULL);  确保p不为空指针 
    assert(n >= 0);  确保n不为负数 
    while (n)  循环n次. 
    {
        *p++;  增大p
        p++, n--;  p指向下一位，n减1 
    }
}

以上代码的实现有错误，下面哪句话的表述是正确的？( A )
A *p++使得p在解引用之前增大，应该改为(*p)++
B 数组的值是一个不能改变的值，所以p不能直接被修改。应该使用一个和p相关联的指针来完成这个操作。
C while循环的条件必须是一个布尔类型的表达式，表达式应该为n!=0.
D p不应该定义为变长的数组，参数中不应该包含参数n。


4.如下函数的f(1)的值为( C )
int f(int n) {
    static int i = 1;
    if (n >= 5)
        return n;
    n = n + i;
    i++;
    return f(n);
}
A 5
B 6
C 7
D 8


5.下列给定程序中，函数fun的功能是：把形参a所指数组中的最小值放在元素a[0]中，接着把a所指数组中的最大值放在a[1]元素中;再把a所指数组元素中的次小值放在
a[2]中，把a索取数组元素中的次大值放在a[3]，以此类推。
例如:若a所指数组中的数据最初排列为：9,1,4,2,3,6,5,8,7;按规则移动后，数据排列为:1,9,2,8,3,7,4,6,5。形参n中存放a所指数组中数据的个数。
规定fun函数中的max存放的当前所找的最大值,px存放当前所找最大值得下标。 请在程序的下画线处填入正确的内容并将下画线删除，使程序得出正确的结果。
试题程序。( B )
#include<stdio.h>
#define N 9
void fun(int a[], int n)
{
    int i, j, max, min, px, pn, t;
    for (i = 0; i < n - 1; i += 2)
    {
        max = min = __;
        px = pn = i;
        for (j = i + 1; j < n; j++)
        {
            if (max < __)
            {
                max = a[j];
                px = j;
            }
            if (min > __)
            {
                min = a[j];
                pn = j;
            }
        }
        if (pn != i)
        {
            t = a[i];
            a[i] = min;
            a[pn] = t;
            if (px == i)
                px = pn;
        }
        if (px != i + 1)
        {
            t = a[i + 1];
            a[i + 1] = max;
            a[px] = t;
        }
    }
}
int main()
{
    int b[N] = { 9, 1, 4, 2, 3, 6, 5, 8, 7 };
    printf("\nThe original data:\n");
    for (int i = 0; i < N; i++)
        printf("% 4d", b[i]);
    printf("\n");
    fun(b, N);
    printf("\nThe data after mocinng \n");
    for (int i = 0; i < N; i++)
        printf("% 4d", b[i]);
    printf("\n");
}

A 0 a[i] a[i]
B a[i] a[j] a[j]
C 0 a[j] a[j]
D a[i] a[i] a[i]



6.下面说法正确的是（ B）
A C++已有的任何运算符都可以重载
B const对象只能调用const类型成员函数
C 构造函数和析构函数都可以是虚函数   
D 函数重载返回值类型必须相同

构造函数不能是虚函数，因为对象的虚函数表指针是在初始化列表生成


7.下面关于迭代器失效的描述哪个是错误的（ A）
A vector的插入操作不会导致迭代器失效
B map的插入操作不会导致迭代器失效
C vector的删除操作只会导致指向被删除元素及后面的迭代器失效
D map的删除操作只会导致指向被删除元素的迭代器失效


8.下面哪一个是sort的template的正确写法( D )
A void sort(class A first，class A last，class B pred)
B void template(class A，class B)sort(A first，A last，B pred)
C template<class A><class B> void sort(A first，A last，B pred)
D template<class A，class B> void sort(A first，A last，B pred)

  
9.以下程序的运行结果是( D )
main()
{
    char a[] = "programming", b[] = "language";
    char* p1, * p2;
    int i;
    p1 = a, p2 = b;
    for (i = 0; i < 7; i++)
        if (*(p1 + i) == *(p2 + i))
            printf(" % c", *(p1 + i));
}

A gm
B rg
C or
D ga


10.下列程序的输出结果：( C )
#include <iostream>
using namespace std;
class A
{
public:
    void print()
    {
        cout << "A:print()";
    }
};
class B : private A
{
public:
    void print()
    {
        cout << "B:print()";
    }
};
class C : public B
{
public:
    void print()
    {
        A::print();
    }
};
int main()
{
    C b;
    b.print();
}

A A:print()
B B:print()
C 编译出错



11.标题：统计每个月兔子的总数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【统计每个月兔子的总数】
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？
本题有多组数据。
数据范围：每组输入满足 1<=n<=31
输入描述：
多行输入，一行输入一个int型整数表示第n个月
输出描述：
每一行输出对应的兔子总数
示例1：
输入
9
输出
34

#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n <= 2) //由于没有兔子不会死，所以当输入的月份小于等于2时，就可以直接返回只有1只，因为3个月才生一只
        {
            cout << 1 << endl;
        }
        else
        {
            int a = 1; //起始的1月
            int b = 1; //起始的2月
            int c = a + b;//起始的3月
            n -= 2; //由于小于等于2月的结果我们已经知晓，所以我们从3月开始计算，所以先间2个月
            //又由于我们现在已经是3月的结果了，所以我们要进行n-1次
            while (--n)
            {
                a = b;
                b = c;
                c = a + b;
            }
            cout << c << endl;
        }
    }
    return 0;
}


12.标题：字符串通配符 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【字符串通配符】
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（注：能被*和?匹配的字符仅由英文字母和数字0到9组成，下同）
？：匹配1个字符
注意：匹配时不区分大小写。
输入：
通配符表达式；
一组字符串。
输出：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
注意：本题含有多组样例输入！
数据范围：数据组数：1<=t<=10,字符串长度：1<=s<=100
进阶：时间复杂度：O(n^2)  ，空间复杂度：O(n)
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
示例1：
输入
te?t*.*
txt12.xls
输出
false


方法一：复杂度过高，过不了OJ
#include<iostream>
#include<vector>
using namespace std;
bool isMatch(const char* pattern, const char* str)
{
    if (*pattern == '\0' && *str == '\0')  //如果两个字符串匹配到了\0，则证明匹配成功
    {
        return true;
    }
    //如果有一个字符串匹配到\0,而另外一个没有匹配到，则说明匹配失败
    if (*pattern == '\0' || *str == '\0')
    {
        return false;
    }

    if (*pattern == '?')  //只匹配一个字符
    {
        return isMatch(pattern + 1, str + 1);
    }
    else if (*pattern == '*')
    {
        return isMatch(pattern, str + 1)
            || isMatch(pattern + 1, str + 1)
            || isMatch(pattern + 1, str);
    }
    else if (*pattern == *str)
    {
        return isMatch(pattern + 1, str + 1);
    }
    else
    {
        return false;
    }
}
int main()
{
    string pattern;
    string str;
    while (cin >> pattern >> str)
    {
        bool ret = isMatch(pattern.c_str(), str.c_str());
        if (ret == true)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}




方法二：动态规划
#include<iostream>
#include<vector>
using namespace std;
bool isMatch(string& t, char ch, vector<bool>& prevRow, vector<bool>& curRow)
{
    //思路：利用两个数组，prevRow记录的是上一层的匹配情况，第一次prevRow里就是空字符串配对t的情况
    //然后用curRow数组来得到下一层的匹配情况，最后将prevRow=curRow，在将curRow清空，循环继续计算下一层
    for (size_t i = 0, j = 1; i < t.size(); ++i, ++j)
    {
        if ((ch >= '0' && ch <= '9') ||
            islower(ch) || isupper(ch) || ch == '.') //这个点恶心到我了
        {
            if ((t[i] == ch || t[i] == toupper(ch)) || (t[i] == '?'))
                //忽略大小写，如果相同就会走第一个，不相同就先将ch变为大写字母在判断是否匹配
            {
                //curRow[i] = prevRow[j - 1];
                curRow.push_back(prevRow[j - 1]);
            }
            else if (t[i] == '*')
            {
                //curRow[i] = (curRow[j - 1] || prevRow[j]);
                curRow.push_back(curRow[j - 1] || prevRow[j]);
            }
            else
            {
                //curRow[i] = false;
                curRow.push_back(false);
            }
        }
        else //如果有其他不是要匹配的字符直接返回false
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string t;
    string s;
    while (cin >> t >> s)
    {
        int Tsize = static_cast<int>(t.size());
        int Ssize = static_cast<int>(s.size());
        vector<bool>prev(Tsize + 1, false);
        prev[0] = true;
        vector<bool>cur;
        for (int i = 1; i < Tsize; ++i)
        {
            if (t[i - 1] == '*')
            {
                prev[i] = prev[i - 1];
            }
        }
        bool flag;
        for (int i = 0; i < Ssize; ++i)
        {
            cur.push_back(false);
            flag = isMatch(t, s[i], prev, cur);
            if (flag == false) //这里判断一下如果有其他字符就直接为false，直接结束这次判断
            {
                cout << "false" << endl;
                break;
            }
            prev = cur;
            cur.clear();
        }
        if (flag == true)
        {
            if (prev[Tsize] == true)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}



*/
