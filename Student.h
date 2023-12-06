#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class Student {
public:
	Student();
	Student(string n,string p);
	void Apply_appointment();
	bool Show_My_appointment();
	void Show_anyone_appointment();
	void Cancel_appointment();
	bool Quit_login();
	
private:
	string name;
	string password;
};