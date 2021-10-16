#include<iostream>
#include<string>
using namespace std;
/*标题：字符串中找出连续最长的数字串 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【字符串中找出连续最长的数字串】读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述：
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述：
在一行内输出str中里连续最长的数字串。
示例1：
输入：
abcd12345ed125ss123456789
输出：
123456789
*/
int main()
{
    string str;
    cin >> str;
    int i = 0, j = 0;
    int size = str.size();
    string ret;
    str.resize(size + 1);
    while (j < size)
    {
        if (isdigit(str[j]))
        {
            if (str[j] < str[j + 1])
            {
                while (isdigit(str[j + 1]) && j < size && str[j] <= str[j + 1])
                {
                    ++j;
                }
                ++j;
            }
            else if (str[j] == str[j + 1])
            {
                while (isdigit(str[j + 1]) && j < size && str[j] == str[j + 1])
                {
                    ++j;
                }
                ++j;
            }
            else
            {
                while (isdigit(str[j + 1]) && j < size && str[j] >= str[j + 1])
                {
                    ++j;
                }
                ++j;
            }
            int elemnum = j - i;
            if (ret.size() < elemnum)
            {
                ret = str.substr(i, elemnum);
            }
            i = j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    cout << ret;
    return 0;
}
