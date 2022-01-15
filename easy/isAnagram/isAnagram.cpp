/*242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
提示:
1 <= s.length, t.length <= 5*104
s 和 t 仅包含小写字母
*/

//利用哈希先来计算其中一个字符串的所有出现的字符的频次
//在让另外一个字符串放入到同一个哈希中，看它的频次是否小于0
//小于0则返回false
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<int, int> hash;
        for(auto &ch : s)
        {
            hash[ch]++;
        }
        for(auto &ch :t)
        {
            hash[ch]--;
            if(hash[ch] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
