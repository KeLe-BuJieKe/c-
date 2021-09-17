#include"hashTable.h"
#include"myUnordered_map.h"
#include"myUnordered_set.h"

template<class T>
struct com
{
	T operator()(const T&obj)
	{
		return obj;
	}
};

//test hashTable
void testhastTable()
{
	ZJ::hashTable<int, int, com<int>> h;
	h.insert(4);
	h.insert(14);
	h.insert(24);
	h.insert(2);
	h.insert(6);

	h.insert(7);
	h.insert(1);
	h.insert(9);
	h.insert(10);
	h.insert(22);
	h.insert(21);
	h.insert(27);
	h.insert(0);

	h.erase(27);
	h.clear();
}

//test map
void testmap()
{
	ZJ::unordered_map<string,string>mp;
	mp.insert(make_pair("sort", "ÅÅĞò"));
	mp.insert(make_pair("left","×ó±ß"));
	mp.insert(make_pair("right", "ÓÒ±ß"));
	//mp.insert(make_pair(4, 4));
	//mp.insert(make_pair(5, 5));

	//mp.insert(make_pair(6,6));
	//mp.insert(make_pair(11, 11));
	//mp.insert(make_pair(11, 11));
	//mp.insert(make_pair(12, 12));
	//mp.insert(make_pair(13, 13));
	//mp.insert(make_pair(14, 14));

	//mp.insert(make_pair(15, 15));
	//mp.insert(make_pair(16, 16));
	mp["string"];
	mp["1"] = "1";
	mp["2"] = "2";
	mp["3"] = "3";
	mp["4"] = "4";
	mp["5"] = "5";
	mp["6"] = "6";
	mp["7"] = "7";
	mp["8"] = "8";
	mp["9"] = "9";
	mp["0"] = "0";
	mp["10"] = "10";
	for (auto &e : mp)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void testset()
{
	ZJ::unordered_set<int>s;
	
}
int main()
{
	//testhastTable();
	testmap();
	//testset();
	system("pause");
	return 0;
}
