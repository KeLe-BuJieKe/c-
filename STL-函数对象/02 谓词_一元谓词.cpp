#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

//�º���  ����ֵ������bool�������ͣ���Ϊν��
//һԪν��

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 7; i++)
	{
		v.push_back(i);
	}

	//����������  ��û�д���5������
	//GreaterFive G;
	//����������Ҫ��һ�������������
	//vector<int>::iterator it = find_if(v.begin(), v.end(), G);

	//GreaterFive() ������������
	vector<int>::iterator it= find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5������Ϊ��" << *it << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}