#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<fstream>

class Computer
{
public:
	map<string, string>* com_room;
	bool com_isfile;
	Computer();
	void LoadComDB();
	//Éî¿½±´
	void operator=(Computer& com);
	~Computer();
};

