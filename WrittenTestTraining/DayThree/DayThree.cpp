/*
1、以下程序的输出结果是?（ B ） 
#include <stdio.h> main()
{
  char a[10]={ '1','2','3','4','5','6','7','8','9',0},*p; int i;
  i=8;
  p=a+i;
  printf("%s\n",p-3);
}

A、6
B、6789
C、'6'
D、789
答：p一开始等于1这个字符的地址加+8就指向了9这个元素。
然后打印时p-3就打印的是6字符开始的字符
最后以%s的形式打印就是6789

2、能把函数处理结果的二个数据返回给主调函数，在下面的方法中不正确的是（ A ）
A、return这二个数
B、形参用数组
C、形参用二个指针
D、用二个全局变量
 
 
3、以下能对二维数组a进行正确初始化的语句是( B  )
A、int ta[2][]={{0,1,2},{3,4,5}};
B、int ta[][3]={{0,1,2},{3,4,5}};
C、int ta[2][4]={{0,1,2},{3,4},{5}};
D、int ta[][3]={{0,,2},{},{3,4,5}};


4、由多个源文件组成的C程序，经过编辑、预处理、编译、链接等阶段会生成最终的可执行程序。
下面哪个阶段可以发现被调用的函数未定义？（ C ）
A、预处理
B、编译
C、链接
D、执行


5、下列main()函数执行后的结果为( B  )
int func()
{
   int i,j,k=0;
   for(i=0,j=-1;j=0;i++,j++)
   {
     k++;
   }
   return k;
}
int main()
{
  cout<<(func());
  return 0;
}

A、-1
B、0
C、1
D、2

6、以下哪种STL容器中的对象是连续存储的:( B  )
A、list
B、vector
C、map
D、set

7、当一个类对象的生命周期结束后，关于调用析构函数的描述正确的是:（ C ） #当时做错了，也不知道为啥能错离谱#
A、如果派生类没有定义析构函数，则只调用基类的析构函数
B、如果基类没有定义析构函数，则只调用派生类的析构函数
C、先调用派生类的析构函数，后调用基类的析构函数
D、先调用基类的析构函数，后调用派生类的析构函数


8、下面3段程序代码的效果一样吗？( C  )
int b;
(1)const int *a = &b;
(2)int const *a = &b;
(3)int *const a = &b

A、(2)=(3)
B、(1)=(3)
C、(1)=(2)
D、都不一样
E、都一样

9、下面关于一个类的静态成员描述中,不正确的是( C  )
A、静态成员变量可被该类的所有方法访问
B、该类的静态方法只能访问该类的静态成员函数
C、该类的静态数据成员变量的值不可修改
D、子类可以访问父类的静态成员
E、静态成员无多态特性


10、
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  vector<int>array;
  array.push_back(100);
  array.push_back(300);
  array.push_back(300);
  array.push_back(300);
  array.push_back(300);
  array.push_back(500);
  vector<int>::iterator itor;
  for(itor=array.begin();itor!=array.end();itor++)
  {
    if(*itor==300)
    {
       itor=array.erase(itor);
    }
  }
  for(itor=array.begin();itor!=array.end();itor++)
  {
    cout<<*itor<<"";
  }
  return 0;
}

下面这个代码输出的是( C )
A、100 300 300 300 300 500
B、100 3OO 300 300 500
C、100 300 300 500
D、100 300 500
E、100 500
F、程序错误
答：这题考察的就是迭代器失效问题



11、标题：字符串中找出连续最长的数字串 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【字符串中找出连续最长的数字串】读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述：
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述：
在一行内输出str中里连续最长的数字串。
示例1：
输入
abcd12345ed125ss123456789
输出
123456789


#include<iostream>
#include<string>
using namespace std;
int main()
{
  string str;
  cin >> str;
  int i = 0, j = 0;
  int size = str.size();
  string ret;
  str.resize(size + 1);
  while (j < size)
  {
    if (isdigit(str[j]))
    {
       if (str[j] < str[j + 1])
       {
         while (isdigit(str[j+1]) && j < size && str[j] <= str[j + 1])
         {
           ++j;
         }
          ++j;
       }
       else if (str[j] == str[j + 1])
       {
          while (isdigit(str[j+1]) && j < size && str[j] == str[j + 1])
          {
            ++j;
          }
          ++j;
       }
       else
       {
         while (isdigit(str[j+1]) && j < size && str[j] >= str[j + 1])
         {
           ++j;
         }
         ++j;
       }
       int elemnum = j - i;
       if (ret.size() < elemnum)
       {
         ret = str.substr(i, elemnum);
       }
       i = j;
    }
    else
    {
     ++i;
     ++j;
    }
  }
  cout << ret;
  return 0;
}



12、标题：数组中出现次数超过一半的数字 
| 时间限制：1秒 | 内存限制：65536K | 语言限制： [Kotlin, Typescript, Python, C++, Groovy, Rust, C#, Java, Go, C,
Scala, Javascript, Ruby, Swift, Php, Python 3]
【数组中出现次数超过一半的数字】
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
数据范围：n<=5000 ,数组中元素的值0<=val<=10000
要求：空间复杂度： O(1),时间复杂度O(n)
输入描述：
保证数组输入非空，且保证有解
class Solution
{
public:
//利用计数器，出现次数大于数组中一半的元素的次数
//如果count为0说明该数有可能是我们要找的数
//如果我们保存的ret的可能取值如果相等，就让计数器++，否则就--
int MoreThanHalfNum_Solution(vector<int> numbers)
{
  int count=0;
  int ret;
  for(auto &e:numbers
  {
    if(count==0)
    {
      count=1;
      ret=e;
    }
    else if(e!=ret)
    {
      --count;
    }
    else
    {
      ++count;
    }
  }
  return ret;
  }
};
*/


