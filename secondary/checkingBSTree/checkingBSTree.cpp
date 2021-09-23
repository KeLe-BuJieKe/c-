#include<iostream>
using namespace std;
#include<stack>
#include<limits.h>
/*给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
*/


struct TreeNode {
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
  /*思路：利用中序遍历
   * 如果当前遍历的元素比我们前一个元素的值小，则证明不是我们的二叉搜索树 
   * */
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*>st;
        TreeNode*cur=root;
        long long prevval=LONG_MIN;
        while(!st.empty()||cur!=nullptr)
        {
            while(cur!=nullptr)
            {
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            if(cur->val<=prevval)
            {
                return false;
            }
            prevval=cur->val;
            cur=cur->right;
        }
        return true;
    }
};

int main()
{
  return 0;
}
