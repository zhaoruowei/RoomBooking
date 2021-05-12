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
	cout << "欢迎管理员" << this->admin_name << "登录！" << endl;
	cout << "                --------------------            " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     1.添加账号     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     2.查看账号     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     3.查看机房     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     4.清空预约     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     0.注销登录     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "                --------------------            " << endl;
}

void AdminSys::ExitUserSys()
{
	cout << "注销登录成功！退回系统界面" << endl;
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
	cout << "请输入创建用户类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		cout << "请输入学号：" << endl;
		string id;
		cin >> id;
		if (!this->stu_user->empty())
		{
			if (this->stu_user->find(id) != this->stu_user->end())
			{
				cout << "学号已存在，请重新输入！" << endl;
				break;
			}
		}
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		cout << "请输入密码：" << endl;
		string passwd;
		cin >> passwd;
		this->SaveUser("D:\\Programmer\\C++\\机房预约系统\\student.txt", id, name, passwd);
		this->stu_user->insert(make_pair(id, make_pair(name, passwd)));
		cout << "创建学生账户成功！" << endl;
		break;
	}
	case 2:
	{
		cout << "请输入职工号：" << endl;
		string id;
		cin >> id;
		if (!this->tea_user->empty())
		{
			if (this->tea_user->find(id) != this->tea_user->end())
			{
				cout << "职工号已存在，请重新输入！" << endl;
				break;
			}
		}
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		cout << "请输入密码：" << endl;
		string passwd;
		cin >> passwd;
		this->SaveUser("D:\\Programmer\\C++\\机房预约系统\\teacher.txt", id, name, passwd);
		this->tea_user->insert(make_pair(id, make_pair(name, passwd)));
		cout << "创建老师账户成功！" << endl;
		break;
	}
	default:
		cout << "请按提示输入！" << endl;
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
		cout << "打开账户文件失败！" << endl;
		return;
	}
	ofs << id << "," << name << "," << passwd << endl;
	ofs.close();
}

void AdminSys::GetUser()
{
	cout << "请选择查看用户类型" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		if (this->stu_user->empty())
		{
			cout << "学生账户信息文件不存在或记录为空！" << endl;
		}
		else
		{
			for (map<string, pair<string, string>>::iterator it = this->stu_user->begin(); it != this->stu_user->end(); it++)
			{
				cout << "学生编号：" << (*it).first << " 学生姓名：" << (*it).second.first << " 账户密码：" << (*it).second.second << endl;
			}
		}
		break;
	case 2:
		if (this->tea_user->empty())
		{
			cout << "老师账户信息文件不存在或记录为空！" << endl;
		}
		else
		{
			for (map<string, pair<string, string>>::iterator it = this->tea_user->begin(); it != this->tea_user->end(); it++)
			{
				cout << "职工编号：" << (*it).first << " 老师姓名：" << (*it).second.first << " 账户密码：" << (*it).second.second << endl;
			}
		}
		break;
	default:
		cout << "请按提示输入！" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void AdminSys::GetComputer()
{
	if (this->com_room->empty())
	{
		cout << "机房信息文件不存在！" << endl;
	}
	else
	{
		for (map<string, string>::iterator it = this->com_room->begin(); it != this->com_room->end(); it++)
		{
			cout << "机房编号：" << (*it).first << " 机房最大容量：" << (*it).second << endl;
		}
	}
	system("pause");
	system("cls");
}

void AdminSys::SaveCom()
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\机房预约系统\\computer.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	string id;
	string cap;
	cout << "输入机房编号" << endl;
	cin >> id;
	cout << "输入机房容量" << endl;
	cin >> cap;
	ofs << id << "," << cap << endl;

	ofs.close();
}

void AdminSys::ClearOrder()
{
	cout << "是否清空所有预约信息？[y/n]" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		ofstream ofs("D:\\Programmer\\C++\\机房预约系统\\order.txt", ios::trunc);
		ofs.close();
		cout << "清空所有预约成功!" << endl;
	}
	system("pause");
	system("cls");
}

AdminSys::~AdminSys()
{
	//cout << "管理系统析构" << endl;
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
