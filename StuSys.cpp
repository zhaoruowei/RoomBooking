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
	cout << "��ӭѧ������" << this->stu_name << "��¼��" << endl;
	cout << "                --------------------------            " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       1.����ԤԼ         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       2.�鿴�ҵ�ԤԼ     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       3.�鿴����ԤԼ     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       4.ȡ��ԤԼ         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       0.ע����¼         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "                --------------------------            " << endl;
}

void StuSys::ExitUserSys()
{
	cout << "ע����¼�ɹ����˻�ϵͳ����" << endl;
	system("pause");
	system("cls");
}

void StuSys::ComputerOrder()
{
	//��ȡ�û�����
	cout << "����ԤԼʱ��Ϊ��һ�����壡" << endl;
	cout << "������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	string day;
	string time;
	string room;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		day = "��һ";
		break;
	case 2:
		day = "�ܶ�";
		break;
	case 3:
		day = "����";
		break;
	case 4:
		day = "����";
		break;
	case 5:
		day = "����";
		break;
	default:
		cout << "�밴��ʾ���룡" << endl;
		break;
	}
	cout << "������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		time = "����";
		break;
	case 2:
		time = "����";
		break;
	default:
		cout << "�밴��ʾ���룡" << endl;
		break;
	}
	cout << "��ѡ�������" << endl;
	cout << "1.1�Ż���������" << "20" << endl;
	cout << "2.2�Ż���������" << "50" << endl;
	cout << "3.3�Ż���������" << "100" << endl;
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
	
	string stat = "�����";
	vector<string> v1_test;
	v1_test.push_back(room);
	v1_test.push_back(day);
	v1_test.push_back(time);
	v1_test.push_back(stat);

	//���,¼��
	if (this->stu_od.order_isfile == true)
	{
		//������ʣ����
		stat = "ԤԼ�ɹ�";

		vector<string> v_test;
		v_test.push_back(room);
		v_test.push_back(day);
		v_test.push_back(time);
		v_test.push_back(stat);

		int count = this->stu_od.order_info->count(v_test);
		int num = atoi((*(this->stu_com.com_room))[room].c_str());

		if (count >= num)
		{
			cout << "��ʱ�δ˻�����Լ����������ԤԼ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		//����ظ�ԤԼ
		for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
		{
			if ((*it).first == v_test || (*it).first == v1_test)
			{
				if ((*it).second.first.front() == this->stu_id)
				{
					cout << "����ԤԼ��ʱ��θû�����λ�������ظ�ԤԼ��" << endl;
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
	cout << "ԤԼ�ɹ�������У�" << endl;
	this->SaveOrder(room, day, time);

}

void StuSys::SaveOrder()
{
	ofstream ofs;
	ofs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\order.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "ԤԼ��Ϣ�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		int n = 0;
		bool tea = true;
		//���������Ϣ
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
				//�ж��Ƿ���������ʦ��Ϣ
				if (*(itcom) == "�����" || *(itcom) == "ԤԼ��ȡ��")
				{
					tea = false;
				}
				break;
			}
			}
			n++;
		}
		//�����������Ϣ
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
			//��������ʦ��Ϣ
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
	ofs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\order.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "ԤԼ��Ϣ�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//ofs << "������" << room << " ���ڣ�" << day << " ʱ�䣺" << time << " ״̬������� ������ѧ�ţ�" << this->stu_id << " ������" << this->stu_name << endl;
	ofs << room << "," << day << "," << time << "," << "�����" << "," << this->stu_id << "," << this->stu_name << endl;
	ofs.close();
	cout << "ԤԼ�������ύ" << endl;
	system("pause");
	system("cls");
}

void StuSys::GetOrder()
{
	int sum = 1;
	if (this->stu_od.order_info->empty())
	{
		cout << "����ԤԼ��Ϣ��" << endl;
	}
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		cout << "------------------------------------------------" << endl;
		int n = 0;
		bool tea = true;
		//���������Ϣ
		for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
		{
			switch (n)
			{
			case 0:
				cout << sum << ": " << "������" << *(itcom);
				break;
			case 1:
				cout << " ���ڣ�" << *(itcom);
				break;
			case 2:
				cout << " ʱ�䣺" << *(itcom);
				break;
			case 3:
			{
				cout << " ����״̬��" << *(itcom);
				//�ж��Ƿ���������ʦ��Ϣ
				if (*(itcom) == "�����" || *(itcom) == "ԤԼ��ȡ��")
				{
					tea = false;
				}
				break;
			}
			}
			n++;
		}
		//�����������Ϣ
		for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
		{
			switch (n)
			{
			case 4:
				cout << " �����˱�ţ�" << *(itstu);
				break;
			case 5:
				cout << " ������������" << *(itstu);
				break;
			}
			n++;
		}
		if (tea == true)
		{
			//��������ʦ��Ϣ
			for (vector<string>::const_iterator ittea = it->second.second.begin(); ittea != it->second.second.end(); ittea++)
			{
				switch (n)
				{
				case 6:
					cout << " �����ְ���ţ�" << *(ittea);
					break;
				case 7:
					cout << " �����������" << *(ittea);
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
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		//�ж�������
		if (id == it->second.first.front())
		{
			cout << "------------------------------------------------" << endl;
			int n = 0;
			bool tea = true;
			//���������Ϣ
			for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
			{
				switch (n)
				{
				case 0:
					cout << sum << ": "<< "������" << *(itcom);
					break;
				case 1:
					cout << " ���ڣ�" << *(itcom);
					break;
				case 2:
					cout << " ʱ�䣺" << *(itcom);
					break;
				case 3:
				{
					cout << " ����״̬��" << *(itcom);
					//�ж��Ƿ���������ʦ��Ϣ
					if (*(itcom) == "�����" || *(itcom) == "ԤԼ��ȡ��")
					{
						tea = false;
					}
					break;
				}
				}
				n++;
			}
			//�����������Ϣ
			for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
			{
				switch (n)
				{
				case 4:
					cout << " �����˱�ţ�" << *(itstu);
					break;
				case 5:
					cout << " ������������" << *(itstu);
					break;
				}
				n++;
			}
			if (tea == true)
			{
				//��������ʦ��Ϣ
				for (vector<string>::const_iterator ittea = it->second.second.begin(); ittea != it->second.second.end(); ittea++)
				{
					switch (n)
					{
					case 6:
						cout << " �����ְ���ţ�" << *(ittea);
						break;
					case 7:
						cout << " �����������" << *(ittea);
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
		cout << "����ԤԼ��Ϣ��" << endl;
	}
	system("pause");
	system("cls");
}

map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> StuSys::GetOrder(string id, int)
{
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp;
	int sum = 1;
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->stu_od.order_info->begin(); it != this->stu_od.order_info->end(); it++)
	{
		//�ж�������
		if (id == it->second.first.front() && it->first.back() != "ԤԼʧ��" && it->first.back() != "ԤԼ��ȡ��")
		{
			cout << "------------------------------------------------" << endl;
			int n = 0;
			bool tea = true;
			//���������Ϣ
			for (vector<string>::const_iterator itcom = it->first.begin(); itcom != it->first.end(); itcom++)
			{
				switch (n)
				{
				case 0:
					cout << sum << ": " << "������" << *(itcom);
					break;
				case 1:
					cout << " ���ڣ�" << *(itcom);
					break;
				case 2:
					cout << " ʱ�䣺" << *(itcom);
					break;
				case 3:
				{
					cout << " ����״̬��" << *(itcom);
					//�ж��Ƿ���������ʦ��Ϣ
					if (*(itcom) == "�����" || *(itcom) == "ԤԼ��ȡ��")
					{
						tea = false;
					}
					break;
				}
				}
				n++;
			}
			//�����������Ϣ
			for (vector<string>::const_iterator itstu = it->second.first.begin(); itstu != it->second.first.end(); itstu++)
			{
				switch (n)
				{
				case 4:
					cout << " �����˱�ţ�" << *(itstu);
					break;
				case 5:
					cout << " ������������" << *(itstu);
					break;
				}
				n++;
			}
			if (tea == true)
			{
				//��������ʦ��Ϣ
				for (vector<string>::const_iterator ittea = it->second.second.begin(); ittea != it->second.second.end(); ittea++)
				{
					switch (n)
					{
					case 6:
						cout << " �����ְ���ţ�" << *(ittea);
						break;
					case 7:
						cout << " �����������" << *(ittea);
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
		cout << "����ԤԼ��Ϣ��" << endl;
	}
	return mp;
}

void StuSys::CancelOrder()
{
	cout << "����л�ԤԼ�ɹ���ԤԼ����ȡ������������Ҫȡ���ļ�¼��0�����أ�" << endl;
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp = this->GetOrder(this->stu_id, 10);
	cout << "����������ѡ��" << endl;
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
		temp1.push_back("ԤԼ��ȡ��");
		this->stu_od.order_info->erase(mp.find(select)->second);
		this->stu_od.order_info->insert(make_pair(temp1, make_pair(temp2, temp3)));
		this->SaveOrder();
		cout << "ԤԼȡ���ɹ�" << endl;
	}
	else
	{
		cout << "�밴��ʾ���룡" << endl;
	}
	system("pause");
	system("cls");
}

StuSys::~StuSys()
{
}
