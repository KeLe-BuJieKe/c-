/*【删除公共字符】输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符
串变成”Thy r stdnts.”
输入描述：
每个测试输入包含2个字符串
输出描述：
输出删除后的字符串
示例1：
输入：They are students. aeiou
输出：Thy r stdnts.
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string ret;
  string t;
  string sub;
  getline(cin,t);
  getline(cin, sub);
  int hash[256]={0};
  for(auto &e:sub)
  {
    hash[e]=1;
  }
  for(auto &e:t)
  {
    if(hash[e]==0)
    {
    ret+=e;
    }
  }
  cout<<ret;
  return 0;
}

