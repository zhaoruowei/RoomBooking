#include "Sysmanager.h"

Sysmanager::Sysmanager()
{
	cout << "��ӭʹ�û�������ϵͳ��" << endl;
	system("pause");
	system("cls");
}

void Sysmanager::ShowSysUI()
{
	cout << "=============��ӭʹ�ù�����ѧ��������ϵͳ=============" << endl;
	cout << endl;
	cout << "������������ݣ�" << endl;
	cout << "                --------------------            " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     1.ѧ������     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     2.��    ʦ     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     3.�� �� Ա     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "               |     0.�˳�ϵͳ     |           " << endl;
	cout << "               |                    |           " << endl;
	cout << "                --------------------            " << endl;
}

void Sysmanager::LoginAdmin()
{
	Admin ad;
	int count = 0;
	while (true)
	{
		cout << "�������û�����" << endl;
		string name;
		cin >> name;
		map<string, string>::iterator it = ad.admin_user.find(name);
		if ( it == ad.admin_user.end())
		{
			cout << "����Ա�û��������ڣ����������룡" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "���������룺" << endl;
			string passwd;
			cin >> passwd;
			if ((*it).second != passwd)
			{
				cout << "����Ա���벻��ȷ�����������룡" << endl;
				count++;
				if (count < 3)
				{
					cout << "ʣ�ೢ�Դ�����" << 3 - count << endl;
				}
				else
				{
					cout << "�����������ϵ����Ա��" << endl;
					exit(-1);
				}
			}
			else
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				this->RunAdmin(name);
				return;
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunAdmin(string name)
{
	AdminSys ads(name);
	while (true)
	{
		ads.ShowUserUI();
		int select = 0;
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			ads.CreateUser();
			break;
		case 2:
			ads.GetUser();
			break;
		case 3:
			ads.GetComputer();
			break;
		case 4:
			ads.ClearOrder();
			break;
		case 0:
			ads.ExitUserSys();
			return;
			break;
		case 10000:
			ads.SaveCom();
			break;
		default:
			cout << "�밴��ʾ���룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::LoginStu()
{
	Student stu;
	int count = 0;
	while (true)
	{
		cout << "������ѧ�ţ�" << endl;
		string id;
		cin >> id;
		map<string, pair<string, string>>::iterator it = stu.stu_user->find(id);
		if (it == stu.stu_user->end())
		{
			cout << "ѧ�Ų����ڣ����������룡" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "������������" << endl;
			string name;
			cin >> name;
			cout << "���������룺" << endl;
			string passwd;
			cin >> passwd;
			if (it->second.first == name && it->second.second == passwd)
			{
				cout << "��½�ɹ���" << endl;
				system("pause");
				system("cls");
				this->RunStu(id, name);
				return;
			}
			else
			{
				cout << "�˺���Ϣ��֤ʧ�ܣ����������룡" << endl;
				count++;
				if (count < 3)
				{
					cout << "ʣ�ೢ�Դ�����" << 3 - count << endl;
				}
				else
				{
					cout << "�˺���Ϣ��֤��������ϵ����Ա��" << endl;
					exit(-1);
				}
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunStu(string id, string name)
{
	StuSys stu(id, name);
	while (true)
	{
		stu.ShowUserUI();
		int select = 0;
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			stu.ComputerOrder();  //����ԤԼ
			break;
		case 2:
			stu.GetOrder(id);     //�鿴�ҵ�ԤԼ
			break;
		case 3:
			stu.GetOrder();       //�鿴����ԤԼ
			break;
		case 4:
			stu.CancelOrder();    //ȡ��ԤԼ
			break;
		case 0:
			stu.ExitUserSys();
			return;
			break;
		default:
			cout << "�밴��ʾ���룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::LoginTea()
{
	Teacher tea;
	int count = 0;
	while (true)
	{
		cout << "������ְ���ţ�" << endl;
		string id;
		cin >> id;
		map<string, pair<string, string>>::iterator it = tea.tea_user->find(id);
		if (it == tea.tea_user->end())
		{
			cout << "ְ���Ų����ڣ����������룡" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "������������" << endl;
			string name;
			cin >> name;
			cout << "���������룺" << endl;
			string passwd;
			cin >> passwd;
			if (it->second.first == name && it->second.second == passwd)
			{
				cout << "��½�ɹ���" << endl;
				system("pause");
				system("cls");
				this->RunTea(id, name);
				return;
			}
			else
			{
				cout << "�˺���Ϣ��֤ʧ�ܣ����������룡" << endl;
				count++;
				if (count < 3)
				{
					cout << "ʣ�ೢ�Դ�����" << 3 - count << endl;
				}
				else
				{
					cout << "�˺���Ϣ��֤��������ϵ����Ա��" << endl;
					exit(-1);
				}
			}
		}
		system("pause");
		system("cls");
		this->ShowSysUI();
	}
}

void Sysmanager::RunTea(string id, string name)
{
	TeaSys tea(id, name);
	while (true)
	{
		tea.ShowUserUI();
		int select = 0;
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			tea.GetOrder();  //�鿴����ԤԼ
			break;
		case 2:
			tea.DealOrder(); //���ԤԼ
			break;
		case 0:
			tea.ExitUserSys();
			return;
			break;
		default:
			cout << "�밴��ʾ���룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Sysmanager::ExitSys()
{
	system("cls");
	cout << "ϵͳ���˳�����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(1);
}

Sysmanager::~Sysmanager()
{
}
