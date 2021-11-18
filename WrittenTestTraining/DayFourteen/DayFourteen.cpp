/*
1.定义char dog[]="wang\0miao";那么sizeof(dog)与strlen(dog)分别是多少：( A )
A 10,4
B 4,4
C 9,9
D 9,4

答：这题没啥难度，要点就是strlen碰到\0计算结束，而sizeof是计算整个变量的大小

2.假设寄存器为8位，用补码形式存储机器数，包括一位符号位，那么十进制数-25在寄存器表示为：( D )
A 67H
B 99H
C E6H
D E7H

3.下面代码的执行结果是什么：( A )
char ccString1[] = "Is Page Fault??";
char ccString2[] = "No Page Fault??";
strcpy(ccString1, "No");
if (strcmp(ccString1, ccString2) == 0)
    cout << ccString2;
else
    cout << ccString1;

A No
B No Page Fault??
C Is Page Fault??
D 其他三项都错

4.输入参数为197时，函数返回多少？( C )
int Function(unsigned int n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}
A 2
B 3
C 4
D 5

5.下面程序的功能是输出数组的全排列。请填空。( B )
void perm(int list[], int k, int m)
{
    if ()
    {
        copy(list, list + m, ostream_iterator<int>(cout, " "));
        cout << endl;
        return;
    }
    for (int i = k; i <= m; i++)
    {
        swap(&list[k], &list[i]);
        ();
        swap(&list[k], &list[i]);
    }
}
A k!=m 和 perm（list，k+1，m）
B k==m 和 perm（list，k+1，m）
C k!=m 和 perm（list，k，m）
D k==m 和 perm（list，k，m）

6.C++中以下关于函数调用的说法哪个是正确的？( D )
A 传地址后实参和形参指向不同的对象
B 传引用后实参和形参是不同的对象
C 传值后对形参的修改会改变实参的值
D 其他三项都不对

7.有一个类B继承自类A，他们数据成员如下：
class A {
...
private：
    int a;
};
class B : public A {
    ...
private:
    int a;
public:
    const int b;
    A& c;
    static const char* d;
    B* e;
}
则构造函数中，成员变量一定要通过初始化列表来初始化的是_ F___。
A a b c
B b c e
C b c d e
D c e
E b d
F b c

8.以下代码编译有错误，哪个选项能解决编译错误？( D )
class A {
public:
    int GetValue() const {
        vv = 1;
        return vv;
    }
private:
    int vv;
};
A 改变成员变量"vv"为"mutable int vv"
B 改变成员函数"GetValue"的声明，以使其不是const的
C 都不能修复编译错误
D 都可以修复编译错误

答：被 mutable 修饰的变量，将永远处于可变的状态，即使是 const 函数中也可以改变这个变量的值。
而常函数不能修改非常对象，故将该常函数改成不是常函数也可以修改该变量

9.下面程序运行后的结果为：( D )
char str[] = "glad to test something";
char* p = str;
p++;
int* p1 = reinterpret_cast<int*>(p);
p1++;
p = reinterpret_cast<char*>(p1);
printf("result is %s\n", p);

A result is glad to test something
B result is ad to test something
C result is test something
D result is to test something


10.以下程序的输出是( C )
class Base
{
public:
    Base(int j) : i(j) {}
    virtual~Base() {}
    void func1() 
    {
        i *= 10;
        func2();
    }
    int getValue()
    {
        return i;
    }
protected:
    virtual void func2() 
    {
        i++;
    }
protected:
    int i;
};
class Child : public Base 
{
public:
    Child(int j) : Base(j) {}
    void func1() 
    {
        i *= 100;
        func2();
    }
protected:
    void func2() 
    {
        i += 2;
    }
};
int main() 
{
    Base* pb = new Child(1);
    pb->func1();
    cout << pb->getValue() << endl; delete pb;
}

A 11
B 101
C 12
D 102
答：一开始这里先用父类指针去创建一个子类对象然后i的值为1，然后用该父类指针去调用func1()函数，由于func1()函数不是虚函数，
故不构成动态多态，然后父类指针去调用的就是父类的函数，然后i就变为了10，在父类的func1()函数中，它去调用了func2()函数
由于该函数是虚函数，又由于成员函数都隐藏一个this指针，这就相当于父类指针指向了子类对象，然后构成多态，进而去调用了子类的func2()函数
而在子类的func2()中，i+=2,故最后的值为12



11.标题：计算日期到天数转换 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【计算日期到天数转换】
根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。
进阶：时间复杂度：O(n) ，空间复杂度：O(n)
输入描述：
输入一行，每行空格分割，分别是年，月，日
输出描述：
输出是这一年的第几天
示例1：
输入
2012 12 31
输出
366

#include<iostream>
using namespace std;
bool islear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}
int main()
{
    int year, month, day;
    int dayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    cin >> year >> month >> day;
    int ret = 0;
    if (month > 3 && islear(year))
    {
        ret += 1;
    }
    for (int i = 1; i < month; ++i)
    {
        ret += dayArr[i];
    }
    ret += day;
    cout << ret;
    return 0;
}



12.标题：幸运的袋子 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【幸运的袋子】一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的
号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述：
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数x (x ≤ 1000)
输出描述：
输出可以产生的幸运的袋子数
示例1：
输入
3
1 1 1
输出
2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<int>& arr, int pos, int sum, int mul)
{
    int count = 0;
    for (int i = pos; i < arr.size(); ++i)
    {
        sum += arr[i];
        mul *= arr[i];
        //判断是否幸运
        if (sum > mul)
        {
            count += 1 + dfs(arr, i + 1, sum, mul);
        }
        else if (arr[i] == 1) //刚开始的情况，至少要有一个数为1，不然不会构成幸运
        {
            count += dfs(arr, i + 1, sum, mul);
        }
        else
        {
            break; //回溯
        }
        sum -= arr[i];
        mul /= arr[i];
        //去重剪枝比如 1 1 3 5,第一个1已经将3 和5，组成1 3 5 了，第二个1就不再需要在组成1 3 5了，虽然这个是不幸运的，举个例子而已 
        while (i < arr.size() - 1 && arr[i] == arr[i + 1])
        {
            ++i;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    int sum = 0;
    int mul = 1;
    for (auto& e : arr)
    {
        cin >> e;
    }
    sort(arr.begin(), arr.end()); //为了后面的去重和剪枝操作
    cout << dfs(arr, 0, sum, mul);
    return 0;
}
*/
