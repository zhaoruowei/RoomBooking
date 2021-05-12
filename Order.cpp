#include "Order.h"

Order::Order()
{
	//cout << "Order���캯��" << endl;
	this->order_info = NULL;
	this->order_info = new multimap<vector<string>, pair<vector<string>, vector<string>>>;
	this->LoadOrdDB();
}

void Order::LoadOrdDB()
{
	//��ȡԤԼ��Ϣ
	ifstream ifs;
	ifs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\order.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "ԤԼ��Ϣ�ļ���ʧ�ܣ�" << endl;
		this->order_isfile = false;
		return;
	}
	if (ifs.eof())
	{
		cout << "ԤԼ��Ϣ��¼Ϊ�գ�" << endl;
		this->order_isfile = false;
	}
	else
	{
		this->order_isfile = true;
		string buf;
		vector<string> com;
		vector<string> stu;
		vector<string> tea;
		while (ifs >> buf)
		{
			vector<string> temp = MySplit(buf);
			int num = MyCount(buf);
			if (num == 5)
			{
				for (int i = 0; i < 8; i++)
				{
					if (i < 4)
					{
						com.push_back(temp[i]);
					}
					else if (i < 6)
					{
						stu.push_back(temp[i]);
					}
					else
					{
						//tea.push_back(temp[i]);
						tea.push_back("");
					}
				}
				this->order_info->insert(make_pair(com, make_pair(stu, tea)));
			}
			else
			{
				for (int i = 0; i < 8; i++)
				{
					if (i < 4)
					{
						com.push_back(temp[i]);
					}
					else if (i < 6)
					{
						stu.push_back(temp[i]);
					}
					else
					{
						tea.push_back(temp[i]);
					}
				}
				this->order_info->insert(make_pair(com, make_pair(stu, tea)));
			}
			com.clear();
			stu.clear();
			tea.clear();
		}
	}
	ifs.close();
}

void Order::operator=(Order& od)
{
	this->order_isfile = od.order_isfile;
	this->order_info = new multimap<vector<string>, pair<vector<string>, vector<string>>>;
	*(this->order_info) = *(od.order_info);
}

Order::~Order()
{
	//cout << "Order��������" << endl;
	if (this->order_info != NULL)
	{
		delete this->order_info;
		this->order_info = NULL;
	}
}

vector<string> MySplit(const string& str)
{
	//cout << "��ȡ��������" << endl;
	string sub_str;
	vector<string> v_substr;
	string temp = str;
	while (temp.find(',', 0) != -1)
	{
		sub_str = temp.substr(0, temp.find(',', 0));
		temp = temp.substr(temp.find(',', 0) + 1, temp.size());
		v_substr.push_back(sub_str);
	}
	v_substr.push_back(temp);
	return v_substr;
}

int MyCount(const string& str)
{
	//cout << "ͳ�ƺ�������" << endl;
	string temp = str;
	int num = 0;
	while (temp.find(',', 0) != -1)
	{
		temp = temp.substr(temp.find(',', 0) + 1, temp.size());
		num++;
	}
	return num;
}


