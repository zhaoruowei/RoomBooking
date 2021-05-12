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
	cout << "��ӭ��ʦ" << this->tea_name << "��¼��" << endl;
	cout << "                --------------------------            " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       1.�鿴����ԤԼ     |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       2.���ԤԼ         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "               |       0.ע����¼         |           " << endl;
	cout << "               |                          |           " << endl;
	cout << "                --------------------------            " << endl;
}

void TeaSys::ExitUserSys()
{
	cout << "ע����¼�ɹ����˻�ϵͳ����" << endl;
	system("pause");
	system("cls");
}

void TeaSys::GetOrder()
{
	int sum = 1;
	if (this->tea_od.order_info->empty())
	{
		cout << "����ԤԼ��Ϣ��" << endl;
	}
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
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

void TeaSys::DealOrder()
{
	cout << "����л�ԤԼ�ɹ���ԤԼ����ȡ������������Ҫȡ���ļ�¼��0�����أ�" << endl;
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp = this->GetOrder(10);
	cout << "����������ѡ��" << endl;
	int select1 = 0;
	cin >> select1;
	if (select1 == 0)
	{
		system("cls");
		return;
	}
	else if (mp.find(select1) != mp.end())
	{
		cout << "��������˽����" << endl;
		cout << "1.ͨ��" << endl;
		cout << "2.��ͨ��" << endl;
		int select2;
		cin >> select2;
		switch (select2)
		{
		case 1:case 2:
			AlterOrder(mp, select1, select2);
			cout << "ԤԼ��˳ɹ���" << endl;
			break;
		default:
			cout << "�밴��ʾ���룡" << endl;
			break;
		}
	}
	else
	{
		cout << "�밴��ʾ���룡" << endl;
	}
	system("pause");
	system("cls");
}

map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> TeaSys::GetOrder(int)
{
	map<int, multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator> mp;
	int sum = 1;
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
	{
		//�ж����״̬
		if (it->first.back() == "�����")
		{
			cout << "------------------------------------------------" << endl;
			int n = 0;
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
			cout << endl;
			mp.insert(make_pair(sum, it));
			sum++;
		}
	}
	if (sum == 1)
	{
		cout << "���������ԤԼ��" << endl;
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
		temp1.push_back("ԤԼ�ɹ�");
	}
	else
	{
		temp1.push_back("ԤԼʧ��");
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
	ofs.open("D:\\Programmer\\C++\\����ԤԼϵͳ\\order.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "ԤԼ��Ϣ�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//����ԤԼ��Ϣ����
	for (multimap<vector<string>, pair<vector<string>, vector<string>>>::iterator it = this->tea_od.order_info->begin(); it != this->tea_od.order_info->end(); it++)
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

TeaSys::~TeaSys()
{
}
