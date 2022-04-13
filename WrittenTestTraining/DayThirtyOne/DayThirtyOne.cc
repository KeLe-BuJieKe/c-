/*
1.在 OSI 分层模型中，把传输的比特流划分为帧，是哪一层的功能（ C ）
A 物理层
B 网络层
C 数据链路层
D 传输层


2.下面关于源端口地址和目标端口地址的描述中，正确的是（ ）
A 在TCP/UDP传输段中，源端口地址和目的端口地址是不能相同的
B 在TCP/UDP传输段中，源端口地址和目的端口地址必须是相同的
C 在TCP/UDP传输段中，源端口地址和目的端口地址是可以相同的
D 以上描述均不正确

解析：端口地址 = ip + 端口号。
TCP/UDP传输段的源IP地址&目标IP地址不能相同，一旦允许相同，在网络中就可以发动Land攻击
LAND攻击利用了TCP连接建立的三次握手过程，通过向一个目标计算机发送一个TCP SYN报文（连接建立请求报文）而完成对目标计算机的攻击。
与正常的TCP SYN报文不同的是LAND攻击报文的源IP地址和目的IP地址是相同的，都是目标计算机的IP地址。
这样目标计算机接收到这个SYN报文后，就会向该报文的源地址发送一个ACK报文，并建立一个TCP连接控制结构（TCB），
而该报文的源地址就是自己，因此，这个ACK报文就发给了自己。这样如果攻击者发送了足够多的SYN报文，则目标计算机的TCB可能会耗尽，
最终不能正常服务。这也是一种DOS攻击。


3.网段地址 154.27.0.0 的网络。若不做子网划分，能支持（ C ）台主机
A 254
B 1024
C 65,534
D 16,777,206


4.SNMP 使用 udp 161 和 162 端口，则该协议属于 TCP/IP 模型中的（ C ）
A 网络层
B 数据链路层
C 应用层
D 传输层


5.http 协议中，状态码 500 的意思为（ D ）
A 重定向
B 访问被拒绝
C 未找到请求的内容
D 服务器内部有错误


6.主机 A 向主机 B 连续发送了两个 TCP 报文段，其序号分包是 70 和 100 ，如果 A 发送的第一个报文段丢失了，但第二个报文段达到了 B ， B 在第二个报文段到达
后向 A 发送确认，那么这个确认号是多少？( C )
A 100
B 101
C 70
D 71


7.每个 IP 地址都可以有一个主机名，通过主机名得到该主机对应 ip 地址的过程叫（ B ）
A ip地址解析
B 域名解析
C 域名编译
D ip地址编译


8.以下说法不正确的是（）
A HTTP是一种请求/响应式的协议
B HTTP请求消息中Accept表示浏览器可接受的MIME类型
C HTTP请求消息中Accept-Encoding表示浏览器能够进行解码的数据编码方式
D HTTP请求消息中Css表示初始URL中的主机和端口


9.关于计算机网络，下列描述当中，正确的是（ C ）
A 在同一信道上同一时刻，可进行双向数据传送的通信方式是半双工
B TCP协议是无连接的；UDP协议是面向连接的
C 假设一个主机的ip地址为192.168.8.123，而子网掩码为255.255.255.248，那么该主机的网络号是192.168.8.120
D 计算机网络中的OSI结构分别是：物理层，数据链路层，传输层，会话层，表示层，应用层


10.下列关于 http 状态码描述正确的是（ C ）
A 404读取浏览器缓存，502错误网关
B 404找不到资源，403服务器错误
C 500服务器错误，304读取浏览器缓存
D 304服务器错误，200请求成功
E 500找不到资源，200请求成功


11.美国节日
描述：
和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。
输入描述：
输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
输出描述：
对应每一组数据，以“YYYY-MM-DD”格式输出当年所有的节日日期，每个日期占一行。

每组数据之后输出一个空行作为分隔。
示例1
输入：
2014
2013
输出：
2014-01-01
2014-01-20
2014-02-17
2014-05-26
2014-07-04
2014-09-01
2014-11-27
2014-12-25

2013-01-01
2013-01-21
2013-02-18
2013-05-27
2013-07-04
2013-09-02
2013-11-28
2013-12-25

#include<iostream>
using namespace std;

//根据蔡勒公式得出该天是星期几
//w=y+y/4+c/4-2c+26(m+1)/10+d-1
int getWeek(int year,int mouth,int day)
{
    if(mouth==1||mouth==2)
    {
        year-=1;
        mouth+=12;
    }
    int century=year/100;
    year%=100;
    int week=year+year/4+century/4-2*century+(26*(mouth+1))/10+day-1;
    week=(week%7+7)%7;
    if(week==0)
    {
        week=7;
    }
    return week;
}


void newYearDay(const int& year)
{
    printf("%d-01-01\n",year);
}


int dayDemand(int year,int mouth,int count,int dayOfWeek)
{
    int week=getWeek(year,mouth,1);
    int day=1+(count-1)*7+(7+dayOfWeek-week)%7;
    return day;
}

//马丁路德金纪念日(1月第三个星期一)
void martinLutherKingDay(const int & year)
{
    int day=dayDemand(year,1,3,1);
    printf("%d-01-%02d\n",year,day);
}
//总统节(2月第三个星期一)
void presidentDay(const int &year)
{
    int day=dayDemand(year,2,3,1);
    printf("%d-02-%02d\n",year,day);
}

//将士阵亡纪念日(5月最后一个星期一)
void memorialDay(const int & year)
{
    int week=getWeek(year,6,1);
    int day=31-((week==1)?6:(week-2));
    printf("%d-05-%02d\n",year,day);
}

void nationalDay(const int &year)
{
    printf("%d-07-04\n",year);
}

//劳动节(9月第一个星期一)
void laborDay(const int & year)
{
    int day=dayDemand(year,9,1,1);
    printf("%d-09-%02d\n",year,day);
}

//感恩节
void thanksGivingDay(const int & year)
{
    int day=dayDemand(year,11,4,4);
    printf("%d-11-%2d\n",year,day);
}

void christmasDay(const int & year)
{
    printf("%d-12-25\n",year);
}

int main()
{
    int year;
    while(cin>>year)
    {
        newYearDay(year);
        martinLutherKingDay(year);
        presidentDay(year);
        memorialDay(year);
        nationalDay(year);
        laborDay(year);
        thanksGivingDay(year);
        christmasDay(year);
        cout<<endl;
    }
    
    return 0;
}


12.分解因数
描述
所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
输入描述：
输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
输出描述：
对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
示例1
输入：
10<br/>18
输出：
10 = 2 * 5<br/>18 = 2 * 3 * 3


#include <iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        cout << n << " = ";
        for(int i = 2; i <= sqrt(n); ++i){
            //反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况
            while(n % i == 0 && n != i){
                cout << i << " * ";
                n /= i;//能整除就修改n的值
            }
        }
        cout << n << endl;
    }
    return 0;
}
*/

