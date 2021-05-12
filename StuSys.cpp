#include "StuSys.h"

StuSys::StuSys(string id, string name)
{
	this->stu_id = id;
	this->stu_name = name;
	Order od;
	this->stu_od = od;
	Computer com;
	this->stu_com = com;
}

void StuSys::ShowUserUI()
{
	cout << "欢迎学生代表" << this->stu_name << "登录！" << endl;
	cout << "                --------------------------            " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       1.申请预约         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       2.查看我的预约     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       3.查看所有预约     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       4.取消预约         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       0.注销登录         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "                --------------------------            " << endl;
}

void StuSys::ExitUserSys()
{
	cout << "注销登录成功！退回系统界面" << endl;
	system("pause");
	system("cls");
}

void StuSys::ComputerOrder()
{
	//获取用户输入
	cout << "机房预约时间为周一至周五！" << endl;
	cout << "请输入预约的时间段：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	string day;
	string time;
	string room;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		day = "周一";
		break;
	case 2:
		day = "周二";
		break;
	case 3:
		day = "周三";
		break;
	case 4:
		day = "周四";
		break;
	case 5:
		day = "周五";
		break;
	default:
		cout << "请按提示输入！" << endl;
		break;
	}
	cout << "请输入预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		time = "上午";
		break;
	case 2:
		time = "下午";
		break;
	default:
		cout << "请按提示输入！" << endl;
		break;
	}
	cout << "请选择机房：" << endl;
	cout << "1.1号机房容量：" << "20" << endl;
	cout << "2.2号机房容量：" << "50" << endl;
	cout << "3.3号机房容量：" << "100" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		room = "1";
		break;
	case 2:
		room = "2";
		break;
	case 3:
		room = "3";
		break;
	default:
		break;
	}
	
	string stat = "审核中";
	vector<string> v1_test;
	v1_test.push_back(room);
	v1_test.push_back(day);
	v1_test.push_back(time);
	v1_test.push_back(stat);

	//检测,录入
	if (this->stu_od.order_isfile == true)
	{
		//检测机房剩余量
		stat = "预约成功";

		vector<string> v_test;
		v_test.push_back(room);
		v_test.push_back(day);
		v_test.push_back(time);
		v_test.push_back(stat);

		int count = this->stu_od.order_info->count(v_test);
		int num = atoi((*(this->stu_com.com_room))[room].c_str());

		if (count >= num)
		{
			cout << "该时段此机房已约满，请重新预约！" << endl;
			system("pause");
			system("cls");
			return;
		}
		//检测重复预约
		for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
		{
			if ((*it).first == v_test || (*it).first == v1_test)
			{
				if ((*it).second.first.front() == this->stu_id)
				{
					cout << "您已预约此时间段该机房机位，请勿重复预约！" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
		}
	}
	vector<string> v2_test;
	v2_test.push_back(this->stu_id);
	v2_test.push_back(this->stu_name);
	vector<string> v3_test;
	v3_test.push_back("0");
	v3_test.push_back("0");
	this->stu_od.order_info->insert(make_pair(v1_test, make_pair(v2_test, v3_test)));
	cout << "预约成功，审核中！" << endl;
	this->SaveOrder(room, day, time);

}

void StuSys::SaveOrder()
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\机房预约系统\\order.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "预约信息文件打开失败！" << endl;
		return;
	}
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
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

void StuSys::SaveOrder(string room, string day, string time)
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\机房预约系统\\order.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "预约信息文件打开失败！" << endl;
		return;
	}
	//ofs << "机房：" << room << " 日期：" << day << " 时间：" << time << " 状态：审核中 申请人学号：" << this->stu_id << " 姓名：" << this->stu_name << endl;
	ofs << room << "," << day << "," << time << "," << "审核中" << "," << this->stu_id << "," << this->stu_name << endl;
	ofs.close();
	cout << "预约申请已提交" << endl;
	system("pause");
	system("cls");
}

void StuSys::GetOrder()
{
	int sum = 1;
	if (this->stu_od.order_info->empty())
	{
		cout << "暂无预约信息！" << endl;
	}
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
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

void StuSys::GetOrder(string id)
{
	int sum = 1;
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		//判断申请人
		if (id == it->second.first.front())
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
					cout << sum << ": "<< "机房：" << *(itcom);
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
	}
	if (sum == 1)
	{
		cout << "暂无预约信息！" << endl;
	}
	system("pause");
	system("cls");
}

map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> StuSys::GetOrder(string id, int)
{
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp;
	int sum = 1;
	//遍历预约信息容器
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		//判断申请人
		if (id == it->second.first.front() && it->first.back() != "预约失败" && it->first.back() != "预约已取消")
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
			mp.insert(make_pair(sum, it));
			sum++;
		}
	}
	if (sum == 1)
	{
		cout << "暂无预约信息！" << endl;
	}
	return mp;
}

void StuSys::CancelOrder()
{
	cout << "审核中或预约成功的预约可以取消，请输入需要取消的记录，0代表返回：" << endl;
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp = this->GetOrder(this->stu_id, 10);
	cout << "请输入您的选择" << endl;
	int select = 0;
	cin >> select;
	if (select == 0)
	{
		system("cls");
		return;
	}
	else if (mp.find(select) != mp.end())
	{
		vector<string> temp1;
		vector<string> temp2;
		vector<string> temp3;
		for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
		{
			if (it == mp.find(select)->second)
			{
				for (vector<string>::const_iterator it1 = (*it).first.begin(); it1 != (*it).first.end(); it1++)
				{
					temp1.push_back((*it1));
				}
				temp2 = (*it).second.first;
				temp3 = (*it).second.second;
			}
		}
		temp1.pop_back();
		temp1.push_back("预约已取消");
		this->stu_od.order_info->erase(mp.find(select)->second);
		this->stu_od.order_info->insert(make_pair(temp1, make_pair(temp2, temp3)));
		this->SaveOrder();
		cout << "预约取消成功" << endl;
	}
	else
	{
		cout << "请按提示输入！" << endl;
	}
	system("pause");
	system("cls");
}

StuSys::~StuSys()
{
}
