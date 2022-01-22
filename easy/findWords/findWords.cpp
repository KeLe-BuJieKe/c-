/*500. 键盘行
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
美式键盘 中：
第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。

示例 1：
输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]

示例 2：
输入：words = ["omk"]
输出：[]

示例 3：
输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]
提示：
1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] 由英文字母（小写和大写字母）组成
*/


//思路：先利用一个哈希映射，将所有的小写字符进行直接定制法。
//先取出第一个字符看它出现再哪一行，最后判断所有的字符将其与第一个字符所出现的行做比对
//相同就继续，不相同就使flag置为false
class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        const string rowNum = "12210111011122000010020202";
        vector<string> ret;
        for(auto &str : words)
        {
            bool flag = true;
            char row = rowNum[tolower(str[0]) - 'a'];
            for(size_t i = 1; i < str.size(); ++i)
            {
                if(rowNum[tolower(str[i]) - 'a'] != row)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                ret.push_back(str);
            }
        }
        return ret;
    }
};
