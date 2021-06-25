#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
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


/*8. 反转字符串 II
给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
示例:
输入: s = "abcdefg", k = 2
输出: "bacdfeg"
提示：
该字符串只包含小写英文字母。
给定字符串的长度和 k 在 [1, 10000] 范围内。*/

class Solution
{
public:
	string reverseStr(string s, int k)
	{
		//1.根据题意我们需要在每隔2k个字符，把前k个字符反转
		for (int i = 0; i < s.size(); i += 2 * k)
		{
			//2.我们给两个下标，一个是开始位置begin，一个结束位置end
			//结束位置等于开始的位置begin+k-1，由于我们的i的变化量是2k
			//2k就是每隔的一个区间大小
			int begin = i;
			int end = begin + k - 1;

			//3.这个if是为了防止剩余字符少于 k 个，则将剩余字符全部反转。
			//由于剩余字符数量不足，若继续使用上面未修正的end下标，就会造成越界
			//此时我们需要把结束的end下标修正一下，以防发生错误
			if (end >= s.size())
			{
				end = s.size() - 1;
			}

			//4.这里我们就把我们所需要逆置的元素区间逆置
			while (begin < end)
			{
				swap(s[begin], s[end]);
				begin++;
				end--;
			}
		}
		//5.返回s
		return s;
	}
};



/*9.反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
示例：
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
提示：
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
*/

class Solution
{
public:
	string reverseWords(string s)
	{
		for (int i = 0; i < s.size();)
		{
			int begin = i;
			//1.我们要找到分隔符空格，并且改位置要小于该字符串的长度，
			//跳出这个循环的情况有两种，1、是碰到分隔符空格
			//                        2、是要碰到'\0'，即i=s.size这个位置，这一步可以防止越界
			while (i < s.size() && s[i] != ' ')
			{
				++i;
			}
			int end = i - 1;

			//2.我们逆置【begin，end】这个前闭后闭这个区间内的元素
			while (begin < end)
			{
				swap(s[begin], s[end]);
				begin++;
				end--;
			}

			//3.这一步我们要跳过空格这个位置，并给下一个区间的begin赋值
			while (i < s.size() && s[i] == ' ')
			{
				++i;
			}
		}
		return s;
	}
};




/*10.字符串最后一个单词的长度
描述
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。
输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。
输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。
示例1
输入：hello nowcoder
输出：8
说明：最后一个单词为nowcoder，长度为8
链接：https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

int CalWord(std::string& str)
{
	//思路：我们从后往前遍历，在该字符串中找到分隔符' '
	//空格符到str.size()-1的距离即是该字符最后一个单词的长度
	int i = str.size() - 1;
	for (; i >= 0 && i < str.size();)
	{
		if (str[i] != ' ')
		{
			i--;
		}
		else
		{
			break;
		}
	}
	return str.size() - i - 1;
}

int main()
{
	std::string s;
	getline(std::cin, s);
	std::cout << CalWord(s);
	return 0;
}


/*11.字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
提示：
num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
链接：https://leetcode-cn.com/problems/add-strings/
*/


class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		//1.首先我们从后往前开始加，也就是我们所说的从低为向高位加
		//这里的length1与length2分别记录的是num1与num2当前最后一个数字字符的下标
		int length1 = num1.size() - 1;
		int length2 = num2.size() - 1;
		int carry = 0;        //进位
		string retstr = "";   //结果字符串

		//2.这里有几种情况
		/*
		1.当num1字符个数少于num2中的个数时，此时则表明是num2比num1多出来的部分是要与0和进位carry相加
		同理
		2.当num2字符个数少于num1中的个数时，此时则表明是num1比num2多出来的部分是要与0和进位carry相加
		3.当num1与num2中数字字符都没有了，但是进位还是为1，相当于是把最后的一个进位单独尾插到目标字符串retstr中
		*/
		while (length1 >= 0 || length2 >= 0 || carry > 0)
		{
			int temp1 = length1 >= 0 ? num1[length1] - '0' : 0;
			int temp2 = length2 >= 0 ? num2[length2] - '0' : 0;
			int result = temp1 + temp2 + carry;
			//如果这个结果大于9，这证明该结果是需要进位的，并且该结果要 %10
			//此时把carry置为1
			if (result > 9)
			{
				result %= 10;
				carry = 1;
			}
			//如果这个结果没有大于9，则证明该结果不需要进位，此时把进位carrt置为0，result不需要修改
			else
			{
				carry = 0;
			}
			//3.到了这里我们要把我们算好的结果要尾插到该字符串的末尾
			//此时得到的结果与我们想要的结果是颠倒的，即下标0这个位置是最低位，下标retstr.size()-1这个位置是最高位
			retstr.push_back(result + '0');
			--length1;
			--length2;
		}

		//4.最后我们把该字符串逆置
		//可以使用reverse()库函数把该string的对象逆置
		int begin = 0;
		int end = retstr.size() - 1;
		while (begin < end)
		{
			swap(retstr[begin], retstr[end]);
			begin++;
			end--;
		}

		//5.最后返回我们的目标字符串
		return retstr;
	}
};


/*12.字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
链接：https://leetcode-cn.com/problems/multiply-strings/
*/

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		//1.当num1或num2中出现0时，因为0乘任何数都为0，直接返回一个匿名对象。
		if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))
		{
			return string("0");
		}
		//2.创建一个动态数组，用来存储得出结果的数
		/*这里的m与n分别为该字符串的长度
		由于num1与num2的乘积的最大长度为m+n，因此我们创建长度为m+n的数组num用来存储乘积。对于任意0<=i<=m和0<=j<n,
		num1[i]×num2[j]的结果位与num[i+j+1],但是如果num[i+j+1]>=10,则将进位的部分加到num[i+j]。
		*/
		vector<int>num(num1.size() + num2.size(), 0);
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				int mul = (num1[i] - '0') * (num2[j] - '0');
				int sum = mul + num[i + j + 1];
				num[i + j] += sum / 10;
				num[i + j + 1] = sum % 10;
			}
		}


		//3.将数组num转成字符串，如果最高位是0，则舍弃最高位。
		int i = 0;
		while (i < num.size() && num[i] == 0)
		{
			i++;
		}
		string ans;
		while (i < num.size())
		{
			ans += num[i++] + '0';
		}

		//4.最后返回目标字符串
		return ans;
	}
};