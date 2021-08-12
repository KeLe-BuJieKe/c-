#include<iostream>
using namespace std;
/*输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    bool equal(double num1,double num2)     //防止是double或者float类型时，造成的精度误差
    {
        if((num1-num2)>-0.0000001&&(num1-num2)<0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool _isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(nullptr==B)      //如果B为空了，说明这一部分结构是相同的了
        {
            return true;
        }

        if(nullptr==A)      //如果B为空了,但A没空这说明这部分结构不相同返回false
        {
            return false;
        }
        if(!equal(A->val,B->val))   //如果结构相同，但值不相同，返回false
        {
            return false;
        }
        //相同继续递归下一层
        return _isSubStructure(A->left,B->left)&&_isSubStructure(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        bool flag=false;    //结果
        if(nullptr!=A&&nullptr!=B)  //如果A或B任意一个为空指针都为false
        {
            if(equal(A->val,B->val))    //首先，因为结构相同了，先判断A的头指针与B的值是否相等，如果相同则判断它的下一层
            {
                flag=_isSubStructure(A,B);
            }
            if(flag!=true)      //如果头不相同，则递归判断它的左子树
            {
                flag=isSubStructure(A->left,B);
            }
            if(flag!=true)      //最好判断右子树
            {
                flag=isSubStructure(A->right,B);
            }
        }
        return flag;
    }
};

int main()
{
  return 0;
}
