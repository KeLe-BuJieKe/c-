#include<iostream>
using namespace std;

int BF(string S, string T)
{
    //防止如果主串或者子串任意一个为空，就不需要查找了。还有当子串的长度大于主串就代表一定不匹配，不匹配就返回-1
    if (S.size() == 0 || T.size() == 0 || S.size() < T.size())
    {
        return -1;
    }

    //强制类型转换，分别得到主串S的长度，和子串T的长度
    int sLen = static_cast<int>(S.size());
    int tLen = static_cast<int>(T.size());

    int i = 0,j=0;     //i为主串的遍历下标      j为子串的遍历下标
    int start = 0;  //回溯下标
    while (i<sLen&&j<tLen)
    {
        if (S[i] == T[j])   //如果相同，主串与子串一起++
        {
            ++j;
            ++i;
        }
        else               //如果不相同，则让主串回溯到start++位置，因为start位置是上一轮的回溯下标
                           //j就重新回到0下标，之后就重新开始匹配
        {
            i = ++start;
            j = 0;
        }
    }

    if (j >= tLen)  //如果j>=tlen就是以及匹配成功了，其实这里的j不可能大于tlen，这里用==也可以
    {
        return i - j;
    }
    else            //不匹配返回-1
    {
        return -1;
    }
}

int main()
{
	string S="abcd";
	string T="bc";
	cout<<BF(S,T)<<endl;
	return 0;	
}
