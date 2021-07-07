#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

//图书的信息
class StudentReader;
class TeacherReader;
class Book
{
	friend StudentReader;
	friend TeacherReader;
public:
	Book();
	void CreatBook(vector<Book>&obj);    //录入书
	void ClearBook(vector<Book>& obj);   //删除书
	bool operator==(const Book& obj)const;    //粗略的比较是否是同一本书，只判断名字是否相同
	vector<Book>::iterator GetId(vector<Book>& obj);
	void showBook(const vector<Book>& obj); //显示全部书的信息
	void printBook();  //打印单本书的信息
	void search(const vector<Book>& obj, int select);  //查找
	void read(vector<Book>& obj);
	void write(vector<Book>& obj);
private:
	string _bookId;		//图书编号
	string _bookName;   //书名
	string _writerName; //作者名
	string _classId;       //分类号
	string _publisher;  //出版单位
	string _publishTime;//出版时间
	float _money = 0;		//价格
	int _storage = 0;       //库存量
};

class Reader
{
public:
	Reader(string cardId = "000000", string name = "", string sex = "", string birthTime = "0年0月0日")
		:m_cardId("cardId"), m_name(name), m_sex(sex), m_birthTime(birthTime)
	{

	}
	~Reader()
	{

	}
	string m_cardId;   //借阅证号
	string m_name;     //读者姓名
	string m_sex;      //读者性别
	string m_birthTime;//出生日期    
};

class StudentReader :public Reader
{
public:
	StudentReader(string cardId="00000", string name = "---", string sex = "未知", string birthTime="0年0月0日"
		,string grade = "0", string department = "未设置", int CNnumber = 0, int ENGnumber = 0, int isResearcher = 0)
		:Reader(cardId, name, sex, birthTime),
		m_grade(grade), m_department(department), m_CNnumber(CNnumber), m_ENGnumber(ENGnumber), m_isResearcher(isResearcher)
	{

	}
	~StudentReader()
	{

	}
	void CreatStudent(vector<StudentReader>& obj);			//创建一个学生
	bool operator==(const StudentReader& obj)const;			//通过卡号比较是否是同一个人
	vector<StudentReader>::iterator GetCardId(vector<StudentReader>& obj);
	void borrowBook(vector<StudentReader>& obj1, vector<Book>& obj2);  //借书，库存量减少
	void returnBook(vector<StudentReader>& obj1, vector<Book>& obj2);  //还书，库存量增加
	void read(vector<StudentReader>& obj);
	void write(vector<StudentReader>& obj);
private:
	string m_grade;      //年级
	string m_department;  //系别
	int m_CNnumber;      //中文数量
	int m_ENGnumber;     //外文数量
	int m_isResearcher; 
	vector<string>m_bookName;
	vector<string> m_returnDate;
};

class TeacherReader :public Reader
{
public:
	TeacherReader(string cardId="00000", string name="---", string sex="未知", string birthTime="0年0月0日"
		, string department="未设置", int CNnumber =15, int ENGnumber =5)
		:Reader(cardId, name, sex, birthTime)
		, m_department(department), m_CNnumber(CNnumber), m_ENGnumber(ENGnumber)
	{

	}
	~TeacherReader()
	{

	}
	void CreatTeacher(vector<TeacherReader>& obj);		//创建一个老师
	bool operator==(const TeacherReader& obj)const;		//通过卡号比较是否是同一个人
	vector<TeacherReader>::iterator GetCardId(vector<TeacherReader>& obj); 
	void borrowBook(vector<TeacherReader>& obj1, vector<Book>& obj2);  //借书，库存量减少
	void returnBook(vector<TeacherReader>& obj, vector<Book>& obj2);  //还书，库存量增加
	void read(vector<TeacherReader>& obj);
	void write(vector<TeacherReader>& obj);
private:
	string m_department;  //部门
	int m_CNnumber;      //中文  15
	int m_ENGnumber;     //外文   5
	vector<string>m_bookName;
	vector<string> m_returnDate;
};