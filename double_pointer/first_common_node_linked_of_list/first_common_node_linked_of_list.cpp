#include<iostream>
using namespace std;

/*
 *输入两个链表，找出它们的第一个公共节点。
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    //这道题就和《你的名字》这部电影的剧情一样。
    //你变成我，走过我走过的路。
		//我变成你，走过你走过的路。
		//然后我们便相遇了
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode*node1=headA;
        ListNode*node2=headB;
        while(node1!=node2)
        {
            node1=node1!=nullptr?node1=node1->next:headB;
            node2=node2!=nullptr?node2=node2->next:headA;
        }
        return node1;
    }
};


int main()
{
  return 0;
}
