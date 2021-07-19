#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
    /*
    1、对下述程序，正确的判断是（ A ）
    int a, b;
	scanf("%d,%d", &a, &b);
	if (a > b) a = b; b = a;
	else a++;b++;
	printf("%d,%d", a, b);
    A:有语法错误不能通过编译
    B:若输入4，5则输出5，6
    C:若输入5，4则输出4，5
    D:若输入5，4则输出5，5
    */
}

void Question_2()
{
    /*
    2、下面程序段的运行结果是（ C ）
    char s[ ]="abcdefgh",*p =s;
    p += 3;
    printf("%d\n",strlen(strcpy(p,"ABCD")));
    A: 8        B: 12       C: 4        D: 7
    */
}

void Question_3()
{
    /*
    3、( C ) 可区分存储单元中存放的是指令还是数据
    A:存储器        B:运算器       C:控制器        D:用户
    */
}


//二、算法题
/*
4、给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写.注意：如果测试用例出现错误：OP这个情况一定注意，这是0P.
链接：https://leetcode-cn.com/problems/valid-palindrome/
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            //1.先判断该字符是否是数字或者是字母，如果不是，则让该下标指向一个数字或者字母
            while ((begin < end) && (!(s[end] >= '0' && s[end] <= '9')) &&
                (!(((s[end] >= 'A' && s[end] <= 'Z')) || (s[end] >= 'a' && s[end] <= 'z'))))
            {
                end--;
            }

            while ((begin < end) && (!(s[begin] >= '0' && s[begin] <= '9')) &&
                (!(((s[begin] >= 'A' && s[begin] <= 'Z')) || (s[begin] >= 'a' && s[begin] <= 'z'))))
            {
                begin++;
            }
            //2.如果该字符为大写字符，我们则把该字符改成小写字符
            if ((s[end] >= 'A' && s[end] <= 'Z'))
            {
                s[end] += 32;
            }

            if ((s[begin] >= 'A' && s[begin] <= 'Z'))
            {
                s[begin] += 32;
            }

            //3.最后我们比较两个字符是否相同，相同就继续，不相同就返回false
            if (s[end] != s[begin])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

/*
5、给定一组字符，使用原地算法将其压缩。压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。在完成原地修改输入数组后，返回数组的新长度.
链接：https://leetcode-cn.com/problems/string-compression/
*/
#include<vector>
class Solution
{
public:
    //判断是几位数
    int digit(int nums)
    {
        int length = 0;
        while (nums)
        {
            nums = nums / 10;
            length++;
        }
        return length;
    }
    int compress(vector<char>& chars)
    {
        int slow = 0, fast = 0, cur = 0;    //我们用slow与fast找到需要压缩的前闭后开的区间，cur是压缩写的位置
        int charSize = 0;   //元素的个数
        while (fast < chars.size())
        {
            //让fast找到与slow所在位置的不同字符
            while (fast < chars.size() && chars[fast] == chars[slow])
            {
                fast++;
            }
            int count = fast - slow;        //得到该区间内的字符个数
            if (count != 1)                 //如果字符只有一个，则不需要压缩
            {
                int size = digit(count);    //判断字符个数是几位数，几位数就要占几个位置
                charSize += (size + 1);     //加上字符个数的位数+自己本身这个字符
                chars[cur] = chars[slow];   //把slow这个位置的字符写入到cur的位置上
                while (size)                //我们从cur+size就是当前写入的最后的位置，依次写入字符个数的最后一位
                {
                    chars[cur + size] = (count % 10) + '0';
                    count /= 10;
                    size--;
                }
            }
            else        //不需要压缩，但我们还是要把slow这个位置的字符写入到cur的位置上，并让字符个数+1
            {
                chars[cur] = chars[slow];
                charSize += 1;
            }
            cur = charSize;
            slow = fast;
        }
        return charSize;
    }
};