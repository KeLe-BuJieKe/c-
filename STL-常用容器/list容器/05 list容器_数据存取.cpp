#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using  namespace std;

//list����  ���ݴ�ȡ

void test()
{
	list<int>L1;

	L1.push_back(0);
	L1.push_back(10);
	L1.push_back(20);

	//L1[0]	   ��������[]����list�����е�Ԫ��

	//L1.at(0) ��������at��ʽ����list�����е�Ԫ��
	//ԭ������Ϊlist�ı����Ǵ�ͷ����˫��ѭ�������������������Կռ�洢����
	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;

	//��֤�������ǲ�֧��������ʵ�
	list<int>::iterator it = L1.begin();
	it++;		//֧��˫��
	it--;

	//it = it + 1;		//����,��Ϊ��֧���������	

}
int main()
{
	test();
	system("pause");
	return 0;
}