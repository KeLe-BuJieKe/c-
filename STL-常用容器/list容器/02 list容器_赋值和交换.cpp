#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<list>

//����ԭ��
/*
assign(beg,end);				//��[beg,end)�����е����ݿ�����ֵ������
assign(n,elem);					//��n��elem������ֵ������
list&operator=(const list&lst);	//���صȺŲ�����
swap(lst);						//��lst�뱾���Ԫ�ػ���
*/
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//��ֵ
void test01()
{
	//����list������
	list<int>L1;		

	//�������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_front(30);
	L1.push_front(40);

	printList(L1);
	list<int>L2 = L1;			//operator= ��ֵ
	printList(L2);


	list<int>L3;
	//��[beg,end)�����е����ݿ�����ֵ������
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);

}

//����
void  test02()
{
	list<int>L1;

	//�������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_front(30);
	L1.push_front(40);


	list<int>L2;
	L2.assign(10, 100);
	cout << "����ǰ:" << endl;
	printList(L1);
	printList(L2);

	//����
	swap(L1, L2);
	cout << "������:" << endl;
	printList(L1);
	printList(L2);
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}