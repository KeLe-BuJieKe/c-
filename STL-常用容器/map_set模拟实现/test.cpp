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
	/*while (it != m.end())
	{
		cout << it->first << ": " << it -> second << endl;
		++it;
	}*/
	for (auto& e : m)
	{
		cout << e.first << ": " << e.second << endl;
	}
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
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

}
int main()
{
	testMap();
	//testSet();
	system("pause");
	return 0;
}