/*1.以下程序的输出结果是？( D  )
int x = 1;
do{
  printf("%2d\n",x++);
}while(x--);

A 1
B 无任何输出
C 2
D 陷入死循环
答：由于这是do while循环，不管条件成不成立都会进去执行一次，然后打印x，在x++了
到了判断条件这先此时x==2了，然后条件为true继续循环，然后x--，x==1，这里一直死循环的打印1

2.下面两个结构体
struct One{
  double d;
  char c;
  int i;
}
struct Two{
  char c;
  double d;
  int i;
}
在#pragma pack(4)和#pragma pack(8)的情况下，结构体的大小分别是( C  )
A 16 24,16 24
B 16 20,16 20
C 16 16,16 24
D 16 16,24 24
答：#pragma pack(4)
此时one的d先占了 0 -7，然后c占了8这一位，由于i是int类型要与4的整数倍对齐，故9-11被浪费了，i就占了12-15这4个位置，然后在根据结构体内存对齐就是16
Two的c先占了0这一位，然后由于d是double类型要与8的整数倍对齐，但这里是#pragma pack(4)，故以4对齐，故只浪费了1-3，一共3个字节
d就占了4-11，这8个位，然后i占了12-15，然后以4结构体内存对齐，故大小为16
#pragma pack(8)
同理
one的d占0-7，然后c占8，然后9-11被浪费，i占12-15，然后以8在结构体内存对齐就是16
two的c先占0，然后d以8的整数倍对齐，所以1-7被浪费，然后d占8-15，然后i占16-19，一共20个字节，然后要根据结构体内存对齐以8，然后就是24

3.下列程序的打印结果是?( D  )
char p1[15]= "abcd",*p2= "ABCD", str[50]= "xyz";
strcpy(str+2,strcat(p1+2,p2+1));
printf("%s",str);

A xyabcAB
B abcABz
C ABabcz
D xycdBCD
E 运行出错
答：p1+2指向的是c这个元素，p2+1指向的是B这个元素，然后将BCD这三个元素连接到cd的尾部就变成了cdBCD
str+2指向的z这个元素，然后将cdBCD这5个元素拷贝到以z这个元素位置为起始位置的str这个数组中

4.下面程序的输出结果是( B  )
#include<iosteam.h>
void main()
{
  int n[][3] = {10,20,30,40,50,60};
  int (*p)[3];
  p=n;
  cout<<p[0][0]<<","<<*(p[0]+1)<<","<<(*p)[2]<<endl;
}

A 10,30,50
B 10,20,30
C 20,40,60
D 10,30,60
答：p是一个指针数组，其中数组中的每一个指针指向的是一个存储3个int类型的数组,然后这里就相当于是2维数组一般了
然后这里对由于p是一个指针数组，然后呢存储了6个元素，就相当于是有两行
p[0]、*p相当于得到第一行数组的首地址，在p[0][0]就得到了第一行一个元素
同理p[0]是第一行元素的首地址+1后就跳到了一行第二个元素的地址，此时在解引用就等于20了
*p同理

5.int main(){
  int a;float b,c;
  scanf("%2d%3f%4f",&a,&b,&c);
  printf("\na=%d,b=%d,c=%f\n",a,b,c);
}
若运行时从键盘上输入9876543210l,则上面程序在gcc编译器下的输出结果是( B )
A a=98,b=765,c=4321.000000
B a=98,b=0,c=0.000000
C a=98,b=765.000000,c=4321.000000
D a=98,b=765.0,c=4321.0
答：这题考察的是浮点数的存储模式，尽管输入进来的时候，a=98,b=765,c=4321
但由于printf哪里的b是以%d的方式打印的造成的问题。

6.STL中的unordered_map和priority_queue使用的底层数据结构分别是什么?( B  )
A rbtree,queue
B hashtable,heap
C rbtree,heap
D hashtable,queue

7.下面说法正确的是( A  )
A 一个空类默认一定生成构造函数,拷贝构造函数,赋值操作符,引用操作符,析构函数
B 可以有多个析构函数
C 析构函数可以为virtual,可以被重载
D 类的构造函数如果都不是public访问属性,则类的实例无法创建

8.c++语言中，类ClassA的构造函数和析构函数的执行次数分别为( A )
ClassA *pclassa=new ClassA[5];
delete pclassa;
A 5,1
B 1,1
C 5,5
D 1,5

9.关于重载和多态正确的是( B )
A 如果父类和子类都有相同的方法,参数个数不同,将子类对象赋给父类后,由于子类继承于父类,所以使用父类指针 调用父类方法时,实际调用的是子类的方法
B 选项全部都不正确
C 重载和多态在C++面向对象编程中经常用到的方法,都只在实现子类的方法时才会使用
D 
class A {
    void test(float a) { cout << "1"; }
};
class B :public A{
    void test(int b) { cout << "2"; }
};
A* a = new A;
B* b = new B;
a = b;
a.test(1.1);
结果是1
答：A中父类和子类有相同的函数，但是参数个数不同，显然这构成函数隐藏也叫重定义，然后用父类指针调用父类方法调用的肯定是父类的方法
C重载不是
D结果是1.1

10.请选择下列程序的运行结果( A )
#include<iostream>
using namespace std;
class B0//基类BO声明
{
public://外部接口
    virtual void display()//虚成员函数
    {
        cout << "B0::display0" << endl;
    }
};
class B1 :public B0//公有派生
{
public:
    void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//公有派生
{
public:
    void display() { cout << "D1::display0" << endl; }
};
void fun(B0 ptr)//普通函数
{
    ptr.display();
}
int main()//主函数
{
    B0 b0;//声明基类对象和指针
    B1 b1;//声明派生类对象
    D1 d1;//声明派生类对象
    fun(b0);//调用基类B0函数成员
    fun(b1);//调用派生类B1函数成员
    fun(d1);//调用派生类D1函数成员
}
A B0::display0 B0::display0 B0::display0
B B0::display0 B0::display0 D1::display0
C B0::display0 B1::display0 D1::display0
D B0::display0 B1::display0 B1::display0

11.标题：统计回文 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【统计回文】“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有对称美的回文串，生日的时候她
得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少
种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2
输入描述：
每组输入数据共两行。
第一行为字符串A
第二行为字符串B
字符串长度均小于100且只包含小写字母
输出描述：
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
示例1：
输入
aba
b
输出
2

#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string& str)
{
    int start = 0;
    int end = str.size() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}
int main()
{
    string A;
    string B;
    cin >> A >> B;
    size_t size = A.size();
    string temp;
    int count = 0;
    for (size_t i = 0; i <= size; ++i)
    {
        temp = A;
        temp.insert(temp.begin() + i, B.begin(), B.end());
        if (isPalindrome(temp))
        {
            ++count;
        }
    }
    cout << count;
    return 0;
}


12.标题：连续最大和 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【连续最大和】一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述：
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述：
所有连续子数组中和最大的值.
示例1：
输入
3 -1 2 1
输出
3

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
    int size;
    cin >> size;
    vector<int>arr(size, 0);
    for (auto& e : arr)
    {
        cin >> e;
    }
    long long ret = INT_MIN;
    vector<long long>dp(size, 0);
    for (size_t i = 0; i < size; ++i)
    {
        if (i == 0 || dp[i - 1] + arr[i] <= arr[i])
        {
            dp[i] = arr[i];
        }
        else if (dp[i - 1] + arr[i] > arr[i])
        {
            dp[i] = dp[i - 1] + arr[i];
        }
        ret = max(dp[i], ret);
    }
    cout << ret;
    return 0;
}
*/
