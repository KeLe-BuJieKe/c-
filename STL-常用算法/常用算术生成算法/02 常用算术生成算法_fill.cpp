#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using  namespace std;

/*
����ԭ�ͣ�
fill(iterator beg,iterator end,value);
�����������Ԫ��
beg ��ʼ������
end ����������
value ����ֵ
*/

//�������������㷨 fill
void MyPrint(const int& val)
{
	cout << val << "  ";
}

void test()
{
	vector<int>v;
	v.resize(10);

	//�����������
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

//�ܽ᣺����fill���Խ�������Ԫ�����Ϊ ָ����ֵ
int main()
{
	test();
	system("pause");
	return 0;
}