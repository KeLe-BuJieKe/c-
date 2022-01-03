/*116. 填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL
进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
示例：
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
提示：
树中节点的数量少于 4096
-1000 <= node.val <= 1000
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


//方法一：利用队列来层序遍历来给每个结点的next指针来进行赋值
//时间复杂度O(n) 空间复杂度O(n)
class Solution1 
{
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        queue<Node*>q;
        q.push(root);
        queue<Node*>temp;
        Node* cur = nullptr;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur->left != nullptr)
            {
                temp.push(cur->left);
            }
            if(cur->right != nullptr)
            {
                temp.push(cur->right);
            }
            if(!q.empty())
            {
                cur->next = q.front();
            }
            else
            {
                cur->next = nullptr;
            }
            if(q.empty())
            {
                swap(temp,q);
            }
        }
        return root;
    }
};


//方法二：利用已经建立好的next指针来建立
//首先同一个根结点的左孩子的next指针是要指向他父结点的右孩子，
//那我们直接连接即可
//但是父结点的右孩子就等于父结点的next指针的左孩子
//循环以上两步即可
//要防止父结点的next指针为空的情况
//时间复杂度O(n) 空间复杂度O(1)
class Solution2 
{
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        Node* leftMostNode = root;

        while(leftMostNode->left != nullptr)
        {
            Node* temp = leftMostNode;
            while(temp != nullptr)
            {
                temp->left->next = temp->right;
                if(temp ->next != nullptr)
                {
                    temp->right->next = temp->next->left;
                }
                else
                {
                    temp->right->next = nullptr;
                }
                temp = temp->next;
            }
            leftMostNode = leftMostNode->left;
        }
        return root;
    }
};
