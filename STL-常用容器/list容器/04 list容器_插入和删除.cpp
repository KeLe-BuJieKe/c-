#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using  namespace std;

//list���������ɾ��

/*
push_back(elem);			//������β������һ��Ԫ��
pop_back();					//ɾ�����������һ��Ԫ��
push_front();				//������ͷ������һ��Ԫ��
pop_front();				//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);			//��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
insert(pos,n,elem);			//��posλ�ò���n��elem���ݣ��޷���ֵ
insert(pos,beg,end);		//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
clear();					//�Ƴ���������������
erase(beg,end);				//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
erase(pos);					//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
remove(elem);				//ɾ��������������elemֵƥ���Ԫ��
*/

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test()
{
	list<int>L1;

	//β��
	L1.push_back(0);
	L1.push_back(10);
	L1.push_back(20);


	//ͷ��
	L1.push_front(30);
	L1.push_front(40);
	L1.push_front(50);

	//50 40 30 0 10 20
	printList(L1);


	//βɾ
	L1.pop_back();

	//ͷɾ
	L1.pop_front();
	//40 30 0 10
	printList(L1);


	//insert����
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	//40 1000 30 0 10
	printList(L1);


	//eraseɾ��
	it= L1.begin();
	L1.erase(++it);
	//40 30 0 10
	printList(L1);


	//�Ƴ�
	L1.push_back(1000);
	L1.push_back(1000);
	L1.push_back(1000);
	//40 30 0 10 1000 1000 1000 
	printList(L1);

	L1.remove(1000);		//ɾ��������������elemֵƥ���Ԫ��
	//40 30 0 10
	printList(L1);

	L1.clear();
	if (L1.empty())
	{
		cout << "����L1Ϊ��" << endl;
	}
	else
	{
		cout << "����L1��Ϊ��" << endl;
		cout << "����L1��Ԫ�ظ���Ϊ��" << L1.size() << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}