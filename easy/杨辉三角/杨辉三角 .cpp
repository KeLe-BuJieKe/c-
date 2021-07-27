#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>>ret;
        for (size_t i = 0; i < numRows; ++i)   //初始化ret的左右两边，并给予值 1
        {
            vector<int>sub;
            sub.resize(i + 1);
            sub[0] = 1, sub[sub.size() - 1] = 1;
            ret.push_back(sub);
        }
        if (numRows > 2)
        {
            for (int i = 2; i < numRows; ++i)
            {
                for (int j = 1; j < i; ++j)
                {
                    ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
        }

        return  ret;
    }
};