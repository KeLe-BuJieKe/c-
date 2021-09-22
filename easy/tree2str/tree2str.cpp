#include<iostream>
using namespace std;
/*606. 根据二叉树创建字符串
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
示例 1:
输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     
输出: "1(2(4))(3)"
解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。

示例 2:
输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 
输出: "1(2()(4))(3)"
解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
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
    string tree2str(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return string();
        }
        string ret;

        ret+=to_string(root->val);

        if(root->left!=nullptr)
        {
            ret+='(';
            ret+=tree2str(root->left);
            ret+=')';
        }
        else if(root->right!=nullptr)
        {
            ret+="()";
        }

        if(root->right!=nullptr)
        {
            ret+='(';
            ret+=tree2str(root->right);
            ret+=')';
        }
        return ret;
    }
};




int main()
{
  TreeNode*A=new TreeNode(1);

  TreeNode*B=new TreeNode(2);  
  TreeNode*C=new TreeNode(3);  
  TreeNode*D=new TreeNode(4);  
  A->left=B;
  B->left=C;
  A->right=D;
  cout<<Solution().tree2str(A)<<endl;
  return 0;
}
