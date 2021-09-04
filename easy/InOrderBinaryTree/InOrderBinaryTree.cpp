#include<iostream>
#include<vector>
#include<stack>
using std::stack;
using std::vector;
struct TreeNode {
     int val;
     TreeNode *left;
TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    
//递归法
int TreeSize(struct TreeNode*root)
{
      return root==NULL?0:TreeSize(root->left)+TreeSize(root->right)+1;
       
}

void _inorderTraversal(struct TreeNode*root,int *array,int *pi)
{
      if(NULL==root)
      {
                return;
                    
      }
          _inorderTraversal(root->left,array,pi);
              array[(*pi)++]=root->val;
                  _inorderTraversal(root->right,array,pi);

}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
      *returnSize=TreeSize(root);
          int *resultArray=(int *)malloc(sizeof(struct TreeNode)*(*returnSize));
              int i=0;
                  _inorderTraversal(root,resultArray,&i);
                      return resultArray;

}

//迭代法
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return {};
        }

        stack<TreeNode*>path;
        vector<int>ret;
        TreeNode*cur=root;
        while(cur!=nullptr)
        {
            path.push(cur);
            cur=cur->left;
        }

        while(!path.empty())
        {
            TreeNode*temp=path.top();
            path.pop();
            ret.push_back(temp->val);

            cur=temp->right;
            while(cur!=nullptr)
            {
                path.push(cur);
                cur=cur->left;
            }

        }
        return  ret;
    }
};



int main()
{
  return 0;
}
