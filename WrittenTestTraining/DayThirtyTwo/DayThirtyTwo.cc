/*
1.在计算机网络中，TCP和UDP协议的相似之处是（ D ）
A 面向非连接的协议
B 面向连接的协议
C 其余选项都不对
D 传输层协议


2.在 OSI 参考模型中能实现路由选择，拥塞控制与互联功能的层是（ B ）
A 物理层
B 网络层
C 数据链路层
D 应用层


3.在TCP/IP中，ICMP属于哪一层协议？( A )
A IP
B PPP
C UDP
D TCP


4.在发送TCP接收到确认ACK之前，由其设置的重传计时器到时，这时发送TCP会__A__。
A 重传重要的数据段
B 放弃该连接
C 调整传送窗口尺寸
D 向另一个目标端口重传数据


5.下列哪项最恰当地描述了建立TCP连接时“第一次握手”所做的工作C____。
A “连接发起方”向“接收方”发送一个SYN-ACK段
B “接收方”向“连接发起方”发送一个SYN-ACK段
C “连接发起方”向目标主机的TCP进程发送一个SYN段
D “接收方”向源主机得到TCP进程发送一个SYN段作为应答


6.关于以下 URL 的描述错误的是（ A ）
A http表明使用TCP协议；
B 又名统一资源定位符，方便确定一个资源，并表示它在哪里
C URL中隐藏了端口号，默认是80端口
D 访问URL可使用大写字母


7.不属于交换机攻击的是（ A ）
A 目录遍历攻击
B MAC泛洪攻击
C VLAN攻击
D DHCP欺骗攻击


8.在下面给出的协议中，（ B ）是TCP/IP的应用层协议
A ARP和FTP
B DNS和SMTP
C RARP和DNS
D ICMP和IGMP


9.IP地址块为211.168.15.192/26、211.168.15.160/27和211.168.15.128/27三个地址块经聚合后可用地址数为（ A ）？
A 126
B 62
C 128
D 68


10.以下不是合法HTTP请求方法的是( B )
A GET
B SET
C HEAD
D PUT


11.标题：淘宝网店 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【淘宝网店】NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。
输入描述：
输入包含多组数据。
每组数据包含两个日期from和to (2000-01-01 ≤ from ≤ to ≤ 2999-12-31)。
日期用三个正整数表示，用空格隔开：year month day。
输出描述：
对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
示例1：
输入
2000 1 1 2000 1 31\n2000 2 1 2000 2 29
输出
62\n29

#include<iostream>
using namespace std;

const int dayArr[13] = { 0,31,28,31,60,31,60,31,62,60,62,30,62 };
bool isLeap(int year)
{
    if ( (year % 400 == 0) ||( (year % 4 == 0 )&& (year % 100 != 0)))
    {
        return true;
    }
    return false;
}

int isPriNum(int month)
{
    if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
    {
        return 1;
    }
    return 2;
}

int main()
{
    int dayArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    while (cin >> startYear >> startMonth >> startDay >> endYear >> endMonth >> endDay)
    {
        int earn = 0;
        if (startYear == endYear)
        {
            if (startMonth == endMonth)
            {
                earn = (endDay - startDay+1) * isPriNum(endMonth);

            }
            else
            {
                //不同月份
                //1、先计算两者相差整月份的收益
                earn += ((dayArr[startMonth] - startDay+1) * isPriNum(startMonth));
                //2、再计算不满一个月的收益
                earn += (endDay * isPriNum(endMonth));
                for (int i = startMonth + 1; i < endMonth; ++i)
                {
                    earn += (dayArr[i] * isPriNum(i));
                }
            }
            if (isLeap(startYear) && (startMonth <= 2 && endMonth > 2))
            {
                earn += 1;
            }
        }
        else
        {
            //1、先计算两者相差整月份的收益
            earn += ((dayArr[startMonth] - startDay + 1) * isPriNum(startMonth));

            earn += (endDay * isPriNum(endMonth));

            //起始日期年份不足一年整月份的收益
            if (isLeap(startYear) && startMonth <= 2)
            {
                earn += 1;
            }
            for (int i = startMonth + 1; i < 13; ++i)
            {
                earn += (dayArr[i] * isPriNum(i));
            }

            //截至日期年份不足一年整月份的收益
            if ( isLeap(endYear) && ( ( endMonth > 2 ) ||( endMonth==2 && endDay==29 ) ) )
            {
                earn += 1;
            }
            for (int i = 1; i < endMonth; ++i)
            {
                earn+= (dayArr[i] * isPriNum(i));
            }


            //计算两者相差整年份的收益
            for (int i = startYear + 1; i < endYear; ++i)
            {
                earn += 579;
                if (isLeap(i))
                {
                    earn += 1;
                }
            }
        }

        cout << earn << endl;
    }
    return 0;
}


12.标题：斐波那契凤尾 | 时间限制：3秒 | 内存限制：32768K | 语言限制：不限
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
输入描述:
输入有多组数据。
每组数据一行，包含一个整数n (1≤n≤100000)。
输出描述:
对应每一组输入，输出第n个斐波那契数的最后6位。
示例1
输入
1<br/>2<br/>3<br/>4<br/>100000
输出
1<br/>2<br/>3<br/>5<br/>537501

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>fibArr(100000,0);
    fibArr[0]=1;
    fibArr[1]=2;
    for(int i=2;i<100000;++i)
    {
        fibArr[i]=(fibArr[i-1]+fibArr[i-2])%1000000;
    }
    int n;
    
    while(cin>>n)
    {
        if(n<25)
        {
            cout<<fibArr[n-1]<<endl;
        }
        else
        {
            printf("%06d\n",fibArr[n-1]);
        }
    }
    return 0;
}
*/
