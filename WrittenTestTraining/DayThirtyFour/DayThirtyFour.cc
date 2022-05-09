/*
1.上网的时候，访问某个网页却突然出现了某个运营商的网页（如联通、电信）。出现此问题可能的原因是?（ A ）
A DNS劫持
B DDoS攻击
C MAC地址欺骗
D 伪造DHCP服务器


2.TCP建立连接的三次握手中，第二次握手发送的包会包含的标记，最正确的描述是？( B )
A ACK
B SYN,ACK
C SYN,PSH
D SYN


3.当使用TCP协议编程时，下列问题哪个是必须由程序员考虑和处理的？( D )
A 乱序数据包的重传
B 数据传输过程中的纠错
C 网络拥塞处理
D 发送数据的格式和应用层协议


4.现在有很多网站都开始选择HTTPS作为默认的协议，HTTPS的用途是（ C ）
A 可以加速页面的加载，提高响应速度
B 可以让服务器端主动推送消息到客户端
C 可以确保传输数据的安全性和防篡改
D 为了提高浏览器兼容性


5.TCP断开连接的四次挥手中，第四次挥手发送的包会包含的标记，最正确的描述是？（ C ）
A FIN
B FIN,PSH
C ACK
D FIN,ACK


6.某浏览器发出的HTTP 请求报文如下：
GET /index.html HTTP/1.1
Host:www.test.edu.cn 
Connection:Close
Cookie:123456
下列叙述错误的是( C )
A 该浏览器请求浏览 index.html
B Index.html 存放在 www.test.edu.cn 上
C 该浏览器请求使用持续连接
D 该浏览器曾经浏览过 www.test.edu.cn 


7.主机甲和主机乙新建一个TCP 连接，甲的拥塞控制初始阈值为 32KB，甲向乙始终以 MSS=1KB 大小的段发送数据，并一直有数据发送；乙为该连接分配 16KB 接收
缓存，并对每个数据段进行确认， 忽略段传输延迟。若乙收到的数据全部存入缓存，不被取走，则甲从连接建立成功时刻起，未发送超时 的情况下，经过 4 个 RTT
后，甲的发送窗口是（ A ）。
A 1KB
B 8KB
C 16KB
D 32KB


8.通过POP3 协议接收邮件时，使用的传输层服务类型是（ D ）。
A 无连接不可靠的数据传输服务
B 无连接可靠的数据传输服务
C 有连接不可靠的数据传输服务
D 有链接可靠的数据传输服务


9.下列关于UDP协议的叙述中，正确的是 （ B）
Ⅰ 提供无连接服务
Ⅱ 提供复用/分用服务
Ⅲ 通过差错校验，保障可靠数据传输
A 仅Ⅰ
B 仅Ⅰ、Ⅱ
C 仅Ⅱ、Ⅲ
D Ⅰ、ⅡⅢ


10.主机甲与主机乙之间已建立一个TCP 连接，双方持续有数据传输，且数据无差错与丢失。若甲收到 1 个来自乙的 TCP 段，该段的序号为 1913、确认序号为 2046、
有效载荷为 100 字节，则甲立即发送给乙的 TCP 段的序号和确认序号分别是（ B ）。
A 2046、 2012
B 2046、 2013
C 2047、 2012
D 2047、 2013



11.标题：收件人列表 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【收件人列表】NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓
名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
输入描述：
输入包含多组数据。
每组数据的第一行是一个整数n (1≤n≤128)，表示后面有n个姓名。
紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
输出描述：
对应每一组输入，输出一行收件人列表。
示例1：
输入
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
输出
Joe, "Quan, William", "Letendre,Bruce"
Leon, Kewell
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void getRecipientList(const vector<string>& nameStr)
{
    for(size_t i=0;i<nameStr.size();++i)
    {
        if(nameStr[i].find(',')!=-1||nameStr[i].find(' ')!=-1)
        {
            cout<<"\""<<nameStr[i]<<"\"";
        }
        else
        {
            cout<<nameStr[i];
        }
        if(i!=nameStr.size()-1)
        {
            cout<<", ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        getchar();
        vector<string>nameStr(n);
        for(int i=0;i<n;++i)
        {
            getline(cin,nameStr[i]);
        }
        getRecipientList(nameStr);
    }
    return 0;
}



12.标题：养兔子 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【养兔子】一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
输入描述：
测试数据包括多组，每组一行，为整数n(1≤n≤90)。
输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。
示例1
输入
1<br/>2
输出
1<br/>2
#include<iostream>
#include<vector>
using namespace std;

long long getRabbitNum(const int & n)
{
    if(n<=2)
    {
        return n;
    }
    vector<long long>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;++i)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    while( cin >> n)
    {
        cout<<getRabbitNum(n)<<endl;
    }
    return 0;
}
*/
