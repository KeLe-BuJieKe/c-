#include<iostream>
using namespace std;

/*剑指 Offer 68 - II. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    bool FindPath(TreeNode*&root,TreeNode*&subNode)
    {
        if(root==nullptr)
        {
            return false;
        }

        return root==subNode
        ||FindPath(root->left,subNode)
        ||FindPath(root->right,subNode);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        
        //如果p或q任意一个是根结点，那么它们之间的最近公共祖先即是root
        if( p==root || q==root )
        {
            return root;
        }

        //判断q和p分别是左边还是在右边
        bool qInLeft,qInright,pInLeft,pInright;
        qInLeft=FindPath(root->left,q);
        qInright=!qInLeft;

        pInLeft=FindPath(root->left,p);
        pInright=!pInLeft;

        //情况一：一左一右的情况
        if( ( qInLeft&&pInright ) || ( qInright&&pInLeft ))
        {
            return root;
        }

        //情况二：p与q之间有一个是最近公共祖先
        if( pInLeft&&qInLeft )
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        if( pInright&&qInright )
        {
            return lowestCommonAncestor(root->right,p,q);
        }

        return nullptr;
    }
};

int main()
{


  return 0;
}
