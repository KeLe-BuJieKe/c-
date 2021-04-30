#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

/*����ԭ�ͣ�
reverse(iterator beg,iterator end);
��תָ����Χ��Ԫ��
beg ��ʼ������
end ����������
*/

//���������㷨 reverse
class MyPrint
{
public:
	void operator ()(const int& val)
	{
		cout << val << " ";
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	reverse(v.begin(), v.end());
	cout << "��ת��" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

}

//ģ��ʵ��reverse
template<class T>
void MySwap(T&x, T&y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
void MyReverse(T*array, int begin, int end)
{
	while ((begin != end) && (begin!=--end))
	{
		MySwap(array[begin], array[end]);
		begin++;
	}

}
int main()
{
	test();
	//-------------���Դ���-------------
	char array[5] = {'A','B','C','D','E'};
	MyReverse(array,0,5);
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] <<"  ";
	}
	system("pause");
	return 0;
}