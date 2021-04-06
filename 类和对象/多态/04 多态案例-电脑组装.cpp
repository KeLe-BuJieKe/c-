#define _CRT_SECURE_NO_WARNINGS 1
//��̬����3-������װ
/*����������
������Ҫ��ɲ���ΪCPU�����ڼ��㣩���Կ�(������ʾ)���ڴ��������ڴ洢��
��ÿ�������װ�ɳ�����࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����
�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/
#include<iostream>
using namespace std;
//����ͬ���
//����CPU��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard
{
public:
	//�������ʾ����
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		//������������������ýӿ�
		this->m_cpu = cpu;
		this->m_vc = vc;
		this->m_mem = mem;
	}
	//�ṩ�������� �ͷ�3��������� 
	~Computer()
	{
		//�ͷ�CPU���
		if (this->m_cpu != NULL)
		{
			delete this->m_cpu;
			this->m_cpu = NULL;
		}
		if (this->m_vc != NULL)
		{
			delete this->m_vc;
			this->m_vc = NULL;
		}
		if (this->m_mem != NULL)
		{
			delete this->m_mem;
			this->m_mem = NULL;
		}
	}
	//�ṩ��������
	void dowork()
	{
		this->m_cpu->calculate();
		this->m_vc->display();
		this->m_mem->storage();
	}
private:
	CPU* m_cpu;         //CPU�����ָ��
	VideoCard* m_vc;    //�Կ������ָ��
	Memory* m_mem;      //�ڴ��������ָ��
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl;
	}
};

//lenovo����
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
	void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
	}
};

class LenovoMemory :public Memory
{
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢��" << endl;
	}
};
void test01()
{
	//��һ̨�������
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelCard = new  IntelVideoCard;
	Memory* intelMem = new IntelMemory;


	cout << "��һ̨���Կ�ʼ������" << endl;
	//������һ̨����
	Computer* computer1 = new Computer(intelCPU, intelCard, intelMem);
	computer1->dowork();
	delete computer1;


	cout << "----------------------------------------------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	//�ڶ�̨������װ
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->dowork();
	delete computer2;


	cout << "----------------------------------------------------------" << endl;
	cout << "����̨���Կ�ʼ������" << endl;
	//����̨������װ
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->dowork();
	delete computer3;

}

int main()
{
	
	test01();
	system("pause");
	return 0;
}