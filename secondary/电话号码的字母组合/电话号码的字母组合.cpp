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
    ˼·��dfs,�ж���û�дﵽ����Ҫ���ַ������ȣ����û�м����ݹ鵽��һ�㣬�ﵽ�˾�˵����һ�������������Ҫ���ַ�������push��ȥ
    ret---������Ž��������
    temp---�Ǵ��ѡ���·�����ַ���
    length---�ַ����ĳ���
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