#include<iostream>
using namespace std;

/*92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
示例 1：
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：
输入：head = [5], left = 1, right = 1
输出：[5]
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
  /*先分隔链表得出我们要逆置的区间，将这段区间与原链表断开，在逆置我们要得到的区间，最后在链接起来。
	时间复杂度O(n) 空间复杂度O(1)
  */
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==right)
        {
            return head;
        }
        int count=1;
        ListNode*leftnode=head;
        ListNode*prevleft=nullptr;
        ListNode*rightnode=head;
        ListNode*nextright=rightnode->next;
        //1、先确定要反转的区间
        while(count<right)
        {
            if(count<left)
            {
                prevleft=leftnode;
                leftnode=leftnode->next;
            }
            rightnode=nextright;
            nextright=nextright->next;
            ++count;
        }
        //2、切断链接
        if(prevleft!=nullptr)
        {
            prevleft->next=nullptr;
        }
        rightnode->next=nullptr;

        //3、反转这部分的链表
        ListNode*newHead=nullptr;
        ListNode*cur=leftnode;
        while(cur!=nullptr)
        {
            ListNode*next=cur->next;
            cur->next=newHead;
            newHead=cur;
            cur=next;
        }

        //4、这里会有三种情况
        //4.1 当prevleft与nextright都为空时就表明逆置的是整一个链表，那么最后的头即是我们上面创建的newhead
        //4.2 当prevleft==nullptr，但nextright不为空时，我们要将原先是左区间的第一个结点的next域指向原先最开始的
        //右区间的下一个结点，此时返回新创建的newhead
        //4.3 当两个都不为空时，说明逆置的链表范围在中间部分，我们需要将原先左区间的前一个结点的next域指向newhead
        //在将原先是左区间的第一个结点的next域指向原先最开始的右区间的下一个结点，返回head结点
        if(prevleft==nullptr&&nextright==nullptr)
        {
            return newHead;
        }
        else if(prevleft==nullptr&&nextright!=nullptr)
        {
            leftnode->next=nextright;
            return newHead;
        }
        else
        {
            prevleft->next=newHead;
            leftnode->next=nextright;
            return head;
        }
    }
};


int main()
{

  return 0;
}
