#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��ӡ���ݺ���
void showValue(const int& val)
{
	//val=1000; ��ʱ�ͻᷢ������
	cout << "val=" << val << endl;
}

int main()
{
	//��������
	//����ʹ�ó��������������βΣ���ֹ�����
	int a = 10;

	//��ô�����ܲ���д��������������أ�
	//int& b = 10;	//���ǲ��е�
	//��������һ���ǰ�����const֮��Ϳ��ԣ���������
	const int& b = 10;		//���ñ�����һ��Ϸ����ڴ�ռ�
	//����constΪʲô�����أ��������ڱ������������޸�Ϊ
	//int temp=10;
	//const int &ref=temp;

	//-----------------�ֽ���-----------------------
	int c = 100;
	showValue(c);
	cout << "c=" << c << endl;
	system("pause");
	return 0;
}