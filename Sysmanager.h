#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Admin.h"
#include<algorithm>
#include"AdminSys.h"
#include"StuSys.h"
#include"TeaSys.h"

class Sysmanager
{
public:
	Sysmanager();
	//系统主界面
	void ShowSysUI();
	//管理员登录
	void LoginAdmin();
	//运行管理员系统
	void RunAdmin(string name);
	//学生登录
	void LoginStu();
	//运行学生系统
	void RunStu(string id, string name);
	//老师登录
	void LoginTea();
	//运行老师系统
	void RunTea(string id, string name);
	//退出主系统
	void ExitSys();
	~Sysmanager();
};

