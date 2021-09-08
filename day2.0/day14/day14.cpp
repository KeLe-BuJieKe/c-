#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1�����д�������н���� B ��
	short i=65537;
	int j=i+1;
	printf("i=%d,j=%d\n", i, j);
	A: i=65537,j=65538		B: i=1,j=2		C: i=-1,j=0			D: i=1,j=65538
	*/
}

void Question_2()
{
	/*
	2��������ȷ��˵���ǣ� C ����
	A:�û�������ñ�׼�⺯��������ǰ�������¶���
	B:�û��������¶����׼�⺯��������ˣ��ú�����ʧȥԭ�к���
	C:ϵͳ�����������û����¶����׼�⺯��
	D:�û�������ñ�׼�⺯��������ǰ����ʹ��Ԥ��������ú��������ļ��������û�Դ�ļ��У�ϵͳ�Զ�ȥ��
	*/
}

void Question_3()
{
	/*
	3�����г������������ �� B ��
	int a[] = {2, 4, 6, 8, 10}, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));
	printf(" % d\n", **k);
	A: 4,4		B: 2,4		C: 2,2		 D: 4,6
	*/
}


//�����㷨��
/*
4������һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ(ע�⣺����ͰͿ��������Ŀ)��
���ӣ�https://leetcode-cn.com/problems/binary-tree-right-side-view/
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
     void _rightSideView(vector<int>& ret, TreeNode* root, int depth)    //������ȱ���
     {
         if (root == nullptr)
         {
             return;
         }
         /*
         ˼·Ϊ����-������-����������������û�б����ʣ���ô�ʹ����Ž��������Ԫ�صĸ�����������
         ��ʱ���ǰ����ڷ��ʵĽ���ֵ��ӵ����������
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
 5������·�� 
 ���ӣ�https://leetcode-cn.com/problems/bus-routes/
 */
#include<unordered_map>
#include<queue>
 class Solution 
 {
 public:
     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
         // �������յ���ͬ
         if (source == target) 
         {
             return 0;
         }
         // ���վ����ֵ���·
         unordered_map<int, vector<int>> mp;
         // ��Ƿ��ʵ���·
         vector<bool> visited(routes.size(), false);
         // ��¼վ����ֵ���·
         for (int i = 0; i < routes.size(); i++) 
         {
             for (int j = 0; j < routes[i].size(); j++) 
             {
                 mp[routes[i][j]].push_back(i);
             }
         }
         // ������в���ʼ��
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
6������һ���ַ��� (s) ��һ���ַ�ģʽ (p) ��ʵ��һ��֧�� '?' �� '*' ��ͨ���ƥ�䡣'?' ����ƥ���κε����ַ���
'*' ����ƥ�������ַ������������ַ���).
���ӣ�https://leetcode-cn.com/problems/wildcard-matching/submissions/
*/


 class Solution
 {
 public:
     // ״̬ת�Ʒ��̣�
     //      1. �� s[i] == p[j]������ p[j] == ? ��ô dp[i][j] = dp[i - 1][j - 1];
     //      2. �� p[j] == * ��ô dp[i][j] = dp[i][j - 1] || dp[i - 1][j]    
     // ����:dp[i][j - 1] ��ʾ * ������ǿ��ַ������� a, *
     //      dp[i - 1][j] ��ʾ * ������Ƿǿ��ַ������� abc, ab*
     // ��ʼ����
     //      1. dp[0][0] ��ʾʲô��û�У���ֵΪ true
     //      2. ��һ�� dp[0][j]�����仰˵��s Ϊ�գ��� p ƥ�䣬����ֻҪ p ��ʼΪ * ��Ϊ true
     //      3. ��һ�� dp[i][0]����Ȼȫ��Ϊ false
     bool isMatch(string s, string p)
     {
         size_t S_size = s.size();
         size_t P_size = p.size();

         // ״̬���壺dp[i][j] ��ʾ s ��ǰ i ���ַ��� p ��ǰ j ���ַ��Ƿ�ƥ��
         vector<vector<bool>> dp(S_size + 1, vector<bool>(P_size + 1));
         // 1.��ʼ�� ���ַ�������ַ�����ƥ���
         dp[0][0] = true;
         for (size_t i = 1; i <= P_size; ++i)
         {
             if (p[i - 1] == '*')       //2.���ַ�����*��ƥ���
             {
                 dp[0][i] = dp[0][i - 1];
             }

         }
         for (size_t i = 1; i <= S_size; ++i) //״̬ת��
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
