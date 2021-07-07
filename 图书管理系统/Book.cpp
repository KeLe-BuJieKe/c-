#include"ͼ�����.h"


Book::Book()
{
	this->_bookId = "";
	this->_bookName = "";
	this->_classId = "";
	this->_money = 0;
	this->_publisher = "";
	this->_publishTime = "";
	this->_storage = 0;
}

void Book::CreatBook(vector<Book>& obj)
{
	Book b;
	cout << "����������:" << endl;
	cin >> b._classId;

	cout << "����������:" << endl;
	cin >> b._bookName;

	cout << "�������鱾��:" << endl;
	cin >> b._storage;


	cout << "������ͼ����:" << endl;
	cin >> b._bookId;

	cout << "����������:" << endl;
	cin >> b._writerName;

	cout << "�����������:" << endl;
	cin >> b._publisher;

	cout << "���������ʱ��:" << endl;
	cin >> b._publishTime;

	cout << "������Ǯ:" << endl;
	cin >> b._money;

	vector<Book>::iterator index =b.GetId(obj);
	if (index != obj.end())
	{
		(*index)._storage += b._storage;
	}
	else
	{
		obj.push_back(b);
	}
	cout << "��ӳɹ�" << endl;
	this->write(obj);
	system("pause");
	system("cls");
}



void Book::ClearBook(vector<Book>& obj)
{
	Book b;
	cout << "��������Ҫɾ��������" << endl;
	cin>>b._bookName;
	vector<Book>::iterator index = b.GetId(obj);
	if (index != obj.end())
	{
		obj.erase(index);
		this->write(obj);
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "Ҫɾ�����鲻����" << endl;
	}
	system("pause");
	system("cls");
}

bool Book::operator==(const Book& obj)const
{
	if (this->_bookName == obj._bookName)
	{
		return true;
	}
	else
	{
		return false;
	}
}



vector<Book>::iterator Book::GetId(vector<Book>& obj)
{

	vector<Book>::iterator index = find(obj.begin(), obj.end(),*this);
	return index;
}


void Book::showBook(const vector<Book>& obj)
{
	bool flag = false;
	for (auto e : obj)
	{
		flag = true;
		cout << "���:" << e._bookId  << "\t" << "����:" <<e._bookName <<"\t" 
			<< "����:" <<e._writerName<<"\t" << " ������:" <<e._publisher <<"\t"
			<< "����ʱ��:" <<e._publishTime<<"\t" << "�����:" <<e._classId<<"\t"
			<< "�۸�:" <<e._money << "\t" << "�����:" <<e._storage<< endl;
	}
	if (flag == false)
	{
		cout << "ͼ��Ϊ��" << endl;
	}
	system("pause");
	system("cls");
}

void Book::printBook()
{
	cout << "���:" <<this->_bookId << "\t" << "����:" << this->_bookName << "\t"
		<< "����:" << this->_writerName << "\t" << " ������:" << this->_publisher << "\t"
		<< "����ʱ��:" << this->_publishTime << "\t" << "�����:" << this->_classId << "\t"
		<< "�۸�:" << this->_money << "\t" << "�����:" << this->_storage << endl;
}

void Book::search(const vector<Book>& obj,int select)
{
	string str;
	if (select == 1)
	{
		cout << "��������Ҫ���ҵ�����:" << endl;
		cin >> str;
		bool flag = false;
		for (auto e : obj)
		{
			if (e._writerName == str)
			{
				flag = true;
				e.printBook();
			}
		}
		if (flag == false)
		{
			cout<< "���޸����ߵ���Ʒ��" << endl;
		}
	}
	else if(select == 2)
	{
		cout << "��������Ҫ���ҵ�����:" << endl;
		cin >> str;
		bool flag = false;

		for (auto e : obj)
		{
			if (e._bookName == str)
			{
				flag = true;
				e.printBook();
			}
		}
		if (flag == false)
		{
			cout << "���޸���������Ʒ��" << endl;
		}
	}
	else if (select == 2)
	{
		return;
	}
	system("pause");
	system("cls");
}


void Book::read(vector<Book>& obj)
{
	ifstream ifs;
	ifs.open("Book.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	else
	{
		Book b;
		while (ifs >> b._bookId
			>>b._bookName
			>> b._writerName
			>> b._classId
			>> b._publisher
			>> b._publishTime
			>> b._money
			>> b._storage)
		{
			obj.push_back(b);
		}
	}
	ifs.close();
}

void Book::write(vector<Book>& obj)
{
	ofstream ofs;
	ofs.open("Book.txt", ios::out);
	for (size_t i = 0; i < obj.size(); ++i)
	{
		ofs << obj[i]._bookId<< "   "
			<<obj[i]._bookName<< "   "
			<< obj[i]._writerName << "   "
			<< obj[i]._classId << "   "
			<< obj[i]._publisher << "   "
			<< obj[i]._publishTime << "   "
			<< obj[i]._money << "   "
			<< obj[i]._storage << endl;
	}
	ofs.close();
}
