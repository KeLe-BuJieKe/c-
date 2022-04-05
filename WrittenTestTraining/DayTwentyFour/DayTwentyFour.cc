/*
1.将N条长度均为M的有序链表进行合并，合并以后的链表也保持有序，时间复杂度为( A )?
A O(N * M * logN)
B O(N*M)
C O(N)
D O(M)


2.下设栈S的初始状态为空，元素a,b,c,d,e,f依次入栈S，出栈的序列为b,d,c,f,e,a则栈S的容量至少为（ D ）
A 6
B 5
C 4
D 3


3.大小为MAX的循环队列中，f为当前队头元素位置，r为当前队尾元素位置(最后一个元素的位置)，则任意时刻，队列中的元素个数为( B )
A r-f
B (r-f+MAX+1)%MAX
C r-f+1
D (r-f+MAX)%MAX


4.n！后面有多少个0,6！=1*2*3*4*5*6=720.720后面有1个0，n=10000，求n！。( B )
A 2498
B 2499
C 2450
D 2451


5.若一棵二叉树具有12个度为2的结点，6个度为1的结点，则度为0的结点个数是（ C）。
A 10
B 11
C 13
D 不确定
度为0得结点个数=度为2得结点个数+1


6.若将关键字1，2，3，4，5，6，7 依次插入到初始为空的平衡二叉树 T 中，则 T 中平衡因子为 0 的分支结点的个数是（ D ）。
A 0
B 1
C 2
D 3


7.已知小根堆为8,15,10,21,34,16,12，删除关键字 8 之后需重建堆，在此过程中，关键字之间的比较次数是（ C ） 。
A 1
B 2
C 3
D 4


8.已知某个哈希表的n个关键字具有相同的哈希值，如果使用二次探测再散列法将这n个关键字存入哈希表，至少要进行__E__次探测。
A n-1
B n
C n+1
D n(n+1)
E n(n+1)/2
F 1+n(n+1)/2


9.下列选项中，不可能是快速排序第2趟排序结果的是 （ C）
A 2,3,5,4,6,7,9
B 2,7,5,6,4,3,9
C 3,2,5,4,7,6,9
D 4,2,3,5,7,6,9


10.设有向图G=(V,E)，顶点集 V={V0,V1,V2,V3}，边集 E={<v0,v1>，<v0,v2>，<v0,v3>，<v1,v3>}。若从顶点 V0 开始对图进行深度优先遍历，则可能得到的不同
遍历序列个数是 （ D） 。
A 2
B 3
C 4
D 5



11.小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，
每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，
请设计一个算法使小东拿到价值最高的礼物。
给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。

class Bonus {
public:
    int getMost(vector<vector<int> > board)
    {
        vector<vector<int>>dp(6,vector<int>(6));
        //设f(i,j)定义为当前位置最大的礼物和
        //我们可以知道第一行与第一列只能是由当前行或者当前列来走得到，所以 我们直接初始化好
        //这里的状态转移 方程为：dp[i][j]=max(dp[i-1][j],dp[i][j-1])+board[i][j]
        dp[0][0]=board[0][0];
        for(int i=1;i<6;++i)
        {
            dp[0][i]=board[0][i]+dp[0][i-1];
        }
        for(int j=1;j<6;++j)
        {
            dp[j][0]=dp[j-1][0]+board[j][0];
        }
        for(int i=1;i<6;++i)
        {
            for(int j=1;j<6;++j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+board[i][j];
            }
        }
        return dp[5][5];
    }
};



12.定义一个二维数组 N*M ，如 5 × 5 数组下所示：


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的路线。
入口点为[0,0],既第一格是可以走的路。
数据范围： 2≤n,m≤10  ， 输入的内容只包0≤val≤1 
输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。
输出描述：
左上角到右下角的最短路径，格式如样例所示。
示例1
输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
示例2
输入：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0
输出：
(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4)
说明：
注意：不能斜着走！！    


#include <iostream>
#include <vector>
using namespace std;

//回溯
void MazeTrack(vector<vector<int>>& ret,vector<vector<int>>& path, vector<vector<int>>& arr, int x, int y)
{
    path.push_back({ x, y });
    arr[x][y] = 1;
    int row = arr[0].size();
    int col = arr.size();
    if (x == col - 1 && y == row - 1)
    {
        if (ret.empty() || path.size() < ret.size()) //求最短路径
        {
            ret = path;
        }
        return;
    }
    if (x - 1>= 0 && arr[x - 1][y] == 0)
    {
        MazeTrack(ret, path, arr, x - 1, y);
    }
    if (x + 1< col && arr[x + 1][y] == 0)
    {
        MazeTrack(ret, path, arr, x + 1, y);
    }
    if (y - 1>= 0 && arr[x][y - 1] == 0)
    {
        MazeTrack(ret, path, arr, x, y - 1);
    }
    if (y + 1< row && arr[x][y + 1] == 0)
    {
        MazeTrack(ret, path, arr, x, y + 1);
    }
    path.pop_back();
    arr[x][y] = 0;
}

void PrintPath(vector<vector<int>>& ret)
{
    for (int i = 0; i < ret.size(); ++i)
    {
        cout << "(";
        for (int j = 0; j < ret[i].size(); ++j)
        {
            cout << ret[i][j];
            if (j != ret[j].size() - 1)
            {
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
}

int main()
{
    int col, row;
    while (std::cin >> row >> col)
    {
        std::vector<std::vector<int>> maze(row, std::vector<int>(col, 0));
        vector<vector<int>>path;
        vector<vector<int>>ret;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                std::cin >> maze[i][j];
            }
        }
        MazeTrack(ret, path, maze, 0, 0);
        PrintPath(ret);
    }
    return 0;
}

*/
