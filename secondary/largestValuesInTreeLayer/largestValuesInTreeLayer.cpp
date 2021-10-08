#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

/*515. 在每个树行中找最大值
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
示例1：
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
解释:
          1
         / \
        3   2
       / \   \  
      5   3   9 

示例2：
输入: root = [1,2,3]
输出: [1,3]
解释:
          1
         / \
        2   3
示例3：
输入: root = [1]
输出: [1]

示例4：
输入: root = [1,null,2]
输出: [1,2]
解释:      
           1 
            \
             2     

示例5：
输入: root = []
输出: []
提示：
二叉树的节点个数的范围是 [0,104]
-2^31 <= Node.val <= 2^31 - 1
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
    //思路：利用一个数组来进行广度优先遍历，每次将当前遍历的结点的左右子树结点放入到队列中
    //每次与我们的当前的最大值比较，当前层的最大值放入到我们的结果数组中
    vector<int> largestValues(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return {};
        }
        vector<int>ret;
        queue<TreeNode*>mq;
        mq.push(root);
        int maxnum=INT_MIN;
        while(!mq.empty())
        {
            int levelSize=static_cast<int>(mq.size());
            for(int i=0;i<levelSize;++i)
            {
                TreeNode*front=mq.front();
                mq.pop();
                maxnum=max(maxnum,front->val);

                if(front->left!=nullptr)
                {
                    mq.push(front->left);
                }
                if(front->right!=nullptr)
                {
                    mq.push(front->right);
                }
            }
            ret.push_back(maxnum);
            maxnum=INT_MIN;
        }
        return ret;
    }
};

int main()
{
  return 0;
}
