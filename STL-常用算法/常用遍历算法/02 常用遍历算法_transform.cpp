#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using  namespace std;

//����ԭ��
//transform(iterator beg1,iterator end1,iterator beg2,_func);
//beg1  Դ������ʼ������
//end1  Դ��������������
//beg2  Ŀ��������ʼ������
//_func �������ߺ�������


class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};

class print
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//���ñ����㷨 transform
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;	//Ŀ������
	vTarget.resize(v.size());//Ŀ������ ��Ҫ��ǰ���ٿռ�
	transform(v.begin(), v.end(), vTarget.begin(), Transform());

	for_each(vTarget.begin(), vTarget.end(), print());

}
int main()
{
	test01();
	system("pause");
	return 0;
}