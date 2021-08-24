#include<iostream>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。*/


//方法一：自顶向下，时间复杂度:(O^2) 空间复杂度:O(n)
class Solution1 
{
public:
    int maxDepth(TreeNode*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return true;
        }
        int leftlen= maxDepth(root->left);
        int rightlen= maxDepth(root->right);
        return abs(rightlen-leftlen)<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
};


//方法二：自底向上，时间复杂度O(n) 空间复杂度O(n)
class Solution 
{
public:
    int _isBalanced(TreeNode*root)
    {
      //如果为空返回0，代表深度0
        if(root==nullptr)
        {
            return 0;
        }

        int left=_isBalanced(root->left);
        int right=_isBalanced(root->right);
        //为什么要设置left和right分别为-1的情况呢？
        //这是因为当left==-1,right==-1时，abs(left-right)==0
        //或者其中一个为-1，另一个为0时，abs(left-right)==1
        if(left==-1||right==-1||abs(left-right)>1)
        {
            return -1;
        }
        else
        {
            return max(left,right)+1;
        }
        
    }
    bool isBalanced(TreeNode* root) 
    {
      //返回的值与0进行比较，如果深度为0，则说明是空树
      //返回的如果是负数那么就代表不是平衡二叉树
       return _isBalanced(root)>=0;
    }
};


int main()
{
  return 0;
}
