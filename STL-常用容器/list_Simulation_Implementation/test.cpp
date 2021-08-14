#include"List_Implementation.h"


#include<list>
void teststandardlibrary()		//test standard library
{
	//list<int>L(-1,0);
	//L.push_back(1);
	//cout << L.front();
	//L.push_back(2);
	//L.push_back(3);
	//list<int>::iterator it = L.begin();
	//it = L.insert(it, 0);
	//while (it != L.end())
	//{
	//	cout << *it << "  ";
	//	it++;
	//}
	//cout << endl;
	//cout << "----------------" << endl;
	//list<int>::iterator il = L.end();
	//--il;
	//it = L.erase(il);

	//while (it != L.end())
	//{
	//	cout << *it << "  ";
	//	it++;
	//}
}

void test()			//pop_back() and push_back() no error
{
	ZJ::list<int>L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	ZJ::list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		//(*it) += 1;
		
		cout << *it++ << "  ";
	}
	cout << endl;
	L.pop_back();
	L.pop_back();
	L.pop_back();
	L.pop_back();

	it = L.begin();
	cout << "1"<<endl;
	while (it != L.end())
	{
		
		//(*it) += 1;

		cout << *it++ << "  ";
	}
}


void test1()		//test insert() erase() no error
{
	ZJ::list<int>L;

	L.insert(L.begin(), 3,1);
	ZJ::list<int>::iterator it = L.begin();

	while (it != L.end())
	{
		cout << *it << "  ";
		++it;
	}
	cout << endl;
	cout << "----------------" << endl;
	//it=L.erase(L.begin());
	//it = L.erase(L.begin());
	ZJ::list<int>L1;
	L1.insert(L1.begin(), L.begin(), L.end());
	L1.push_back(2);
	it = L1.begin();
	while (it != L1.end())
	{
		cout << *it << "  ";
		it++;
	}

	cout << endl;
	it=L1.erase(L1.begin(), L1.end());
	//it = L1.begin();
	while (it != L1.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;
}

void  test2()			//test front() and back() no error
{
	ZJ::list<int>L;
	L.push_back(1);
	L.push_back(2);
	cout << L.front() << endl;
	cout<<L.back()<<endl;

}

void test3()		//test push_front() pop_front() no error
{
	ZJ::list<int>L;
	L.push_front(1);
	L.push_front(2);
	L.push_front(3);
	L.pop_front();
	L.pop_front();
	L.pop_front();

	L.push_front(3);
	L.push_front(2);

	ZJ::list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << "  ";
		++it;
	}
}

void test4()	//test size() and clear() no error
{
	ZJ::list<int>const L(3,1);
	//L.push_front(1);
	//L.push_front(2);
	//L.push_front(3);
	cout << L.size()<<endl;
	//L.clear();

	ZJ::list<int>::const_iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << "  ";
		++it;
	}
	//cout << L.size() << endl;

}


void test5()		//测试 copy constructor  and operator= no error
{
	ZJ::list<int>L(2,1);
	ZJ::list<int>L1(L.begin(), L.end());
	//L.push_front(1);
	//L1.push_front(2);
	//L.push_front(3);

	//ZJ::list<int>L1(L);
	ZJ::list<int>::iterator it = L1.begin();
	while (it != L1.end())
	{
		cout << it.m_pnode->m_val << "  ";
		++it;
	}
	cout << endl;
	ZJ::list<int>L2;
	L2= L;
	L2.push_back(0);
	ZJ::list<int>::iterator it1 = L2.begin();
	while (it1 != L2.end())
	{
		cout << it1.m_pnode->m_val << "  ";
		++it1;
	}
	cout << endl;
}

void test6()
{
	ZJ::list<int>L1(7, 1);
	L1.resize(8);
	ZJ::list<int>::iterator it = L1.begin();
	while (it != L1.end())
	{
		cout << it.m_pnode->m_val << "  ";
		++it;
	}
	cout << endl;
	cout << L1.size() << endl;
}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//teststandardlibrary();
	test6();
	system("pause");
	return 0;
}
