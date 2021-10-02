#include<iostream>
using namespace std;

/*61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==nullptr||k==0||head->next==nullptr)
        {
            return head;
        }
        //先找到链表尾
        int size=1;
        ListNode*cur=head;
        while(cur->next!=nullptr)
        {
            ++size;
            cur=cur->next;
        }
        k%=size;    //先得到一个不大于链表结点的数
        if(k==0)    //如果等于0，证明旋转了n圈回到了原位置，直接返回head即可
        {
            return head;
        }
        int move=size-k;    //找到要断开的结点的位置是第几号元素
        ListNode*movetail=cur;  //把找到的尾节点用一个变量存储着
        cur=head;           //从头开始遍历
        ListNode*movehead=cur->next;
        while(--move)
        {
            cur=cur->next;
            movehead=movehead->next;
        }
        cur->next=nullptr;  //断开链接
        movetail->next=head;
        return movehead;
    }
};


int main()
{
  return 0;
}
