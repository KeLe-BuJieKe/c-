#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
����ԭ�ͣ�
replace(iterator beg,iterator end,oldvalue,newvalue);
�������ھ�Ԫ��  �滻��  ��Ԫ��
beg ��ʼ������
end ����������
oldvalue ��Ԫ��
newvalue ��Ԫ��
*/


class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};
//���ÿ������滻�㷨  replace

void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	//�����е�20 �滻�� 2000
	replace(v.begin(), v.end(), 20, 2000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}