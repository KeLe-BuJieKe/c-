#include<iostream>
using namespace std;
#include<vector>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归法：
int TreeSize(struct TreeNode*root)
{
    return NULL==root?0:TreeSize(root->left)+TreeSize(root->right)+1;
}

void _preorder(struct TreeNode*root,int*array,int *i)
{
    if(NULL==root)
    {
        return;
    }
    array[(*i)++]=root->val;
    _preorder(root->left,array,i);
    _preorder(root->right,array,i);
}

int* preorderTraversal1(struct TreeNode* root, int* returnSize)
{
    *returnSize=TreeSize(root);
    int *array=(int *)malloc(sizeof(struct TreeNode)*(*returnSize));
    int i=0;
    _preorder(root,array,&i);
    return array;
}


//迭代法：
class Solution 
{
public:
    vector<int> preorderTraversal2(TreeNode* root) 
    {   
        if(  root==nullptr  )
        {
            return {};
        }

        vector<int> ret;
        stack<TreeNode*>path;
        path.push(root);
        while(!path.empty())
        {
            TreeNode*temp=path.top();
            path.pop();
            ret.push_back(temp->val);

            if(temp->right!=nullptr)
            {
                path.push(temp->right);
            }
            if(temp->left!=nullptr)
            {
                path.push(temp->left);
            }
        }
        return ret;
    }   
};


int main()
{
  return 0; 
}
