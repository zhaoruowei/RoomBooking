#pragma once
#include<iostream>
using namespace std;
#include"UserSys.hpp"
#include<string>
#include"Student.h"
#include"Teacher.h"
#include<map>
#include"Computer.h"

class AdminSys : public UserSys
{
public:
	string admin_name;
	map<string, pair<string, string>>* tea_user;
	map<string, pair<string, string>>* stu_user;
	map<string, string>* com_room;
	AdminSys(string name);
	//重写界面函数
	virtual void ShowUserUI();
	//重写退出函数
	virtual void ExitUserSys();
	//读取学生，老师数据库内容
	void LoadUser();
	//读取机房信息
	void LoadComputer();
	//创建账号函数
	void CreateUser();
	//储存账号函数
	void SaveUser(string filename, string id, string name, string passwd);
	//查看账户函数
	void GetUser();
	//查看机房函数
	void GetComputer();
	//修改机房函数
	void SaveCom();
	//清空预约函数
	void ClearOrder();
	~AdminSys();
};

