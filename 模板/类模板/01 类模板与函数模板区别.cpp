#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
//��ģ���뺯��ģ������
template<class NameType,class AgeType>
class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << "  age=" << this->m_Age << endl;
	}
private:
	NameType m_Name;
	AgeType m_Age;
};

//����
//1.��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test01()
{
	//Person p("�����", 1000);	//�����޷����Զ������Ƶ�

	Person<string,int>p("�����", 1000);
	p.showPerson();
}

//2.��ģ����ģ������б��п�����Ĭ�ϲ���
//���԰�������ģ���Ϊ���£�
//template<class NameType,class AgeType=int>
int main()
{
	test01();
	system("pause");
	return 0;
}