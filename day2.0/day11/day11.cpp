#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
    /*
    1��������������ȷ���ж��ǣ� A ��
    int a, b;
	scanf("%d,%d", &a, &b);
	if (a > b) a = b; b = a;
	else a++;b++;
	printf("%d,%d", a, b);
    A:���﷨������ͨ������
    B:������4��5�����5��6
    C:������5��4�����4��5
    D:������5��4�����5��5
    */
}

void Question_2()
{
    /*
    2���������ε����н���ǣ� C ��
    char s[ ]="abcdefgh",*p =s;
    p += 3;
    printf("%d\n",strlen(strcpy(p,"ABCD")));
    A: 8        B: 12       C: 4        D: 7
    */
}

void Question_3()
{
    /*
    3��( C ) �����ִ洢��Ԫ�д�ŵ���ָ�������
    A:�洢��        B:������       C:������        D:�û�
    */
}


//�����㷨��
/*
4������һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд.ע�⣺��������������ִ���OP������һ��ע�⣬����0P.
���ӣ�https://leetcode-cn.com/problems/valid-palindrome/
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
            //1.���жϸ��ַ��Ƿ������ֻ�������ĸ��������ǣ����ø��±�ָ��һ�����ֻ�����ĸ
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
            //2.������ַ�Ϊ��д�ַ���������Ѹ��ַ��ĳ�Сд�ַ�
            if ((s[end] >= 'A' && s[end] <= 'Z'))
            {
                s[end] += 32;
            }

            if ((s[begin] >= 'A' && s[begin] <= 'Z'))
            {
                s[begin] += 32;
            }

            //3.������ǱȽ������ַ��Ƿ���ͬ����ͬ�ͼ���������ͬ�ͷ���false
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
5������һ���ַ���ʹ��ԭ���㷨����ѹ����ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�
�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1 ���ַ������� int �������ͣ��������ԭ���޸���������󣬷���������³���.
���ӣ�https://leetcode-cn.com/problems/string-compression/
*/
#include<vector>
class Solution
{
public:
    //�ж��Ǽ�λ��
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
        int slow = 0, fast = 0, cur = 0;    //������slow��fast�ҵ���Ҫѹ����ǰ�պ󿪵����䣬cur��ѹ��д��λ��
        int charSize = 0;   //Ԫ�صĸ���
        while (fast < chars.size())
        {
            //��fast�ҵ���slow����λ�õĲ�ͬ�ַ�
            while (fast < chars.size() && chars[fast] == chars[slow])
            {
                fast++;
            }
            int count = fast - slow;        //�õ��������ڵ��ַ�����
            if (count != 1)                 //����ַ�ֻ��һ��������Ҫѹ��
            {
                int size = digit(count);    //�ж��ַ������Ǽ�λ������λ����Ҫռ����λ��
                charSize += (size + 1);     //�����ַ�������λ��+�Լ���������ַ�
                chars[cur] = chars[slow];   //��slow���λ�õ��ַ�д�뵽cur��λ����
                while (size)                //���Ǵ�cur+size���ǵ�ǰд�������λ�ã�����д���ַ����������һλ
                {
                    chars[cur + size] = (count % 10) + '0';
                    count /= 10;
                    size--;
                }
            }
            else        //����Ҫѹ���������ǻ���Ҫ��slow���λ�õ��ַ�д�뵽cur��λ���ϣ������ַ�����+1
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