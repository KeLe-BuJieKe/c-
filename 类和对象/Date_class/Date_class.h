#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iomanip>
#include<iostream>

//由于我们经常调用这个函数，且函数体较小
// 获取某年某月的天数
inline int GetMonthDay(int year, int month);

class Date
{
public:
    // 全缺省的构造函数
    Date(int year = 2000, int month = 1, int day = 1);

    // 拷贝构造函数
    // d2(d1)
    Date(const Date& d);

    // 赋值运算符重载
    // d2 = d3 -> d2.operator=(&d2, d3)
    Date& operator=(const Date& d);

    // 析构函数
    ~Date();

    // 日期+=天数
    Date& operator+=(int day);

    // 日期+天数
    Date operator+(int day);

    // 日期-天数
    Date operator-(int day);

    // 日期-=天数
    Date& operator-=(int day);

    //前置++、--需要返回引用，后置++、--返回的不是引用，而是一个临时值，所以不能进行连续使用。
    //后置--、++  例如 a=b--;  我们是先把b原本的值给a，在让b自减1，而不是让它返回b的引用，返回b的引用会导致a与b的值相同
    // 前置++
    Date& operator++();

    // 后置++
    Date operator++(int);

    // 后置--
    Date operator--(int);

    // 前置--
    Date& operator--();

    // >运算符重载
    bool operator>(const Date& d);

    // ==运算符重载
    bool operator==(const Date& d);

    // >=运算符重载
    bool operator >= (const Date& d);

    // <运算符重载
    bool operator < (const Date& d);

    // <=运算符重载
    bool operator <= (const Date& d);

    // !=运算符重载
    bool operator != (const Date& d);

    // 日期-日期 返回天数
    int operator-(const Date& d);

    // 打印日期
    void PrintDate();

private:
    int m_year;      //年
    int m_month;     //月
    int m_day;       //日
};