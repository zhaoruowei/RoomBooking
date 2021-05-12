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
	//����ԤԼ
	void ComputerOrder();
	//�洢����ԤԼ��Ϣ���������ذ汾
	void SaveOrder();
	void SaveOrder(string room, string day, string time);
	//�鿴ԤԼ���������ذ汾,��ӿ���Ϣ����
	void GetOrder();
	void GetOrder(string id);
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> GetOrder(string id, int);
	//ȡ��ԤԼ
	void CancelOrder();
	~StuSys();
};

