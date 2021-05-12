#include "AdminSys.h"

AdminSys::AdminSys(string name)
{
	admin_name = name;
	this->stu_user = NULL;
	this->tea_user = NULL;
	this->com_room = NULL;
	this->stu_user = new map<string, pair<string, string>>;
	this->tea_user = new map<string, pair<string, string>>;
	this->com_room = new map<string, string>;
	this->LoadUser();
	this->LoadComputer();
}

void AdminSys::ShowUserUI()
{
	cout << "��ӭ����Ա" << this->admin_name << "��¼��" << endl;
	cout << "                --------------------            " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     1.����˺�     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     2.�鿴�˺�     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     3.�鿴����     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     4.���ԤԼ     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     0.ע����¼     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "                --------------------            " << endl;
}

void AdminSys::ExitUserSys()
{
	cout << "ע����¼�ɹ����˻�ϵͳ����" << endl;
	system("pause");
	system("cls");
}

void AdminSys::LoadUser()
{
	Student stu;
	Teacher tea;
	if (stu.stu_isfile == true)
	{
		*(this->stu_user) = *(stu.stu_user);
	}
	if (tea.tea_isfile == true)
	{
		*(this->tea_user) = *(tea.tea_user);
	}
}

void AdminSys::LoadComputer()
{
	Computer com;
	if (com.com_isfile == true)
	{
		*(this->com_room) = *(com.com_room);
	}
}

void AdminSys::CreateUser()
{
	cout << "�����봴���û�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		cout << "������ѧ�ţ�" << endl;
		string id;
		cin >> id;
		if (!this->stu_user->empty())
		{
			if (this->stu_user->find(id) != this->stu_user->end())
			{
				cout << "ѧ���Ѵ��ڣ����������룡" << endl;
				break;
			}
		}
		cout << "������������" << endl;
		string name;
		cin >> name;
		cout << "���������룺" << endl;
		string passwd;
		cin >> passwd;
		this->SaveUser("D:\\Programmer\\C++\\����ԤԼϵͳ\\student.txt", id, name, passwd);
		this->stu_user->insert(make_pair(id, make_pair(name, passwd)));
		cout << "����ѧ���˻��ɹ���" << endl;
		break;
	}
	case 2:
	{
		cout << "������ְ���ţ�" << endl;
		string id;
		cin >> id;
		if (!this->tea_user->empty())
		{
			if (this->tea_user->find(id) != this->tea_user->end())
			{
				cout << "ְ�����Ѵ��ڣ����������룡" << endl;
				break;
			}
		}
		cout << "������������" << endl;
		string name;
		cin >> name;
		cout << "���������룺" << endl;
		string passwd;
		cin >> passwd;
		this->SaveUser("D:\\Programmer\\C++\\����ԤԼϵͳ\\teacher.txt", id, name, passwd);
		this->tea_user->insert(make_pair(id, make_pair(name, passwd)));
		cout << "������ʦ�˻��ɹ���" << endl;
		break;
	}
	default:
		cout << "�밴��ʾ���룡" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void AdminSys::SaveUser(string filename, string id, string name, string passwd)
{
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "���˻��ļ�ʧ�ܣ�" << endl;
		return;
	}
	ofs << id << "," << name << "," << passwd << endl;
	ofs.close();
}

void AdminSys::GetUser()
{
	cout << "��ѡ��鿴�û�����" << endl;
	cout << "1.�鿴ѧ��" << endl;
	cout << "2.�鿴��ʦ" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		if (this->stu_user->empty())
		{
			cout << "ѧ���˻���Ϣ�ļ������ڻ��¼Ϊ�գ�" << endl;
		}
		else
		{
			for (map<string, pair<string, string>>::iterator it = this->stu_user->begin(); it != this->stu_user->end(); it++)
			{
				cout << "ѧ����ţ�" << (*it).first << " ѧ��������" << (*it).second.first << " �˻����룺" << (*it).second.second << endl;
			}
		}
		break;
	case 2:
		if (this->tea_user->empty())
		{
			cout << "��ʦ�˻���Ϣ�ļ������ڻ��¼Ϊ�գ�" << endl;
		}
		else
		{
			for (map<string, pair<string, string>>::iterator it = this->tea_user->begin(); it != this->tea_user->end(); it++)
			{
				cout << "ְ����ţ�" << (*it).first << " ��ʦ������" << (*it).second.first << " �˻����룺" << (*it).second.second << endl;
			}
		}
		break;
	default:
		cout << "�밴��ʾ���룡" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void AdminSys::GetComputer()
{
	if (this->com_room->empty())
	{
		cout << "������Ϣ�ļ������ڣ�" << endl;
	}
	else
	{
		for (map<string, string>::iterator it = this->com_room->begin(); it != this->com_room->end(); it++)
		{
			cout << "������ţ�" << (*it).first << " �������������" << (*it).second << endl;
		}
	}
	system("pause");
	system("cls");
}

void AdminSys::SaveCom()
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\computer.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	string id;
	string cap;
	cout << "����������" << endl;
	cin >> id;
	cout << "�����������" << endl;
	cin >> cap;
	ofs << id << "," << cap << endl;

	ofs.close();
}

void AdminSys::ClearOrder()
{
	cout << "�Ƿ��������ԤԼ��Ϣ��[y/n]" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		ofstream ofs("D:\\Programmer\\C++\\����ԤԼϵͳ\\order.txt", ios::trunc);
		ofs.close();
		cout << "�������ԤԼ�ɹ�!" << endl;
	}
	system("pause");
	system("cls");
}

AdminSys::~AdminSys()
{
	//cout << "����ϵͳ����" << endl;
	if (this->stu_user != NULL)
	{
		delete this->stu_user;
		this->stu_user = NULL;
	}
	if (this->tea_user != NULL)
	{
		delete this->tea_user;
		this->tea_user = NULL;
	}
	if (this->com_room != NULL)
	{
		delete this->com_room;
		this->com_room = NULL;
	}
}
