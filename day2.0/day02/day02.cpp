#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//һ��ѡ����
void Question_1()
{
	//1.���ʽ 0x13&0x17, 0x13|0x17 ��ֵ�ֱ��Ƕ���___B___
	//A.0x17 0x13     B.0x13 0x17   C.0xF8 0xE8    D.0xec  0xC8
}

void Question_2()
{
	//2.C �����У���������ֵ���͵Ķ������ȱʡ����ʱ��������ֵ������������___B___
	//A.void   B.int    C.float    D.double
}

void Question_3()
{
	//3.���²�����ȷ�����ά�����ѡ����___D___
	//A.int a[2][2]={{1},{2}};
	//B.int a[][2]={1,2,3,4};
	//C.int a[2][2]={{1},2,3};
	//D.int a[2][] = { {1,2},{3,4} };
}

void Question_4()
{
	//4.��VS2013�£�����ṹ����ռ�Ŀռ��С��___C___�ֽ�
	typedef struct
	{
		int a;
		char b;
		short c;
		short d;
	}AA_t;
}

void Question_5()
{
	//5.����ȷ�ĸ�ֵ�򸳳�ֵ�ķ�ʽ��__C___
	//A.char str[6]={'\0'};
	//B.char str[7]="string";
	//C.char str[10]; str="string";
	//D.char str[6]="g";
}


//���������
void Question_6()
{
	//6.��֪��䣺const char *p="Hello!"������� printf("%c\n,*p")�������___H____
}

void Question_7()
{
	//7.�� int a=10,��ִ�б��ʽ a+=a*=a-=a/3 �� a ��ֵΪ___98____
	int a = 10;
	a += a *= a -= a / 3;
	//49+=7*(10-10/3);
}

void Question_8()
{
	//8.���³���whileѭ����ѭ��������__��ѭ��____
	int i = 0;
	while (i < 10)
	{
		if (i < 1)
		{
			continue;
		}
		if (i == 5)
		{
			break;
		}
		i++;
	}
}


//�����㷨��
//Ҫ��дһ�����������ַ����еĿո��滻Ϊ%20������:"abc defgx yz"ת����"abc%20defgx%20yz"
void ReplaceSpace(string &str)
{
	if (str.size() == 0)
	{
		return;
	}

	int SpaceSize = 0;		//�洢�ո�ĸ���
	int ChSize = str.size();	
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			++SpaceSize;
		}

	}
	str.resize(ChSize + SpaceSize *2);   //�����ĳ�������Ϊԭ���ĳ���+�ո�ĸ���*2
	int newChSize = str.size();
	while (newChSize> ChSize)
	{
		if (str[ChSize] == ' ')
		{
			str[newChSize--] = '0';
			str[newChSize--] = '2';
			str[newChSize--] = '%';
		}
		else
		{
			str[newChSize--] = str[ChSize];
		}
		ChSize--;
	}
	
}

//������
/*A��B��C��D�ĸ��ˣ�Ҫ��ҹ���һ���š�����ͨ�������ŷֱ���Ҫ��ʱ1��2��5��10���ӣ�ֻ��һ֧�ֵ磬����ͬʱ���ֻ��������һ����š�
���ʣ���ΰ��ţ��ܹ���17���������ĸ��˶����ţ�* /
/*
��һ�ˣ�A��B�ȹ���,	��ʱ2����
����A����			��ʱ3����
�ڶ��ˣ�����C��D���ţ���ʱ13����
����B����			��ʱ15����
�����ˣ�A��B�ٹ��ţ�	��ʱ17����
����Ҫ��
*/
