#include<iostream>
using namespace std;
/*请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*思路：首先我们先判断头指针是否问空，如果为空直接返回true，如果不检查头指针会导致下面的空指针访问权限错误
 检查完头指针后，我们就针对头指针的左子树与右子树判断它们的值和结构是否相同
 *当左子树的left与右子树的right  和  左子树的right与右子树的left结构都相等时，返回true
 否则返回false
 * */

bool _isSymmetric(TreeNode*obj1,TreeNode*obj2)
{
    if(obj1==nullptr&&obj2==nullptr) //当两个子树的对称位置都为空时，则该子树的该部位是对称的
    {
        return true;
    }
    if(obj1==nullptr||obj2==nullptr)  //如果两个子树的对称位置有一个不为空，则说明不对称
    {
        return false;
    }
    if(obj1->val!=obj2->val)  //如果两个子树都不为空，但它们的值不相同时，返回false
    {
        return false;
    }
    //相同时，在递归调用它们的obj1左子树与obj2的右子树比较&&obj1的右子树与obj2的左子树
    return _isSymmetric(obj1->left,obj2->right)&&_isSymmetric(obj1->right,obj2->left);
}
bool isSymmetric(TreeNode* root) 
{
    if(root==nullptr)
    {
        return true;
    }
    return _isSymmetric(root->left,root->right);
    
}


int main()
{

  return 0;
}
