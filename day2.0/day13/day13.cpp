#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、操作数在指令中，是下列哪种寻址方式（ B ）。
	A:直接寻址 B:立即寻址 C:隐含寻址 D:间接寻址
	*/
}

void Question_2()
{
	/*
	2、C语言，设有宏定义： 则表达式B*B的值为 ： ( D )
	#define A 4+5
	#define B A*A
	A: 81		B: 69			C: 6561			D: 29
	*/
}

void Question_3()
{
	/*
	3、计算机所能处理的最小的数据项称为（ A ）
	A:位		 B:字节		C:字		 D:双字
	*/
}


//二、算法题
/*
4、给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
链接：https://leetcode-cn.com/problems/subsets/
*/
#include<vector>
class Solution
{
public:
    //nums为题目中的给的数组
    //path为路径结果，要把每一条 path 加入结果集
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>& path, int start)
    {
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(ret, nums, path, i + 1);
            ret.push_back(path);
            path.pop_back();
        }
    }
    //思路
    /*1.找结束条件，这里比较特殊所有路径都应该加入结果集，所以不存在结束条件。
    或者说当 start 参数越过数组边界的时候，程序就自己跳过下一层递归了，因此不需要手写结束条件,直接加入结果集
    2.找选择列表，选择列表为，是上一条选择路径之后的剩下的数
    3.判断是否需要减枝，由于这题目所说nums中的元素互不相同，故不需要
    4.做出选择，进行下一层选择，递归
    5.撤销选择
    */
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>ret;
        ret.push_back({});
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int>path;
            path.push_back(nums[i]);
            ret.push_back(path);
            backtrack(ret, nums, path, i + 1);
        }
        return ret;
    }
};


/*
5、给定一个整数矩阵，找出最长递增路径的长度。对于每个单元格，你可以往上，下，左，右四个方向移动。 
你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
*/
#include<algorithm>

//方法一：没有记忆的普通深度优先，会超出时间限制
class Solution1
{
public:
    int _longestIncreasingPath(vector<vector<int>>& matrix, int x, int y)
    {
        int len = 1;
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y])
        {
            len = max(len, _longestIncreasingPath(matrix, x - 1, y) + 1);
        }
        if (x + 1 < matrix.size() && matrix[x + 1][y] > matrix[x][y])
        {
            len = max(len, _longestIncreasingPath(matrix, x + 1, y) + 1);
        }
        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y])
        {
            len = max(len, _longestIncreasingPath(matrix, x, y - 1) + 1);
        }
        if (y + 1 < matrix[x].size() && matrix[x][y + 1] > matrix[x][y])
        {
            len = max(len, _longestIncreasingPath(matrix, x, y + 1) + 1);
        }
        return len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        vector<vector<int>>Pathlength(matrix.size(), vector<int>(matrix[0].size(), 0));
        int _max = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                _max = max(_max, _longestIncreasingPath(matrix, i, j));
            }
        }
        return _max;
    }
};

//方法二：采取记忆化深度优先
class Solution
{
public:
    int _longestIncreasingPath(vector<vector<int>>& Pathlength, vector<vector<int>>& matrix, int x, int y)
    {
        if (Pathlength[x][y] != 0)
        {
            return Pathlength[x][y];
        }
        else
        {
            //如果等于0，说明该点没有路径走过，但每个点的最短递增长度至少为1，就是它本身
            Pathlength[x][y]++;
        }
        if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y])
        {
            Pathlength[x][y] = max(Pathlength[x][y], _longestIncreasingPath(Pathlength, matrix, x - 1, y) + 1);
        }
        if (x + 1 < matrix.size() && matrix[x + 1][y] > matrix[x][y])
        {
            Pathlength[x][y] = max(Pathlength[x][y], _longestIncreasingPath(Pathlength, matrix, x + 1, y) + 1);
        }
        if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y])
        {
            Pathlength[x][y] = max(Pathlength[x][y], _longestIncreasingPath(Pathlength, matrix, x, y - 1) + 1);
        }
        if (y + 1 < matrix[x].size() && matrix[x][y + 1] > matrix[x][y])
        {
            Pathlength[x][y] = max(Pathlength[x][y], _longestIncreasingPath(Pathlength, matrix, x, y + 1) + 1);
        }
        return Pathlength[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        vector<vector<int>>Pathlength(matrix.size(), vector<int>(matrix[0].size(), 0));
        int _max = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                _max = max(_max, _longestIncreasingPath(Pathlength, matrix, i, j));
            }
        }
        return _max;
    }
};
