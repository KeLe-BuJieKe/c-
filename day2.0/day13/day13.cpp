#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1����������ָ���У�����������Ѱַ��ʽ�� B ����
	A:ֱ��Ѱַ B:����Ѱַ C:����Ѱַ D:���Ѱַ
	*/
}

void Question_2()
{
	/*
	2��C���ԣ����к궨�壺 ����ʽB*B��ֵΪ �� ( D )
	#define A 4+5
	#define B A*A
	A: 81		B: 69			C: 6561			D: 29
	*/
}

void Question_3()
{
	/*
	3����������ܴ������С���������Ϊ�� A ��
	A:λ		 B:�ֽ�		C:��		 D:˫��
	*/
}


//�����㷨��
/*
4������һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
���ӣ�https://leetcode-cn.com/problems/subsets/
*/
#include<vector>
class Solution
{
public:
    //numsΪ��Ŀ�еĸ�������
    //pathΪ·�������Ҫ��ÿһ�� path ��������
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
    //˼·
    /*1.�ҽ�������������Ƚ���������·����Ӧ�ü������������Բ����ڽ���������
    ����˵�� start ����Խ������߽��ʱ�򣬳�����Լ�������һ��ݹ��ˣ���˲���Ҫ��д��������,ֱ�Ӽ�������
    2.��ѡ���б�ѡ���б�Ϊ������һ��ѡ��·��֮���ʣ�µ���
    3.�ж��Ƿ���Ҫ��֦����������Ŀ��˵nums�е�Ԫ�ػ�����ͬ���ʲ���Ҫ
    4.����ѡ�񣬽�����һ��ѡ�񣬵ݹ�
    5.����ѡ��
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
5������һ�����������ҳ������·���ĳ��ȡ�����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� 
�㲻���ڶԽ��߷������ƶ����ƶ����߽��⣨���������ƣ���
���ӣ�https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
*/
#include<algorithm>

//����һ��û�м������ͨ������ȣ��ᳬ��ʱ������
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

//����������ȡ���仯�������
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
            //�������0��˵���õ�û��·���߹�����ÿ�������̵�����������Ϊ1������������
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
