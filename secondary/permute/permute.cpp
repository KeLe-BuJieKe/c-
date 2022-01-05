/*46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
提示：
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/

class Solution 
{
public:
    vector<vector<int>>ret; //结果数组
    vector<int>temp;        //存储每一次递归的元素
    vector<bool>status;     //定义一个状态数组，表示该位置的数字是否给用过
    void _permute(vector<int>& nums,int len)
    {
        if(len==nums.size())    //如果等于我们要找的长度时，则说明已经排列完成了，直接把temp加入到我们的结果数组中
        {
            ret.push_back(temp);
            return;
        }
        for(size_t i=0;i<nums.size();++i)
        {
            if(!status[i]==true)
            {
                status[i]=true;         //使用了该元素就将该元素的状态设置成true
                temp.push_back(nums[i]);
                _permute(nums,len+1);
                temp.pop_back();        //把元素弹出后，将该元素的使用状态还原至false
                status[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        status.resize(nums.size(),false);   //初始化状态数组
        _permute(nums,0);
        return ret;
    }
};
