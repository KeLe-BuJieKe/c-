/*529. 扫雷游戏
让我们一起来玩扫雷游戏！
给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
'M' 代表一个 未挖出的 地雷，
'E' 代表一个 未挖出的 空方块，
'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
'X' 则表示一个 已挖出的 地雷。
给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，
clickc 是列下标）。
根据以下规则，返回相应位置被点击后对应的盘面：
如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回盘面。
示例 1:
输入：board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
输出：[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]

示例 2：
输入：board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
输出：[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
提示：
m == board.length
n == board[i].length
1 <= m, n <= 50
board[i][j] 为 'M'、'E'、'B' 或数字 '1' 到 '8' 中的一个
click.length == 2
0 <= clickr < m
0 <= clickc < n
board[clickr][clickc] 为 'M' 或 'E'
*/

//思路：利用dfs来进行遍历，并根据3条规则来进行递归判断
class Solution 
{
public:
    int arr[8][2] = {{-1,-1},{-1,0},{-1,1}
                            ,{0,-1},{0,1}
                            ,{1,-1},{1,0},{1,1}};
    int getMine(const vector<vector<char>>& board, const int& row, const int& col)
    {
        int count = 0;
        for(size_t i = 0; i < 8; ++i)
        {
            int x = row + arr[i][0];
            int y = col + arr[i][1];
            if (x >=0 && x < board.size()&& y >= 0 && y < board[0].size() && board[x][y] == 'M')
            {
                ++count;
            }
        }
        return count;
    }
    void _updateBoard(vector<vector<char>>& board, const int& row, const int& col)
    {
        if(board[row][col] == 'M') //规则1，如果是雷将其改为X
        {
            board[row][col] = 'X';
            return;
        }
        else if(board[row][col] == 'E') //如果不是雷且该位置没有被挖过
        {
            int count = getMine(board, row, col); //统计该位置周围的八个位置的雷的数目
            if(count == 0)
            {
                board[row][col] = 'B'; // 规则2
                for(size_t i = 0; i < 8; ++i)
                {
                    int x = row + arr[i][0];
                    int y = col + arr[i][1];
                     if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
                    {
                        _updateBoard(board, x, y);
                    }
                }
            }
            else
            {
                board[row][col] = '0' + count; //规则3
                return;
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int row = click[0];
        int col = click[1];
        _updateBoard(board, row, col);

        return board;
    }
};
