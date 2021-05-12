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
	//��д���溯��
	virtual void ShowUserUI();
	//��д�˳�����
	virtual void ExitUserSys();
	//��ȡѧ������ʦ���ݿ�����
	void LoadUser();
	//��ȡ������Ϣ
	void LoadComputer();
	//�����˺ź���
	void CreateUser();
	//�����˺ź���
	void SaveUser(string filename, string id, string name, string passwd);
	//�鿴�˻�����
	void GetUser();
	//�鿴��������
	void GetComputer();
	//�޸Ļ�������
	void SaveCom();
	//���ԤԼ����
	void ClearOrder();
	~AdminSys();
};

