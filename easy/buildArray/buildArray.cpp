/*1441. 用栈操作构建数组
给你一个目标数组 target 和一个整数 n。每次迭代，需要从  list = {1,2,3..., n} 中依序读取一个数字。

请使用下述操作来构建目标数组 target ：

Push：从 list 中读取一个新元素， 并将其推入数组中。
Pop：删除数组中的最后一个元素。
如果目标数组构建完成，就停止读取更多元素。
题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。
请返回构建目标数组所用的操作序列。
题目数据保证答案是唯一的。

示例 1：
输入：target = [1,3], n = 3
输出：["Push","Push","Pop","Push"]
解释： 
读取 1 并自动推入数组 -> [1]
读取 2 并自动推入数组，然后删除它 -> [1]
读取 3 并自动推入数组 -> [1,3]

示例 2：
输入：target = [1,2,3], n = 3
输出：["Push","Push","Push"]

示例 3：
输入：target = [1,2], n = 4
输出：["Push","Push"]
解释：只需要读取前 2 个数字就可以停止。

示例 4：
输入：target = [2,3,4], n = 4
输出：["Push","Pop","Push","Push","Push"]
提示：
1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target 是严格递增的
*/

class Solution 
{
public:
    //除开要返回的结果数组外，只使用了O(1)的空间复杂度
    //时间复杂度为O(n)
    //思路：一次遍历，由于target是严格递增的，所以拿一个整形变量去判断是否与之对应的位置的值是否相等
    //如果相等就只需要push
    //如果不相等那么就需要push和pop
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ret;
        int i = 1;
        int size = 0;
        int index = 0;
        while(size < target.size())
        {
            if(target[index] == i)
            {
                ret.push_back("Push");
                ++index;
                ++size;
            }
            else
            {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ++i;

        }
        return ret;
    }
};
