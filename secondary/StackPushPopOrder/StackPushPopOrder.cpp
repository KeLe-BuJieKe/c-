#include<iostream>
using namespace std;
#include<stack>
#include<vector>

/*剑指 Offer 31. 栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
*/

class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int>st;
        int pushedSize=static_cast<int>(pushed.size());
        int pushedi=0;

        //先入栈，再判断栈顶元素和出栈数组中的元素是否匹配
        //如果匹配则再pop掉这个元素
        //最后如果我们的辅助栈st为空了，那么压入与弹出是满足要求的
        while(pushedi<pushedSize)
        {
            st.push(pushed[pushedi]);
            
            while(!st.empty()&&st.top()==popped.front())
            {
                st.pop();
                popped.erase(popped.begin());
            }
            ++pushedi;
        }
        return st.empty();
    }
};

int main()
{
  return 0;
}
