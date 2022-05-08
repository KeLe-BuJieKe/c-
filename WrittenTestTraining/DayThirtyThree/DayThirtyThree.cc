/*
1./etc/resolv.conf的用途是( C )
A 邮件服务的设置文件
B DHCP的设置文件
C DNS解析的设置文件
D 网络路由的设置文件

resolv.conf这个文件下有个nameserver
它表示的是解析域名时使用该地址指定的主机为域名服务器


2.能够PING通同网段的节点，但却如PING不通其他网段的所有节点的最可能的原因( A )
A 本机网关设置错误
B 本机没有正确设置DNS
C 对方运行的是不同的操
D 二层交换机故障

A:ping是TCP/IP协议族的一部分，使用ICMP协议，ICMP底层使用IP协议。
主要是用来检测网络是否通畅，如果要ping其他网段，则需要设置网关。
B:和DNS没有关系，DNS设置错会影响访问公网服务器的域名，而不会影响内部子设备是否ping通
C:ping命令是跨操作系统的，windows主机能够ping通linux主机
D:二层交换机如果出现故障，那么同网段主机则不会ping通

3.常被提及的Dos攻击的是以下的行为；( C )
A 侵入目标服务器，获取重要数据
B 采用穷举的方式获得登录账号
C 发送无效的请求，使得正确的请求无法被响应
D 利用微软DOS从操作系统图的各种漏洞达到攻击的目的


4.以下不是DNS服务的作用的是：( D )
A 将主机名翻译到指定的IP地址
B 将IP地址反解成主机名
C 解析特定类型的服务的地址，如MX,NS
D 将IP解析成MAC地址


5.在小红书公司的局域网中，署队长的私人电脑可以查看到的同事的电脑，也成功了登录了QQ，
但无法访问到公司的站点"http://www.xiaohongshu.com”,请协助署队长查找最有可能出现的问题的地方是？( C )
A UDP
B DHCP
C DNS
D HTTP
E 浏览器

解题分析：
1.可以再私网当中查看到同事的电脑，说明再局域网内通信没有问题
2.能成功登录QQ，说明访问QQ服务器没有问题，换而言之，访问外网是通的
3.但是访问不了一个特定的域名，所以问题就出现在了域名转换成ip的过程，所以，出问题的点在DNS


6.将一个C类网络划分20个子网，最适合的子网掩码是多少（ B ）
A 255.255.255.240
B 255.255.255.248
C 255.255.255.252
D 255.255.255.255

解题分析：
A类网络默认的子网掩码：255.0.0.0
B类网络默认的子网掩码：255.255.0.0
C类网络默认的子网掩码：255.255.255.0

2^4<20<2^5
如果划分20个子网，需要将子网掩码向后使用5个比特位
255.255.255.11111000
11111000是二进制，转换为十进制是248
所以子网掩码是255.255.255.248


7.以下哪种http状态下，浏览器会产生两次http请求？（ C）
A 400
B 404
C 302
D 304

302临时重定向


8.局域网的网络地址192.168.1.0/24，局域网络连接其他网络的网关地址是192.168.1.1。主机192.168.1.20访问172.16.1.0/24网络时，其路由设置正确的是？( B )
A route add default 192.168.1.0 netmask 172.16.1.1 metric 1
B route add -net 172.16.1.0 gw 192.168.1.1 netmask 255.255.255.0 metric 1
C route add -net 192.168.1.0 gw 192.168.1.1 netmask 255.255.255.0 metric 1
D route add -net 172.16.1.0 gw 172.16.1.1 netmask 255.255.255.0 metric 1

解析分析：
(1)路由信息组成部分：1.目的主机的网络地址 2.下一个跳转的地址 3. 子网掩码
(2)-net后面跟的是目标网络，gw就是gateway(网关入口),表示从那个网关到那个目标网络
所以，如题，因为主机要访问172.16.1.0/24网络，那么目标网络就是172.16.1.0/24
因此-net后面跟就是172.16.1.0/24，排除AC
因为gw表示网关入口，那么gw后面跟的就是网关地址，即192.168.1.1


9.建立一条TCP连接需要（C）个步骤，关闭一个TCP连接需要（C）个步骤
A 4，3
B 4，4
C 3，4
D 3，3


10.以下关于HTTP状态码的描述，错误的是？（ C ）
A 100，代表客户端应当继续发送请求
B 2xx，代表请求已成功被服务器接收、理解、并接受
C 301，代表被请求的资源已永久移动到新位置，用于重定向
D 4xx，代表服务器在处理请求的过程中有错误或者异常状态发生



11.标题：剪花布条 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【剪花布条】一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小
饰条来呢？
输入描述：
输入包含多组数据。
每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。
花纹条和小饰条不会超过1000个字符长。
输出描述：
对应每组输入，输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果占一行。
示例1：
输入
abcde a3\naaaaaa aa

#include<iostream>
#include<vector>
#include<string>
using namespace std;
void getNext(vector<int>& next, string& t)
{
    next[0] = -1;
    next[1] = 0;
    int k = 0;
    int i = 1;
    int tLen = static_cast<int>(t.size());
    while (i < tLen - 1)
    {
        if (k == -1 || t[i] == t[k])
        {
            next[i + 1] = k + 1;
            ++i;
            ++k;
        } 
        else
        {
            k = next[k];
        }
    }
}

int KMP(string& s, string& t, int position)
{
    int sLen = static_cast<int>(s.size());
    int tLen = static_cast<int>(t.size());
    if (sLen < tLen)
    {
        return -1;
    } 
    int i = position, j = 0;
    vector<int>next(tLen);
    getNext(next, t);
    while (i < sLen && j < tLen)
    {
        if (j == -1 || s[i] == t[j])
        {
            ++i;
            ++j;
        } 
        else
        {
            j = next[j];
        }
    } 
    if(j >= tLen)
    {
        return i - j;
    } 
    else
    {
        return -1;
    }
} 

int getTrimStrip(string& s, string& t)
{
    int count = 0;
    for (size_t i = 0; i < s.size();)
    {
        int index = KMP(s, t, i);
        if (index == -1)
        {
            break;
        } 
        else
        {
            ++count;
            i = index + t.size();
        }
    } 
    return count;
} 
int main()
{
    //s是主串，t是子串
    string s, t;
    while (cin >> s >> t)
    {
        cout << getTrimStrip(s, t) << endl;
    } 
    return 0;
}



12.标题：客似云来 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【客似云来】NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早
餐后，接下来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。
输入描述：
测试数据包括多组。
每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。
输出描述：
对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐。


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int from, to;
    while (cin >> from >> to)
    {
        if (to == 1)
        {
            cout << 1 << endl;
            continue;
        } 
        vector<long long >fibArr(to);
        fibArr[0] = 1;
        fibArr[1] = 1;
        for (size_t i = 2; i < fibArr.size(); ++i)
        {
            fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
        } 
        long long ret = 0;
        for (int i = from - 1; i < to; ++i)
        {
            ret += fibArr[i];
        } 
        cout << ret << endl;
    } 
    return 0;
}
*/
