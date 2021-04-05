#define _CRT_SECURE_NO_WARNINGS 1
//���ص��������
#include<iostream>
using namespace std;
class MyInteger
{
	friend ostream& operator<<(ostream& cout, const MyInteger& myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ��++�����     ǰ��++��������    ��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++()
	{
		//�Ƚ���++�����
		++m_Num;
		//�ٽ����������أ��Դﵽ��ʽ��̣�һֱ����׷��
		return *this;
	}
	//���غ���++�����    ����++����ֵ     int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)
	{
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		m_Num++;
		//��󽫼�¼���������
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, const MyInteger& myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

//�ܽ᣺
//ǰ�õ����������ã����õ�������ֵ
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}