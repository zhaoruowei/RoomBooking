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
	//ϵͳ������
	void ShowSysUI();
	//����Ա��¼
	void LoginAdmin();
	//���й���Աϵͳ
	void RunAdmin(string name);
	//ѧ����¼
	void LoginStu();
	//����ѧ��ϵͳ
	void RunStu(string id, string name);
	//��ʦ��¼
	void LoginTea();
	//������ʦϵͳ
	void RunTea(string id, string name);
	//�˳���ϵͳ
	void ExitSys();
	~Sysmanager();
};

