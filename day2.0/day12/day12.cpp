#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、下列程序执行 func(15,20) 的结果为（ D ）
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
	2、 程序的输出结果是（ D ）
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
	3、程序运行后的输出结果是（ D ）
	int a=1;
	int b=2;
	for(;a<8;a++)
	{
		b+=a;a+=2;
	}
	printf("%d，%d\n",a,b);
	A: 9,18		B: 8,11		C: 7,11		D: 10,14
	*/
}

//二、算法题
/*
4、给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/submissions/
*/
#include<vector>
#include<algorithm>

//方法一：时间复杂度O(nlogn) 空间复杂度O(n)
class Solution1
{
public:
    /*
    创建一个数组将其排序，排完序之后与原数组比较，判断最左边与最右边那个位置最早开始不相同
    这两个位置是就是我们要找的需要排序的区间
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


//方法二：时间复杂度O(n) 空间复杂度O(1)
class Solution2
{
public:
    /*
    思路：
    由于nums[0]一定存的必须得是最小的，我们就可以找到一个最小的数与nums[0]进行比较来判断，nums[0]是不是我们要找的左端点。
    nums[0]>curmin 说明nums[0]这个位置有误，存放的不是最小值，所以左端点就是从0开始。
    nums[0]<curmin 说明nums[0]这个位置存放的就是最小值，是不需要加入到要排序的区间内，
    此时我们就需要判断nums[1]到nums[n-1]，对于所有的元素，我们都这样判断一遍，就可以找到区间的左端点啦。
    但问题又来了，如果对于每个元素都求一遍其后所有元素的最小值，那复杂度还是O(n^2)的，此时我们就想到逆序找最小的，
    并且一边判断该点是否在这个需要排序的区间即可。
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
5、根据逆波兰表示法，求表达式的值。有效的运算符包括 + , - , * , / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
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
    //思路：碰到数字就压入栈，碰到运算符就从栈中弹出两个数进行运算，在把运算的值压入栈中
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
