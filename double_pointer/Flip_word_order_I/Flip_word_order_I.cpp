#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
/*输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。*/

class Solution 
{
public:
    string reverseWords(string s)
    {
        vector<string>ret;
        string temp;
        s+=' ';
        for(auto e:s)
        {
            if(e!=' ')
            {
                temp+=e;
            }
            else
            {
                if(!temp.empty())
                {
                    ret.push_back(temp);
                    temp.clear();
                }
            }
        }
        reverse(ret.begin(),ret.end());
        s.clear();
        for(auto e:ret)
        {
            s+=e;
            s+=' ';
        }
        s.pop_back();
        return s;
    }
};


//测试代码
void test()
{
  string s="  hello world!  ";
  string ret=Solution().reverseWords(s);
  for(auto e:ret)
  {
    cout<<e;
  }
  cout<<endl;
}


int main()
{
  test();
  return 0;
}
