#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<map>

class Student
{
public:
	string stu_name;
	string stu_id;
	string stu_passwd;
	map<string, pair<string, string>>* stu_user;
	bool stu_isfile;
	Student();
	void LoadStuDB();
	~Student();
};

