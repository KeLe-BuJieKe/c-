#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>

//vector���� Ԥ���ռ�

void test01()
{
	vector<int>v1;

	//����reserveԤ���ռ�
	//v1.reserve(100000);
	
	int* p = NULL;
	int num = 0;		//ͳ�ƿ��ٴ���
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout <<"num= "<< num << endl;


}
int main()
{
	test01();
	system("pause");
	return 0;
}