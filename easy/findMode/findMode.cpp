#include<iostream>
#include<vector>
#include<stack>
using  namespace std;

/*
501. 二叉搜索树中的众数
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
假定 BST 有如下定义：
结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],
   1
    \
     2
    /
   2
返回[2].
提示：如果众数超过1个，不需考虑输出顺序
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
    vector<int> findMode(TreeNode* root) 
    {
        vector<int>ret;
        int maxcount=0;
        int size=0;
        int num;
        TreeNode*cur=root;
        stack<TreeNode*>st;
        while(cur!=nullptr||!st.empty())
        {
            while(cur!=nullptr)
            {
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            if(num==cur->val)
            {
                ++size;
            }
            else
            {
                size=1;
                num=cur->val;
            }
            if(size==maxcount)
            {
                ret.push_back(cur->val);
            }
            else if(size>maxcount)
            {
                maxcount=size;
                vector<int>temp;
                temp.push_back(cur->val);
                swap(temp,ret);
            }
            cur=cur->right;
        }
        return ret;
    }
};

int  main()
{
  return 0;
}
