#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
void test01()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//ͷ��
	d1.push_front(5);
	d1.push_front(4);
	d1.push_front(3);

	//ͨ��[]��ʽ����Ԫ��
	//3 4 5 10 20 30
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//ͨ��at��ʽ����Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;


	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ: " << d1.front() << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ: " << d1.back() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}