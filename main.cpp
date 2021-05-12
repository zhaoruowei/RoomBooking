#include<iostream>
using namespace std;
#include"Sysmanager.h"
#include<string>

int main()
{
	Sysmanager sys;
	
	while (true)
	{
		sys.ShowSysUI();
		int select = 0;
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:             //学生登录
			sys.LoginStu();
			break;
		case 2:             //老师登录
			sys.LoginTea();
			break;
		case 3:             //管理员登录
			sys.LoginAdmin();
			break;
		case 0:
			sys.ExitSys();
			break;
		default:
			cout << "请按提示输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}