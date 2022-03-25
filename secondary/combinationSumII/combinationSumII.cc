/*40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/


class Solution 
{
public:
    void Dfs(vector<vector<int>>& ret, vector<int>& candidates, int& target, vector<int>& path, int start)
    {
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }
        size_t size = candidates.size();
        for(size_t i = start; i < size; ++i)
        {
						//去重
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            target -= candidates[i];
            path.push_back(candidates[i]);
            Dfs(ret, candidates, target, path, i+1);
            target += candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
				//排序
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ret;
        std::vector<int> path;
        Dfs(ret, candidates, target, path, 0);
        return ret;
    }
};
