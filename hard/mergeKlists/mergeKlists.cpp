#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//方法一：逐一合并两个链表
class Solution1 
{
public:
    ListNode* mergeTwoLists( ListNode* &l1, ListNode* &l2) 
    {
        ListNode* preHead = new ListNode(-1);

        ListNode* tail = preHead;
        while (l1 != nullptr && l2 != nullptr) 
        {
            if (l1->val < l2->val) 
            {
                tail->next = l1;
                l1 = l1->next;
            } else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        tail->next = l1 == nullptr ? l2 : l1;
        return preHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        for(size_t i=1;i<lists.size();++i)
        {
            lists[0]=mergeTwoLists(lists[0],lists[i]);
        }
        return lists[0];
    }
};

//方法二：运用优先级队列，堆中数据最多为K个，并且插入和删除堆中元素的时间复杂度度为O(logk)，
//而每个链表的长度为n，所以所有链表的结点总数为Kn，故时间复杂度O(kn×logk)空间复杂度(K)
class Solution2 
{
public:
    struct mypair
    {
        int val;
        ListNode*ptr;

        bool operator> (const mypair&obj)const
        {
            return val>obj.val;
        }

    };
    class less
    {
    public:
        bool operator() (const mypair& x, const mypair& y) const
        {
            return x > y;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode*head=new ListNode(-1);
        ListNode*tail=head;
        priority_queue< mypair,vector<mypair>,less>pq;
        for(auto &e:lists)
        {
            if(e!=nullptr)
            {
                pq.push({e->val,e});    //这里相当于是给一个mypair对象赋值后再入堆中
            }
        }
        while(!pq.empty())
        {
            mypair cur=pq.top();
            pq.pop();
            tail->next=cur.ptr;
            tail=tail->next;
            if(cur.ptr->next!=nullptr)
            {
                pq.push({cur.ptr->next->val,cur.ptr->next});
            }
        }
        ListNode*ret=head->next;
        delete head;
        return ret;
    }
};

int main()
{
  return 0;
}
