#include<iostream>
using namespace std;

/*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，
 * 这条路径上所有节点值相加等于目标和 targetSum 。叶子节点 是指没有子节点的节点。
链接：https://leetcode-cn.com/problems/path-sum
 * */


struct TreeNode
{  
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

/*思路：若当前节点就是叶子节点，那么我们直接判断 temp是否等于 targetsum即可 
 * 若当前节点不是叶子节点，我们只需要递归地询问它的子节点是否能满足条件即可。
 * */
class Solution 
{
public:
    bool _hasPathSum(TreeNode*root,int targetSum,int temp)
    {
        if(root==nullptr)
        {
            return false;
        }
        temp+=root->val;
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(temp==targetSum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return _hasPathSum(root->left,targetSum,temp)||_hasPathSum(root->right,targetSum,temp);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return _hasPathSum(root,targetSum,0);
    }
};

int main()
{
  
  return 0;
}
