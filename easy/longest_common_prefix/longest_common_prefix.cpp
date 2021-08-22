#include<iostream>
using namespace std;
#include<vector>

/*编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
链接：https://leetcode-cn.com/problems/longest-common-prefix
 */

class Solution 
{
public:
    
    string longestCommonPrefix(vector<string>& strs) 
    {
      //1、边界判断，如果个数<=1，那么公共子串就是自己本身
        if(strs.size()<=1)
        {
            return strs[0];
        }
        //2、我们把第一行的元素拿出来和每一行的元素进行比对，如果不同，则直接返回我们的结果
        //如果相同，我们则通过重载的+=运算符进行添加元素。
        string ret="";
        int col_len=static_cast<int>(strs[0].size());
        int row_len=static_cast<int>(strs.size());
        for(int col=0;col<col_len;++col)
        {
            char s=strs[0][col];
            for(int row=1;row<row_len;++row)
            {
              //3、继续边界判断
              //例如第1行有4个元素，而第二行只有2个元素
              //那么那么col==3时，就会造成越界的情况，所有如果我们的col>=当前的行数的元素时，直接返回结果
                if(col>=static_cast<int>(strs[row].size())||s!=strs[row][col])
                {
                    return ret;
                }
                if(row==row_len-1)
                {
                    ret+=s;
                }
            }
        }
        return ret;
    }
};


//测试代码
void test()
{
  vector<string>str{"dsagsdf","dsagfdsq","dssdweqfgdghh"};
  cout<<Solution().longestCommonPrefix(str)<<endl;
}
int main()
{
  test();
  return 0;
}
