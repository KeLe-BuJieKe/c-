#include"ͼ�����.h"

void menuSearchMethod()
{
	cout << "1.���������ֲ�ѯ" << endl;
	cout << "2.��������ѯ" << endl;
	cout << "0.�˳�" << endl;

}

void menuBorrowBook()
{
	cout << "1.ѧ��������" << endl;
	cout << "2.��ʦ������" << endl;
	cout << "0.�˳�" << endl;
}

void menuReturnBook()
{
	cout << "1.ѧ������" << endl;
	cout << "2.��ʦ����" << endl;
	cout << "0.�˳�" << endl;
}

void mainmenu()
{
	cout << "1.¼��ͼ��" << endl;
	cout << "2.ɾ��ͼ��" << endl;
	cout << "3.����ͼ��" << endl;
	cout << "4.��ʾȫ���鼮"<<endl;
	cout << "5.���ѧ��" << endl;
	cout << "6.�����ʦ" << endl;
	cout << "7.����ͼ��" << endl;
	cout << "8.����" << endl;
	cout << "0.�˳�" << endl;

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
				cout << "������������������" << endl;
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
				cout << "������������������" << endl;
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
				cout << "������������������" << endl;
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
			cout << "���ѳ�����" << endl;
			flag = false;
			break;
		default:
			cout << "������������������" << endl;
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