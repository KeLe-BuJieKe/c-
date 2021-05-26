#include"Date_class.h"

inline int GetMonthDay(int year, int month)
{
	//���ﴴ��һ��Ԫ�ظ���Ϊ13�������飬�������ǾͿ��԰��±����·�һһ��Ӧ��
	static int DayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = DayArray[month];
	if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		day += 1;
	}
	return day;
}

//ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day)
{
	//����ʼ�����ڵ�ֵ�Ƿ�Ϸ�
	if ((year >= 0) && ((month > 0) && (month < 13)) && (day <= GetMonthDay(year, month)))
	{
		this->m_day = day;
		this->m_month = month;
		this->m_year = year;
	}
	else
	{
		std::cout << "�Ƿ�����" << std::endl;
		exit(-1);
	}
}

//�������캯��
Date::Date(const Date& d)
{
	this->m_year = d.m_year;
	this->m_month = d.m_month;
	this->m_day = d.m_day;
}

//���� = ��
Date& Date::operator=(const Date& d)
{
	//���˿�������Լ������ֵ�����Լ� ����  a=a;
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

//��������
Date::~Date()
{
	//�������ǲ�û���ڶ������ٿռ䣬�ʲ���Ҫ������������д�κδ���
}

//���� += ��
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		//����operator -=����
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

//���� + ��
Date Date::operator+(int day)
{
	//����+����������ӣ���ԭ���Ķ��������κεĸı䣬����������Ҫ��ֵ���ݣ�����һ����ʱ����
	Date tempD(*this);
	//����operator +=����
	tempD += day;
	return tempD;
}

//���� - ��
Date Date::operator-(int day)
{
	//����-���������������ԭ���Ķ��������κεĸı䣬����������Ҫ��ֵ���ݣ�����һ����ʱ����
	Date tempD(*this);
	//����operator -=����
	tempD -= day;
	return tempD;
}

//���� -= ��
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		//����operator +=����
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

//ǰ�� ++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//���� ++
Date Date::operator++(int)
{
	Date tempD(*this);
	*this += 1;
	return tempD;
}

//���� --
Date Date::operator--(int)
{
	Date tempD(*this);
	*this -= 1;
	return tempD;
}

//ǰ�� --
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}



//���� != ��
bool Date::operator!=(const Date& d)
{
	//����==������
	return !(*this==(d));
}



//���� > ��
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

//���� == ��
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

//���� >= ��
bool Date::operator>=(const Date& d)
{
	//�������� == �� �� >
	return this->operator==(d) || this->operator>(d);
}

//���� < ��
bool Date::operator<(const Date& d)
{
	//�������ص� >= ��
	return !this->operator>=(d);
}

//���� <= ��
bool Date::operator<=(const Date& d)
{
	//�������ص� >��
	return !this->operator>(d);
}

//���� - ��
int Date::operator-(const Date& d)
{
	int flag = 1;

	Date tempMax = *this;
	Date tempMin = d;
	if (tempMin < tempMax)
	{
		//����ģ���е�swap���������������Զ������������
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
//��ӡ����
void Date::PrintDate()
{
	std::cout << std::left << std::setw(4) << this->m_year << "��"
		<< std::left << std::setw(2) << this->m_month << "��"
		<< std::left << std::setw(2) << this->m_day << "��" << std::endl;
}
