#pragma once
#include<iostream>
using namespace std;
#include"UserSys.hpp"
#include"Student.h"
#include"Order.h"
#include"Computer.h"

class StuSys : public UserSys
{
public:
	Order stu_od;
	Computer stu_com;
	string stu_name;
	string stu_id;
	StuSys(string id, string name);
	virtual void ShowUserUI();
	virtual void ExitUserSys();
	//机房预约
	void ComputerOrder();
	//存储机房预约信息，两个重载版本
	void SaveOrder();
	void SaveOrder(string room, string day, string time);
	//查看预约，两个重载版本,添加空信息处理
	void GetOrder();
	void GetOrder(string id);
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> GetOrder(string id, int);
	//取消预约
	void CancelOrder();
	~StuSys();
};

