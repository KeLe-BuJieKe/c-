#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//一、选择题
void Question_1()
{
	//1.表达式 0x13&0x17, 0x13|0x17 的值分别是多少___B___
	//A.0x17 0x13     B.0x13 0x17   C.0xF8 0xE8    D.0xec  0xC8
}

void Question_2()
{
	//2.C 语言中，函数返回值类型的定义可以缺省，此时函数返回值的隐含类型是___B___
	//A.void   B.int    C.float    D.double
}

void Question_3()
{
	//3.以下不能正确定义二维数组的选项是___D___
	//A.int a[2][2]={{1},{2}};
	//B.int a[][2]={1,2,3,4};
	//C.int a[2][2]={{1},2,3};
	//D.int a[2][] = { {1,2},{3,4} };
}

void Question_4()
{
	//4.在VS2013下，这个结构体所占的空间大小是___C___字节
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
	//5.不正确的赋值或赋初值的方式是__C___
	//A.char str[6]={'\0'};
	//B.char str[7]="string";
	//C.char str[10]; str="string";
	//D.char str[6]="g";
}


//二、填空题
void Question_6()
{
	//6.已知语句：const char *p="Hello!"，则语句 printf("%c\n,*p")输出的是___H____
}

void Question_7()
{
	//7.若 int a=10,则执行表达式 a+=a*=a-=a/3 后 a 的值为___98____
	int a = 10;
	a += a *= a -= a / 3;
	//49+=7*(10-10/3);
}

void Question_8()
{
	//8.以下程序while循环的循环次数是__死循环____
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


//三、算法题
//要求写一个函数，将字符串中的空格替换为%20。样例:"abc defgx yz"转换成"abc%20defgx%20yz"
void ReplaceSpace(string &str)
{
	if (str.size() == 0)
	{
		return;
	}

	int SpaceSize = 0;		//存储空格的个数
	int ChSize = str.size();	
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			++SpaceSize;
		}

	}
	str.resize(ChSize + SpaceSize *2);   //把它的长度扩充为原来的长度+空格的个数*2
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

//智力题
/*A、B、C、D四个人，要在夜里过一座桥。他们通过这座桥分别需要耗时1、2、5、10分钟，只有一支手电，并且同时最多只能俩个人一起过桥。
请问，如何安排，能够在17分钟内这四个人都过桥？* /
/*
第一趟：A与B先过桥,	耗时2分钟
再让A回来			耗时3分钟
第二趟：再让C与D过桥，耗时13分钟
再让B回来			耗时15分钟
第三趟：A与B再过桥，	耗时17分钟
满足要求
*/
