#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<map>

class Teacher
{
public:
	string tea_name;
	string tea_id;
	string tea_passwd;
	map<string, pair<string, string>>* tea_user;
	bool tea_isfile;
	Teacher();
	void LoadTeaDB();
	~Teacher();
};

