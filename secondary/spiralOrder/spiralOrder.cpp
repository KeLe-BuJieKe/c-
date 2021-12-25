/*
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

ass Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int>ret;
        int row = static_cast<int>(matrix[0].size());
        int col = static_cast<int>(matrix.size());
        int top = 0;
        int left = 0;
        int right = row - 1;
        int bottom = col - 1;

        while(true)
        {
            for(int i = left; i <= right; ++i)
            {
                ret.push_back(matrix[top][i]);
            }
            if( ++top > bottom) //边界检查以及更新边界
            {
                break;
            }

            for(int j = top; j <= bottom; ++j)
            {
                ret.push_back(matrix[j][right]);
            }
            if( --right < left) //边界检查以及更新边界
            {
                break;
            }

            for(int k = right; k >= left; --k)
            {
                ret.push_back(matrix[bottom][k]);
            }
            if( --bottom < top) //边界检查以及更新边界
            {
                break;
            }

            for(int m = bottom; m >= top; --m)
            {
                ret.push_back(matrix[m][left]);
            }
            if( ++left > right) //边界检查以及更新边界
            {
                break;
            }
        }
        return ret;
    }
};
