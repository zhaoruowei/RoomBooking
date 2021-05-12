#include "Teacher.h"

Teacher::Teacher()
{
	this->tea_user = NULL;
	this->tea_user = new map<string, pair<string, string>>;
	this->LoadTeaDB();
}

void Teacher::LoadTeaDB()
{
	//读取老师账号数据库
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\机房预约系统\\teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "老师账号文件不存在！" << endl;
		this->tea_isfile = false;
		return;
	}
	if (ifs.eof())
	{
		//cout << "老师帐号文件为空！" << endl;
		this->tea_isfile = false;
	}
	else
	{
		this->tea_isfile = true;
		string buf;
		while (ifs >> buf)
		{
			string id = buf.substr(0, buf.find(',', 0));
			string name = buf.substr(buf.find(',', 0) + 1, buf.rfind(',', buf.size()) - 2);
			string passwd = buf.substr(buf.rfind(',') + 1, buf.size());
			this->tea_user->insert(make_pair(id, make_pair(name, passwd)));
		}
	}
	ifs.close();
}

Teacher::~Teacher()
{
	//cout << "老师析构" << endl;
	if (this->tea_user != NULL)
	{
		delete this->tea_user;
		this->tea_user = NULL;
	}
}
