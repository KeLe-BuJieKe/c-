#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<vector>
/*
����ԭ�ͣ�
vector<T> v;					//����ģ����ʵ�� ��Ĭ�Ϲ��캯��
vector(v.begin(),v.end());		//��v[begin(),end())�����е�Ԫ�ؿ���������  ǰ�պ�
vector(n,elem);					//���캯����n��elem����������
vector(const vector &vec);		//�������캯��
*/

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}



//vector�����乹��
void test01()
{
	vector<int>v1;		//Ĭ�Ϲ���  �޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);


	//ͨ�����䷽ʽ���й���
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);


	//n��elem��ʽ����
	//vector(n,elem);					//���캯����n��elem����������
	vector<int>v3(10, 100);				//10��100
	printVector(v3);


	//��������
	vector<int>v4(v1);
	printVector(v4);

}
int main()
{
	test01();
	system("pause");
	return 0;
}