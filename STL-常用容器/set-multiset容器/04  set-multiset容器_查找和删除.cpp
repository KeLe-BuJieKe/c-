#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using  namespace std;

/*
����ԭ�ͣ�
find(key);			//����key�Ƿ���ڣ������ڣ��򷵻ظ�Ԫ�صĵ��������������ڣ�����set.end();
count(key);			//ͳ��key��Ԫ�ظ���
*/

//set����  ���Һ�ͳ��

//����
void test01()
{
	set<int>s1;
	//����
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);



	set<int>::iterator pos = s1.find(30);	
	if (pos != s1.end())
	{
		cout << "�ҵ�Ԫ�أ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
}

//ͳ��
void test02()
{
	set<int>s1;
	//����
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);

	//ͳ��30�ĸ��� 
	int num = s1.count(30);
	//����set����  ͳ�ƽ�� Ҫô��0 Ҫô��1
	cout << "num=" << num << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}