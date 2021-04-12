#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
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

//1.ָ����������
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("�����", 1000);
	printPerson1(p);
}

//2.����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p)
{
	p.showPerson();
}

void test02()
{
	Person<string, int>p("��˽�", 1000);
	printPerson2(p);
}


//3.������ģ�廯
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
}
void test03()
{
	Person<string, int>p("ɳ��", 1000);
	printPerson3(p);
}

//�ܽ�:
/*
1.ͨ����ģ�崴���Ķ��󣬿��������ַ�ʽ�뺯���н��д���
2.ʹ�ñȽϹ㷺���ǵ�һ�֣�ָ�����������
*/
int main()
{
	test01();

	test02();

	test03();
	system("pause");
	return 0;
}