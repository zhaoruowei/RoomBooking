#include "Admin.h"

Admin::Admin()
{
	//读取管理员账号数据库
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\机房预约系统\\admin.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "管理员账户数据库不存在！" << endl;
		return;
	}
	if (ifs.eof())
	{
		cout << "管理员信息不存在！" << endl;
	}
	else
	{
		string buf;
		while (ifs >> buf)
		{
			string name = buf.substr(0, buf.find(','));
			string passwd = buf.substr(buf.find(',') + 1, buf.size());
			//cout << buf << endl;
			//cout << name << endl;
			//cout << passwd << endl;
			this->admin_user.insert(make_pair(name, passwd));
		}
	}
	ifs.close();
}

Admin::~Admin()
{
}
