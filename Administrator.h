#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Administrator {
public:
	Administrator();
	Administrator(string n, string p);
	void Add_account();
	void Show_account();
	void Show_computer();
	void Clear_appointment();
	bool Quit_login();
	string Show_admin_name();
private:
	string name;
	string password;
};