#include<iostream>
using namespace std;


/*标题：走方格的方案数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【走方格的方案数】
请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往
下走，不能往左和往上走。
本题含有多组样例输入.
输入描述：
输入两个正整数
输出描述：
返回结果
示例1：
输入
2
2
输出
6

*/
#include<iostream>
#include<vector>
using namespace std;
int planNum(int& n, int& m)
{
    if (n == 0 || m == 0)
    {
        return 1;
    }
    //当时没理解题意，一直没明白测试用理怎么走出6种的
		//这道题明面上看着是走方格，其实不然，走的是方格的边缘线。当有n行、m列的方格时，相当于有n+1行、m+1列的方格线。
		//这就相当于n+1行、m+1列的方格
    vector<vector<int>>arr(n + 1, vector<int>(m + 1, 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[n][m];
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << planNum(n, m) << endl;
    }
    return 0;
}
