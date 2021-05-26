#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iomanip>
#include<iostream>

//�������Ǿ�����������������Һ������С
// ��ȡĳ��ĳ�µ�����
inline int GetMonthDay(int year, int month);

class Date
{
public:
    // ȫȱʡ�Ĺ��캯��
    Date(int year = 2000, int month = 1, int day = 1);

    // �������캯��
    // d2(d1)
    Date(const Date& d);

    // ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
    Date& operator=(const Date& d);

    // ��������
    ~Date();

    // ����+=����
    Date& operator+=(int day);

    // ����+����
    Date operator+(int day);

    // ����-����
    Date operator-(int day);

    // ����-=����
    Date& operator-=(int day);

    //ǰ��++��--��Ҫ�������ã�����++��--���صĲ������ã�����һ����ʱֵ�����Բ��ܽ�������ʹ�á�
    //����--��++  ���� a=b--;  �������Ȱ�bԭ����ֵ��a������b�Լ�1����������������b�����ã�����b�����ûᵼ��a��b��ֵ��ͬ
    // ǰ��++
    Date& operator++();

    // ����++
    Date operator++(int);

    // ����--
    Date operator--(int);

    // ǰ��--
    Date& operator--();

    // >���������
    bool operator>(const Date& d);

    // ==���������
    bool operator==(const Date& d);

    // >=���������
    bool operator >= (const Date& d);

    // <���������
    bool operator < (const Date& d);

    // <=���������
    bool operator <= (const Date& d);

    // !=���������
    bool operator != (const Date& d);

    // ����-���� ��������
    int operator-(const Date& d);

    // ��ӡ����
    void PrintDate();

private:
    int m_year;      //��
    int m_month;     //��
    int m_day;       //��
};