#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
/*
����ԭ�ͣ�
deque<T>deq T;			//Ĭ�Ϲ�����ʽ
deque(degin,end);		//���캯����[begin,end)�����е�Ԫ�ؿ���������
deque(n,elem);			//���캯����n��elem����������
deque(const deque &deq);//�������캯��
*/


void  printdeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; �����е����ݲ������޸���
		cout << *it << "  ";
	}
	cout << endl;
}

void test()
{
	//deque<T>deq T;			//Ĭ�Ϲ�����ʽ
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);


	//deque(degin,end);		//���캯����[begin,end)�����е�Ԫ�ؿ���������
	deque<int>d2(d1.begin(), d1.end());
	printdeque(d2);


	//deque(n,elem);			//���캯����n��elem����������
	deque<int>d3(10, 100);
	printdeque(d3);
	

	//deque(const deque &deq);//�������캯��
	deque<int>d4(d3);
	printdeque(d4);

}
int main()
{
	test();
	system("pause");
	return 0;
}