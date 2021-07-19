#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、对于以下递归函数f，调用 f (4) ，其返回值为（ A ）。
	int f (int n)
	{
		if (n)
		{
			return f (n -1) + n;
		}
		else 
		{
			return n;
		}
	}
	A: 10		B: 4		C: 0		 D: 以上均不是
	*/
}

void Question_2()
{
	/*
	2、下面程序的输出是？ ( B )
	#include <iostream>
	using namespace std;
	int fun (int x,int y)
	{
		if(x==y)
		{
			return (x);
		}
		else
		{
			return ((x+y)/2);
		}
	}
	int main()
	{
		int a=4,b=5,c=6;
		printf("%d\n",fun(2*a,fun(b,c)));
	}
	A: 8		B: 6		C: 12		D: 3
	*/
}

void Question_3()
{
	/*
	3、在位运算中,操作数每左移一位,其结果相当于( A )
	A:操作数乘以2
	B:操作数除以2
	C:操作数除以4
	D:操作数乘以4
	*/
}

//二、算法题
/*
4、给定一个整数数组 nums 和一个目标值 target ，请你在该数组中找出和为目标值的那 两个 整数，并返回他们
的数组下标。 要求时间复杂度 O(n) ，当然你可以选择使用暴力的 O(n^2) 的解法
链接：https://leetcode-cn.com/problems/two-sum/
*/
#include <unordered_map>
#include<vector>
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//利用哈希表
		unordered_map<int, int>hashtable;
		for (int i = 0; i < nums.size(); i++)
		{
			//到哈希表中查找是否有target-nums[i]这个数，查找时间复杂度为O（1）
			unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return { it->second,i };
			}
			else
			{
				//如果没有找到就把该数插入到哈希表中，frist值为nums[i],second值为i
				hashtable[nums[i]] = i;
			}
		}
		return {};
	}
};

/*
5、给定两个二进制字符串，返回他们的和（用二进制表示）。输入为非空字符串且只包含数字 1 和 0
链接：https://leetcode-cn.com/problems/add-binary/
*/
string addBinary(string a, string b)
{
	int carry = 0;
	int lenA = a.size() - 1;
	int lenB = b.size() - 1;
	string retStr;
	while ((lenA >= 0) || (lenB >= 0))
	{
		int val1 = ((lenA >= 0) ? a[lenA] : 0);
		int val2 = ((lenB >= 0 )? b[lenB] : 0);
		int ret = val1 + val2 + carry;
		if (ret > 1)
		{
			ret %= 2;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		lenA--;
		lenB--;
		retStr += (ret + '0');
	}
	if (carry != 0)
	{
		retStr += ('1');
	}
	reverse(retStr.begin(), retStr.end());
	return retStr;
}

int main()
{
	string a = "1010", b = "1011";
	cout<<addBinary(a, b);
	return 0;
}