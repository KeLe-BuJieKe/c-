#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
class Building
{
	//GoodGayȫ�ֺ�����Building�ĺ����� �����Է���Building�е�˽�г�Ա
	friend void GoodGay(Building& building);
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
	string m_SittingRoom;       //����
private:
	string m_BedRoom;           //����
};

//ȫ�ֺ���
void GoodGay(Building& building)
{
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building.m_SittingRoom << endl;

	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ�" << building.m_BedRoom << endl;
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
