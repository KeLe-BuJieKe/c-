#define _CRT_SECURE_NO_WARNINGS 1
//多态案例3-电脑组装
/*案例描述：
电脑主要组成部件为CPU（用于计算），显卡(用于显示)，内存条（用于存储）
将每个零件封装成抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
测试时组装三台不同的电脑进行工作
*/
#include<iostream>
using namespace std;
//抽象不同零件
//抽象CPU类
class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
//抽象显卡类
class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;
};
//抽象内存条类
class Memory
{
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		//让零件工作起来，调用接口
		this->m_cpu = cpu;
		this->m_vc = vc;
		this->m_mem = mem;
	}
	//提供析构函数 释放3个电脑零件 
	~Computer()
	{
		//释放CPU零件
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
	//提供工作函数
	void dowork()
	{
		this->m_cpu->calculate();
		this->m_vc->display();
		this->m_mem->storage();
	}
private:
	CPU* m_cpu;         //CPU的零件指针
	VideoCard* m_vc;    //显卡的零件指针
	Memory* m_mem;      //内存条的零件指针
};

//具体厂商
//Intel厂商
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
	void display()
	{
		cout << "Intel的显卡开始显示了" << endl;
	}
};

class IntelMemory :public Memory
{
	void storage()
	{
		cout << "Intel的内存条开始存储了" << endl;
	}
};

//lenovo厂商
class LenovoCPU :public CPU
{
	void calculate()
	{
		cout << "Lenovo的CPU开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
	void display()
	{
		cout << "Lenovo的显卡开始显示了" << endl;
	}
};

class LenovoMemory :public Memory
{
	void storage()
	{
		cout << "Lenovo的内存条开始存储了" << endl;
	}
};
void test01()
{
	//第一台电脑零件
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelCard = new  IntelVideoCard;
	Memory* intelMem = new IntelMemory;


	cout << "第一台电脑开始工作！" << endl;
	//创建第一台电脑
	Computer* computer1 = new Computer(intelCPU, intelCard, intelMem);
	computer1->dowork();
	delete computer1;


	cout << "----------------------------------------------------------" << endl;
	cout << "第二台电脑开始工作！" << endl;
	//第二台电脑组装
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->dowork();
	delete computer2;


	cout << "----------------------------------------------------------" << endl;
	cout << "第三台电脑开始工作！" << endl;
	//第三台电脑组装
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