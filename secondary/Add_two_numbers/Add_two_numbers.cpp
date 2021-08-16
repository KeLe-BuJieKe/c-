#include<iostream>
using namespace std;

/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
链接：https://leetcode-cn.com/problems/add-two-numbers
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*1、首先先判断两个指针是否都为空，如果都为空直接返回nullptr
  2、其次题目给出的指针是指向最低位的，所有我们可以直接进行相加
 * */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    if(l1==nullptr&&l2==nullptr)
    {
        return  l1;
    }
    ListNode*cur1=l1;
    ListNode*cur2=l2;
    ListNode*head=nullptr;
    ListNode*tail=nullptr;
    int carry=0;
    while(cur1!=nullptr||cur2!=nullptr||carry==1)
    {
        ListNode*newnode=new ListNode(carry);
        if(cur1!=nullptr&&cur2==nullptr)
        {
            newnode->val=cur1->val+carry;
            cur1=cur1->next;
        }
        if(cur2!=nullptr&&cur1==nullptr)
        {
            newnode->val=cur2->val+carry;
            cur2=cur2->next;
        }
        if(cur1!=nullptr&&cur2!=nullptr)
        {
            newnode->val=cur1->val+cur2->val+carry;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        if(newnode->val>9)
        {
            newnode->val-=10;
            carry=1;
        }
        else
        {
            carry=0;
        }

        if(head==nullptr)
        {
            head=newnode;
            tail=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        
    }
    return head;
}

//测试代码
void test()
{
  ListNode*A=new ListNode(9);
  ListNode*B=new ListNode(9);
  ListNode*C=new ListNode(9);
  ListNode*D=new ListNode(9);
  ListNode*E=new ListNode(9);
  ListNode*F=new ListNode(9);
  ListNode*G=new ListNode(9);
  A->next=B;
  B->next=C;
  C->next=D;
  D->next=E;
  E->next=F;
  F->next=G;

  ListNode*H=new ListNode(9);
  ListNode*I=new ListNode(9);
  ListNode*J=new ListNode(9);
  ListNode*K=new ListNode(9);
  H->next=I;
  I->next=J;
  J->next=K;
  ListNode*node=addTwoNumbers(A,H);
  while(node!=nullptr)
  {
    cout<<node->val<<" ";
    node=node->next;
  }
}

int main()
{
  test();
  return 0;
}
