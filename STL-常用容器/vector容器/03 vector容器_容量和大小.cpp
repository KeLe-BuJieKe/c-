#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>
/*
����ԭ�ͣ�
resize(int num);		//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ(0)�����λ��
						//���������� ����ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num,elem);	//����ָ�������ĳ���num���������߳�������elemֵ�����λ��
						//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
*/
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//vector�����������ʹ�С����
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())				//���Ϊ�գ�����true����Ϊ�գ�����false��
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ�� " << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ:  " << v1.size() << endl;
	}

	//����ָ����С
	//v1.resize(15);			//�������ָ���ı�ԭ���ĳ��ˣ�Ĭ����0����µ�λ��
	v1.resize(15, 100);			//�������ذ汾������ָ��Ĭ�����ֵ������2
	printVector(v1);		


	v1.resize(5);				//�������ָ���ı�ԭ�����ˣ��������ֻ�ɾ����
	printVector(v1);
}

/*
�ܽ᣺
�ж��Ƿ�Ϊ��------empty
����Ԫ�ظ���------size
������������------capacity
����ָ����С------resize
*/
int main()
{
	test01();
	system("pause");
	return 0;
}