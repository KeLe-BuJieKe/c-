#include<vector>
#include<iostream>
#include<deque>
using namespace std;
/*请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 * */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/*思路：我们利用层序遍历 +一个双端队列 时间复杂度 O(N)，空间复杂度 O(N)
 * 奇数层我们从右往左取数，也就是从尾取，然后从头插入数据，先插入left的val在插入right的val
 * 偶数层我们从左往右取数，也就是从头取，然后从尾插入数据，但此时要先插入right的val在插入left的val
 * */

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return {};
        }
        vector<vector<int>>ret;
        vector<int>temp;
        deque<TreeNode*>path;
        int nextlevelsize=0;
        int printsize=1;
        path.push_back(root);
        bool flag=false;
        while(!path.empty())
        {
            TreeNode*cur=nullptr;
            if(flag==true)
            {
                cur=path.back();
                path.pop_back();
            }
            else
            {
                cur=path.front();
                path.pop_front();
            }

            temp.push_back(cur->val);
            if(flag==false)
            {
                if(cur->left!=nullptr)
                {
                    path.push_back(cur->left);
                    ++nextlevelsize;
                }
                if(cur->right!=nullptr)
                {
                    path.push_back(cur->right);
                    ++nextlevelsize;
                }
            }
            else
            {
                if(cur->right!=nullptr)
                {
                    path.push_front(cur->right);
                    ++nextlevelsize;
                }
                if(cur->left!=nullptr)
                {
                    path.push_front(cur->left);
                    ++nextlevelsize;
                }
            }


            --printsize;
            if(printsize==0)
            {
                flag=(!flag);
                ret.push_back(temp);
                temp.clear();
                printsize=nextlevelsize;
                nextlevelsize=0;
            }
        }
        return ret;
    }
};
