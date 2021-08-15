#include<iostream>
using namespace std;

/*输入一个链表，输出该链表中倒数第k个节点。
 * */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode*next=head;
        ListNode*cur=head;
        //先让next指针走k-1步，始终保持next指针与cur指针相差k-1个距离
        //当next指针为空时，cur所在的节点位置就是倒数第k个节点的位置
        //如果k大于我们的链表长度直接返回空指针
        
        while(--k)
        {
            if(next->next!=nullptr)
            {
                next=next->next;
            }
            else
            {
                return nullptr;
            }
        }
        while(next->next!=nullptr)
        {
            cur=cur->next;
            next=next->next;
        }

        return cur;
    }
};

int main()
{

  return 0;
}
