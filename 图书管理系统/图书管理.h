#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

//ͼ�����Ϣ
class StudentReader;
class TeacherReader;
class Book
{
	friend StudentReader;
	friend TeacherReader;
public:
	Book();
	void CreatBook(vector<Book>&obj);    //¼����
	void ClearBook(vector<Book>& obj);   //ɾ����
	bool operator==(const Book& obj)const;    //���ԵıȽ��Ƿ���ͬһ���飬ֻ�ж������Ƿ���ͬ
	vector<Book>::iterator GetId(vector<Book>& obj);
	void showBook(const vector<Book>& obj); //��ʾȫ�������Ϣ
	void printBook();  //��ӡ���������Ϣ
	void search(const vector<Book>& obj, int select);  //����
	void read(vector<Book>& obj);
	void write(vector<Book>& obj);
private:
	string _bookId;		//ͼ����
	string _bookName;   //����
	string _writerName; //������
	string _classId;       //�����
	string _publisher;  //���浥λ
	string _publishTime;//����ʱ��
	float _money = 0;		//�۸�
	int _storage = 0;       //�����
};

class Reader
{
public:
	Reader(string cardId = "000000", string name = "", string sex = "", string birthTime = "0��0��0��")
		:m_cardId("cardId"), m_name(name), m_sex(sex), m_birthTime(birthTime)
	{

	}
	~Reader()
	{

	}
	string m_cardId;   //����֤��
	string m_name;     //��������
	string m_sex;      //�����Ա�
	string m_birthTime;//��������    
};

class StudentReader :public Reader
{
public:
	StudentReader(string cardId="00000", string name = "---", string sex = "δ֪", string birthTime="0��0��0��"
		,string grade = "0", string department = "δ����", int CNnumber = 0, int ENGnumber = 0, int isResearcher = 0)
		:Reader(cardId, name, sex, birthTime),
		m_grade(grade), m_department(department), m_CNnumber(CNnumber), m_ENGnumber(ENGnumber), m_isResearcher(isResearcher)
	{

	}
	~StudentReader()
	{

	}
	void CreatStudent(vector<StudentReader>& obj);			//����һ��ѧ��
	bool operator==(const StudentReader& obj)const;			//ͨ�����űȽ��Ƿ���ͬһ����
	vector<StudentReader>::iterator GetCardId(vector<StudentReader>& obj);
	void borrowBook(vector<StudentReader>& obj1, vector<Book>& obj2);  //���飬���������
	void returnBook(vector<StudentReader>& obj1, vector<Book>& obj2);  //���飬���������
	void read(vector<StudentReader>& obj);
	void write(vector<StudentReader>& obj);
private:
	string m_grade;      //�꼶
	string m_department;  //ϵ��
	int m_CNnumber;      //��������
	int m_ENGnumber;     //��������
	int m_isResearcher; 
	vector<string>m_bookName;
	vector<string> m_returnDate;
};

class TeacherReader :public Reader
{
public:
	TeacherReader(string cardId="00000", string name="---", string sex="δ֪", string birthTime="0��0��0��"
		, string department="δ����", int CNnumber =15, int ENGnumber =5)
		:Reader(cardId, name, sex, birthTime)
		, m_department(department), m_CNnumber(CNnumber), m_ENGnumber(ENGnumber)
	{

	}
	~TeacherReader()
	{

	}
	void CreatTeacher(vector<TeacherReader>& obj);		//����һ����ʦ
	bool operator==(const TeacherReader& obj)const;		//ͨ�����űȽ��Ƿ���ͬһ����
	vector<TeacherReader>::iterator GetCardId(vector<TeacherReader>& obj); 
	void borrowBook(vector<TeacherReader>& obj1, vector<Book>& obj2);  //���飬���������
	void returnBook(vector<TeacherReader>& obj, vector<Book>& obj2);  //���飬���������
	void read(vector<TeacherReader>& obj);
	void write(vector<TeacherReader>& obj);
private:
	string m_department;  //����
	int m_CNnumber;      //����  15
	int m_ENGnumber;     //����   5
	vector<string>m_bookName;
	vector<string> m_returnDate;
};