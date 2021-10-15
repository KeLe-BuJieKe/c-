/*
【组队竞赛】牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现
队伍的水平值等于该队伍队员中第二高水平值。
例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.
输入描述：
输出描述：
示例1：
输入
输出
代码片段
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
输出一个整数表示所有队伍的水平值总和最大值.
2
5 2 8 5 1 5
1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int groupnum;
	cin >> groupnum;
	vector<int>arr(3 * groupnum, 0);
	for (int i = 0; i<3 * groupnum; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int size = groupnum;
	long long ret = 0;
	int i = 3 * groupnum - 2;
	while (size--)
	{
		ret += arr[i];
		i -= 2;
	}
	cout << ret;
	return 0;
}
