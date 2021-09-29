#include<iostream>
using namespace std;

/*19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
进阶：你能尝试使用一趟扫描实现吗？
示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
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
    //时间复杂度O(n)，n为链表的长度
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //拿到题，先找题眼：删除链表的倒数第n个结点 
        //那么这里就会有一个奇妙的关系
        //利用快慢指针法，先让fast指针先从头指针开始先走n-1步
        //最后利用迭代遍历一次链表，当我们的fast指针的next==nullptr时结束迭代
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*prev=nullptr;
        while(--n)  //先让快指针先走n-1步
        {
            fast=fast->next;
        }
        while(fast->next!=nullptr)  //在让快慢指针同时走，走到快指针的next为空为止
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev!=nullptr)   
        //如果我们的prev指针指向不为空，那么我们就使prev指针所指的对象的next域指向我们要删除的结点
        {
            prev->next=slow->next;
        }
        else //如果为空，说明我们要删除的就是头指针所指向的位置，那么我们只需要使头指针指向它的下一个即可
        {
            head=head->next;
        }
        delete slow;
        
        return head;
    }
};


int main()
{
  return 0;
}
