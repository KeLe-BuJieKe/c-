#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>


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
  //该题思路与ConstructBinaryTree_I的思路相同，唯一的区别即是先进行构建右子树再构建左子树
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int &posi,int inbegin,int inend) 
    {
        //如果inbegin>inend就说明没有元素可以构建了
        if(inbegin>inend)
        {
            return nullptr;
        }

        TreeNode*root=new TreeNode(postorder[posi]);
        //找到当前的根
        int rooti=inbegin;
        while(rooti<=inend)
        {
            if(postorder[posi]==inorder[rooti])
            {
                break;
            }
            else
            {
                ++rooti;
            }
        }

        //用刚刚找到的根来划分左右区间
        //1、先判断该结点是否有右子树区间
        if(rooti+1<=inend)
        {
            root->right=_buildTree(inorder,postorder,++posi,rooti+1,inend);
        }
        else    //如果该结点并没有右子树区间，那么将它的右子树指针置为空
        {   
            root->right=nullptr;
        }

        //2、再判断该结点是否有左子树区间
        if(inbegin<=rooti-1)
        {
            root->left=_buildTree(inorder,postorder,++posi,inbegin,rooti-1);
        }
        else    //同理如果该结点并没有左子树区间，那么将它的左子树指针置为空
        {
            root->left=nullptr;
        }

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        reverse(postorder.begin(),postorder.end()); //先逆置
        int posi=0,inbegin=0,inend=static_cast<int>(inorder.size())-1;
        return _buildTree(inorder,postorder,posi,inbegin,inend);
    }
};

int main()
{


  return 0;
}
