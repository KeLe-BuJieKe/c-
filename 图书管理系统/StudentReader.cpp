#include"图书管理.h"

void StudentReader::CreatStudent(vector<StudentReader>& obj)
{

	StudentReader s;
go1:
	cout << "请输入借阅证号" << endl;
	cin >> s.m_cardId;
	vector<StudentReader>::iterator index=s.GetCardId(obj);
	if (index != obj.end())
	{
		cout << "您输入的借阅号已存在,请重新输入" << endl;
		system("pause");
		system("cls");
		goto go1;

	}
	cout << "请输入姓名：" << endl;
	cin >> s.m_name;
	cout << "请输入性别：" << endl;
	cin >> s.m_sex;
	cout << "请输入生日：" << endl;
	cin >> s.m_birthTime;
	cout << "请输入年级：" << endl;
	cin >> s.m_grade;
	cout << "请输入系别：" << endl;
	cin >> s.m_department;
f:
	cout << "0：本科  1：研究生" << endl;
	cout << "请输入学历:" << endl;
	cin >> s.m_isResearcher;
	if (s.m_isResearcher == 0)
	{
		s.m_CNnumber = 8;
		s.m_ENGnumber = 2;
	}
	else if(s.m_isResearcher == 1)
	{
		s.m_CNnumber = 15;
		s.m_ENGnumber = 5;
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
		goto f;
	}
	obj.push_back(s);
	this->write(obj);
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

}

bool StudentReader::operator==(const StudentReader& obj) const
{
	if (this->m_cardId == obj.m_cardId)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<StudentReader>::iterator StudentReader::GetCardId(vector<StudentReader>& obj)
{
	vector<StudentReader>::iterator index = find(obj.begin(), obj.end(), *this);
	return index;
}

void StudentReader::borrowBook(vector<StudentReader>& obj1, vector<Book>& obj2)
{
	StudentReader s;
	cout << "请输入所借人的借阅证号" << endl;
	cin >> s.m_cardId;

	Book b;
	vector<StudentReader>::iterator index = s.GetCardId(obj1);
	if (index != obj1.end())
	{
		cout << "请输入要借的书名" << endl;
		cin >> b._bookName;
		vector<Book>::iterator temp = b.GetId(obj2);
		if (temp != obj2.end())
		{

			if ((*temp)._storage == 0)
			{
				cout << "库存量不足！" << endl;
			}
			else
			{
				string ReturnTime;
				cout << "请输入归还时间（0年 0月 0日）：" << endl;
				cin >> ReturnTime;

				string edition;
				cout << "请输入所需要的版本(中文/英文):" << endl;
				cin >> edition;

				if (edition == "中文")
				{
					if ((*index).m_CNnumber == 0)
					{
						cout << "当前中文版可借阅数为0" << endl;
						return;
					}
					else
					{
						(*index).m_CNnumber--;
						(*temp)._storage -=1;
					}
				}
				else
				{
					if ((*index).m_ENGnumber== 0)
					{
						cout << "当前英文版可借阅数为0" << endl;
						return;
					}
					else
					{
						(*index).m_ENGnumber--;
						(*temp)._storage--;
					}
				}
				(*index).m_bookName.push_back(b._bookName);
				(*index).m_returnDate.push_back(ReturnTime);
				cout << "图书借阅成功" << endl;
			}

		}
		else
		{
			cout << "您要借的书名不存在" << endl;
		}
	}
	else
	{
		cout << "查无账号" << endl;
	}
	this->write(obj1);
	b.write(obj2);
	system("pause");
	system("cls");
}


void StudentReader::returnBook(vector<StudentReader>& obj1, vector<Book>& obj2)
{
	StudentReader s;
	cout << "请输入要归还的借阅号：" << endl;
	cin>>s.m_cardId;
	Book b;
	vector<StudentReader>::iterator index = s.GetCardId(obj1);
	if (index == obj1.end())
	{
		cout << "该借阅号不存在" << endl;
	}
	else
	{
		if ((*index).m_bookName.size() == 0)
		{
			cout << "暂时无书要归还" << endl;
		}
		else
		{
			
			cout << "请输入要还的书名" << endl;
			cin >> b._bookName;
			vector<Book>::iterator temp = b.GetId(obj2);
			vector<string>::iterator ret = find((*index).m_bookName.begin(), (*index).m_bookName.end(), b._bookName);
			if (temp != obj2.end()&&ret!=(*index).m_bookName.end())
			{
				string edition;
				cout << "请输入要归还的版本(中文/英文):" << endl;
				cin >> edition;
				if (edition == "中文")
				{
					if ((*index).m_isResearcher == 0)
					{
						if ((*index).m_CNnumber<8)
						{
							(*index).m_CNnumber++;
						}
					}
					else if((*index).m_isResearcher == 1)
					{
						if ((*index).m_CNnumber < 15)
						{
							(*index).m_CNnumber++;
						}
					}
				}
				else 
				{
					if ((*index).m_isResearcher == 0)
					{
						if ((*index).m_ENGnumber < 2)
						{
							(*index).m_CNnumber++;
						}
					}
					else if ((*index).m_isResearcher == 1)
					{
						if ((*index).m_ENGnumber <5)
						{
							(*index).m_ENGnumber++;
						}
					}
				}

				string ReturnTime;
				cout << "请输入今天归还书的时间" << endl;
				cin >> ReturnTime;
				vector<string>::iterator result = find((*index).m_returnDate.begin(), (*index).m_returnDate.end(), ReturnTime);
				if ((*result) < ReturnTime)
				{
					cout << "归还书时间超市，您需要缴纳 1元 超时费" << endl;
				}
				//删除该名学生的所还这本书的名字
				(*index).m_bookName.erase(ret);
				(*index).m_returnDate.erase(result);
				//图书存储量增加
				(*temp)._storage++;
				cout << "还书成功" << endl;
			}
			else
			{
				cout << "该书不在书库目录中，不需要归还" << endl;
			}
		}
	}
	this->write(obj1);
	b.write(obj2);
	system("pause");
	system("cls");
}

void StudentReader::read(vector<StudentReader>& obj)
{
	ifstream ifs;
	ifs.open("StudentReader.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	else
	{
		int i = 0;
		StudentReader s;
		while (ifs >> s.m_cardId
			>> s.m_name
			>> s.m_sex
			>> s.m_birthTime
			>> s.m_grade
			>> s.m_department
			>> s.m_CNnumber
			>> s.m_ENGnumber
			>> s.m_isResearcher
			>> i)
		{
			
			string str1;
			int j = 0;
			while ((j < i) && (ifs >> str1))
			{
				s.m_bookName.push_back(str1);
				j++;
			}

			string str2;
			j = 0;
			while ((j < i) && (ifs >> str2))
			{
				s.m_returnDate.push_back(str2);
				j++;
			}
			obj.push_back(s);
		}

	}
	ifs.close();
}

void StudentReader::write(vector<StudentReader>& obj)
{
	ofstream ofs;
	ofs.open("StudentReader.txt", ios::out);
	for (size_t i = 0; i < obj.size(); ++i)
	{
		ofs << obj[i].m_cardId << "   "
			<< obj[i].m_name << "   "
			<< obj[i].m_sex << "   "
			<< obj[i].m_birthTime << "   "
			<< obj[i].m_grade << "   "
			<< obj[i].m_department << "   "
			<< obj[i].m_CNnumber << "   "
			<< obj[i].m_ENGnumber << "   "
			<< obj[i].m_isResearcher << "   " 
			<<obj.size() << "   ";

		for (size_t j = 0; j < obj[i].m_bookName.size(); ++j)
		{
			ofs << obj[i].m_bookName[j] << "   ";
		}

		for (size_t k = 0; k < obj[i].m_returnDate.size(); ++k)
		{
			ofs << obj[i].m_returnDate[k] << "   ";
		}
		ofs << endl;
	}
	ofs.close();
}
