#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/*题目：最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"

示例 3：
输入：s = ""
输出：0
链接：https://leetcode-cn.com/problems/longest-valid-parentheses/
*/

/*方法一：栈
具体做法是我们始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」，
这样的做法主要是考虑了边界条件的处理，栈里其他元素维护左括号的下标：
⒈对于遇到的每个'(' ，我们将它的下标放入栈中
⒉对于遇到的每个')' ，我们先弹出栈顶元素表示匹配了当前右括号：
    ①如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
    ②如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，这样就不满足提及的「最后一个没有被匹配的右括号的下标」，
为了保持统一，我们在一开始的时候往栈中放入一个值为 -1 的元素。
复杂度分析：
时间复杂度： O(n)，n 是给定字符串的长度。我们只需要遍历字符串一次即可。
空间复杂度： O(n)。栈的大小在最坏情况下会达到 n，因此空间复杂度为 O(n)
*/
int longestValidParentheses1(string s)
{
    stack<int>index;  //存储左括号'('的下标，以及存储分割每段匹配的括号的边界
    index.push(-1);   //防止最后栈为空碰到右括号还要继续弹出，造成异常

    int i = 0;
    int length = 0;
    //我们的思路是，碰到左括号就把它的下标存入栈中
    //遇到右括号，我们就弹出栈顶元素，此时就相当于'(',')'是匹配了的情况
    //如果一开始或者最后碰到')'，此时我们就得弹出我们一开始存入的-1或者上个不匹配的')'的下标，即弹出栈顶
    //如果栈内为空，就需要存入当前')'的下标作为分割
    //否则就将length就被赋值，用max来找两个数的较大值，由于index的栈顶存储的是上一个不匹配的')'下标，
    //此时当前')'下标减去上一个不匹配的')'下标，就为该段匹配的括号的长度
    while (i < s.size())
    {
        if (s[i] == '(')
        {
            index.push(i);
        }

        if (s[i] == ')')
        {
            index.pop();
            if (index.empty())
            {
                index.push(i);
            }
            else
            {
                length = max(length, i - index.top());
            }
        }
        ++i;
    }
    return length;
}


/*方法二：正向逆向结合法
我们利用两个计数器 left_flag 和 right_flag 。首先，我们从左到右遍历字符串，对于遇到的每个‘(’，我们增加left_flag 计数器，
对于遇到的每个 ‘)’ ，我们增加 right_flag 计数器。每当 left_flag 计数器与 right_flag 计数器相等时，我们计算当前有效字符串的长度，
并且记录目前为止找到的最长子字符串。当 right_flag 计数器比 left_flag 计数器大时，我们将 left_flag 和right_flag 计数器同时变回 0。
此时上面的方法会有一些问题，即当 left_flag始终大于 right_flag 时，即 (())) 这种类似的情况时，这种情况下我们最长的有效括号长度是算不出来的
此时我们只需要从右到左再遍历一边该字符串，情况与刚才相反，即可完美解决此种问题。
复杂度分析：
时间复杂度： O(n)，其中 n 为字符串长度。我们只要正反遍历两边字符串即可。
空间复杂度： O(1)。我们只需要常数空间存放若干变量。
*/
int longestValidParentheses2(string s)
{
    int left = 0, right = (int)s.size() - 1;
    int max_length = 0;
    int left_flag = 0, right_flag = 0;

    for (; left < s.size(); ++left)
    {
        if (s[left] == '(')
        {
            left_flag++;
        }
        else
        {
            right_flag++;
        }

        if (left_flag < right_flag)
        {
            left_flag = 0;
            right_flag = 0;
        }
        else if (left_flag == right_flag)
        {
            max_length = max(max_length, left_flag * 2);
        }
    }

    left_flag = 0, right_flag = 0;
    for (; right >= 0; --right)
    {
        if (s[right] == ')')
        {
            right_flag++;
        }
        else
        {
            left_flag++;
        }

        if (left_flag > right_flag)
        {
            left_flag = 0;
            right_flag = 0;
        }
        else if (left_flag == right_flag)
        {
            max_length = max(max_length, left_flag * 2);
        }
    }
    return max_length;
}