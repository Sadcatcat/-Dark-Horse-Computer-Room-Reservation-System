#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class Teacher {
public:
	Teacher();
	Teacher(string n, string p);
	bool Show_anyone_appointment();
	void Agree_appointment();
	bool Quit_login();

private:
	string name;
	string password;
};