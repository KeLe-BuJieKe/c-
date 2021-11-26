#include"CloseHash.h"

void testHash()
{
	int arr[] = { 1,5,10,100000,100 ,18,15,7,40};
	ZJ::Hash<int, int>ht;;
	for (auto &e : arr)
	{
		ht.Insert(make_pair(e,e));
	}
	auto ret = ht.Find(10);
	if (ret == nullptr)
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
	}

	ht.Erase(10);
	ret = ht.Find(10);
	if (ret == nullptr)
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
	}
}

int main()
{
	testHash();
	system("pause");
	return 0;
}