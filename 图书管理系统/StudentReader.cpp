#include"ͼ�����.h"

void StudentReader::CreatStudent(vector<StudentReader>& obj)
{

	StudentReader s;
go1:
	cout << "���������֤��" << endl;
	cin >> s.m_cardId;
	vector<StudentReader>::iterator index=s.GetCardId(obj);
	if (index != obj.end())
	{
		cout << "������Ľ��ĺ��Ѵ���,����������" << endl;
		system("pause");
		system("cls");
		goto go1;

	}
	cout << "������������" << endl;
	cin >> s.m_name;
	cout << "�������Ա�" << endl;
	cin >> s.m_sex;
	cout << "���������գ�" << endl;
	cin >> s.m_birthTime;
	cout << "�������꼶��" << endl;
	cin >> s.m_grade;
	cout << "������ϵ��" << endl;
	cin >> s.m_department;
f:
	cout << "0������  1���о���" << endl;
	cout << "������ѧ��:" << endl;
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
		cout << "������������������" << endl;
		goto f;
	}
	obj.push_back(s);
	this->write(obj);
	cout << "��ӳɹ�" << endl;
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
	cout << "�����������˵Ľ���֤��" << endl;
	cin >> s.m_cardId;

	Book b;
	vector<StudentReader>::iterator index = s.GetCardId(obj1);
	if (index != obj1.end())
	{
		cout << "������Ҫ�������" << endl;
		cin >> b._bookName;
		vector<Book>::iterator temp = b.GetId(obj2);
		if (temp != obj2.end())
		{

			if ((*temp)._storage == 0)
			{
				cout << "��������㣡" << endl;
			}
			else
			{
				string ReturnTime;
				cout << "������黹ʱ�䣨0�� 0�� 0�գ���" << endl;
				cin >> ReturnTime;

				string edition;
				cout << "����������Ҫ�İ汾(����/Ӣ��):" << endl;
				cin >> edition;

				if (edition == "����")
				{
					if ((*index).m_CNnumber == 0)
					{
						cout << "��ǰ���İ�ɽ�����Ϊ0" << endl;
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
						cout << "��ǰӢ�İ�ɽ�����Ϊ0" << endl;
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
				cout << "ͼ����ĳɹ�" << endl;
			}

		}
		else
		{
			cout << "��Ҫ�������������" << endl;
		}
	}
	else
	{
		cout << "�����˺�" << endl;
	}
	this->write(obj1);
	b.write(obj2);
	system("pause");
	system("cls");
}


void StudentReader::returnBook(vector<StudentReader>& obj1, vector<Book>& obj2)
{
	StudentReader s;
	cout << "������Ҫ�黹�Ľ��ĺţ�" << endl;
	cin>>s.m_cardId;
	Book b;
	vector<StudentReader>::iterator index = s.GetCardId(obj1);
	if (index == obj1.end())
	{
		cout << "�ý��ĺŲ�����" << endl;
	}
	else
	{
		if ((*index).m_bookName.size() == 0)
		{
			cout << "��ʱ����Ҫ�黹" << endl;
		}
		else
		{
			
			cout << "������Ҫ��������" << endl;
			cin >> b._bookName;
			vector<Book>::iterator temp = b.GetId(obj2);
			vector<string>::iterator ret = find((*index).m_bookName.begin(), (*index).m_bookName.end(), b._bookName);
			if (temp != obj2.end()&&ret!=(*index).m_bookName.end())
			{
				string edition;
				cout << "������Ҫ�黹�İ汾(����/Ӣ��):" << endl;
				cin >> edition;
				if (edition == "����")
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
				cout << "���������黹���ʱ��" << endl;
				cin >> ReturnTime;
				vector<string>::iterator result = find((*index).m_returnDate.begin(), (*index).m_returnDate.end(), ReturnTime);
				if ((*result) < ReturnTime)
				{
					cout << "�黹��ʱ�䳬�У�����Ҫ���� 1Ԫ ��ʱ��" << endl;
				}
				//ɾ������ѧ���������Ȿ�������
				(*index).m_bookName.erase(ret);
				(*index).m_returnDate.erase(result);
				//ͼ��洢������
				(*temp)._storage++;
				cout << "����ɹ�" << endl;
			}
			else
			{
				cout << "���鲻�����Ŀ¼�У�����Ҫ�黹" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
