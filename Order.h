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
	//机房编号，日期，时间，状态，申请人id，申请人姓名，审核人id，审核人姓名
	//vector<string>* order_com;
	//vector<string>* order_stu;
	//vector<string>* order_tea;
	multimap<vector<string>, pair<vector<string>, vector<string>>>* order_info;
	//机房编号，日期，时间，状态，申请人id，申请人姓名，审核人id，审核人姓名
	//multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, multimap<string, string>>>>>>>* order_info; //机房编号，日期，时间，状态，申请人id，申请人姓名，审核人id，审核人姓名
	bool order_isfile;
	Order();
	void LoadOrdDB();
	//深拷贝
	void operator=(Order& od);
	~Order();
};

//字符串截取实现
vector<string> MySplit(const string& str);
//字符串统计实现
int MyCount(const string& str);



