#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1�����г���ִ�� func(15,20) �Ľ��Ϊ�� D ��
	int func(int i, int j)
	{
		if (i <= 0 || j <= 0)
			return 1;
		return 2 * func( i-3, j/2);
	}
	A: 8	 B: 16		C: 24		 D: 32
	*/
}

void Question_2()
{
	/*
	2�� ������������ǣ� D ��
	int a[ ] = { 2,4,6,8 }, *p=a, i;
	for( i=0; i<4; i++ )
	a[i]=*p++;
	printf( "%d\n" ,a[2] );
	A: 2		 B: 8		C: 4		 D: 6
	*/
}

void Question_3()
{
	/*
	3���������к���������ǣ� D ��
	int a=1;
	int b=2;
	for(;a<8;a++)
	{
		b+=a;a+=2;
	}
	printf("%d��%d\n",a,b);
	A: 9,18		B: 8,11		C: 7,11		D: 10,14
	*/
}

//�����㷨��
/*
4������һ���������飬����ҪѰ��һ�������������飬���������������������������ô�������鶼���Ϊ��������
���ӣ�https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/submissions/
*/
#include<vector>
#include<algorithm>

//����һ��ʱ�临�Ӷ�O(nlogn) �ռ临�Ӷ�O(n)
class Solution1
{
public:
    /*
    ����һ�����齫������������֮����ԭ����Ƚϣ��ж�����������ұ��Ǹ�λ�����翪ʼ����ͬ
    ������λ���Ǿ�������Ҫ�ҵ���Ҫ���������
    */
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int>arr = nums;
        sort(arr.begin(), arr.end());

        int left = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != nums[i])
            {
                left = i;
                break;
            }
        }

        int right = 0;
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            if (arr[j] != nums[j])
            {
                right = j;
                break;
            }
        }
        return left == right ? 0 : right - left + 1;
    }
};


//��������ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
class Solution2
{
public:
    /*
    ˼·��
    ����nums[0]һ����ı��������С�ģ����ǾͿ����ҵ�һ����С������nums[0]���бȽ����жϣ�nums[0]�ǲ�������Ҫ�ҵ���˵㡣
    nums[0]>curmin ˵��nums[0]���λ�����󣬴�ŵĲ�����Сֵ��������˵���Ǵ�0��ʼ��
    nums[0]<curmin ˵��nums[0]���λ�ô�ŵľ�����Сֵ���ǲ���Ҫ���뵽Ҫ����������ڣ�
    ��ʱ���Ǿ���Ҫ�ж�nums[1]��nums[n-1]���������е�Ԫ�أ����Ƕ������ж�һ�飬�Ϳ����ҵ��������˵�����
    �����������ˣ��������ÿ��Ԫ�ض���һ���������Ԫ�ص���Сֵ���Ǹ��ӶȻ���O(n^2)�ģ���ʱ���Ǿ��뵽��������С�ģ�
    ����һ���жϸõ��Ƿ��������Ҫ��������伴�ɡ�
    */
    int findUnsortedSubarray(vector<int>& nums)
    {

        int left = nums.size();
        int curmin = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > curmin)
            {
                left = i;
            }
            curmin = min(nums[i], curmin);
        }

        int right = 0;
        int curmax = nums[0];
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < curmax)
            {
                right = j;
            }
            curmax = max(nums[j], curmax);
        }
        return max(right - left + 1, 0);
    }
};


/*
5�������沨����ʾ��������ʽ��ֵ����Ч����������� + , - , * , / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
���ӣ�https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
*/
#include<stack>
class Solution
{
public:
    int calculation(int& val1, int& val2, char ch)
    {
        int val = 0;
        switch (ch)
        {
        case '+':
            val = val1 + val2;
            break;
        case '-':
            val = val1 - val2;
            break;
        case '*':
            val = val1 * val2;
            break;
        case '/':
            val = val1 / val2;
            break;
        }
        return val;
    }
    int Atoi(string& str)
    {
        int val = 0;
        int flag = 1;
        int i = 0;
        if (str[0] == '-')
        {
            flag = -1;
            i++;
        }
        else if (str[0] == '+')
        {
            flag = 1;
            i++;

        }
        for (; i < str.size(); i++)
        {
            val = (val * 10 + (str[i] - '0') * flag);
        }
        return val;
    }
    bool isnumber(string& token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
    //˼·���������־�ѹ��ջ������������ʹ�ջ�е����������������㣬�ڰ������ֵѹ��ջ��
    int evalRPN(vector<string>& tokens)
    {
        stack<int>st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (isnumber(tokens[i]))
            {
                st.push(Atoi(tokens[i]));
            }
            else
            {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                st.push(calculation(val1, val2, tokens[i][0]));
            }
        }
        return st.top();
    }
};
