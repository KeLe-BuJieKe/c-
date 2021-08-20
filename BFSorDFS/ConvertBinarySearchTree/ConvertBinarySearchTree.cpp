#include<iostream>
using namespace std;
#include<stack>

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
class Node {
public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
      val = _val;
      left = NULL;
      right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
      val = _val;
      left = _left;
      right = _right;
  }


class Solution 
{
public:
    //思路，用一个栈去存储每个节点的左节点，用一个prev指针一直指向cur指针指向的当前节点的前一个节点，最后链接起来
    Node* treeToDoublyList(Node* root) 
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        stack<Node*>s;
        Node*cur=root;
        while(cur!=nullptr)
        {
            s.push(cur);
            cur=cur->left;
        }
        Node*head=s.top();
        Node*prev=nullptr;
        
        while(!s.empty())
        {
            cur=s.top();
            s.pop();
            if(prev!=nullptr)
            {
                prev->right=cur;
            }
            cur->left=prev;
            prev=cur;
            cur=cur->right;
            while(cur!=nullptr)
            {
                s.push(cur);
                cur=cur->left;
            }
        }
        prev->right=head;
        head->left=prev;
        return head;
    }
};


int main()
{

  return 0;
}
