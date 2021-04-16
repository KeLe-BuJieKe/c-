#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
/*
����ԭ�ͣ�
resize(int num);		//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ(0)�����λ��
						//���������� ����ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);	//����ָ�������ĳ���num���������߳�������elemֵ�����λ��
						//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
*/
void  printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; �����е����ݲ������޸���
		cout << *it << "  ";
	}
	cout << endl;
}

//deque������С����
void test()
{

	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	if (d1.empty())		//���Ϊ�գ�����true���෴������false
	{
		cout << "d1Ϊ��" << endl;
	}
	else
	{
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ: " << d1.size() << endl;
		//deque����û����������
	}

	//����ָ����С
	//d1.resize(15);				//�������ָ���ı�ԭ���ĳ��ˣ�Ĭ����0����µ�λ��
	d1.resize(15, 100);				//�������ذ汾������ָ��Ĭ�����ֵ������2
	printdeque(d1);
	cout << "d1�Ĵ�СΪ: " << d1.size() << endl;


	d1.resize(5);					//�������ָ���ı�ԭ�����ˣ��������ֻ�ɾ����
	printdeque(d1);
	cout << "d1�Ĵ�СΪ: " << d1.size() << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}