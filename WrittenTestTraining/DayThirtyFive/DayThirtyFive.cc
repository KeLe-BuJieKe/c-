/*
1.主机甲和乙已建立了TCP连接，甲始终以MSS=1KB大小的段发送数据，并一直有数据发送；乙每收到一个数据段
都会发出一个接收窗口为10KB的确认段。若甲在t时刻发生超时时拥塞窗口为8KB，则从t时刻起，不再发生超时的情况下，经过10个RTT后，甲的发送窗口是 （ A ）
A 10KB
B 12KB
C 14KB
D 15KB

解题分析：
1.把慢开始的门限值设为当前窗口的一半，即ssthresh=0.5*8kb=4kb
2.把拥塞窗口cwnd设置为1个最大报文段mss大小
3.再次从慢开始阶段，发生拥塞后
开始慢启动cwnd=1kb，之后呈指数增长
经过1个RTTcwnd=2*1=2kb
经过2个RTTcwnd=2*2=4kb
经过3个RTTcwnd=4+1=5kb
...
经过9个RTTcwnd=10，因为发送端不能超过接收端10，此后拥塞窗口一直保持cwnd=10kb
发送窗口大小=min(接收窗口，拥塞窗口)=10kb


2.某主机的IP 地址为 180.80.77.55，子网掩码为 255.255.252.0。若该主机向其所在子网发送广播分组，则目的地址可以是（ D ）。
A 180.80.76.0
B 180.80.76.255
C 180.80.77.255
D 180.80.79.255

180.80.77.55
77:0100 1101
1.子网掩码255.255.252.0 即1111 1111. 1111 1111. 1111 1100 .0000 0000
网络号为连续的1，网络号22位，主机号为连续的0，也就是10位
2.然后题目要发送广播分组，所以求的是广播地址，广播地址的主机位也是全为1，所以
180.80.77.55所在的广播地址就是180.80.010011(11.11111111),括号里的是主机号，主机号全为1就是广播地址
即180.80.79.255


3.ARP 协议的功能是（ A ）。
A 根据 IP 地址查询 MAC 地址
B 根据 MAC 地址查询 IP 地址
C 根据域名查询 IP 地址
D 根据 IP 地址查询域名


4.下列关于IP 路由器功能的描述中，正确的是（ C ）。
Ⅰ． 运行路由协议，设置路由表
Ⅱ． 监测到拥塞时，合理丢弃 IP 分组
Ⅲ． 对收到的 IP 分组头进行差错校验，确保传输的 IP 分组不丢失
Ⅳ、 根据收到的 IP 分组的目的 IP 地址，将其转发到合适的输出线路上
A 仅Ⅲ、 Ⅳ
B 仅Ⅰ、 Ⅱ、 Ⅲ
C 仅Ⅰ、 Ⅱ、 Ⅳ
D Ⅰ、 Ⅱ、 Ⅲ、 Ⅳ


IP层不负责差错检测和纠错，差错检测由数据链路层实现


5.以太网的MAC 协议提供的是（ A ）。
A 无连接不可靠服务
B 无连接可靠服务
C 有连接不可靠服务
D 有连接可靠服务



6.在TCP/IP 体系结构中，直接为 ICMP 提供服务的协议是（ B ）。
A PPP
B IP
C UDP
D TCP


7.主机甲向主机乙发送一个（SYN=1， seq=11220）的 TCP 段，期望与主机乙建立 TCP 连接，若主机乙接受该连接请求，则主机乙向主机甲发送的正确的 TCP 段可
能是（ C ）。
A （ SYN=0， ACK=0， seq=11221， ack=11221）
B （ SYN=1， ACK=1， seq=11220， ack=11220）
C （ SYN=1， ACK=1， seq=11221， ack=11221）
D （ SYN=0， ACK=0， seq=11220， ack=11220）


8.TCP/IP 参考模型的网络层提供的是（ A ）。
A 无连接不可靠的数据报服务
B 无连接可靠的数据报服务
C 有连接不可靠的虚电路服务
D 有连接可靠的虚电路服务


9.主机甲和主机乙之间建立一个TCP连接，TCP最大段长度为1000字节，若主机甲的当前拥塞窗口为4000字节，在主机甲向主机乙连续发送 两 个最大段后，成功收到
主机乙发送的第一 个 段的确认段，确认段中通告的 接收 窗口大小为2000字节，则此时主机甲还可以向主机乙发送的最大字节数是( A )
A 1000
B 2000
C 3000
D 4000


10.某网络的IP地址空间为192.168.5.0/24 ， 采用 定 长子网划分，子网掩码为255.255.255.248，则该网络的最大子网个数 、 
每个子网内的最大可分配地址个数为( B )
A 32，8
B 32，6
C 8，32
D 8，30


11.标题：年会抽奖 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【年会抽奖】今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
输入描述：
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
输出描述：
对应每一组数据，以“xx.xx%”的格式输出发生无人获奖的概率。
示例1：
输入
2
输出
50.00%


#include<iostream>
#include<cmath>
using namespace std;
//1.概率：n个人取到的不是自己名字的序列个数/n个人可能抽取的所有可能性
long long NotSelf(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return (n - 1) * (NotSelf(n - 1) + NotSelf(n - 2));
}
long long Count(int n)
{
    double s = 1;
    double m = 1;
    for (int i = 2; i <= n; ++i)
    {
        m *= i;
    }
    return m;
}

int main()
{
    int n;
    while (cin >> n)
    {
        double ret = (double)NotSelf(n) / Count(n);         //计算概率
        printf("%2.2f%%\n", ret * 100);
    }
    return 0;
}



12.标题：抄送列表 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【抄送列表】NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因
此他要过滤掉这些次要的邮件，优先处理重要的邮件。
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
输入描述：
输入有多组数据，每组数据有两行。
第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。
第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。
输出描述：
如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
示例1：
输入
Joe,Kewell,Leon\nJoe\n"Letendre, Bruce",Joe,"Quan, William"\nWilliam
输出
Ignore
Important

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str,name;
    while(getline(cin,str))
    {
        getline(cin,name);
        
        vector<string>ret;
        size_t size=str.size();
        for(size_t i=0;i<size;++i)
        {
            if(str[i]=='\"')
            {
                int nextPos=str.find('\"',i+1);
                string temp=str.substr(i+1,nextPos-i-1);
                ret.push_back(temp);
                i=nextPos+1;
            }
            else
            {
                size_t index=str.find(',',i);
                string temp="";
                if(index==-1)
                {
                    temp=str.substr(i);
                    i=str.size();
                }
                else
                {
                    size_t nextIndex=str.find(',',i);
                    temp=str.substr(i,nextIndex-i);
                }
                ret.push_back(temp);
           }
        }
        size_t j;
        for(j=0;j<ret.size();++j)
        {
            if(ret[j]==name)
            {
                cout<<"Ignore"<<endl;
                break;
            }
        }
        if(j==ret.size())
        {
            cout<<"Important!"<<endl;
        }
        
    }
    return 0;
}
*/
