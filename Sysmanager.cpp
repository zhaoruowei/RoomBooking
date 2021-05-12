#include "Sysmanager.h"

Sysmanager::Sysmanager()
{
	cout << "欢迎使用机房管理系统！" << endl;
	system("pause");
	system("cls");
}

void Sysmanager::ShowSysUI()
{
	cout << "=============欢迎使用哈拉大学机房管理系统=============" << endl;
	cout << endl;
	cout << "请输入您的身份：" << endl;
	cout << "                --------------------            " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     1.学生代表     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     2.老    师     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     3.管 理 员     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     0.退出系统     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "                --------------------            " << endl;
}

void Sysmanager::LoginAdmin()
{
	Admin ad;
	int count = 0;
	while (true)
	{
		cout << "请输入用户名：" << endl;
		string name;
		cin >> name;
		map<string, string>::iterator it = ad.admin_user.find(name);
		if ( it == ad.admin_user.end())
		{
			cout << "管理员用户名不存在，请重新输入！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "请输入密码：" << endl;
			string passwd;
			cin >> passwd;
			if ((*it).second != passwd)
			{
				cout << "管理员密码不正确，请重新输入！" << endl;
				count++;
				if (count < 3)
				{
					cout << "剩余尝试次数：" << 3 - count << endl;
				}
				else
				{
					cout << "密码错误，请联系管理员！" << endl;
					exit(-1);
				}
			}
			else
			{
				cout << "登录成功！" << endl;
				system("pause");
				system("cls");
				this->RunAdmin(name);
				return;
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunAdmin(string name)
{
	AdminSys ads(name);
	while (true)
	{
		ads.ShowUserUI();
		int select = 0;
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			ads.CreateUser();
			break;
		case 2:
			ads.GetUser();
			break;
		case 3:
			ads.GetComputer();
			break;
		case 4:
			ads.ClearOrder();
			break;
		case 0:
			ads.ExitUserSys();
			return;
			break;
		case 10000:
			ads.SaveCom();
			break;
		default:
			cout << "请按提示输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::LoginStu()
{
	Student stu;
	int count = 0;
	while (true)
	{
		cout << "请输入学号：" << endl;
		string id;
		cin >> id;
		map<string, pair<string, string>>::iterator it = stu.stu_user->find(id);
		if (it == stu.stu_user->end())
		{
			cout << "学号不存在，请重新输入！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "请输入姓名：" << endl;
			string name;
			cin >> name;
			cout << "请输入密码：" << endl;
			string passwd;
			cin >> passwd;
			if (it->second.first == name && it->second.second == passwd)
			{
				cout << "登陆成功！" << endl;
				system("pause");
				system("cls");
				this->RunStu(id, name);
				return;
			}
			else
			{
				cout << "账号信息验证失败，请重新输入！" << endl;
				count++;
				if (count < 3)
				{
					cout << "剩余尝试次数：" << 3 - count << endl;
				}
				else
				{
					cout << "账号信息验证错误，请联系管理员！" << endl;
					exit(-1);
				}
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunStu(string id, string name)
{
	StuSys stu(id, name);
	while (true)
	{
		stu.ShowUserUI();
		int select = 0;
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			stu.ComputerOrder();  //申请预约
			break;
		case 2:
			stu.GetOrder(id);     //查看我的预约
			break;
		case 3:
			stu.GetOrder();       //查看所有预约
			break;
		case 4:
			stu.CancelOrder();    //取消预约
			break;
		case 0:
			stu.ExitUserSys();
			return;
			break;
		default:
			cout << "请按提示输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::LoginTea()
{
	Teacher tea;
	int count = 0;
	while (true)
	{
		cout << "请输入职工号：" << endl;
		string id;
		cin >> id;
		map<string, pair<string, string>>::iterator it = tea.tea_user->find(id);
		if (it == tea.tea_user->end())
		{
			cout << "职工号不存在，请重新输入！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "请输入姓名：" << endl;
			string name;
			cin >> name;
			cout << "请输入密码：" << endl;
			string passwd;
			cin >> passwd;
			if (it->second.first == name && it->second.second == passwd)
			{
				cout << "登陆成功！" << endl;
				system("pause");
				system("cls");
				this->RunTea(id, name);
				return;
			}
			else
			{
				cout << "账号信息验证失败，请重新输入！" << endl;
				count++;
				if (count < 3)
				{
					cout << "剩余尝试次数：" << 3 - count << endl;
				}
				else
				{
					cout << "账号信息验证错误，请联系管理员！" << endl;
					exit(-1);
				}
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunTea(string id, string name)
{
	TeaSys tea(id, name);
	while (true)
	{
		tea.ShowUserUI();
		int select = 0;
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			tea.GetOrder();  //查看所有预约
			break;
		case 2:
			tea.DealOrder(); //审核预约
			break;
		case 0:
			tea.ExitUserSys();
			return;
			break;
		default:
			cout << "请按提示输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::ExitSys()
{
	system("cls");
	cout << "系统已退出，欢迎下次使用！" << endl;
	system("pause");
	exit(1);
}

Sysmanager::~Sysmanager()
{
}
