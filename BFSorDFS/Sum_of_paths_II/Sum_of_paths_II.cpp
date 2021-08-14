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

class Solution 
{
public:
    void _pathSum(TreeNode*root,int targetSum,vector<vector<int>>&ret,vector<int>temp,int sumval=0)
    {
        if(root==nullptr)
        {
            return;
        }
        sumval+=root->val;
        temp.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(sumval==targetSum)
            {
                ret.push_back(temp);
            }
            return;
        }
        
        _pathSum(root->left,targetSum,ret,temp,sumval);
        _pathSum(root->right,targetSum,ret,temp,sumval);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>ret;
        vector<int>temp;
        _pathSum(root,targetSum,ret,temp);
        return  ret;
    }
};


int main()
{

  return 0;
}
