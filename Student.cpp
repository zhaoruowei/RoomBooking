#include "Student.h"

Student::Student()
{
	this->stu_user = NULL;
	this->stu_user = new map<string, pair<string, string>>;
	this->LoadStuDB();
}

void Student::LoadStuDB()
{
	//读取学生账号数据库
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\机房预约系统\\student.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "学生账号文件不存在！" << endl;
		this->stu_isfile = false;
		return;
	}
	if (ifs.eof())
	{
		//cout << "学生帐号文件为空！" << endl;
		this->stu_isfile = false;
	}
	else
	{
		this->stu_isfile = true;
		string buf;
		while (ifs >> buf)
		{
			string id = buf.substr(0, buf.find(',', 0));
			string name = buf.substr(buf.find(',', 0) + 1, buf.rfind(',', buf.size())-2);
			string passwd = buf.substr(buf.rfind(',', buf.size()) + 1, buf.size());
			this->stu_user->insert(make_pair(id, make_pair(name, passwd)));
		}
	}
	ifs.close();
}

Student::~Student()
{
	//cout << "学生析构" << endl;
	if (this->stu_user != NULL)
	{
		delete this->stu_user;
		this->stu_user = NULL;
	}
}
