/*49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母

*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    //利用哈希和排序，这样每一个拥有相同个数的同个数的英文单词排完序后，它们之间一定是相同的key值
    //这样就可以将这个string放入到这个哈希函数同样的key值下的second，即vector<string>当中
    //最后只需要将哈希函数中的每个second值放入到结果数组中即可
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ret;
        unordered_map<string,vector<string>>hash;
        string temp;
        for(auto &e:strs)
        {
            temp = e;
            sort(temp.begin(),temp.end());
            hash[temp].push_back(e);
        }
        
        for(auto &e:hash)
        {
            ret.push_back(e.second);
        }
        return ret;
    }
};


