#include"RBTree.h"
#include"myset.h"
#include"mymap.h"

void testMap()
{
	ZJ::map<int, int>m;
	m.insert(make_pair(3,3));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(5, 5));
	ZJ::map<int,int>::iterator it = m.begin();
	m[6] = 6;
	while (it != m.end())
	{
		cout << it->first << ": " << it -> second << endl;
		++it;
	}
	//for (auto& e : m)
	//{
	//	cout << e.first << ": " << e.second << endl;
	//}
	m[0] = 6;
	cout << m[0] << endl;
}

void testSet()
{
	ZJ::set<int>s;
	s.insert(3);
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	ZJ::set<int>::iterator it= s.begin();
	//++it;
	//++it;
	//++it;
	//++it;

	//while (it != s.begin())
	//{
	//	cout << *it << endl;
	//	--it;
	//}
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	s.erase(3);
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

}

void testReverse_iterator()
{
	ZJ::set<int>s;
	s.insert(3);
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	ZJ::set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
		++rit;
	}
}

void  test()
{
	//string a[10] = { "Smith","smith","SMITH","SmItH","Dean","dean","Lord","lord","SMITH","Dean" };
	string a[] = { "Smith","smith","SMITH","SmItH","Dean","dean","Lord","lord","SMITH" ,"Dean" };
	ZJ::map<string, int>m;
	for (auto& e : a)
	{
		m[e]++;
	}
	ZJ::map<string, int>::iterator it1 = m.begin();
	while (it1 != m.end())
	{
		cout << it1->first << ": " << it1->second << endl;
		++it1;
	}
	cout << endl;
	ZJ::map<string, int>T(m);
	ZJ::map<string, int>::iterator it2 = T.begin();
	int i = 0;
	for (auto& e : a)
	{
		T.erase(e);
	}
}
int main()
{
	//testMap();
	testSet();
	//testReverse_iterator();
	//test();
	system("pause");
	return 0;
}