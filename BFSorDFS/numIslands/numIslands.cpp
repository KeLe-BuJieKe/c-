/*200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

输出：3
提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/

class Solution 
{
public:
    void DFS(vector<vector<char>>& grid, int x, int y, const int& m, const int& n)
    {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1')
        {
            return;
        }
        grid[x][y] = '0';
        DFS(grid, x+1, y, m, n);
        DFS(grid, x-1, y, m, n);
        DFS(grid, x, y+1, m, n);
        DFS(grid, x, y-1, m, n);
    }
    //深搜
    int numIslands(vector<vector<char>>& grid) 
    {
        size_t m = grid.size();
        size_t n = grid[0].size();
        int ret = 0;
        for(size_t i = 0; i < m; ++i)
        {
            for(size_t j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++ret;
                    DFS(grid, i, j, m, n);
                }
            }
        }
        return ret;
    }
};
