#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal�Ĺ��캯������" << endl;
	}
	//���������������������Խ��  ����ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal()
	{
		cout << "Animal����������������" << endl;
	}*/
	//��������   ��Ҫ����Ҳ��Ҫ������ʵ��
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;

	//���麯��
	virtual void speak() = 0;
};
Animal:: ~Animal()
{
	cout << "Animal�Ĵ���������������" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat�Ĺ��캯������" << endl;
		this->m_Name = new string(name);
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat��������������" << endl;
			delete this->m_Name;
			this->m_Name = NULL;
		}
	}
	virtual void  speak()
	{
		cout <<*this->m_Name<< "Сè��˵��" << endl;
	}
	string* m_Name;
};
void test()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ��  ������������е�����������������������ж������ԣ�������ڴ�й©
	delete animal;
}
int main()
{
	test();
	system("pause");
	return 0;
}
//��̬ʵ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ �޷����õ��������������
//����������������е�����������Ϊ���������ߴ�������

//�������ʹ����������ԣ�
/*
1.���Խ������ָ���ͷ��������
2.����Ҫ�о���ĺ���ʵ��
*/

//�������ʹ�����������
//������Ǵ����������������ڳ����࣬�޷�ʵ��������



//�ܽ᣺
/*
1.�������������������������ͨ������ָ���ͷ��������
2.���������û�ж������ݣ����Բ�дΪ��������������
3.ӵ�д���������������Ҳ���ڳ�����
*/