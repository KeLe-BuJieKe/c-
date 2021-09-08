#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、下列代码的运行结果（ B ）
	short i=65537;
	int j=i+1;
	printf("i=%d,j=%d\n", i, j);
	A: i=65537,j=65538		B: i=1,j=2		C: i=-1,j=0			D: i=1,j=65538
	*/
}

void Question_2()
{
	/*
	2、以下正确的说法是（ C ）。
	A:用户若需调用标准库函数，调用前必须重新定义
	B:用户可以重新定义标准库函数，若如此，该函数将失去原有含义
	C:系统根本不允许用户重新定义标准库函数
	D:用户若需调用标准库函数，调用前不必使用预编译命令将该函数所在文件包括到用户源文件中，系统自动去调
	*/
}

void Question_3()
{
	/*
	3、下列程序的输出结果是 （ B ）
	int a[] = {2, 4, 6, 8, 10}, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	A: 4,4		B: 2,4		C: 2,2		 D: 4,6
	*/
}


//二、算法题
/*
4、给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值(注意：阿里巴巴考过这个题目)。
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view/
*/
#include<vector>
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
 class Solution
 {
 public:
     void _rightSideView(vector<int>& ret, TreeNode* root, int depth)    //深度优先遍历
     {
         if (root == nullptr)
         {
             return;
         }
         /*
         思路为：根-右子树-左子树，如果该深度没有被访问，那么就代表着结果数组中元素的个数与深度相等
         此时我们把正在访问的结点的值添加到结果数组中
         */
         if (ret.size() == depth)
         {
             ret.push_back(root->val);
         }
         ++depth;
         _rightSideView(ret, root->right, depth);
         _rightSideView(ret, root->left, depth);
     }
     vector<int> rightSideView(TreeNode* root)
     {
         vector<int>ret;
         _rightSideView(ret, root, 0);
         return ret;
     }
 };


 /*
 5、公交路线 
 链接：https://leetcode-cn.com/problems/bus-routes/
 */
#include<unordered_map>
#include<queue>
 class Solution 
 {
 public:
     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
         // 如果起点终点相同
         if (source == target) 
         {
             return 0;
         }
         // 标记站点出现的线路
         unordered_map<int, vector<int>> mp;
         // 标记访问的线路
         vector<bool> visited(routes.size(), false);
         // 记录站点出现的线路
         for (int i = 0; i < routes.size(); i++) 
         {
             for (int j = 0; j < routes[i].size(); j++) 
             {
                 mp[routes[i][j]].push_back(i);
             }
         }
         // 定义队列并初始化
         queue<int> q;
         q.push(source);
         int step = 0;
         while (!q.empty()) 
         {
             step++;
             int len = q.size();
             for (int i = 0; i < len; i++) 
             {
                 int site = q.front();
                 q.pop();
                 for (int& r : mp[site]) 
                 {
                     if (!visited[r]) 
                     {
                         for (int j = 0; j < routes[r].size(); j++) 
                         {
                             if (routes[r][j] == target) 
                             {
                                 return step;
                             }
                             q.push(routes[r][j]);
                         }
                         visited[r] = true;
                     }
                 }
             }
         }
         return -1;
     }
 };


/*
6、给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串).
链接：https://leetcode-cn.com/problems/wildcard-matching/submissions/
*/


 class Solution
 {
 public:
     // 状态转移方程：
     //      1. 当 s[i] == p[j]，或者 p[j] == ? 那么 dp[i][j] = dp[i - 1][j - 1];
     //      2. 当 p[j] == * 那么 dp[i][j] = dp[i][j - 1] || dp[i - 1][j]    
     // 其中:dp[i][j - 1] 表示 * 代表的是空字符，例如 a, *
     //      dp[i - 1][j] 表示 * 代表的是非空字符，例如 abc, ab*
     // 初始化：
     //      1. dp[0][0] 表示什么都没有，其值为 true
     //      2. 第一行 dp[0][j]，换句话说，s 为空，与 p 匹配，所以只要 p 开始为 * 才为 true
     //      3. 第一列 dp[i][0]，当然全部为 false
     bool isMatch(string s, string p)
     {
         size_t S_size = s.size();
         size_t P_size = p.size();

         // 状态定义：dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否匹配
         vector<vector<bool>> dp(S_size + 1, vector<bool>(P_size + 1));
         // 1.初始化 空字符串与空字符串是匹配的
         dp[0][0] = true;
         for (size_t i = 1; i <= P_size; ++i)
         {
             if (p[i - 1] == '*')       //2.空字符串和*是匹配的
             {
                 dp[0][i] = dp[0][i - 1];
             }

         }
         for (size_t i = 1; i <= S_size; ++i) //状态转移
         {
             for (size_t j = 1; j <= P_size; ++j)
             {
                 if (p[j - 1] == '*')
                 {
                     dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                 }
                 else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                 {
                     dp[i][j] = dp[i - 1][j - 1];
                 }
             }
         }
         return dp[S_size][P_size];
     }
 };

int main()
{
    
	system("pause");
	return 0;
}
