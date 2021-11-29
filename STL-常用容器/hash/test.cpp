#include"hashTable.h"
#include"myUnordered_map.h"
#include"myUnordered_set.h"
#include"bitmap.h"
#include"bloomfilter.h"
#include"InterviewQuestions.h"

template<class T>
struct com
{
	T operator()(const T&obj)
	{
		return obj;
	}
};

void testhastTable()
{
	ZJ::hashTable<int, int, com<int>> h;
	h.insert(4);
	h.insert(14);
	h.insert(24);
	h.insert(2);
	h.insert(6);
	ZJ::hashTable<int, int, com<int>>h1;
	h1=h;
	//h.insert(7);
	//h.insert(1);
	//h.insert(9);
	//h.insert(10);
	//h.insert(22);
	//h.insert(21);
	//h.insert(27);
	//h.insert(0);
	//
	//h.erase(27);
	//h.clear();

}

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
	mp["10"] = "1";

	auto it = mp.begin();
	while (it != mp.end())
	{
		//cout << it->first << endl;
		printf("%s\n", (*it).first.c_str());
		++it;
	}

	//for (auto &e : mp)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}
}

void testset()
{
	ZJ::unordered_set<int>s;
	
}

void  testbitmap()
{
	ZJ::BitMap b(100);
	b.set(98);
	b.set(99);
	b.set(9);
	b.set(8);
	b.set(89);
	b.set(18);
	b.set(28);
	b.unset(8);
	for (size_t i = 0; i < 100; i++)
	{
		printf("[%d]=%d\n", i, b.queryexist(i));
	}
}

void testbloomfilter()
{
	ZJ::BloomFilter<string>b(400);
	b.set("100");
	b.set("200");
	b.set("300");
	b.set("400");
	b.set("600");
	b.set("700");

	cout << b.queryexist("100") << endl;
	cout << b.queryexist("200") << endl;
	cout << b.queryexist("300") << endl;
	cout << b.queryexist("400") << endl;
	cout << b.queryexist("500") << endl;
	cout << b.queryexist("600") << endl;
	cout << b.queryexist("700") << endl;

}
int main()
{
	testhastTable();
	//testmap();
	//testset();
	//testbitmap();
	//testbloomfilter();
	//ZJ::testSolution1();
	system("pause");
	return 0;
}