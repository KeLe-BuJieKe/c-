#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//����ԭ��
//adjacent_find(iterator beg,iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
//beg ��ʼ������
//end ����������

//���ò����㷨 adjacent_find
void test()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);


	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

	if (pos == v.end())
	{
		cout << "δ�ҵ������ظ�Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ������ظ�Ԫ�أ�" << *pos << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}