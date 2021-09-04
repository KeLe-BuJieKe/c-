#include<iostream>
#include<stack>
#include<vector>
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

void _postorderTraversal(struct TreeNode*root,int *array,int *pi)
{
    if(NULL==root)
    {
        return;
    }
    _postorderTraversal(root->left,array,pi);
    _postorderTraversal(root->right,array,pi);
    array[(*pi)++]=root->val;

}



int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize=TreeSize(root);
    int *resultArray=(int *)malloc(sizeof(struct TreeNode)*(*returnSize));
    int i=0;
    _postorderTraversal(root,resultArray,&i);
    return resultArray;
}

//迭代法
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode *root) 
    {
        vector<int> res;
        if (root == nullptr) 
        {
            return res;
        }

        stack<TreeNode *> st;
        TreeNode *prev = nullptr;
        while (root != nullptr || !st.empty()) 
        {
            while (root != nullptr) 
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            //这个prev非常重要，当我们的root此时的right结点要放入vector前，如果我们之前放的是root结点的右结点
            //那么我们就要将我们的root结点放入vector结果数组中
            if (root->right == nullptr || root->right == prev) 
            {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else 
            {
                st.push(root);
                root = root->right;
            }
        }
        return res;
    }
};


int main()
{
  return 0;
}
