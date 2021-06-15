#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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