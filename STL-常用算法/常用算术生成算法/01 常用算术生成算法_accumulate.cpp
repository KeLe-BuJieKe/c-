#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<numeric>
using  namespace std;

/*
����ԭ�ͣ�
accumulate(iterator beg,iterator end,value);
��������Ԫ���ۼ��ܺ�
beg ��ʼ������
end ����������
value ��ʼֵ
*/
//�������������㷨
void test()
{
	vector<int>v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//����������Ϊ��ʼ�ۼ�ֵ
	int total=accumulate(v.begin(), v.end(), 0);
	cout << "total=" << total << endl;
}
//�ܽ᣺accumulateʹ��ʱͷ�ļ�ע����numeric
int main()
{
	test();
	system("pause");
	return 0;
}