#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//����������
//��������Ԫ�غϲ������洢����һ������

//����ԭ�ͣ�
//merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//����Ԫ�غϲ������洢����һ������
//ע�⣺�������������������
//beg1 ����1��ʼ������
//end1 ����1����������
//beg2 ����2��ʼ������
//end2 ����2����������
//dest Ŀ��������ʼ������

//���������㷨 merge
class MyPrint
{
public:
	void operator ()(const int& val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//Ŀ������
	vector<int>vTarget;
	//��ǰ��Ŀ����������ռ�

	//vTarget.reserve(v1.size() + v2.size());	//error


	vTarget.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint());

}
//�ܽ�;merge�ϲ������������������������ͬ����������
int main()
{
	test01();
	system("pause");
	return 0;
}