/*
1.用变量a给出下面的定义:一个有10个指针的数组,该指针指向一个函数,该函数有一个整形参数并返回一个整型数( D )
A int *a[10];
B int (*a)[10];
C int (*a)(int);
D int (*a[10])(int);
答：A是指针数组，本质是数组，存储的元素是int类型的指针
    B是数组指针，本质是指针，该指针指向的元素是一个地址
    C是函数指针，本质是指针，指向的是一个函数
    D是一个函数指针数组，数组中的每一个函数指针指向一个函数

2.对于int* pa[5];的描述，以下哪个选项是正确的（ A ）
A pa是一个具有5个元素的指针数组，每个元素是一个int类型的指针;
B pa是一个指向数组的指针，所指向的数组是5个int类型的元素;
C pa[5]表示某个数的第5个元素的值;
D pa是一个指向某个数组中第5个元素的指针，该元素是int类型的变量

3.下列程序执行后,输出的结果为( B  )
#include<stdio.h>
int cnt = 0;
int fib(int n)
{
    cnt++;
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;
    else
        return fib(n - 1) + fib(n - 2);
}
void main()
{
    fib(8);
    printf("%d", cnt);
}
A 41
B 67
C 109
D 177

4.以下C语言指令：
int a[5] = {1,3,5,7,9};
int *p = (int *)(&a+1);
printf(“%d,%d”,*(a+1)，*(p-1);)
运行结果是什么？( C  )
A 2,1
B 3,1
C 3,9
D 运行时崩溃
答：&a是得到整个数组的地址，然后再+1，相当于跳过了这一整个数组，所以此时p指向的位置为9元素后面的四个字节
然后打印的时候，先用a地址，此时a表示的是第一个元素的地址再加1就跳到了第二个元素，所以第一个数打印的是3
然后第三个是先p-1，p一开始指向的是9后面的4个字节，-1后就指向了9这个元素的地址，所以打印的是9

5.以下哪个选项一定可以将flag的第二个bit置0 ( A )
A flag&=~2
B flag|=2
C flag^=2
D flag>>=2
答：B一定不可能置为1.  C当flag的第一个比特位本来就是0的时候你再异或2，此时反而变成1了。
    D也不行

6.print()函数是一个类的常成员函数，它无返回值，下列表示中正确的是( C  )
A const void print();
B void const print();
C void print() const;
D void print(const);

7.以下关于纯虚函数的说法,正确的是( A  )
A 声明纯虚函数的类不能实例化
B 声明纯虚函数的类成虚基类
C 子类必须实现基类的
D 纯虚函数必须是空函数
答：B.声明纯虚函数的类叫抽象类
    C.子类不一定要实现基类的纯虚函数，只是如果不去实现会无法实例化对象。
    D.纯虚函数不一定是空函数，只是通常弄成空函数

8.下列有关this指针使用方法的叙述正确的是（ D ）
A 保证基类保护成员在子类中可以被访问
B 保证基类私有成员在子类中可以被访问
C 保证基类共有成员在子类中可以被访问
D 保证每个对象拥有自己的数据成员，但共享处理这些数据的代码    

9.下列情况中，不会调用拷贝构造函数的是（  ）
A 用一个对象去初始化同一个类的另一个新对象时
B 将类的一个对象赋值给该类的另一个对象时
C 函数的形参对象，调用函数进行形参和实参结合时
D 函数的返回值是类的对象，函数执行返回调用时

答：B姜磊的一个对象赋值给该类的另一个对象调用的是operator=函数

10.下面程序输出结果是什么?
#include<iostream>
using namespace std;
class A {
public:
    A(const char* s)
    {
        cout << s << endl;
    }
    ~A() {}
};
class B :virtual public A
{
public:
    B(const char* s1, const char* s2) :A(s1) {
        cout << s2 << endl;
    }
};
class C :virtual public A
{
public:
    C(const char* s1, const char* s2) :A(s1) {
        cout << s2 << endl;
    }
};
class D :public B, public C
{
public:
    D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
    {
        cout << s4 << endl;
    }
};
int main() {
    D* p = new D("class A", "class B", "class C", "class D");
    delete p;
    return 0;
}

A class A class B class C class D
B class D class B class C class A
C class D class C class B class A
D class A class C class B class D

答：这题考察的知识点其实就是派生时构造函数的谁先调用的问题，这个跟你继承下来的先后顺序有关
由于D是继承B、C的，然后B与C都是继承A的，所以先调用A的构造函数，然后再调用B，再调用C，最后再调用D的


11.标题：计算糖果 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【计算糖果】A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
输入描述：
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
输出描述：
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1：
输入
1 -2 3 4
输出
2 1 3

思路：根据题意我们可以推导出A=(A-B+A+B)/2=(a+c)/2,B、C同理
最后我们利用反推法：如果同时满足这些条件的话肯定就是存在的，不满足肯定就不存在.
#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    int A = (a + c) >> 1;
    int B = (b + d) >> 1;
    int C = (d - b) >> 1;
    if ((A - B == a) && (B - C == b) && (A + B == c) && (B + C == d))
    {
        cout << A << " " << B << " " << C;
    }
    else
    {
        cout << "No";
    }
    return 0;
}


12.标题：进制转换 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【进制转换】给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述：
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述：
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1：
输入
7 2
输出
111

思路：该题挺简单的，关键得理解怎么去转换，每次用该十进制数去mod我们要转换的进制数，
然后得到的余数就是我们要的结果的一部分进制的结果，且该结果是反的，所以我们最后要逆置一下
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    int radix;
    cin >> num >> radix;
    string ret;
    bool flag = (num < 0);
    if (num != 0)
    {
        if (flag)
        {
            //这里如果num是负数，这里相当于是对num取了绝对值
            //我们知道对一个数的补码取反加1，就会变回原码，
            //那么我们怎么对该负数变为整数呢，这里只需要再取反加1的基础上，将符号位也取反即可
            num = (~num) + 1;
        }
        while (num)
        {
            int cur = num % radix;
            if (cur != 0)
            {
                if (cur < 10)
                {
                    ret += cur + '0';
                }
                else
                {
                    int temp = cur % 10;
                    ret += 'A' + temp;
                }
            }
            else
            {
                ret += '0';
            }
            num /= radix;
        }
        reverse(ret.begin(), ret.end());
        if (flag)
        {
            ret.insert(ret.begin(), '-');
        }
        cout << ret;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
*/
