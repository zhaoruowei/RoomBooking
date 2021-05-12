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
	//�鿴����ԤԼ
	void GetOrder();
	//���ԤԼ
	void DealOrder();
	//��ȡ�����ԤԼ
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> GetOrder(int);
	//�޸����״̬
	void AlterOrder(map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator>& mp, int a, int b);
	//������˽��
	void SaveOrder();
	~TeaSys();
};

