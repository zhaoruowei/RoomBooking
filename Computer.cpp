#include "Computer.h"

Computer::Computer()
{
	this->com_room = NULL;
	this->com_room = new map<string, string>;
	this->LoadComDB();
}

void Computer::LoadComDB()
{
	//���ػ�����Ϣ�ļ�
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\computer.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "������Ϣ�ļ������ڣ�" << endl;
		this->com_isfile = false;
		return;
	}
	if (ifs.eof())
	{
		cout << "������Ϣ�ļ���¼Ϊ�գ�" << endl;
		this->com_isfile = false;
	}
	else
	{
		this->com_isfile = true;
		string buf;
		while (ifs >> buf)
		{
			string id = buf.substr(0, buf.find(',', 0));
			string cap = buf.substr(buf.find(',', 0) + 1, buf.size());
			this->com_room->insert(make_pair(id, cap));
		}
	}
	ifs.close();
}

void Computer::operator=(Computer& com)
{
	this->com_isfile = com.com_isfile;
	this->com_room = new map<string, string>;
	*(this->com_room) = *(com.com_room);
}

Computer::~Computer()
{
	if (this->com_room != NULL)
	{
		delete this->com_room;
		this->com_room = NULL;
	}
}
