#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>
#include<algorithm>

void  printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it=100; �����е����ݲ������޸���
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);

	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	//300 200 100 10 20 30 40
	cout << "����ǰ: " << endl;
	printdeque(d1);


	//����  Ĭ���������  ��С����  ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ�������� sort��������
	sort(d1.begin(), d1.end());
	cout << "�����: " << endl;
	printdeque(d1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}