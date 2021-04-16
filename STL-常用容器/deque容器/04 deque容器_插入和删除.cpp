#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<deque>

/*
����ԭ�ͣ�
���˲��������
push_back(elem);		//������β�����һ������
push_front(elem);		//������ͷ������һ������
pop_back();				//ɾ���������һ������
pop_front();			//ɾ��������һ������

ָ��λ�ò���:
insert(pos,elem);		//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
insert(pos,n,elem);		//��posλ�ò���n��elem����,�޷���ֵ
insert(pos,begin,end);	//��posλ�ò���[begin,end)��������ݣ��޷���ֵ
clear();				//��������е���������
erase(begin,end);		//ɾ����������begin��end֮������ݣ�������һ�����ݵ�λ�á�
erase(pos);				//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
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

//deque���������ɾ��
void test01()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//ͷ��
	d1.push_front(5);
	d1.push_front(4);
	//4 5 10 20 30 40
	printdeque(d1);

	//βɾ
	d1.pop_back();
	//ͷɾ
	d1.pop_front();

	//5 10 20 30
	printdeque(d1);

}



void test02()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//ͷ��
	d1.push_front(5);
	d1.push_front(4);

	//insert����
	//insert(pos, elem);		//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
	d1.insert(d1.begin(), 3);
	//3 4 5 10 20 30 40
	printdeque(d1);

	
	//insert(pos, n, elem);		//��posλ�ò���n��elem����,�޷���ֵ
	d1.insert(d1.begin(), 2, 100);
	//100 100 3 4 5 10 20 30 40
	printdeque(d1);


	//insert(pos, begin, end);	//��posλ�ò���[begin,end)��������ݣ��޷���ֵ
	deque<int>d2;
	d2.push_back(11);
	d2.push_back(22);
	d2.push_back(33);
	//100 11 22 33 100 3 4 5 10 20 30 40
	d1.insert(d1.begin()+1, d2.begin(), d2.end());
	printdeque(d1);


}

//ɾ��
void test03()
{
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	//ͷ��
	d1.push_front(5);
	d1.push_front(4);

	//ɾ��
	d1.erase(d1.begin() + 1);
	//4 10 20 30 40
	printdeque(d1);


	//��������ķ�ʽɾ��
	//4  40
	d1.erase(d1.begin() + 1, d1.end()-1);
	printdeque(d1);

	//�������
	d1.clear();
	printdeque(d1);

}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}