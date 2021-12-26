/*59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]
提示：
1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>ret(n,vector<int>(n,0));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int temp =1;
        while(true)
        {
            for(int i = left; i <= right; ++i)
            {
                ret[top][i] =temp++;
            }
            if(++top > bottom)
            {
                break;
            }

            for(int j = top; j <=bottom ;++j)
            {
                ret[j][right] = temp++;
            }
            if(--right < left)
            {
                break;
            }

            for(int k = right; k >= left; --k)
            {
                ret[bottom][k] = temp++;
            }
            if(--bottom < top)
            {
                break;
            }

            for(int m = bottom; m >= top; --m)
            {
                ret[m][left] = temp++;
            }
            if(++left > right)
            {
                break;
            }
        }
        return ret;
    }
};
