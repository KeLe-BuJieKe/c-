#include<iostream>
#include<stack>
using namespace std;


/*【合法括号序列判断】
给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。
测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
*/
class Parenthesis 
{
public:
    bool chkParenthesis(string A, int n)
    {
        stack<char>st;
        for (const auto& e : A)
        {
            if (e == '(')
            {
                st.push('(');
            }
            else if (e == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};
