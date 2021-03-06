/*15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]
*/

//方法一：
/*思路：利用dfs深搜来得到所有不同的能组成的三数组合，缺点：会超时*/
class Solution {
public:
    void _threeSum(std::vector<int>& nums, std::vector<std::vector<int>>& ret, std::vector<int>& path, std::vector<bool> flag, int start) {
        if (path.size() == 3) {
            if (path[0] + path[1] + path[2] == 0) {
                ret.push_back(path);
            }
            return;
        }
        int size = static_cast<int>(nums.size());
        for (int i = start; i < size; ++i) {
            if (flag[i] == true || (i > 0 && nums[i] == nums[i -1] && flag[i - 1] == false)) {
                continue;
            }
            flag[i] = true;
            path.push_back(nums[i]);
            _threeSum(nums, ret, path, flag, i + 1);
            path.pop_back();
            flag[i] = false;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        if (size < 3) {
            return std::vector<std::vector<int>>();
        }
        std::sort(nums.begin(), nums.end()); 
        std::vector<bool> flag(size, false);
        std::vector<std::vector<int>> ret;
        std::vector<int> path;
        _threeSum(nums, ret, path, flag, 0);
        return ret;
    }
};


//方法二：利用排序+双指针

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t size = nums.size();
        if(size < 3)  //当数组中的元素小于3个，一定凑不出三元组
        {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        for(size_t i = 0; i < size; ++i)
        {
            if(nums[i] > 0) //如果当前的第一个数都大于0了，由于后面的元素一定也是正数，说明不可能再找到等于0的三元组
            {
                return ret;
            }
            if(i != 0 && nums[i] == nums[i-1])  //去重
            {
                continue;
            }
            int left = i + 1; 
            int right = size -1;
            while(left < right)
            {
                if(nums[left] + nums[right] > -nums[i])
                {
                    --right; //两数之和太大，右指针往左移动
                }
                else if(nums[left] + nums[right] < -nums[i])
                {
                    ++left; //两数之和太小，左指针往右移动
                }
                else
                {
                    // 找到一个和为零的三元组，添加到结果中
                    // 并且不能重复，左右指针收缩，继续找下一个
                    ret.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left < right && nums[left] == nums[left-1])
                    {
                        ++left;
                    }
                    while(left < right && nums[right] == nums[right+1])
                    {
                        --right;
                    }
                }
            }
        }
        return ret;
    }
};
