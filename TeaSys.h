#pragma once
#include<iostream>
using namespace std;
#include"UserSys.hpp"
#include"Order.h"


class TeaSys : public UserSys
{
public:
	Order tea_od;
	string tea_name;
	string tea_id;
	TeaSys(string id, string name);
	virtual void ShowUserUI();
	virtual void ExitUserSys();
	//查看所有预约
	void GetOrder();
	//审核预约
	void DealOrder();
	//获取待审核预约
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> GetOrder(int);
	//修改审核状态
	void AlterOrder(map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator>& mp, int a, int b);
	//保存审核结果
	void SaveOrder();
	~TeaSys();
};

