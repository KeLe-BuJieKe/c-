#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*
����ԭ�ͣ�
copy(iterator beg,iterator end,iterator dest);
��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
beg ��ʼ������
end ����������
dest Ŀ����ʼ������
*/
void Myprint(const int val)
{
	cout << val << "  ";
}

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	//����Ҳ����ֱ����==��
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), Myprint);
	cout << endl;
}
//�ܽ᣺����copy�㷨�ڿ���ʱ��Ŀ�������ǵ���ǰ���ٿռ�
int main()
{
	test();
	system("pause");
	return 0;
}