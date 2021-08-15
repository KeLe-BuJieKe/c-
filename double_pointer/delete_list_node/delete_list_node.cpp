#include<iostream>
using namespace std;


/*给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
题目链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * 说明：
题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* deleteNode(ListNode* head, int val) 
    {
        if(head==nullptr)  //如果该链表为空链表直接返回空指针
        {
            return nullptr;
        }
        //我们使用双指针法
        //让prev指向cur的前一个
        ListNode*prev=nullptr;
        ListNode*cur=head;
        while(cur!=nullptr)
        {
            if(cur->val==val)
            {
              //如果第一个开始的一连串就是我们要删除的节点，我们需要判断prev是不是空指针
              //如果是空指针则让头指针直接指向它的下一个节点，此时我们把cur更新至新的头
                if(prev==nullptr)
                {
                    head=head->next;
                    cur=head;
                }
                else
                {
                  //prev不为空时，我们需要将cur这个位置的节点删除，只需要将prev->next链接上cur->next即可
                  //在让cur=prev->next 
                    prev->next=cur->next;
                    cur=prev->next;
                }

            }
            else
            {
              //如果不是我们要删除的节点，prev指针和cur指针一起往后走一步
                prev=cur;
                cur=cur->next;
            }

        }
        return head;
    }
};


int main()
{
  return 0;
}
