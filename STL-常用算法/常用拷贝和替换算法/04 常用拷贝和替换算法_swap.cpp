#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
����ԭ��:
swap(container c1,container c2)
��������������Ԫ��
c1	����1
c2	����2
*/
class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};
void test()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	cout << "����ǰ��" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;


	cout << "������" << endl;
	swap(v1, v2);
		for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

}
//�ܽ᣺swap��������ʱ��ע�⽻��������Ҫͬ������
int main()
{
	test();
	system("pause");
	return 0;
}