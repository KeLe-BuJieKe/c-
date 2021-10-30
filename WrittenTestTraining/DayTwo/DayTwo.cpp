
/*1、有以下定义：
int a[10];
char b[80];
函数声明为：
void sss(char[],int[]);
则正确的函数调用形式是（ D ）。
A、sss(a,b);
B、sss(char b[],int a[]);
C、sss(b[],a[]);
D、sss(b,a);
*/


/*2、数组a的定义语句为“float a[3][4];”,列（D）是对数组元素不正确的引用方法。
A、a[i][j]
B、*(a[i]+j)
C、*(*(a+i)+j)
D、*(a+i*4+j)
*/

/*3、下面叙述错误的是（D）
char acX[]=”abc”;
char acY[]={‘a’,’b’,’c’};
char *szX=”abc”;
char *szY=”abc”;

A acX与acY的内容可以修改
B szX与szY指向同一个地址
C acX占用的内存空间比acY占用的大
D szX的内容修改后，szY的内容也会被更改
答：acX占4个字节+上\0，acY占3个字节,szX与szY指向的是一个常量字符串，都在常量区，值都是指向的同一个
*/

/*4、下列代码的运行结果是（ C ）
int a[]={1,2,3,4};
int *b=a;
*b+=2;
*(b+2)=2;
b++;
printf(“%d,%d\n”,*b,*(b+2));

A 1,3
B 1,2
C 2,4
D 3,2
答：b一开始指向的是1这个元素的地址，然后让在解引用b+=2，相当于此时1的位置的数变成了3
而*（b+2）=2,是将指针往后移动了两个整形，但是到这里位置b的指向一直都没有变，一直指向的是第一个元素，但b+2指向了3这个值，然后让该位置的值被赋予为2
最后b在++,这里才改变了b的指向，指向了2这个元素
*/

/*5、在32位cpu上选择缺省对齐的情况下，有如下结构体定义：
struct A{
unsigned a : 19;
unsigned b : 11;
unsigned c : 4;
unsigned d : 29;
char index;
};
则sizeof（struct A）的值为（C）

A 9
B 12
C 16
D 20

答：该题考察的就是位段，a占19个比特位和b占11个一共占了30个比特位，就是4个字节
然后4个比特位独占4个字节，29个比特位也独占4个字节，在加上index占一个字节
一共就13个字节，然后在考虑结构体内存对齐，以4为基准就是16
*/

/*6、以下关于C++的描述中哪一个是正确的：（ C ）
A 任何指针都必须指向一个实例
B 子类指针不可以指向父类实例
C 任何引用都必须指向一个实例
D 引用所指向的实例不可能无效
*/

/*7、以下不是double compare(int,int)的重载函数的是( D )
A int compare(double,double)
B double compare(double,double)
C double compare(double,int)
D int compare(int,int)
*/


/*8、关于虚函数的描述正确的是( B )
A 派生类的虚函数与基类的虚函数具有不同的参数个数和类型
B 内联函数不能是虚函数
C 派生类必须重新定义基类的虚函数
D 虚函数可以是一个static型的函数
*/

/*9、请将下列构造函数补充完整，使得程序的运行结果是5( B )
#include<iostream>
using namespace std;
class Sample {
public:
    Sample(int x) {
        ________
    }
    ~Sample() {
        if (p) delete p;
    }
    int show() {
        return *p;
    }
private:
    int* p;
};
int main() {
    Sample S(5);
    cout << S.show() << endl;
    return 0;
}
A *p=x;
B p=new int(x);
C *p=new int(x);
D p=&x;

*/

/*10、关于c++的inline关键字,以下说法正确的是( D )
A 使用inline关键字的函数会被编译器在调用处展开
B 头文件中可以包含inline函数的声明
C 可以在同一个项目的不同源文件内定义函数名相同但实现不同的inline函数
D 定义在Class声明内的成员函数默认是inline函数
E 优先使用Class声明内定义的inline函数
F 优先使用Class实现的内inline函数的实现
*/

/*标题：排序子序列 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
 * 【排序子序列】牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任
 * 务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
 * 如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
输入描述：
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。
输出描述：
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
示例1：
输入
6
1 2 3 2 2 1
输出
2

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
  cin >> n;
  vector<int>arr(n, 0);
	for (auto& e : arr)
  {
    cin >> e;
  }
	int j = 0;
  int ret = 0;
  arr.resize(n + 1, 0); //多开辟一个空间，防止到最后一个元素比较时出错
	while (j<n)
  {
     if (arr[j] < arr[j+1])
     {
        while (j<n&&arr[j] <= arr[j+1])
       {
         ++j;
       }
       ++j;
       ++ret;
       }
     }
	//如果相等，不确定是让它是划分到递减还是递增区间内，就算全是相同的数，由于我们在末尾添加了一个数
  //从而使得它这个一定会进入到 < 或者 > 的判断中
	else if (arr[j] == arr[j + 1])
  {
    ++j;
  }
	else
  {
     while (j < n && arr[j] >= arr[j+1])
     {
       ++j;
     }
       ++j;
       ++ret;
     }
  }
  cout << ret;

*/


/*倒置字符串 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
 * 【倒置字符串】将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
 * 输入描述：
 * 每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
 * 输出描述：
 * 依次输出倒置之后的字符串, 以空格分割
 * 示例1：
 * 输入
 * I like beijing.
 * 输出
 * beijing.like I
 

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size();)
		{
			int begin = i;
			 //1.我们要找到分隔符空格，并且改位置要小于该字符串的长度，
       //跳出这个循环的情况有两种，1、是碰到分隔符空格
       //2、是要碰到'\0'，即i=s.size这个位置，这一步可以防止越界
			while (i < s.size() && s[i] != ' ')
      {
                  ++i;
                          
      }
			int end = i - 1;
			//2.我们逆置【begin，end】这个前闭后闭这个区间内的元素
			 while (begin < end)
       {
            swap(s[begin], s[end]);
            begin++;       
            end--;                                       
       }
			//3.这一步我们要跳过空格这个位置，并给下一个区间的begin赋值
			while (i < s.size() && s[i] == ' ')
      {
                  ++i;
                          
      }
		}
	  reverse(s.begin(), s.end());
    cout << s;
    return 0;
}
	
*/
