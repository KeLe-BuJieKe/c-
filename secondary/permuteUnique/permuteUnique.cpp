/*47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
提示：
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution 
{  
public:
    void _permute(vector<int>& nums, vector<vector<int>>& path, vector<int>& step, vector<bool>& status, size_t size)
    {
        if(size == nums.size())
        {
            path.push_back(step);
            return;
        }
        for(size_t i = 0; i < nums.size(); ++i)
        {
            //当前这个元素如果被访问过了，就跳过
            //或者是当前这个元素与前一个元素相同，且前一个没有被访问时
            //当前一个元素没被访问时，说以nums[i]这种元素开始的情况在之前已经出现过，这里不需要再次出现
            if( (status[i] == true) || (i > 0 && nums[i] == nums[i-1] && status[i-1] == false) )
            {
                continue;
            }
            status[i] = true;
            step.push_back(nums[i]);
            _permute(nums, path, step, status, size+1);
            step.pop_back();
            status[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        size_t size = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool>status(size, false);
        vector<vector<int>>path;
        vector<int>step;
        _permute(nums, path, step, status, 0);
        
        return path;
    }
};
