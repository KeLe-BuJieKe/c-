#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Building;            //��ǰ����������࣬���ó��򱨴�
class GoodGay
{
public:
	GoodGay();
	void visit();     //���ʺ���������Building�е�����
private:
	Building* building;
};

class Building
{
	//GoodGay��Building����Ԫ�����Է��ʱ����е�˽�г�Ա
	friend class GoodGay;
public:
	Building();
	string m_SittingRoom;      //����
private:
	string m_BedRoom;          //����
};
GoodGay::GoodGay()
{
	//�������������
	building = new Building;
}
Building::Building()     //�����Ը���ֵ
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
void GoodGay::visit()
{
	cout << "�û������ڷ��� : " << building->m_SittingRoom << endl;
	cout << "�û������ڷ��� : " << building->m_BedRoom << endl;
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