#include"ͼ�����.h"

void TeacherReader::CreatTeacher(vector<TeacherReader>& obj)
{
	TeacherReader t;
go2:
	cout << "���������֤��" << endl;
	cin >> t.m_cardId;
	vector<TeacherReader>::iterator index = t.GetCardId(obj);
	if (index != obj.end())
	{
		cout << "������Ľ��ĺ��Ѵ���,����������" << endl;
		system("pause");
		system("cls");
		goto go2;

	}
	cout << "������������" << endl;
	cin >> t.m_name;
	cout << "�������Ա�" << endl;
	cin >> t.m_sex;
	cout << "���������գ�" << endl;
	cin >> t.m_birthTime;
	cout << "�����벿�ţ�" << endl;
	cin >> t.m_department;

	obj.push_back(t);

	cout << "��ӳɹ�" << endl;
	this->write(obj);
	system("pause");
	system("cls");
}

bool TeacherReader::operator==(const TeacherReader& obj) const
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

vector<TeacherReader>::iterator TeacherReader::GetCardId(vector<TeacherReader>& obj)
{
	vector<TeacherReader>::iterator index = find(obj.begin(), obj.end(), *this);
	return index;

}

void TeacherReader::borrowBook(vector<TeacherReader>& obj1, vector<Book>& obj2)
{
	TeacherReader t;
	cout << "�����������˵Ľ���֤��" << endl;
	cin >> t.m_cardId;
	Book b;
	vector<TeacherReader>::iterator index = t.GetCardId(obj1);
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
						(*temp)._storage -= 1;
					}
				}
				else
				{
					if ((*index).m_ENGnumber == 0)
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


void TeacherReader::returnBook(vector<TeacherReader>& obj1, vector<Book>& obj2)
{
	TeacherReader t;
	cout << "������Ҫ�黹�Ľ��ĺţ�" << endl;
	cin >> t.m_cardId;
	Book b;
	vector<TeacherReader>::iterator index = t.GetCardId(obj1);
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
			if (temp != obj2.end() && ret != (*index).m_bookName.end())
			{
				string edition;
				cout << "������Ҫ�黹�İ汾(����/Ӣ��):" << endl;
				cin >> edition;
				if (edition == "����")
				{
					if ((*index).m_CNnumber < 15)
					{
						(*index).m_CNnumber++;
					}
				}
				else
				{
					if ((*index).m_ENGnumber < 5)
					{
						(*index).m_ENGnumber++;
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
				//ɾ��������ʦ�������Ȿ�������
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

void TeacherReader::read(vector<TeacherReader>& obj)
{
	ifstream ifs;
	ifs.open("TeacherReader.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	else
	{
		int i = 0;
		TeacherReader s;
		while (ifs >> s.m_cardId
			>> s.m_name
			>> s.m_sex
			>> s.m_birthTime
			>> s.m_department
			>> s.m_CNnumber
			>> s.m_ENGnumber
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

void TeacherReader::write(vector<TeacherReader>& obj)
{
	ofstream ofs;
	ofs.open("TeacherReader.txt", ios::out);
	for (size_t i = 0; i < obj.size(); ++i)
	{
		ofs << obj[i].m_cardId << "   "
			<< obj[i].m_name << "   "
			<< obj[i].m_sex << "   "
			<< obj[i].m_birthTime << "   "
			<< obj[i].m_department << "   "
			<< obj[i].m_CNnumber << "   "
			<< obj[i].m_ENGnumber << "   " 
			<< obj.size()<< "   ";
			
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
