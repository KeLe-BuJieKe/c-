#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;



/*题目：从尾到头打印链表
 *输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//方法一：使用递归
//虽然看上去代码很简单，当链表非常长的时候，就会导致函数调用的层级过深
//从而导致函数栈溢出，显然用递归法的话鲁棒性不是很好。
class Solution1 
{
public:
    vector<int> reversePrint(ListNode* head) 
    {
        if(head==nullptr)
        {
            return {};
        }
        reversePrint(head->next);
        ret.push_back(head->val);
        return ret;
    }
    vector<int>ret;
};


//方法二：看到是从尾到头反过来打印，和方法一我们就应该想到可以用栈的方法
//先从头到尾遍历一遍链表，把链表的元素放进栈中，在把栈中的每一个元素放进结果数组中
class Solution2 
{
public:
    vector<int> reversePrint(ListNode* head) 
    {
        stack<int>s;
        vector<int>ret;
        while(head!=nullptr)
        {
            s.push(head->val);
            head=head->next;
        }
        while(!s.empty())
        {
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }
};

//方法三：从头到尾遍历把每个元素都放到vector种，并将此数组逆置
vector<int> reversePrint(ListNode* head) 
{
  vector<int>ret;
  while(head!=nullptr)
  {
      ret.push_back(head->val);
      head=head->next;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}

void test()
{
  ListNode *head=new ListNode(1);  
  ListNode *A=new ListNode(3);  
  ListNode *B=new ListNode(2);
  
  head->next=A;
  A->next=B;
  B->next=nullptr;
  vector<int>v=reversePrint(head);
  for(size_t i=0;i<v.size();++i)
  {
    cout<<v[i]<<endl;
  }
}

//总结：方法二与方法三的鲁棒性都比方法一的鲁棒性要好，推荐使用后面两种方法
int main()
{
  test();
  return 0;
}
