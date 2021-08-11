#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
 *从上到下打印二叉树的每一个结点，同一层的节点按从左到右的顺序打印。
 * */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*思路：BFS，如果头结点为空就return，如果我们的队列path还有元素，说明还有路径没有被打印
 * 每次push_back每一个结点的值，如果该结点有子节点，则把该结点的子节点放到一个队列的末尾
 * */
vector<int> levelOrder(TreeNode* root) 
{
    if(root==nullptr)
    {
        return {};
    }
    vector<int>ret;
    queue<TreeNode*>path;
    path.push(root);
    while(!path.empty())
    {
        TreeNode*cur=path.front();
        path.pop();
        ret.push_back(cur->val);
        if(cur->left!=nullptr)
        {
            path.push(cur->left);
        }
        if(cur->right!=nullptr)
        {
            path.push(cur->right);
        }
    }
    return ret;
}


int main()
{

  return 0;
}
