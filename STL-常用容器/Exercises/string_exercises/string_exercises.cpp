#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using  namespace std;



//1.关于代码输出正确的结果是()（vs2013 环境下编译运行）
int main(int argc, char* argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	a = "";
	if (a.c_str() == b.c_str())
	{

		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}
/*答案：由于1.c_str是一个内容为字符串指向字符数组的临时指针； 
		   2.c_str返回的是一个可读不可改的常量指针；
		   这里比较的是两个指针的地址，故每组对比都不相同，所以都输出false
*/


//2.下面程序的输出结果是( )
int main(int argc, char* argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}

	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;
}
/*答案：在循环中，第一次进如循环体中，在循环条件哪里size_pos被赋值为3，find_first_of是在该对象上找第一次出现该字符的位置
如果未找到，返回的是npos，npos是一个静态的无符号整形，substr是找子串，在一个范围内截取子串函数，第一个参数是起始位置，
第二个参数是截取多少个字符，此时strResult=How    屏幕上显示How，以及自己在cout上输出的空格，在将size_prev_pos=4=size_pos

第二次循环size_pos被赋值为7，strResult从4号位置开始截取3个字符，故strResult为are,屏幕上就会多显示一个are和空格，
此时size_prev_pos=8=size_pos

第三次时，不进入循环体，因为strText从中8号位置开始找不到空格了，故size_pos被赋值为-1
此时我们进入到if判断中，size_prev_pos=8，不等于strText的元素个数
从8号位置开始，截取3个字符，故strResult被赋值为are
此时屏幕上显示     |How are you |
*/


//3.下面程序的输出结果正确的是()
int main()
{
	string str = "Hello Bit.";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it != ' ')
		{ 
			cout << *it;
		}
		else
		{
			str.erase(it);
		}
		it++;
	}
	return 0;
}
/*答案：如果*it是空格就要删除it这个位置的字符，此时it指向了B，然后it++，此时it就指向了i，
屏幕上就显示Helloit
*/

/*4.字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
示例：
s = "leetcode"
返回 0
s = "loveleetcode"
返回 2
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
*/
//方法一：时间复杂度为O(N²)
class Solution1
{
public:
	int firstUniqChar(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				if (s[i] == s[j] && (i != j))
				{
					break;
				}
				if (j == s.size() - 1)
				{
					return i;
				}
			}
		}
		return -1;
	}
};

//方法二：时间复杂度O(N)
class Solution2
{
public:
	int firstUniqChar(string s)
	{
		int count[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i] - 'a']++;
		}

		for (int j = 0; j < s.size(); j++)
		{
			if (count[s[j] - 'a'] == 1)
			{
				return j;
			}
		}
		return -1;
	}
};



/*5.把字符串转换成整数
描述:将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述：输入一个字符串,包括数字字母符号,可以为空
返回值描述：如果是合法的数值表达则返回该数字，否则返回0
示例1
输入："+2147483647"
返回值：2147483647
示例2
输入："1a33"
返回值：0

*/
class Solution
{
public:
	int StrToInt(string str)
	{
		//1.先判断该字符串是否为空，如果为空则返回0，否则执行下面语句
		if (str.size() == 0)
		{
			return 0;
		}
		int flag = 1;         //默认该数是正数
		int i = 0;            //下标
		//2.判断是正数还是负数
		//如果该字符串是正数且第一个没有+号时，则默认是使用正数
		if (str[i] == '-')
		{
			flag = -1;
			i++;
		}
		else if (str[i] == '+')
		{
			flag = 1;
			i++;
		}

		int num = 0;        //返回的结果值
		for (; i < str.size(); i++)
		{
			//我们的数字是从0-9前闭后闭的一个区间
			//如果不是在这个区间内，则说明该字符中有其他的字符，就返回0
			if (str[i] >= '0' && str[i] <= '9')
			{
				//每遍历一个在0-9间的字符，就将其加到num中
				num = num * 10 + flag * (str[i] - '0');
			}
			else
			{
				return 0;
			}
			//判断该数是否造成溢出，如果溢出了，则要返回0
			if (((num > 0x7fffffff) && (flag == 1)) || ((flag == -1) && (num < 0x80000000)))
			{
				return 0;
			}
		}
		return num;
	}
};

/*6.反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
链接：https://leetcode-cn.com/problems/reverse-string/
*/

class Solution 
{
public:
	void reverseString(vector<char>& s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
	}
};



/*7.验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false

链接：https://leetcode-cn.com/problems/valid-palindrome/
*/
//方法一：可以通过但是效率低
//效率低的主要原因是删除的时候，要挪动数据
bool isPalindrome(string s)
{
	for (int i = 0; i < s.size();)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
			i++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			i++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			i++;
		}
		else
		{
			s.erase(i, 1);
		}
	}
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;

		}
		begin++;
		end--;
	}
	return true;
}


//方法二;这种方法相较于上一种方法不需要删除这一个步骤
//时间效率会增加﻿
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