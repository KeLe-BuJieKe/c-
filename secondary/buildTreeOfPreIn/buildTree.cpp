#include<iostream>
#include<vector>
using namespace std;


/*给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点*/
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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int& pi,int inbegin,int inend) 
    {
        if(inbegin>inend)
        {
            return nullptr;
        }
        TreeNode* newNode=new TreeNode(preorder[pi]); //创建根结点
        int rooti=inbegin;  //中序找根来分左右子区间
        while(rooti<=inend)
        {
            if(preorder[pi]==inorder[rooti])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }
        ++pi;
        newNode->left= _buildTree(preorder,inorder,pi,inbegin,rooti-1);
        newNode->right= _buildTree(preorder,inorder,pi,rooti+1,inend);
        return newNode;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int  i=0;
        return _buildTree(preorder,inorder,i,0,inorder.size()-1);
    }
};
