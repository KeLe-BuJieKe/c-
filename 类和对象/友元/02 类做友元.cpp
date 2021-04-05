#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Building;            //提前声明有这个类，不让程序报错
class GoodGay
{
public:
	GoodGay();
	void visit();     //访问函数，访问Building中的属性
private:
	Building* building;
};

class Building
{
	//GoodGay是Building的友元，可以访问本类中的私有成员
	friend class GoodGay;
public:
	Building();
	string m_SittingRoom;      //客厅
private:
	string m_BedRoom;          //卧室
};
GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}
Building::Building()     //给属性赋初值
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
void GoodGay::visit()
{
	cout << "好基友正在访问 : " << building->m_SittingRoom << endl;
	cout << "好基友正在访问 : " << building->m_BedRoom << endl;
}
void test()
{
	GoodGay gg;
	gg.visit();
}
int main()
{
	test();
	return 0;
}