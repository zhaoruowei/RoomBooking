#include "Admin.h"

Admin::Admin()
{
	//��ȡ����Ա�˺����ݿ�
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\admin.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "����Ա�˻����ݿⲻ���ڣ�" << endl;
		return;
	}
	if (ifs.eof())
	{
		cout << "����Ա��Ϣ�����ڣ�" << endl;
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
