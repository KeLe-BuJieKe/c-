#include<iostream>
#include<vector>
using namespace std;

//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
//该方法的时间复杂度为O（m+n）,空间复杂度为O（1）
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty()) //首先先判断是否为空，如果为空直接返回false
	{
		return false;
	}
  //思路：
  //我们初始化先判断第[0][j]列的元素
  //如果target比他大，则说明target可能在它的下方
  //如果target比他小，则说明target可能在它的左边
	int i = 0;
	int j = matrix[i].size() - 1;
	while (j < matrix[i].size() && i < matrix.size()&&i >= 0 && j >= 0)
	{
		if (matrix[i][j] > target)
		{
			--j;
		}
		else if (matrix[i][j] < target)
		{
			++i;
		}
		else
		{
			return true;

		}
    //如果到这里还没有退出函数，则说明target不在该数组中，返回false
		return false;
	}
}
int main()
{
	vector<vector<int>>ret{ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	cout<<findNumberIn2DArray(ret, 20)<<endl;
	return 0;
}
