#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using  namespace std;

//�ڽ��������� _��ϵ�º���
/*
�º���ԭ�ͣ�
template<class T> bool equal_to<T>			//����
template<class T> bool not_equal_to<T>		//�����
template<class T> bool greater<T>			//����
template<class T> bool greater_equal<T>		//���ڵ���
template<class T> bool less<T>				//С��
template<class T> bool less_equal<T>		С�ڵ���
*/
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};
void test()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//����
	//sort(v.begin(), v.end(), MyCompare());
	//greater<int>()  �ڽ���������
	//ͷ�ļ�  #include<functional>
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
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