#include "TeaSys.h"

TeaSys::TeaSys(string id, string name)
{
	this->tea_id = id;
	this->tea_name = name;
	Order od;
	this->tea_od = od;
}

void TeaSys::ShowUserUI()
{
	cout << "欢迎老师" << this->tea_name << "登录！" << endl;
	cout << "                --------------------------            " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       1.查看所有预约     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       2.审核预约         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       0.注销登录         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "                --------------------------            " << endl;
}

void TeaSys::ExitUserSys()
{
	cout << "注销登录成功！退回系统界面" << endl;
	system("pause");
	system("cls");
}

void TeaSys::GetOrder()
{
	int sum = 1;
	if (this->tea_od.order_info->empty())
	{
		cout << "暂无预约信息！" << endl;
	}
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
	{
		cout << "------------------------------------------------" << endl;
		int n = 0;
		bool tea = true;
		//输出机房信息
		for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
		{
			switch (n)
			{
			case 0:
				cout << sum << ": " << "机房：" << *(itcom);
				break;
			case 1:
				cout << " 日期：" << *(itcom);
				break;
			case 2:
				cout << " 时间：" << *(itcom);
				break;
			case 3:
			{
				cout << " 申请状态：" << *(itcom);
				//判断是否输出审核老师信息
				if (*(itcom) == "审核中" || *(itcom) == "预约已取消")
				{
					tea = false;
				}
				break;
			}
			}
			n++;
		}
		//输出申请人信息
		for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
		{
			switch (n)
			{
			case 4:
				cout << " 申请人编号：" << *(itstu);
				break;
			case 5:
				cout << " 申请人姓名：" << *(itstu);
				break;
			}
			n++;
		}
		if (tea == true)
		{
			//输出审核老师信息
			for (vector<string>::const_iterator ittea = it->second.second.begin(); ittea != it->second.second.end(); ittea++)
			{
				switch (n)
				{
				case 6:
					cout << " 审核人职工号：" << *(ittea);
					break;
				case 7:
					cout << " 审核人姓名：" << *(ittea);
					break;
				}
				n++;
			}
		}
		cout << endl;
		sum++;
	}
	system("pause");
	system("cls");
}

void TeaSys::DealOrder()
{
	cout << "审核中或预约成功的预约可以取消，请输入需要取消的记录，0代表返回：" << endl;
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp = this->GetOrder(10);
	cout << "请输入您的选择" << endl;
	int select1 = 0;
	cin >> select1;
	if (select1 == 0)
	{
		system("cls");
		return;
	}
	else if (mp.find(select1) != mp.end())
	{
		cout << "请输入审核结果：" << endl;
		cout << "1.通过" << endl;
		cout << "2.不通过" << endl;
		int select2;
		cin >> select2;
		switch (select2)
		{
		case 1:case 2:
			AlterOrder(mp, select1, select2);
			cout << "预约审核成功！" << endl;
			break;
		default:
			cout << "请按提示输入！" << endl;
			break;
		}
	}
	else
	{
		cout << "请按提示输入！" << endl;
	}
	system("pause");
	system("cls");
}

map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> TeaSys::GetOrder(int)
{
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp;
	int sum = 1;
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
	{
		//判断审核状态
		if (it->first.back() == "审核中")
		{
			cout << "------------------------------------------------" << endl;
			int n = 0;
			//输出机房信息
			for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
			{
				switch (n)
				{
				case 0:
					cout << sum << ": " << "机房：" << *(itcom);
					break;
				case 1:
					cout << " 日期：" << *(itcom);
					break;
				case 2:
					cout << " 时间：" << *(itcom);
					break;
				case 3:
				{
					cout << " 申请状态：" << *(itcom);
					break;
				}
				}
				n++;
			}
			//输出申请人信息
			for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
			{
				switch (n)
				{
				case 4:
					cout << " 申请人编号：" << *(itstu);
					break;
				case 5:
					cout << " 申请人姓名：" << *(itstu);
					break;
				}
				n++;
			}
			cout << endl;
			mp.insert(make_pair(sum, it));
			sum++;
		}
	}
	if (sum == 1)
	{
		cout << "暂无需审核预约！" << endl;
	}
	return mp;
}

void TeaSys::AlterOrder(map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator>& mp, int a, int b)
{
	vector<string> temp1;
	vector<string> temp2;
	vector<string> temp3;
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
	{
		if (it == mp.find(a)->second)
		{
			for (vector<string>::const_iterator it1 = (*it).first.begin(); it1 != (*it).first.end(); it1++)
			{
				temp1.push_back((*it1));
			}
			temp2 = (*it).second.first;
		}
	}
	temp1.pop_back();
	if (b == 1)
	{
		temp1.push_back("预约成功");
	}
	else
	{
		temp1.push_back("预约失败");
	}
	temp3.push_back(this->tea_id);
	temp3.push_back(this->tea_name);
	this->tea_od.order_info->erase(mp.find(a)->second);
	this->tea_od.order_info->insert(make_pair(temp1, make_pair(temp2, temp3)));
	this->SaveOrder();
}

void TeaSys::SaveOrder()
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\机房预约系统\\order.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "预约信息文件打开失败！" << endl;
		return;
	}
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
	{
		int n = 0;
		bool tea = true;
		//输出机房信息
		for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
		{
			switch (n)
			{
			case 0:
				ofs << *(itcom) << ",";
				break;
			case 1:
				ofs << *(itcom) << ",";
				break;
			case 2:
				ofs << *(itcom) << ",";
				break;
			case 3:
			{
				ofs << *(itcom) << ",";
				//判断是否输出审核老师信息
				if (*(itcom) == "审核中" || *(itcom) == "预约已取消")
				{
					tea = false;
				}
				break;
			}
			}
			n++;
		}
		//输出申请人信息
		for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
		{
			switch (n)
			{
			case 4:
				ofs << *(itstu) << ",";
				break;
			case 5:
				ofs << *(itstu);
				break;
			}
			n++;
		}
		if (tea == true)
		{
			//输出审核老师信息
			for (vector<string>::const_iterator ittea = it->second.second.begin(); ittea != it->second.second.end(); ittea++)
			{
				switch (n)
				{
				case 6:
					ofs << "," << *(ittea) << ",";
					break;
				case 7:
					ofs << *(ittea);
					break;
				}
				n++;
			}
		}
		ofs << endl;
	}
	ofs.close();
}

TeaSys::~TeaSys()
{
}
