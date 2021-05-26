#include"Date_class.h"

inline int GetMonthDay(int year, int month)
{
	//这里创建一个元素个数为13个的数组，这样我们就可以把下标与月份一一对应上
	static int DayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = DayArray[month];
	if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		day += 1;
	}
	return day;
}

//全缺省的构造函数
Date::Date(int year, int month, int day)
{
	//检查初始化日期的值是否合法
	if ((year >= 0) && ((month > 0) && (month < 13)) && (day <= GetMonthDay(year, month)))
	{
		this->m_day = day;
		this->m_month = month;
		this->m_year = year;
	}
	else
	{
		std::cout << "非法日期" << std::endl;
		exit(-1);
	}
}

//拷贝构造函数
Date::Date(const Date& d)
{
	this->m_year = d.m_year;
	this->m_month = d.m_month;
	this->m_day = d.m_day;
}

//重载 = 号
Date& Date::operator=(const Date& d)
{
	//有人可能想把自己对象的值赋给自己 例如  a=a;
	if (this == &d)
	{
		return *this;
	}
	else
	{
		this->m_year = d.m_year;
		this->m_month = d.m_month;
		this->m_day = d.m_day;

		return *this;
	}

}

//析构函数
Date::~Date()
{
	//由于我们并没有在堆区开辟空间，故不需要在析构函数中写任何代码
}

//重载 += 号
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		//复用operator -=重载
		return *this -= -day;
	}
	else
	{
		this->m_day += day;
		while (this->m_day > GetMonthDay(this->m_year, this->m_month))
		{
			this->m_day -= GetMonthDay(this->m_year, this->m_month);
			this->m_month++;
			if (this->m_month > 12)
			{
				this->m_year++;
				this->m_month = 1;
			}
		}

		return *this;
	}

}

//重载 + 号
Date Date::operator+(int day)
{
	//由于+是两个数相加，对原来的对象不能有任何的改变，所以我们需要用值传递，返回一个临时变量
	Date tempD(*this);
	//复用operator +=重载
	tempD += day;
	return tempD;
}

//重载 - 号
Date Date::operator-(int day)
{
	//由于-是两个数相减，对原来的对象不能有任何的改变，所以我们需要用值传递，返回一个临时变量
	Date tempD(*this);
	//复用operator -=重载
	tempD -= day;
	return tempD;
}

//重载 -= 号
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		//复用operator +=重载
		return *this += -day;
	}
	else
	{
		this->m_day -= day;
		while (this->m_day <= 0)
		{
			this->m_month--;
			this->m_day += GetMonthDay(this->m_year, this->m_month);
			if (this->m_month < 1)
			{
				this->m_year--;
				this->m_month = 12;
			}
		}
		return *this;
	}

}

//前置 ++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置 ++
Date Date::operator++(int)
{
	Date tempD(*this);
	*this += 1;
	return tempD;
}

//后置 --
Date Date::operator--(int)
{
	Date tempD(*this);
	*this -= 1;
	return tempD;
}

//前置 --
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}



//重载 != 号
bool Date::operator!=(const Date& d)
{
	//复用==号重载
	return !(*this==(d));
}



//重载 > 号
bool Date::operator>(const Date& d)
{
	if (this->m_year > d.m_year)
	{
		return true;
	}
	else if (this->m_year == d.m_year)
	{
		if (this->m_month > d.m_month)
		{
			return true;
		}
		else if (this->m_month == d.m_month)
		{
			if (this->m_day > d.m_day)
			{
				return true;
			}
		}
	}

	return false;
}

//重载 == 号
bool Date::operator==(const Date& d)
{
	if ((this->m_year == d.m_year) && (this->m_month == d.m_month) && (this->m_day == d.m_day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//重载 >= 号
bool Date::operator>=(const Date& d)
{
	//复用重载 == 号 和 >
	return this->operator==(d) || this->operator>(d);
}

//重载 < 号
bool Date::operator<(const Date& d)
{
	//复用重载的 >= 号
	return !this->operator>=(d);
}

//重载 <= 号
bool Date::operator<=(const Date& d)
{
	//复用重载的 >号
	return !this->operator>(d);
}

//重载 - 号
int Date::operator-(const Date& d)
{
	int flag = 1;

	Date tempMax = *this;
	Date tempMin = d;
	if (tempMin < tempMax)
	{
		//利用模板中的swap函数来交换两个自定义的数据类型
		std::swap(tempMax, tempMin);
		flag = -1;
	}

	int ABS_day = 0;
	while (tempMin < tempMax)
	{
		++tempMin;
		++ABS_day;
	}

	return flag * ABS_day;

}
//打印日期
void Date::PrintDate()
{
	std::cout << std::left << std::setw(4) << this->m_year << "年"
		<< std::left << std::setw(2) << this->m_month << "月"
		<< std::left << std::setw(2) << this->m_day << "日" << std::endl;
}
