#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Building;
class GoodGay
{
public:
	GoodGay();

	//��visit1�������Է���Building��˽�г�Ա 
	void visit1();		

	//��visit2���������Է���Building��˽�г�Ա
	void visit2();
private:
	Building* building;
};
class Building
{
	//���߱�����  GoodGay���µ�visit1��Ա������Ϊ����ĺ�����
	friend void GoodGay:: visit1();
	friend void visit1();		//���д���ᱻ��Ϊ��ȫ�ֺ�������Ԫ������Ҫ���������򣬱�������GoodGay��
public:
	Building();
	string m_SittingRoom;      //����
private:
	string m_BedRoom;          //����
};


//����ʵ�ֺ���
GoodGay::GoodGay()
{
	this->building = new Building;
}
void GoodGay::visit1()
{
	cout << "visit1 �������ڷ���:" << this->building->m_SittingRoom << endl;

	cout << "visit1 �������ڷ���:" << this->building->m_BedRoom << endl;

}

void GoodGay::visit2()
{
	cout << "visit2 �������ڷ���:" << this->building->m_SittingRoom << endl;

	//error   �����Է���
	//cout << "visit2 �������ڷ���:" << this->building->m_BedRoom << endl;
}
Building::Building()
{
	this->m_BedRoom = "����";
	this->m_SittingRoom="����";
}


void test()
{
	GoodGay Person;
	Person.visit1();		//��ĳ�Ա��������Ԫ��Ԫ

	Person.visit2();
}
int main()
{
	test();
	system("pause");
	return 0;
}