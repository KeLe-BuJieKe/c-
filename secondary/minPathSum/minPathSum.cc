/*64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t row = grid.size();
        size_t col = grid[0].size();
        for (size_t i = 1; i < row; ++i){
            grid[i][0] += grid[i - 1][0];
        }
        for (size_t j = 1; j < col; ++j){
            grid[0][j] += grid[0][j - 1];
        }
        for (size_t i = 1; i < row; ++i){
            for (size_t j = 1; j < col; ++j){
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row - 1][col - 1];
    }
};
