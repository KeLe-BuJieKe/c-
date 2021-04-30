#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
	#include<vector>
	#include<algorithm>
using  namespace std;

/*����ԭ�ͣ�
replace_if(iterator beg,iterator end,_pred,newvalue);
�������滻Ԫ�أ������������滻��ָ��Ԫ��
beg ��ʼ������
end ����������
_pred ν��
newvalue �滻����Ԫ��
*/

class MyPrint
{
public:
	void operator()(const int& val)
	{
		cout << val << "  ";
	}
};

class Greater30
{
public:
	bool operator()(const int& val)
	{
		return val >= 30;
	}
};
//���ÿ������滻�㷨 replace_if
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	//�����ڵ���30 �滻��3000
	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), MyPrint());

	replace_if(v.begin(), v.end(), Greater30(), 2000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
//�ܽ᣺replace_if���������ң��������÷º������ɸѡ���������
int main()
{
	test();
	system("pause");
	return 0;
}