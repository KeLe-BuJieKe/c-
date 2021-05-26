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
		std::cout << "不相等" << std::endl;
	}
	else
	{
		std::cout << "相等" << std::endl;
	}
	++d2;
	d2.PrintDate();

	//测试后置++
	Date d3=d2++;
	d2.PrintDate();
	d3.PrintDate();
	std::cout << "-----------分割线--------------" << std::endl;

	//测试后置--
	Date d4 = d3--;
	d3.PrintDate();
	d4.PrintDate();
	std::cout << "-----------分割线--------------" << std::endl;

	//测试前置++
	Date d5 = ++d4;
	d4.PrintDate();
	d5.PrintDate();
	std::cout << "-----------分割线--------------" << std::endl;

	//测试前置--
	Date d6 = --d5;
	d5.PrintDate();
	d6.PrintDate();
	std::cout << "-----------分割线--------------" << std::endl;

}

void test01()
{
	Date d1(2021, 5, 26);
	Date d2(2021, 5, 27);
	if (d2>d1)
	{
		std::cout << "大于" << std::endl;

	}
	else
	{
		std::cout << "不大于" << std::endl;

	}

	if (d2.operator==(d1))
	{
		std::cout << "相等" << std::endl;
	}
	else
	{
		std::cout << "不相等" << std::endl;
	}

	//测试 >= 号
	if (d2 >= d1)
	{
		std::cout << "大于等于" << std::endl;
	}
	else
	{
		std::cout << "不大于等于" << std::endl;
	}
}

void test02()
{
	Date d1(2021, 5, 26);
	Date d2(2021, 5, 27);
	if (d2 < d1)
	{
		std::cout << "小于" << std::endl;

	}
	else
	{
		std::cout << "不小于" << std::endl;

	}


	//测试 >= 号
	if (d2 <= d1)
	{
		std::cout << "小于等于" << std::endl;
	}
	else
	{
		std::cout << "不小于等于" << std::endl;
	}
}

void test03()
{
	Date d1(2021, 5, 27);
	Date d2(2021, 5, 25);

	if (d2-d1)
	{
		std::cout <<"d2大"<< std::endl;
	}
	else
	{
		std::cout <<"d2小"<< std::endl;
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