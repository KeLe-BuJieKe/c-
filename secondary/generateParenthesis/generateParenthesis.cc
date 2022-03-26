/*22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]
*/

class Solution 
{
public:
    //当左括号数没有大于n时，先一直放左括号，最后再一层层放右括号
    void Dfs(vector<string>& ret, std::string& path, const std::string& str, const int& n, int left, int right)
    {
        if (n*2 == path.size())
        {
            ret.push_back(path);
            return;
        }

        if(left < n)
        {
            path.push_back(str[0]);
            Dfs(ret, path, str, n, left+1, right);
            path.pop_back();
        }

        if(right < left)
        {
            path.push_back(str[1]);
            Dfs(ret, path, str, n, left, right+1);
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) 
    {
        std::vector<std::string> ret;
        std::string path;
        std::string str = "()";
        Dfs(ret, path, str, n, 0, 0);
        return ret;
    }
};
