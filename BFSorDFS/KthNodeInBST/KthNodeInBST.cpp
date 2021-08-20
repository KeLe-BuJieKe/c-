#include<iostream>
using namespace std;

//给定一棵二叉搜索树，请找出其中第k大的节点。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution 
{
public:
    //思路：利用搜索二叉树的特性，二叉搜索树的中序遍历是升序，可以知道二叉搜索树 的中序遍历倒序为降序
    //终止条件： 当节点 rootroot 为空（越过叶节点），则直接返回；
    //递归右子树： 即 dfs(root->right)
    //这里的k一定得带上引用，如果不带会发生返回的值错误。
    void dfs(TreeNode*root,int &k,int &val)
    {
        if(root==nullptr)
        {
            return;
        }
        dfs(root->right,k,val);
        if(--k==0)
        {
            val=root->val;
            return;
        }
        dfs(root->left,k,val);
    }
    int kthLargest(TreeNode* root, int k) 
    {
        int val=0;
        dfs(root,k,val);
        return val;
    }
};


int main()
{

  return 0;
}
