#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;
class Solution
{
public:
    vector<string>str{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    string temp;
    vector<string> _letterCombinations(vector<string>& ret, string digits, int length)
    {
        if (length == digits.size())
        {
            ret.push_back(temp);
            return {};
        }
        for (int i = 0; i < str[digits[length] - '0'].size(); ++i)
        {
            temp += str[digits[length] - '0'][i];
            _letterCombinations(ret, digits, length + 1);
            temp.pop_back();
        }

        return ret;
    }
    /*
    思路：dfs,判断有没有达到我们要的字符串长度，如果没有继续递归到下一层，达到了就说明这一层就是我们所想要的字符，把它push进去
    ret---用来存放结果的数组
    temp---是存放选择的路径的字符串
    length---字符串的长度
    */
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        vector<string>ret;
        return _letterCombinations(ret, digits, 0);
    }
};
int main()
{
    //vector<string>str{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    string a = "23";
    vector<string>ss = Solution().letterCombinations(a);
    system("pause");
    return 0;
}