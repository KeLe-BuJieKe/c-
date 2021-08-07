#include<iostream>
#include<string>
using namespace std;


/*
//方法一：不限制使用额外的空间的做法，空间复杂度O（n+2*m），时间复杂度O（n）
思路：利用string的+=，碰到空格加 %20，不是空格加位置的字符。
*/
class Solution1 
{
public:
    string replaceSpace(string s) 
    {
        string ret;
        for(size_t i=0;i<s.size();++i)
        {
            if(s[i]!=' ')
            {
                ret+=s[i];
            }
            else
            {
                ret+="%20";
            }
        }
        return ret;
    }
};


/*
方法二：时间复杂度O（n）,遍历了2遍数组，空间复杂度O（1）,我们这里只扩容使用了2*空格个数容量
思路：先统计空格个数，在将该字符串s扩容，并将该数组从后往前遍历
*/
class Solution2 
{
public:
    string replaceSpace(string s) 
    {
        size_t spacenum=0;  //统计空格个数
        for(size_t i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
                ++spacenum;
            }
        }

        int originalindex=s.size()-1;  //原来的最后一个元素的下标
        int Nowindex=s.size()+2*spacenum-1; //扩容后元素的最后的下标
        s.resize(s.size()+2*spacenum);  //扩容

        while(spacenum>0)   //空格数为0，则说明替换完毕
        {
            if(s[originalindex]!=' ') 
            {
                s[Nowindex--]=s[originalindex--];
            }
            else
            {
                s[Nowindex--]='0';
                s[Nowindex--]='2';
                s[Nowindex--]='%';
                --spacenum;
                --originalindex;
            }
        }
        return s;
    }
};


int main()
{
  return 0;
}
