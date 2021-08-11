#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*从上到下打印二叉树，同一层的节点从左到右的顺序打印，每一层打印到一行
 * */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/*思路：BFS，我们用一个队列来记录我们要打印的每一层的节点，
 * 我们需要定义两个变量：
 * 第一个变量为了表示当层中还有没有打印的结点数
 * 第二个变量为了表示下一层要打印的节点的数目
 * */
vector<vector<int>> levelOrder(TreeNode* root) 
{
    if(root==nullptr)     //判断头指针是否为空
    {
        return {};
    }
    vector<vector<int>>ret; //结果数组
    queue<TreeNode*>path;   //路径
    path.push(root);        //存入根结点
    int nextlevelsize=0;  //初始化一开始第一层下一层要打印的个数
    int printsize=1;    //初始化一开始打印本层结点的数量
    vector<int>temp;    //结果子数组
    while(!path.empty())
    {
        TreeNode*cur=path.front();
        path.pop();
        temp.push_back(cur->val);
        if(cur->left!=nullptr)
        {
            ++nextlevelsize;
            path.push(cur->left);
        }
        if(cur->right!=nullptr)
        {
            ++nextlevelsize;
            path.push(cur->right);
        }
        --printsize;
        if(printsize==0)
        {
            ret.push_back(temp);
            temp.clear();
            printsize=nextlevelsize;
            nextlevelsize=0;
        }
    }
    return ret;
}



int main()
{
  return 0;
}
