#include<iostream>
using namespace std;
#include<vector>
#include<string>
/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
*/

class Solution 
{
public:
    bool _exist(vector< vector<bool> >&status,vector< vector<char> >& board,string word,int x,int y,int k)
    {
        //首先先进行判断边界判断，以及一定的减枝操作
        if( x<0|| x>=board.size() || y<0|| y>=board[0].size() || status[x][y]==true || board[x][y]!=word[k])
        {
            return false;
        }
        //如果我们的字符相等，并且此时我们的k等于我们word的元素个数-1时，这就表明已经匹全部配成功了
        if(board[x][y]==word[k]&&k==word.size()-1)
        {
            return true;
        }
        //访问后把每个状态改为true
        status[x][y]=true;
        bool sign=_exist(status,board,word,x-1,y,k+1)
        ||_exist(status,board,word,x+1,y,k+1)
        ||_exist(status,board,word,x,y-1,k+1)
        ||_exist(status,board,word,x,y+1,k+1);
        //这一步可以不要，但不要的前提是，将我们的status不要用引用传参
        status[x][y]=false;
        return sign;
    }
    bool exist(vector< vector<char> >& board, string word) 
    {   
        //status是一个记录每一个对应的位置是否被使用过的状态二维数组
        vector< vector<bool> >status(board.size(),vector<bool>(board[0].size(),false));
        for(size_t i=0;i<board.size();++i)
        {
            for(size_t j=0;j<board[0].size();++j)
            {
                if(_exist(status,board,word,i,j,0))
                {
                    return  true;
                }
            }
        }
        return false;
    }
};


void test()
{
  vector< vector<char> >board={ {'A','B','C','E'} , {'S','F','C','S'} , {'A','D','E','E' } };
  string word="ABCCED";
  cout<<Solution().exist(board,word)<<endl;
}

int main()
{
  test();
  return 0;
}
