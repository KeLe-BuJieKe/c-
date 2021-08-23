#include<iostream>
using namespace std;

/*输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
  //递归，判断每个结点的左右子树的最大深度
    int maxDepth(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main()
{
  return 0;
}
