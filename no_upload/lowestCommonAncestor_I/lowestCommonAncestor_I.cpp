#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
  /*
  二分查找，如果p与q有一个与根结点的值相等时，说明此时的cur是我们的最近祖先
  如果满足同时小于根结点，或者同时大于根结点，那么分别往左、右走。
  时间复杂度O(n)
  */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        TreeNode*cur=root;
        while(cur!=nullptr)
        {
            if( p->val<cur->val && q->val<cur->val )
            {
                cur=cur->left;
            }
            else if( p->val>cur->val && q->val>cur->val )
            {
                cur=cur->right;
            }
            else
            {
                break;
            }
        }
        return cur;
    }
};

int main()
{
  return 0;
}
