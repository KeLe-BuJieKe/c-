#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using  namespace std;

/*����������
ϴ�� ָ����Χ�ڵ�Ԫ�������������
����ԭ�ͣ�
random_shuffle(iterator beg,iterator end);
ָ����Χ�ڵ�Ԫ�������������
beg ��ʼ������
end ����������
*/
//�ܽ᣺random_shuffleϴ���㷨�Ƚ�ʵ�ã�ʹ��ʱ�ǵü����������
//���������㷨 random_shuffle
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	//���Ҫ��ÿ�ε�ϴ���㷨����һ������Ҫ����һ�����������
	srand((unsigned int)time(NULL));
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//����ϴ�� �㷨 ����˳��
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
int main()
{

	test01();
	system("pause");
	return 0;
}