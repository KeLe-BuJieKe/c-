/*
143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]

示例 2:
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
提示：
链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//方法一：直接将每个结点的指针存储到一个数组中
//利用数组的[]来随机访问结点
//时间复杂度O(n) 空间复杂度O(n)
class Solution1 
{
public:
    void reorderList(ListNode* head) 
    {
        vector<ListNode*>PtrArray;
        while(head != nullptr)
        {
            PtrArray.push_back(head);
            head=head->next;
        }
        int i =0, j = PtrArray.size()-1;
        while(i < j)
        {
            PtrArray[i]->next = PtrArray[j];
            ++i;
            if(i == j)
            {
                break;
            }
            PtrArray[j]->next = PtrArray[i];
            --j;
        }
        PtrArray[i]->next = nullptr;
    }
};


//方法二：
//找中间结点+翻转链表+合并链表
//时间复杂度O(n) 空间复杂度O(1)
class Solution2 
{
public:
    ListNode* FindMidNode(ListNode*head) //找到中间结点
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* ReverseList(ListNode*head) //翻转链表
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if(next != nullptr)
            {
                next = next->next;
            }
        }
        return prev;
    }

    void MergeList(ListNode* l1, ListNode* l2) //合并两个链表
    {
        ListNode*  next1 = nullptr;
        ListNode*  next2 = nullptr;
        while(l1 != nullptr && l2 != nullptr)
        {
            next1 = l1->next;
            next2 = l2->next;
            l1->next = l2;
            l1 = next1;
            l2->next = l1;
            l2 = next2;
        }
    }

    void reorderList(ListNode* head) 
    {
        ListNode* midNode = FindMidNode(head);
        ListNode* newHead = ReverseList(midNode->next);
        midNode->next = nullptr;
        MergeList(head,newHead);
    }
};
