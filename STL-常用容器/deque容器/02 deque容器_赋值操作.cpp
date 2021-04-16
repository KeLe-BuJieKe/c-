#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>

/*
����ԭ�ͣ�
deque&operator=(const deque&deq);		//���صȺŲ�����
assign(begin,end);						//��[begin,end�������е����ݿ�����ֵ������
assign(n,elem);							//��n��elem������ֵ������
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

//deque������ֵ����
void test()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);


	//operator = ��ֵ
	deque<int>d2 = d1;
	printdeque(d2);


	//assign ��ֵ
	deque<int>d3;
	d3.assign(d1.begin(),d1.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);

}
int main()
{
	test();
	system("pause");
	return 0;
}