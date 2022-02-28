/*445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例1：
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]

示例2：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]

示例3：
输入：l1 = [0], l2 = [0]
输出：[0]
提示：
链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
进阶：如果输入链表不能翻转该如何解决？
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> st1;
        stack<int> st2;
        while(l1 != nullptr)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* next = nullptr;
        int carry = 0;
        while(!st1.empty() || !st2.empty() || carry != 0)
        {
            int a = st1.empty() == true ? 0 : st1.top();
            int b = st2.empty() == true ? 0 : st2.top();
            if(!st1.empty())
            {
                st1.pop();
            }
            if(!st2.empty())
            {
                st2.pop();
            }
            int c = (a+b+carry)%10;
            carry = (a+b+carry)/10;            
            l1 = new ListNode(c);
            l1->next = next;
            next = l1;
        }
        return l1;
    }
};
