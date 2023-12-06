#include"Show_Interface.h"

void Show_Interface::Print_test_Interface()
{
	cout << "\t\t机房预约系统" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(1):学生登录\t\t    *" << endl;
	cout <<"*\t\t\t\t\t    *"<< endl;
	cout << "*\t\t(2):教师登录\t\t    *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(3):管理员登录\t\t    *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(0):退出系统\t\t    *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
}

bool stu_teacher_compare(string name, string password,int select)
{
	vector<string>V;
	V.push_back("student.txt");
	V.push_back("teacher.txt");
	ifstream R_file(V[select - 1], ios::in);
	if (!R_file.is_open())
		return false;
	string data;
	int is_ture = 0;
	int index = 1;
	while (R_file >> data)
	{
		if (data == name && (index+1) % 3 == 0) is_ture++;
		if (data == password && index % 3 == 0) is_ture++;
		if (is_ture == 2 && index % 3 == 0) return true;
		else if (index % 3 == 0) is_ture = 0;
		index++;
	}
	return false;
}

void Show_Interface::Print_student_Interface()
{
	ofstream W_stu_file("student.txt", ios::out | ios::app);
	string name, password;
	cout << "请输入学生账号:";
	cin >> name;
	cout << "请输入学生密码:";
	cin >> password;
	if (!stu_teacher_compare(name, password,1)) { cout << "登录失败,账号或者密码错误!\n请联系管理员!" << endl; return; }
	Student stu(name,password);
	while (1)
	{
		system("cls");
		cout << "欢迎" << name << "同学登录此系统！" << endl;
		cout << "\t\t学生系统界面" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):申请预约\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):查看我的预约\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(3):查看所有预约\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(4):取消预约\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):注销登录\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;

		int select_type;
		bool is_quit = false;
		cout << "请输入你要进行的操作:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:stu.Apply_appointment(); break;
		case 2:stu.Show_My_appointment(); break;
		case 3:stu.Show_anyone_appointment(); break;
		case 4:stu.Cancel_appointment(); break;
		case 0:is_quit = stu.Quit_login(); break;
		default:cout << "输入错误!" << endl; break;
		}
		if (is_quit) return;
		system("pause");
	}
	
}

void Show_Interface::Print_teacher_Interface()
{
	ofstream W_stu_file("teacher.txt", ios::out | ios::app);
	string name, password;
	cout << "请输入老师账号:";
	cin >> name;
	cout << "请输入老师密码:";
	cin >> password;
	if (!stu_teacher_compare(name, password, 2)) { cout << "登录失败,账号或者密码错误!\n请联系管理员!" << endl; return; }
	Teacher Tea(name, password);

	while (1)
	{
		system("cls");
		cout << "\t\t教师系统界面" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):查看所有预约\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):审核预约\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):注销登录\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		int select_type;
		bool is_quit = false;
		cout << "请输入你要进行的操作:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:Tea.Show_anyone_appointment(); break;
		case 2:Tea.Agree_appointment(); break;
		case 0:is_quit = Tea.Quit_login(); break;
		default:cout << "输入错误!" << endl; break;
		}
		if (is_quit) return;
		system("pause");

	}

}


bool set_admin_flie()
{
	ifstream R_admin_file("admin.txt", ios::in);
	if (!R_admin_file.is_open())
		return true;
	char ch;
	R_admin_file >> ch;
	if(R_admin_file.eof())
		return true;
	return false;
}

bool admin_compare(string name,string password)
{
	ifstream R_admin_file("admin.txt", ios::in);
	string data;
	int index = 0;
	while (R_admin_file >> data)
		if (data == name&&index==0) index++;
	if (data == password) index++;
	if (index == 2) return true;
	return false;
}

void Show_Interface::Print_admin_Interface()
{
	ofstream W_admin_file("admin.txt", ios::out | ios::app);
	string name, password;
	if (set_admin_flie())
	{
		cout << "因为该系统没有管理员\n首次使用系统需要设置管理员账号和密码" << endl;
		cout << "请输入绑定的管理员账号:";
		cin >> name;
		cout << "请输入绑定的管理员密码:";
		cin >> password;
		W_admin_file << name << " " << password << endl;
	}
	cout << "请输入管理员账号:";
	cin >> name;
	cout << "请输入管理员密码:";
	cin >> password;
	if (!admin_compare(name, password)) { cout << "登录失败,账号或者密码吗错误!" << endl; return; }
	Administrator Admin(name, password);
	while (1) 
	{
		system("cls");
		cout << "欢迎" << Admin.Show_admin_name() << "管理员用户访问系统!" << endl;
		cout << endl;
		cout << "\t\t管理员系统界面" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):添加账号\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):查看账号\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(3):查看机房\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(4):清空预约\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):注销登录\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;

		int select_type;
		bool is_quit = false;
		cout << "请输入您要进行的操作:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:Admin.Add_account(); break;
		case 2:Admin.Show_account(); break;
		case 3:Admin.Show_computer(); break;
		case 4:Admin.Clear_appointment(); break;
		case 0:is_quit = Admin.Quit_login(); break;
		default:cout << "输入错误!" << endl; break;
		}
		if (is_quit) return;
		system("pause");
	}
	
}