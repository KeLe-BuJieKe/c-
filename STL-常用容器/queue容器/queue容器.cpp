#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
#include<queue>
#include<string>
//����queue
class Person
{
	friend void test();
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
private:
	string m_name;
	int m_age;
};

void test()
{
	//��������
	queue<Person>q;
	
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳ��", 800);


	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "���д�СΪ��" << q.size() << endl;
	
	//�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ���鿴��β������
	while (!q.empty())
	{
		//�鿴��ͷ
		cout << "��ͷԪ��---����:" << q.front().m_name << "���䣺  " << q.front().m_age << endl;

		//�鿴��β
		cout << "��ͷԪ��---����:" << q.back().m_name << "���䣺  " << q.back().m_age << endl;

		//����
		q.pop();
	}

	cout << "���д�СΪ��" << q.size() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}