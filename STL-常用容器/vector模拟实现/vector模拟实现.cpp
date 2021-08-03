#include"Vector.h"

void test1()		//≤‚ ‘Œ≤≤Â°¢Œ≤…æ°¢resize°¢reserve
{
	ZJ::vector<int>s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	//s.resize(10, 5);
	s.pop_back();
	ZJ::vector<int>s1;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i];
	}
	cout << endl;
}

void test2()		//≤‚ ‘ππ‘Ï∫Ø ˝°¢øΩ±¥ππ‘Ï”Î∏≥÷µ∫Ø ˝
{
	ZJ::vector<string>s;
	s.push_back("1454646");
	//s.push_back("2222");
	ZJ::vector<string>s1= s;
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i]<<"  ";
	}
	//cout << endl;
}

#include<vector>
void test3()		//≤‚ ‘insert°¢erase
{
	ZJ::vector<string> const s(1, "1454646");
	//s.push_back("1454646");
	//s.push_back("1454646");
	//s.push_back("145464dasd6");
	//s.push_back("1454646");
	//s.push_back("145464dasdas6");
	//s.push_back("145464dasdsa6");


	//s.insert(s.end(),1);
	ZJ::vector<string>s1;
	s1=s;
	//s.erase(s.begin());
	//ZJ::vector<int>::const_iterator it = s.erase(s.begin(),s.end());
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << "  ";
	}
	cout << endl;
	//cout<< *it;
}

void test4()
{
	ZJ::vector<string> s(1, "1454646");
	size_t arr[4] = { 1,2,34,4 };
	ZJ::vector<int>s2(10, 1);
	ZJ::vector<int>s1(arr,arr+4);

	cout << s.front() << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1.at(i) << "  ";
	}
}

void test5()
{
	size_t a = 7;
	int b = 7;
	ZJ::vector<int>v1(a, b);
	//ZJ::vector<int>v2(v1.begin(), v1.end());
	for (auto e : v1)
	{
		cout << e << "  ";
	}
	cout << endl;
}
int main()
{
	test5();
	int a = 1;
	int* p = &a;
	cout << p;
	return 0;
}
