#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;


/*
����ԭ�ͣ�
insert(elem);			//�������в���Ԫ��
clear();				//�������Ԫ��
erase(pos);				//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
erase(begin,end);		//ɾ������[begin,end)ǰ�պ����������Ԫ�أ�������һ��Ԫ�صĵ�����
erase(elem);			//ɾ��������ֵΪelem��Ԫ��
*/
//set���� �����ɾ��
void printfSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	//����
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);
	s1.insert(100);

	printfSet(s1);

	//ɾ��
	s1.erase(s1.begin());	//20 30 40
	printfSet(s1);

	//ɾ�����ذ汾
	s1.erase(30);			//20 40
	printfSet(s1);

	//���
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printfSet(s1);
}
int main()
{
	test01();
	system("pause");
	return 0;
}