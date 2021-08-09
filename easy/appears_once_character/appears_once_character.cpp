#include<iostream>
#include<unordered_map>
using namespace std;
/*
题目：第一个只出现一次的字符
在字符串s中找出第一个只出现一次的字符。如果没有，返回一个单空格。s只包含小写字母。
*/
/*
思路：遍历两边字符串，利用哈希表把字符s存入到哈希表中，如果哈希表的val==2，说明该元素不是只出现一次
时间复杂度：O（n） 空间复杂度：O（n）
*/
class Solution 
{
public:
    char firstUniqChar(string s) 
    {
        unordered_map<char,int>mymap;
        for(size_t i=0;i<s.size();++i)
        {
            ++mymap[s[i]];
        }
        
        for(size_t i=0;i<s.size();++i)
        {
            if(mymap[s[i]]==1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};

void test()
{
  string s="dasdasde";
  Solution so;
  cout<<so.firstUniqChar(s)<<endl;

}

int  main()
{
  test();
  return 0;
}
