/*542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
示例 1：
输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]

示例 2：
输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]
提示：
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
mat 中至少有一个 0 
*/

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        size_t row= mat.size(); //行数
        size_t col = mat[0].size(); //列数
        vector<vector<bool>>status(row,vector<bool>(col,false)); //使用状态矩阵
        vector<vector<int>>ret(row,vector<int>(col,0)); //存储结果矩阵
        int dx[4]={-1, 1, 0, 0};
        int dy[4]={0, 0, -1, 1};
        
        queue<pair<int,int>>q;

        for(size_t i = 0; i < row; ++i) //将所有的0都放入到队列中
        {
            for(size_t j = 0; j < col; ++j)
            {
                if(mat[i][j] == 0)
                {
                    q.push(make_pair(i,j));
                    status[i][j] = true;
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int>temp = q.front();
            q.pop();
            for(size_t k = 0; k < 4; ++k)
            {
                size_t nodeX = temp.first + dx[k];
                size_t nodeY = temp.second + dy[k];
                if(nodeX >=0 && nodeX < row && nodeY >=0 && nodeY < col && status[nodeX][nodeY] == false)
                {
                    ret[nodeX][nodeY] = ret[temp.first][temp.second] + 1;
                    status[nodeX][nodeY] = true;
                    q.push(make_pair(nodeX,nodeY));
                }
            }
        }
        return ret;
    }
};
