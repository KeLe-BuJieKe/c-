/*106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
   */


#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int &pi,int inbegin,int inend) 
    {
        if(inbegin>inend)
        {
            return nullptr;
        }
        TreeNode* newNode=new TreeNode(postorder[pi]);
        int rooti=inbegin;
        while(rooti<=inend)
        {
            if(postorder[pi]==inorder[rooti])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }
        --pi;
        newNode->right=_buildTree(inorder,postorder,pi,rooti+1,inend);
        newNode->left=_buildTree(inorder,postorder,pi,inbegin,rooti-1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int i=postorder.size()-1;
        return _buildTree(inorder,postorder,i,0,postorder.size()-1);
    }
};
