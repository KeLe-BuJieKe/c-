#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Building;
class GoodGay
{
public:
	GoodGay();

	//让visit1函数可以访问Building中私有成员 
	void visit1();		

	//让visit2函数不可以访问Building中私有成员
	void visit2();
private:
	Building* building;
};
class Building
{
	//告诉编译器  GoodGay类下的visit1成员函数作为本类的好朋友
	friend void GoodGay:: visit1();
	friend void visit1();		//这行代码会被认为是全局函数作友元，必须要加上作用域，表面是类GoodGay下
public:
	Building();
	string m_SittingRoom;      //客厅
private:
	string m_BedRoom;          //卧室
};


//类外实现函数
GoodGay::GoodGay()
{
	this->building = new Building;
}
void GoodGay::visit1()
{
	cout << "visit1 函数正在访问:" << this->building->m_SittingRoom << endl;

	cout << "visit1 函数正在访问:" << this->building->m_BedRoom << endl;

}

void GoodGay::visit2()
{
	cout << "visit2 函数正在访问:" << this->building->m_SittingRoom << endl;

	//error   不可以访问
	//cout << "visit2 函数正在访问:" << this->building->m_BedRoom << endl;
}
Building::Building()
{
	this->m_BedRoom = "卧室";
	this->m_SittingRoom="客厅";
}


void test()
{
	GoodGay Person;
	Person.visit1();		//类的成员函数作友元友元

	Person.visit2();
}
int main()
{
	test();
	system("pause");
	return 0;
}