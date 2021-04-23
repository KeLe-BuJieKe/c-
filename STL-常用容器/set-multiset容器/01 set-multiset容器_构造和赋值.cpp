#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

//set/multiset���ڹ���ʽ�������ײ�ṹ�Ƕ�����ʵ��
//����Ԫ�ض����ٲ���ʱ�Զ�������
/*
set��multiset����
set���������������ظ���Ԫ��
multiset�������������ظ���Ԫ��
*/
void printfSet(const set<int>&s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}



//set��������͸�ֵ
void test()
{
	set<int>s1;

	//��������  ֻ�� insert��ʽ
	//
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);

	//��������
	//set�����ص㣺����Ԫ�ز���ʱ���Զ�������
	//set��������������ظ�ֵ����Ȼ�����㱨�������벻��ȥ
	printfSet(s1);

	//��������
	set<int>s2(s1);
	printfSet(s2);


	//��ֵ
	set<int>s3 = s2;
	printfSet(s3);


}

int main()
{
	test();
	system("pause");
	return 0;
}