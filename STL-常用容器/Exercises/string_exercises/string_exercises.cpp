#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;



//1.���ڴ��������ȷ�Ľ����()��vs2013 �����±������У�
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
/*�𰸣�����1.c_str��һ������Ϊ�ַ���ָ���ַ��������ʱָ�룻 
		   2.c_str���ص���һ���ɶ����ɸĵĳ���ָ�룻
		   ����Ƚϵ�������ָ��ĵ�ַ����ÿ��Աȶ�����ͬ�����Զ����false
*/


//2.����������������( )
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
/*�𰸣���ѭ���У���һ�ν���ѭ�����У���ѭ����������size_pos����ֵΪ3��find_first_of���ڸö������ҵ�һ�γ��ָ��ַ���λ��
���δ�ҵ������ص���npos��npos��һ����̬���޷������Σ�substr�����Ӵ�����һ����Χ�ڽ�ȡ�Ӵ���������һ����������ʼλ�ã�
�ڶ��������ǽ�ȡ���ٸ��ַ�����ʱstrResult=How    ��Ļ����ʾHow���Լ��Լ���cout������Ŀո��ڽ�size_prev_pos=4=size_pos

�ڶ���ѭ��size_pos����ֵΪ7��strResult��4��λ�ÿ�ʼ��ȡ3���ַ�����strResultΪare,��Ļ�Ͼͻ����ʾһ��are�Ϳո�
��ʱsize_prev_pos=8=size_pos

������ʱ��������ѭ���壬��ΪstrText����8��λ�ÿ�ʼ�Ҳ����ո��ˣ���size_pos����ֵΪ-1
��ʱ���ǽ��뵽if�ж��У�size_prev_pos=8��������strText��Ԫ�ظ���
��8��λ�ÿ�ʼ����ȡ3���ַ�����strResult����ֵΪare
��ʱ��Ļ����ʾ     |How are you |
*/


//3.����������������ȷ����()
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
/*�𰸣����*it�ǿո��Ҫɾ��it���λ�õ��ַ�����ʱitָ����B��Ȼ��it++����ʱit��ָ����i��
��Ļ�Ͼ���ʾHelloit
*/

/*4.�ַ����еĵ�һ��Ψһ�ַ�
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
ʾ����
s = "leetcode"
���� 0
s = "loveleetcode"
���� 2
���ӣ�https://leetcode-cn.com/problems/first-unique-character-in-a-string
*/
//����һ��
class Solution
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