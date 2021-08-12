#include<iostream>
using namespace std;
/*
 *请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*思路：先翻转左子树，在翻转右子树，在将左右子树整体翻转
 */
class Solution 
{
public:
    void _mirrorTree(TreeNode*&node)
    {
        if(node==nullptr)
        {
            return;
        }
        _mirrorTree(node->left);
        _mirrorTree(node->right);
        TreeNode*left=node->left;
        TreeNode*right=node->right;
        node->left=right;
        node->right=left;
    }
    TreeNode* mirrorTree(TreeNode* root) 
    {
        _mirrorTree(root);
        return root;
    }
};

int main()
{


  return 0;
}
