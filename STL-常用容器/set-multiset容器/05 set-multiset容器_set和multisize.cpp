#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

/*
����
1.set�����Բ����ظ����ݣ���multisize����
2.set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
3.multisize���������ݣ���˿��Բ����ظ�����
*/

void test()
{
	set<int>s1;
	pair<set<int>::iterator,bool> ret=s1.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�!" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��!" << endl;
	}
	ret=s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��!" << endl;
	}


	multiset<int>ms;
	//��������ظ�ֵ
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}