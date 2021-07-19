#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	/*
	1、对于结构变量的操作，下面哪一种说法是错误的？ ( B )
	A:两个相同类型的结构变量之间可以赋值，就是复制全部成员的值
	B:两个结构变量之间不能进行关系运算
	C:不能用 cin 输人一个结构变量的全部成员。
	D:可以用一个 cout 输出一个结构变量的全部成员的值
	*/
}

void Question_2()
{
	/*
	2、在定点二进制运算器中，减法运算一般通过（ D ）来实现。
	A:原码运算的二进制减法器
	B:补码运算的二进制减法器
	C:原码运算的十进制加法器。
	D:补码运算的二进制加法器
	*/
}

void Question_3()
{
	/*
	3、字符型常量在内存中存放的是:（ A ）
	A:ASCII码
	B:BCD码
	C:内部码
	D:十进制码
	*/
}
//二、算法题
/*
4、给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数组
中每个元素只存储单个数字
链接：https://leetcode-cn.com/problems/plus-one/submissions/
*/
#include<vector>
class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			//一开始让最后一位自增，相当于是+1了
			//判断该位置 模10 后是否等于 0
			//如果等于0了；就说明该数字有进位就继续往前一位，判断前一位+上进位模10后是否等于0，依此类推
			digits[i]++;
			digits[i] %= 10;
			if (digits[i] != 0)
			{
				return digits;
			}
		}
		//到这里还没有出这个函数，就表明是999+1这种情况，所以我们需要在其头部插入 1
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

/*
5、给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
链接：https://leetcode-cn.com/problems/third-maximum-number/
*/
class Solution
{
public:
	int thirdMax(vector<int>& nums)
	{
		long long max = -0xfffffffff, mid = -0xfffffffff, min = -0xfffffffff;
		for (int i = 0; i < nums.size(); ++i)
		{
			// 考虑是否与max、mid、min相等，如果相等就说明这个数是重复出现过的
			if (nums[i] == max || nums[i] == mid || nums[i] == min)
			{
				continue;
			}
			
			if (nums[i] > max)
			{
				min = mid;
				mid = max;
				// 更新 max
				max = nums[i];
			}
			else if (nums[i] > mid)
			{
				min = mid;
				// 更新 mid
				mid = nums[i];

			}
			else if (nums[i] > min)
			{
				// 更新 min
				min = nums[i];
			}
		}
		return min == -0xfffffffff ? max : min;
	}
};