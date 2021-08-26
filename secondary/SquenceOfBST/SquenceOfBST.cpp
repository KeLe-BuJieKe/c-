#include<iostream>
using namespace std;
#include<vector>

/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
 * 假设输入的数组的任意两个数字都互不相同。*/



class Solution 
{
public:
    bool verifyPostorder(vector<int>& postorder) 
    {
        if(postorder.size()<=1)
        {
            return true;
        }
        int size=static_cast<int>(postorder.size());
        int root=postorder[size-1]; //或得每科子树的根

        int i=0;
        while(i<size)   //得到左子树与右子树的分界下标
        {
            if(postorder[i]>=root)
            {
                break;
            }
            ++i;
        }

        int j=i;
        while(j<size-1) //从上面得到右子树第一个元素的下标开始找，有没有比根结点小的，有就说明不是搜索二叉树
        {
            if(postorder[j]<root)
            {
                return false;
            }
            ++j;
        }

        //最后在判断其左右子树是否也是搜索二叉树
        vector<int>lefttemp(postorder.begin(),postorder.begin()+i);
        bool left=verifyPostorder(lefttemp);
       
        vector<int>righttemp(postorder.begin()+i,postorder.begin()+size-1);
        bool right=verifyPostorder(righttemp);

        return left&&right;
    }
};

void test()
{
  vector<int>v={5, 2, -17, -11, 25, 76, 62, 98, 92, 6};
  cout<<Solution().verifyPostorder(v)<<endl;
}


int main()
{
  test();
  return 0;
}
