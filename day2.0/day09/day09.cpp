#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1���������µݹ麯��f������ f (4) ���䷵��ֵΪ�� A ����
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
	A: 10		B: 4		C: 0		 D: ���Ͼ�����
	*/
}

void Question_2()
{
	/*
	2��������������ǣ� ( B )
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
	3����λ������,������ÿ����һλ,�����൱��( A )
	A:����������2
	B:����������2
	C:����������4
	D:����������4
	*/
}

//�����㷨��
/*
4������һ���������� nums ��һ��Ŀ��ֵ target �������ڸ��������ҳ���ΪĿ��ֵ���� ���� ����������������
�������±ꡣ Ҫ��ʱ�临�Ӷ� O(n) ����Ȼ�����ѡ��ʹ�ñ����� O(n^2) �Ľⷨ
���ӣ�https://leetcode-cn.com/problems/two-sum/
*/
#include <unordered_map>
#include<vector>
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//���ù�ϣ��
		unordered_map<int, int>hashtable;
		for (int i = 0; i < nums.size(); i++)
		{
			//����ϣ���в����Ƿ���target-nums[i]�����������ʱ�临�Ӷ�ΪO��1��
			unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return { it->second,i };
			}
			else
			{
				//���û���ҵ��ͰѸ������뵽��ϣ���У�fristֵΪnums[i],secondֵΪi
				hashtable[nums[i]] = i;
			}
		}
		return {};
	}
};

/*
5�����������������ַ������������ǵĺͣ��ö����Ʊ�ʾ��������Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0
���ӣ�https://leetcode-cn.com/problems/add-binary/
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