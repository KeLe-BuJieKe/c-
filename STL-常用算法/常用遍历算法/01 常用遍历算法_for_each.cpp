#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;


//���ñ����㷨 for_each
//����ԭ��
//for_each(iterator beg,iterator end,_func);
//beg ��ʼ������
//end ����������
//_func �������ߺ�������
void print01(int val)
{
	cout << val << " ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�����㷨
	//print01-----��ͨ����
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	//�������������������������ķº�������
	for_each(v.begin(), v.end(), print02());
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}