#include "Teacher.h"

Teacher::Teacher()
{
	this->tea_user = NULL;
	this->tea_user = new map<string, pair<string, string>>;
	this->LoadTeaDB();
}

void Teacher::LoadTeaDB()
{
	//��ȡ��ʦ�˺����ݿ�
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "��ʦ�˺��ļ������ڣ�" << endl;
		this->tea_isfile = false;
		return;
	}
	if (ifs.eof())
	{
		//cout << "��ʦ�ʺ��ļ�Ϊ�գ�" << endl;
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
	//cout << "��ʦ����" << endl;
	if (this->tea_user != NULL)
	{
		delete this->tea_user;
		this->tea_user = NULL;
	}
}
