#include"图书管理.h"

void menuSearchMethod()
{
	cout << "1.按作者名字查询" << endl;
	cout << "2.按书名查询" << endl;
	cout << "0.退出" << endl;

}

void menuBorrowBook()
{
	cout << "1.学生借阅书" << endl;
	cout << "2.老师借阅书" << endl;
	cout << "0.退出" << endl;
}

void menuReturnBook()
{
	cout << "1.学生还书" << endl;
	cout << "2.老师还书" << endl;
	cout << "0.退出" << endl;
}

void mainmenu()
{
	cout << "1.录入图书" << endl;
	cout << "2.删除图书" << endl;
	cout << "3.查找图书" << endl;
	cout << "4.显示全部书籍"<<endl;
	cout << "5.添加学生" << endl;
	cout << "6.添加老师" << endl;
	cout << "7.借阅图书" << endl;
	cout << "8.还书" << endl;
	cout << "0.退出" << endl;

}



void Start()
{
	vector<Book> barray;
	Book b1;

	vector<StudentReader> sarray;
	StudentReader s1;

	vector<TeacherReader> tarray;
	TeacherReader t1;

	b1.read(barray);
	s1.read(sarray);
	t1.read(tarray);
	bool flag = true;
	while (flag)
	{
		mainmenu();
		int select;
		cin >> select;

		system("pause");
		system("cls");
		switch (select)
		{
		case 1:
			b1.CreatBook(barray);
			break;
		case 2:
			b1.ClearBook(barray);
			break;
		case 3:
f1:
			menuSearchMethod();
			int option;
			cin >> option;
			if (option != 0 && option != 1 && option != 2)
			{
				cout << "输入有误，请重新输入" << endl;
				system("pause");
				system("cls");
				goto f1;
			}
			else
			{
				b1.search(barray, option);
			}
			break;
		case 4:
			b1.showBook(barray);
			break;
		case 5:
			s1.CreatStudent(sarray);
			break;
		case 6:
			t1.CreatTeacher(tarray);
			break;
		case 7:
f2:
			menuBorrowBook();
			int option1;
			cin >> option1;
			if (option1 != 0 && option1 != 1 && option1 != 2)
			{
				cout << "输入有误，请重新输入" << endl;
				system("pause");
				system("cls");
				goto f2;
			}
			else
			{
				if (option1 == 0)
				{
					system("pause");
					system("cls");
				}
				else if (option1 == 1)
				{
					s1.borrowBook(sarray, barray);
				}
				else
				{
					t1.borrowBook(tarray, barray);
				}
			}
			break;
		case 8:
f3:
			menuReturnBook();
			int option2;
			cin >> option2;
			if (option2 != 0 && option2 != 1 && option2 != 2)
			{
				cout << "输入有误，请重新输入" << endl;
				system("pause");
				system("cls");
				goto f3;
			}
			else
			{
				if (option2 == 0)
				{
					system("pause");
					system("cls");
				}
				else if (option2 == 1)
				{
					s1.returnBook(sarray, barray);
				}
				else
				{
					t1.returnBook(tarray, barray);
				}
			}
			break;
		case 0:
			cout << "您已出程序" << endl;
			flag = false;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}

}
int main()
{
	Start();
	system("pause");
	return 0;
}