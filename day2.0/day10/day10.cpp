#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	/*
	1�����³������������ �� B ��
	int a, b;
	void fun()
	{
		a = 100;
		b = 200;
	} 
	int main()
	{
		int a = 5, b = 7;
		fun();
		printf("%d%d", a, b);
		return 0;
	}
	A: 100200		B: 57		 C: 200100		D: 75
	*/
}

void Question_2()
{
	/*
	2�����³��������ǣ� D ��
	struct HAR { int x,y;struct HAR *p;} h[2];
	void main()
	{
		h[0].x=1;h[0].y=2;
		h[1].x=3;h[1].y=4;
		h[0].p=&h[1];h[1].p=h;
		printf("%d,%d \n",(h[0].p)->x,(h[1].p)->y);
	}
	A: 1,2		B: 2,3		C: 1,4		D: 3,2
	*/
}

void Question_3()
{
	/*
	3��ʮ������268ת����ʮ���������ǣ� B ����
	A: 10B		 B: 10C		 C: 10D			D: 10E
	*/
}

//�����㷨��
/*
4���ַ���ת������ (atoi)
���ӣ�
*/
class Solution
{
public:
    int myAtoi(string s)
    {
        int index = 0;    //�±�
        //1.�������õ�ǰ���ո�
        while (index < s.size() && s[index] == ' ')
        {
            index++;
        }
        //2.�ж����Ƿ����ȫ�ǿո���������ֹԽ��
        if (index == s.size())
        {
            return 0;
        }

        //3.�����һ���ַ������Ż��Ǹ���
        int sign = 1;
        if (s[index] == '-')
        {
            index++;
            sign = -1;
        }
        else if (s[index] == '+')
        {
            index++;
            sign = 1;
        }
        int result = 0;
        while (index < s.size())
        {
            //4.����ǲ����ַ�
            //������ַ��͵��жϸ��ַ��Ƿ���ܳ�������������������������32λϵͳ�£�����ʹ��long long�������͵ı���
            //�������Ǿͷ����жϣ���ô�ͰѸ����� INT_MAX��INT_MIN�� ���� 10 ���бȽϡ�
            //��result����INT_MAX/10ʱ����ʱ������һλ�����ִ��� 7 Ҳ���� INT_MAX % 10 ʱ����˵�������������
            //ͬ���������ͬ
            if (s[index] >= '0' && s[index] <= '9')
            {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[index] - '0') > INT_MAX % 10))
                {
                    return INT_MAX;
                }
                if (result < INT_MIN / 10 || (result == INT_MIN / 10 && (s[index] - '0') > (INT_MAX % 10) + 1))
                {
                    return INT_MIN;
                }
                result = result * 10 + sign * (s[index] - '0');
            }
            else
            {
                break;
            }
            index++;
        }
        return result;
    }
};

/*
5������һ�������������е��������� nums ����һ��Ŀ��ֵ target ���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���
λ�á�����㷨ʱ�临�Ӷȱ����� O(log n) ������������в�����Ŀ��ֵ������ [-1, -1] .
���ӣ�https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
#include<vector>
//ʱ�临�Ӷ�Ϊ��O(2*logn)=O(logn)
class Solution
{
public:
    int search(vector<int>& nums, int target, bool sign = false)
    {
        int left = 0;
        int right = nums.size() - 1;
        //2.��������ʹ�ö��ֲ���targetֵ
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                //sign==false�ҵ��ǿ�ʼλ�ã�sign==true�ҵĽ���λ��
                if (sign == false)
                {
                    //��ʱ���ʱ�����λ�ò���һ����������Ҫ�ҵĿ�ʼ�߽�
                    //��ʼ�߽������������
                    //�ٴ�ʱmid==0����������ߵ�λ�ã���ʱmid���λ�þ������ǵĿ�ʼ�߽�
                    //��mid-1����mid������λ�õȲ�����target���������ȣ���֤����λ���ǿ�ʼ�߽�
                    if (mid == 0 || nums[mid - 1] != target)
                    {
                        return mid;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    //ͬ�����������ҽ����߽�λ�ã���ʱҲ���������
                    //�ٴ�ʱmid==nums.size()-1����������ߵ�λ�ã���ʱmid���λ�þ������ǵĿ�ʼ�߽�
                    //��mid+1����mid������λ�õȲ�����target���������ȣ���֤����λ���ǿ�ʼ�߽�
                    if (mid == nums.size() - 1 || nums[mid + 1] != target)
                    {
                        return mid;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
        }
        //3.���û�ҵ�����-1
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        //����һ����СΪ2�����飬��һ��λ�ô�ſ�ʼλ�ã��ڶ���λ�ô�Ž���λ��
        vector<int>ret(2);
        ret[0] = search(nums, target);
        ret[1] = search(nums, target, true);
        return ret;
    }
};