#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//1.下面的程序段运行结果为：
void Questuon_1()
{
	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 };
	int* q[4];
	for (int i = 0; i < 4; i++)
	{
		q[i] = &a[i * 3];
	}
	cout << q[3][1]<<endl;
}

//2.下面的程序段运行结果为：
void Question_2()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
			{
				break;
			}
			a++;
		}
		a++;
	}
	printf("%d\n", a);				//--------4
}

void Question_3()
{
	//宏定义的宏展开是在__A___阶段完成的
	//A.预处理   B.编译   C.预处理前   D.运行
}

void Question_4()
{
	//若有以下定义:char a; int b; float c; double d;则表达式a*b+d-c值的类型为__D__
	//A.float   B.int   C.char   D.double
}

void Question_5()
{
	//能正确表示逻辑关系："a>=10 或 a<=0"的 C 语言表达式是___D__
	//A.a>=10 or a<=0     B.a>=10 | a<=10   C.a>=10 && a<=0    D.a>=10 || a<=0
}

void Question_6()
{
	//1.test.c文件中包括如下语句
	#define INT_PTR int*
	typedef int* int_ptr;
	INT_PTR a, b;
	int_ptr c, d;
	//文件中定义的四个变量，那个变量不是指针类型___b___
}

void Question_7()
{
	//变量分为全局和局部两种，__全局____变量没有赋初值时，将由系统自动置为0
}

void Question_8()
{
	//数组定义为 int a[4][5],则a[1]+3表示元素的__a[1][3]______的地址
}

void Question_9();
/*算法题*/
/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。时间复杂度O（row+col）*/
int find(int* arr, int key, int row, int col)
{
	if (NULL != arr && row > 0 && col > 0)
	{
		int x = 0;
		int y = col - 1;
		while (x < row && y >= 0)
		{
			if (arr[x * row + y] == key)
			{
				return 1;
			}
			else if (arr[x * row + y] < key)
			{
				x++;
			}
			else
			{
				y--;
			}
		}
	}
	return 0;
}
int main()
{
	//数组样例：
	int arr[4][4] = { 1,2,8, 9,
					  2,4,9, 12,
				      4,7,10,13,
				      6,8,11,15 };
	int key;
	printf("请输入要查找的数字\n");
	scanf("%d", &key);
	/*把二维数组强转为int*，当成一维数组来访问*/
	if (find((int *)arr, key, 4, 4) == 1)
	{
		printf("该数组中含有%d\n", key);
	}
	else
	{
		printf("该数组中没有%d\n", key);
	}

	return 0;
}




void Question_10()
{
/*智力题*/
/*有1000瓶药物，但是其中有一瓶是有毒的，小白鼠吃了一个星期以后就会死掉！，请问，在一个星期内找出有毒的药物，最少需要多少只小白鼠*/

/*首先1000与1024相差无几，于是我们可以用10个bit位来对这1000瓶药物进行编号，也就是将第n瓶药物的编号转化为对应的二进制。
然后我们拿10个空瓶编号为（10）（9）（8）（7）（6）（5）（4）（3）（2）（1）。将二进制的第一位（最右边的为第一位）为1的瓶子每瓶取一滴药水装入编号为（1）的瓶子，
将二进制的第二位为1的瓶子每瓶取一滴药水装入编号为（2）的瓶子，以此类推。
最后用10只老鼠编号为10，9，8，7，6，5，4，3，2，1喝下对应编号瓶子的药水，一个星期后检查老鼠的存活情况。
那这其中的道理是什么呢？因为老鼠只要服用任意量有毒药水就会在一个星期内死亡，而只要喝了有毒药水编号所对应的二进制的位数为1的药水的老鼠必定会死亡，
喝了有毒药水编号所对应的二进制的位数为0的药水的老鼠不会死亡，所以最后老鼠所组成的二进制数字就对应那瓶有毒的药水。
*/
}

