#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
class Building
{
	//GoodGay全局函数是Building的好朋友 ，可以访问Building中的私有成员
	friend void GoodGay(Building& building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom;       //客厅
private:
	string m_BedRoom;           //卧室
};

//全局函数
void GoodGay(Building& building)
{
	cout << "好基友的全局函数 正在访问：" << building.m_SittingRoom << endl;

	cout << "好基友的全局函数 正在访问：" << building.m_BedRoom << endl;
}
void test01()
{
	Building building;
	GoodGay(building);
}
int main()
{
	test01();
	return 0;
}
