#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
����ԭ�ͣ�
set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
���������ϵĲ
ע�⣺�������ϱ�������������
beg1 ����1��ʼ������
end1 ����1����������
beg2 ����2��ʼ������
end2 ����2����������
dest Ŀ��������ʼ������
*/
void myPrint(const int& val)
{
	cout << val << " ";
}


//���ü����㷨  set_difference
void test()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	//0`9
		v2.push_back(i + 5);	//5~14
	}

	vector<int>vTarget;


	//Ŀ��������Ҫ��ǰ���ٿռ�
	vTarget.resize(max(v1.size(), v2.size()));

	cout << "v1��v2�ĲΪ��" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

	cout << "v2��v1�ĲΪ��" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}