#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//����ԭ�ͣ�
//bool binary_search(iterator beg,iterator end,value);
//����ָ����Ԫ�أ����� ����true ����false
//ע�⣺�����������в�����
//beg ��ʼ������
//end ����������
//value ���ҵ�Ԫ��

//���ò����㷨 binary_search
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�����������Ƿ��� 9���Ԫ��
	//ע�⣺�������������������
	//������������У����δ֪

	bool result=binary_search(v.begin(), v.end(), 9);
	if (result)
	{
		cout << "�ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}