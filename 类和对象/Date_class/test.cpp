#include"Date_class.h"

void test()
{
	Date d(2019, 4, 30);
	//d.operator+=(-100);
	//d.operator-=(-1);
	d.PrintDate();


	Date d1=d + 1;
	d1.PrintDate();

	Date d2 = d - 1;
	d2.PrintDate();
	
	if (d2 != d1)
	{
		std::cout << "�����" << std::endl;
	}
	else
	{
		std::cout << "���" << std::endl;
	}
	++d2;
	d2.PrintDate();

	//���Ժ���++
	Date d3=d2++;
	d2.PrintDate();
	d3.PrintDate();
	std::cout << "-----------�ָ���--------------" << std::endl;

	//���Ժ���--
	Date d4 = d3--;
	d3.PrintDate();
	d4.PrintDate();
	std::cout << "-----------�ָ���--------------" << std::endl;

	//����ǰ��++
	Date d5 = ++d4;
	d4.PrintDate();
	d5.PrintDate();
	std::cout << "-----------�ָ���--------------" << std::endl;

	//����ǰ��--
	Date d6 = --d5;
	d5.PrintDate();
	d6.PrintDate();
	std::cout << "-----------�ָ���--------------" << std::endl;

}

void test01()
{
	Date d1(2021, 5, 26);
	Date d2(2021, 5, 27);
	if (d2>d1)
	{
		std::cout << "����" << std::endl;

	}
	else
	{
		std::cout << "������" << std::endl;

	}

	if (d2.operator==(d1))
	{
		std::cout << "���" << std::endl;
	}
	else
	{
		std::cout << "�����" << std::endl;
	}

	//���� >= ��
	if (d2 >= d1)
	{
		std::cout << "���ڵ���" << std::endl;
	}
	else
	{
		std::cout << "�����ڵ���" << std::endl;
	}
}

void test02()
{
	Date d1(2021, 5, 26);
	Date d2(2021, 5, 27);
	if (d2 < d1)
	{
		std::cout << "С��" << std::endl;

	}
	else
	{
		std::cout << "��С��" << std::endl;

	}


	//���� >= ��
	if (d2 <= d1)
	{
		std::cout << "С�ڵ���" << std::endl;
	}
	else
	{
		std::cout << "��С�ڵ���" << std::endl;
	}
}

void test03()
{
	Date d1(2021, 5, 27);
	Date d2(2021, 5, 25);

	if (d2-d1)
	{
		std::cout <<"d2��"<< std::endl;
	}
	else
	{
		std::cout <<"d2С"<< std::endl;
	}
}

int main()
{
	//test();
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}