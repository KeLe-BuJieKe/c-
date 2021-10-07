#include<iostream>

using namespace std;
/*450. 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
示例:
root = [5,3,6,2,4,null,7]
key = 3
    5
   / \
  3   6
 / \   \
2   4   7
给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
    5
   / \
  4   6
 /     \
2       7
另一个正确答案是 [5,2,6,null,4,null,7]。
    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        TreeNode*parent=nullptr;
        TreeNode*cur=root;
        while(cur!=nullptr)
        {
            if(cur->val<key)
            {
                parent=cur;
                cur=cur->right;
            }
            else if(cur->val>key)
            {
                parent=cur;
                cur=cur->left;
            }
            else
            {
                if(cur->left==nullptr)
                {
                    if(parent==nullptr)
                    {
                        root=cur->right;
                    }
                    else
                    {
                        if(parent->left==cur)
                        {
                            parent->left=cur->right;
                        }
                        else
                        {
                            parent->right=cur->right;
                        }
                    }
                    delete cur;
					          cur =nullptr;
                }
                else if(cur->right==nullptr)
                {
                    if(parent==nullptr)
                    {
                        root=cur->left;
                    }
                    else
                    {
                        if(parent->left==cur)
                        {
                            parent->left=cur->left;
                        }
                        else
                        {
                            parent->right=cur->left;
                        }
                    }
                    delete cur;
					          cur =nullptr;
                }
                else
                {
                    TreeNode*rightmin=cur->right;
                    TreeNode*rightminparent=nullptr;

                    while(rightmin->left!=nullptr)
                    {
                        rightminparent=rightmin;
                        rightmin=rightmin->left;
                    }
                    if(rightminparent!=nullptr)
                    {
                        cur->val=rightmin->val;
                        rightminparent->left=rightmin->right;
                    }
                    else
                    {
                        cur->val=rightmin->val;
                        cur->right=rightmin->right;
                    }
                    delete rightmin;
                    rightmin=nullptr;
                }
            }
        }
        return root;
    }
};

int main()
{


  return 0;
}
