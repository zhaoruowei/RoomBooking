#include<iostream>
using namespace std;
#include"Sysmanager.h"
#include<string>

int main()
{
	Sysmanager sys;
	
	while (true)
	{
		sys.ShowSysUI();
		int select = 0;
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:             //ѧ����¼
			sys.LoginStu();
			break;
		case 2:             //��ʦ��¼
			sys.LoginTea();
			break;
		case 3:             //����Ա��¼
			sys.LoginAdmin();
			break;
		case 0:
			sys.ExitSys();
			break;
		default:
			cout << "�밴��ʾ���룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}