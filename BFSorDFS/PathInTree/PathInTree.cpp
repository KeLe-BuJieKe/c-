#include<iostream>
using namespace std;
#include<vector>

//输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
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
    //先序遍历： 按照 “根、左、右” 的顺序，遍历树的所有节点。
    //路径记录： 在先序遍历中，记录从根节点到当前节点的路径。
    //当路径为 ① 根节点到叶节点形成的路径 且 ② 各节点值的和等于目标 target 时，将此路径加入结果列表。
    void dfs(vector<vector<int> >&path,vector<int>sub,TreeNode*root,int &target,int temp)
    {
        if(root==nullptr)
        {
            return;
        }
        temp+=root->val;
        sub.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            if(temp==target)
            {
                path.push_back(sub);
            }
            return;
        }
        dfs(path,sub,root->left,target,temp);
        dfs(path,sub,root->right,target,temp);
        
    }
    vector<vector<int> > pathSum(TreeNode* root, int target) 
    {
        vector<vector<int> >path;
        vector<int>sub;
        dfs(path,sub,root,target,0);
        return path;
    }
};

int main()
{
  return 0;
}
