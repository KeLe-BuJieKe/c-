#include<iostream>
using namespace std;
/*
 *输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==nullptr&&l2!=nullptr)
        {
            return l2;
        }
        if(l1!=nullptr&&l2==nullptr)
        {
            return l1;
        }
        ListNode*cur1=l1;
        ListNode*cur2=l2;
        ListNode*head=nullptr;//头指针
        ListNode*tail=nullptr;//尾指针

        //如果两个链表都不为空，就判断那个大，大的就链接在尾指针所指节点的后面，在更新尾指针
        while(cur1!=nullptr&&cur2!=nullptr)
        {
            if(cur1->val>cur2->val)
            {
                if(head==nullptr) //如果头指针为空，则让head=cur2，在把尾指向头
                {
                    head=cur2;
                    tail=head;
                }
                else
                {
                    tail->next=cur2;
                    tail=tail->next;
                }
                cur2=cur2->next;
            }
            else
            {
                if(head==nullptr) //如果头指针为空，则让head=cur1，并让尾指针指向头
                {
                    head=cur1;
                    tail=head;
                }
                else  
                {
                    tail->next=cur1;
                    tail=tail->next;
                }
                cur1=cur1->next;
            }

        }
        //如果有一个不为空，我们将尾指针链接上那个不为空的链表
        if(cur1!=nullptr)
        {
            tail->next=cur1;
        }
        if(cur2!=nullptr)
        {
            tail->next=cur2;
        }
        return head;
    }
};


int main()
{
  return 0;
}
