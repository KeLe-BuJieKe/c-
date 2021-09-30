#include<iostream>

/*328. 奇偶链表
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
  //思路：将链表分隔成两半，一部分存储奇数结点，另一半存储偶数结点
  //最后将奇数结点的尾部链接偶数结点的头部即可  时间复杂度O(n) 空间复杂度O(1)
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode*odd=head;  //奇数链表
        ListNode*even=head->next;//偶数链表
        ListNode*oddtail=odd;//奇数链表尾
        ListNode*eventail=even;//偶数链表尾
        while(eventail!=nullptr&&eventail->next!=nullptr)
        {
            oddtail->next=eventail->next;
            oddtail=oddtail->next;
            eventail->next=oddtail->next;
            eventail=eventail->next;
        }
        oddtail->next=even;
        return odd;
    }
};


void test()
{
    ListNode* A = new ListNode(1);
    ListNode* B = new ListNode(2);
    ListNode* C = new ListNode(3);
    ListNode* D = new ListNode(4);
    ListNode* E = new ListNode(5);
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    Solution().oddEvenList(A);  
}

int main()
{
  test();
  return 0;
}
