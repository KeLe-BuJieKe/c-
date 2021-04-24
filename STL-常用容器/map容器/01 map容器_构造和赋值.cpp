#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using  namespace std;
/*
map������Ԫ�ض���pair
pair�е�һ��Ԫ��Ϊkey(��ֵ)����������ҵ���ڶ���Ԫ��Ϊvalue��ʵֵ��
����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

���ʣ�
map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

�ŵ㣺
���Ը���keyֵ�����ҵ�value

map��multimap����
map���������������ظ�keyֵԪ��
multimap�����������ظ�keyֵԪ��
*/

//map����  ����͸�ֵ
void printMap(const map<int,int>m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first <<"\t"<< "   value=" << it->second << endl;
	}
	cout << "---------------------------" << endl;
}

void test01()
{
	//����map����
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(0, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(-1, 40));

	printMap(m);

	//��������
	map<int, int>m2(m);
	printMap(m2);


	map<int, int>m3 = m2;
	printMap(m2);

}

//�ܽ᣺map������Ԫ�ض��ǳɶԳ��ֵģ���������ʱ��Ҫʹ�ö���
int main()
{
	test01();
	system("pause");
	return 0;
}