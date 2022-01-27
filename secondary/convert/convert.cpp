/*6. Z 字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

示例 3：
输入：s = "A", numRows = 1
输出："A"
提示：
1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000
*/

//按行排序
//思路：通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行
//然后只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
//时间复杂度O(n) 空间复杂度O(n)
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
        {
            return s;
        }
        vector<string> arr(numRows);
        size_t size = s.size();
        int index = 0;
        int flag = -1;
        for(size_t i = 0; i < size; ++i)
        {
            arr[index] += s[i];
            if(index == numRows-1 || index == 0)
            {
                flag = -flag;
            }
            index += flag;
        }
        string ret;
        for(string& str: arr)
        {
            ret += str;
        }
        return ret;
    }
};<Paste>
