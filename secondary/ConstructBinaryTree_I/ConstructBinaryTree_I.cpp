#include<iostream>
using namespace std;
#include<vector>
/*剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
示例 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

示例 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
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
  /*思路：
   * 1、根据前序找根
   * 2、中序确定左子树区间和右子树区间
   * 使用左子树的前序和左子树的中序区间递归构建左子树
   * 同理右子树的前序和右子树的中序区间递归构建右子树
   */
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int &prei,int inBegin,int inend) 
    {
        //如果inbegin>inend就说明没有元素可以构建了
        if(inBegin>inend)
        {
            return nullptr;
        }
        TreeNode*root=new TreeNode(preorder[prei]);

        //找到当前的根
        int rooti=inBegin;
        while(rooti<=inend)
        {
            if(preorder[prei]==inorder[rooti])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }

        //用刚刚找到的根来划分左右区间
        //1、判断该结点是否有左子树区间
        if(inBegin<=rooti-1)
        {
            root->left=_buildTree(preorder,inorder,++prei,inBegin,rooti-1);
        }
        else  //如果该结点并没有左子树区间，那么将它的左子树指针置为空
        {
            root->left=nullptr;
        }
        //2、判断该结点是否有右子树区间
        if(rooti+1<=inend)
        {
            root->right=_buildTree(preorder,inorder,++prei,rooti+1,inend);
        }
        else   //同理如果该结点并没有右子树区间，那么将它的右子树指针置为空
        {
            root->right=nullptr;
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int prei=0,inBegin=0,inend=static_cast<int>(inorder.size())-1;

        return _buildTree(preorder,inorder,prei,inBegin,inend);
    }
};

int main()
{
  
  return 0;
}
