#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<vector>
#include<fstream>

class Order
{
public:
	//string order_day;
	//string order_time;
	//string order_room;
	//string order_stat;
	//������ţ����ڣ�ʱ�䣬״̬��������id�������������������id�����������
	//vector<string>* order_com;
	//vector<string>* order_stu;
	//vector<string>* order_tea;
	multimap<vector<string>, pair<vector<string>, vector<string>>>* order_info;
	//������ţ����ڣ�ʱ�䣬״̬��������id�������������������id�����������
	//multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, string>>>>>>>* order_info; //������ţ����ڣ�ʱ�䣬״̬��������id�������������������id�����������
	bool order_isfile;
	Order();
	void LoadOrdDB();
	//���
	void operator=(Order& od);
	~Order();
};

//�ַ�����ȡʵ��
vector<string> MySplit(const string& str);
//�ַ���ͳ��ʵ��
int MyCount(const string& str);



