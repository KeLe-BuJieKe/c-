#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;

//map����  ���Һ�ͳ��
void test()
{
	//����
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "�鵽��Ԫ�� key= " << pos->first << "  " << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}


	//ͳ��
	//map����������ظ�keyԪ�أ�countͳ�ƶ���  ���Ҫô��0��Ҫô��1
	//multimap��countͳ�ƿ��ܴ���1
	int num = m.count(3);
	cout<<"num = "<<num<<endl;	
}
int main()
{
	test();
	system("pause");
	return 0;
}