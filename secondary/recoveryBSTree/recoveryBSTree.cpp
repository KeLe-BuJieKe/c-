#include<iostream>
using namespace std;
#include<stack>

/*99. 恢复二叉搜索树
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
示例 1：
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。

示例 2：
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution
{
public:
  //思路：利用二叉搜索树的中序遍历是有序的性质
  //时间复杂度O(n) 空间复杂度O(n)
    void recoverTree(TreeNode* root)
    {
        stack<TreeNode*>st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* ret1 = nullptr;
        TreeNode* ret2 = nullptr;

        while (!st.empty() || cur != nullptr)
        {
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (prev != nullptr)
            {
                if (cur->val <= prev->val)
                {
                    if (ret1 == nullptr)
                    {
                        ret1 = prev;
                        ret2 = cur;
                    }
                    else
                    {
                        ret2 = cur;
                    }
                }
            }
            prev = cur;
            cur = cur->right;
        }
        swap(ret1->val, ret2->val);
    }
};

int main()
{
  TreeNode*A =new TreeNode(1);
  TreeNode*B =new TreeNode(3);
  TreeNode*C =new TreeNode(2);
  return 0;
}
