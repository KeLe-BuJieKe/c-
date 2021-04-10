#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//ʵ��ͨ�ã��������������ĺ���
//���򣺴Ӵ�С����
//�㷨��ѡ������
//���ԣ�char���顢int����

//������ģ��
template<class T>
void mySwap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}


//�����㷨ģ��
template<class T>
void mySort(T array[],int len)
{
	for (int i = 0; i < len; i++)
	{	
		int max = i;	//�϶����ֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			//�϶������ֵ ����������ֵ ��˵��j�±��Ԫ�ز������������ֵ
			if (array[max] < array[j])
			{
				max = j;		//�������ֵ�±�
			}
		}
		if (max!=i)
		{
			mySwap(array[max], array[i]);
		}
	}
}


//��ӡ��ģ��
template<class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//����char����
	char charArray[] = "badcfe";
	int len = sizeof(charArray) / sizeof(charArray[0]);
	mySort(charArray, len);
	myPrint(charArray, len);
}

void test02()
{
	//����int��ֵ
	int intArray[] = { 1,2,3,4,5,6,9,8,7};
	int len = sizeof(intArray) / sizeof(intArray[0]);
	mySort(intArray, len);
	myPrint(intArray, len);
}
int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}