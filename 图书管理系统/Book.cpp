#include"图书管理.h"


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
	cout << "请输入分类号:" << endl;
	cin >> b._classId;

	cout << "请输入书名:" << endl;
	cin >> b._bookName;

	cout << "请输入书本量:" << endl;
	cin >> b._storage;


	cout << "请输入图书编号:" << endl;
	cin >> b._bookId;

	cout << "请输入作者:" << endl;
	cin >> b._writerName;

	cout << "请输入出版商:" << endl;
	cin >> b._publisher;

	cout << "请输入出版时间:" << endl;
	cin >> b._publishTime;

	cout << "请输入钱:" << endl;
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
	cout << "添加成功" << endl;
	this->write(obj);
	system("pause");
	system("cls");
}



void Book::ClearBook(vector<Book>& obj)
{
	Book b;
	cout << "请输入你要删除书名：" << endl;
	cin>>b._bookName;
	vector<Book>::iterator index = b.GetId(obj);
	if (index != obj.end())
	{
		obj.erase(index);
		this->write(obj);
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "要删除的书不存在" << endl;
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
		cout << "书号:" << e._bookId  << "\t" << "书名:" <<e._bookName <<"\t" 
			<< "作者:" <<e._writerName<<"\t" << " 出版社:" <<e._publisher <<"\t"
			<< "出版时间:" <<e._publishTime<<"\t" << "分类号:" <<e._classId<<"\t"
			<< "价格:" <<e._money << "\t" << "库存量:" <<e._storage<< endl;
	}
	if (flag == false)
	{
		cout << "图书为空" << endl;
	}
	system("pause");
	system("cls");
}

void Book::printBook()
{
	cout << "书号:" <<this->_bookId << "\t" << "书名:" << this->_bookName << "\t"
		<< "作者:" << this->_writerName << "\t" << " 出版社:" << this->_publisher << "\t"
		<< "出版时间:" << this->_publishTime << "\t" << "分类号:" << this->_classId << "\t"
		<< "价格:" << this->_money << "\t" << "库存量:" << this->_storage << endl;
}

void Book::search(const vector<Book>& obj,int select)
{
	string str;
	if (select == 1)
	{
		cout << "请输入你要查找的作者:" << endl;
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
			cout<< "查无该作者的作品！" << endl;
		}
	}
	else if(select == 2)
	{
		cout << "请输入你要查找的书名:" << endl;
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
			cout << "查无该书名的作品！" << endl;
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
		cout << "文件打开失败" << endl;
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
