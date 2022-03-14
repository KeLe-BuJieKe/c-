/*73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool rowflag = false;
        bool colflag = false;
        size_t rowsize = matrix.size();
        size_t colsize = matrix[0].size();
        for(size_t i = 0; i < colsize; ++i) //记录第一行有没有0
        {
            if(matrix[0][i] == 0)
            {
                rowflag = true;
            }
        }
        for(size_t j = 0; j < rowsize; ++j) //记录第一列有没有0
        {
            if(matrix[j][0] == 0)
            {
                colflag = true;
            }
        }

        for(size_t i = 1; i < rowsize; ++i)//判断第2行以及第2列开始以后有没有0，并将这个每一列喝每一行的第一个元素设置为0
        {
            for(size_t j = 1; j < colsize; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(size_t i = 1; i < rowsize; ++i)//在将上面志好的标志用将剩余的置为0
        {
            for(size_t j = 1; j < colsize; ++j)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowflag)
        {
            for(size_t i = 0; i < colsize; ++i)
            {
                matrix[0][i] = 0;
            }
        }
        if(colflag)
        {
            for(size_t j = 0; j < rowsize; ++j)
            {
                matrix[j][0] = 0;
            }
        }
    }
};
