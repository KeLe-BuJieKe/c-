/*42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
提示：
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

/*我们在遍历数组时维护一个栈。如果当前的条形块小于或等于栈顶的条形块，我们将条形块的索引入栈，意思是当前的条形块被栈中的前一个条形块界定。
 * 如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，因此我们可以弹出栈顶元素并且累加答案到ret
 * */
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        std::stack<int> st;
        int size = static_cast<int>(height.size());
        int ret = 0;
        for (int i = 0; i < size; ++i)
        {
            //找一个V行拐点
            while (!st.empty() && height[i] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if(st.empty())
                {
                    break;
                }
                int left = st.top();
                int width = i - left - 1;
                int high = std::min(height[i], height[left]) - height[top];
                ret += width * high;
            }
            st.push(i);
        }
        return ret;
    }
};
