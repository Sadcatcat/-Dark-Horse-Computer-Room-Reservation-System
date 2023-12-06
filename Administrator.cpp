#include"Administrator.h"

Administrator::Administrator()
{}

Administrator::Administrator(string n, string p)
{
	this->name = n;
	this->password = p;
}

string Administrator::Show_admin_name()
{
	return this->name;
}

bool is_ID_conflict(string id,int select)
{
	vector<string>V;
	V.push_back("student.txt");
	V.push_back("teacher.txt");
	ifstream R_file(V[select-1], ios::in);
	
	if (!R_file.is_open())
		return false;
	
	string data;
	string temp;
	int index = 1;
	while (R_file >> data)
	{
		if ((index+2)%3==0) 
		{
			if (data == id)
				return true;
		}
		index++;
	}
	R_file.close();
	return false;
}

void Administrator::Add_account()
{
	int select_type;
	cout << "请输入添加账号的类型(1.学生  2.老师):" << endl;
	cin >> select_type;
	if (select_type == 1)
	{
		string ID, Name, Password;
		ofstream W_student_file("student.txt", ios::out | ios::app);
		while (1)
		{
			cout << "请输入学生学号:";
			cin >> ID;
			if (is_ID_conflict(ID, select_type))
			{
				cout << "学号冲突,请重新输入!" << endl;
				continue;
			}
			cout << "请输入学生姓名:";
			cin >> Name;
			cout << "请输入学生密码:";
			cin >> Password;
			break;
		}
		W_student_file << ID << " " << Name << " " << Password << endl;
		W_student_file.close();
		cout << "学号:" << ID << " 姓名:" << Name << "学生账号信息添加成功" << endl;
	}

	if (select_type == 2)
	{
		string ID, Name, Password;
		ofstream W_teacher_file("teacher.txt", ios::out | ios::app);
		while (1)
		{
			cout << "请输入老师的职工号:";
			cin >> ID;
			if (is_ID_conflict(ID, select_type))
			{
				cout << "职工号冲突,请重新输入!" << endl;
				continue;
			}
			cout << "请输入老师姓名:";
			cin >> Name;
			cout << "请输入老师密码:";
			cin >> Password;
			break;
		}
		W_teacher_file << ID << " " << Name << " " << Password << endl;
		W_teacher_file.close();
		cout << "职工号:" << ID << " 姓名:" << Name << "老师账号信息添加成功" << endl;
	}
}



void Show_user(int select)
{
	vector<string>V;
	V.push_back("student.txt");
	V.push_back("teacher.txt");
	ifstream R_file(V[select - 1], ios::in);

	if (!R_file.is_open())
	{
		cout << "文件为空!" << endl;
		return;
	}
	
	string data;
	int index = 1;
	if (select == 1)
		cout << "学号\t姓名\t密码" << endl;
	else
		cout << "职工号\t姓名\t密码" << endl;
	while (R_file >> data)
	{
		
		cout << data << "\t";
		if (index % 3 == 0) cout << endl;
		index++;
	}
	R_file.close();
}

void Administrator::Show_account()
{
	int select_type;
	cout << "请输入查看账号的类型(1.学生  2.老师):" << endl;
	cin >> select_type;
	switch (select_type)
	{
	case 1:Show_user(1); break;
	case 2:Show_user(2); break;
	default:
		cout << "输入错误!" << endl;
		break;
	}

}


void Administrator::Show_computer()
{
	cout << "一号机房 100人\t二号机房150人\t三号机房200人" << endl;
}

void Administrator::Clear_appointment()
{
	char select;
	cout << "是否真的清空文件？" << endl;
	cout << "Y or N:";
	cin >> select;
	if (select == 'Y' or select == 'y')
	{
		ofstream file("order.txt", ios::trunc);
		cout << "清空成功!" << endl;
	}
}

bool Administrator::Quit_login()
{
	cout <<this->name<< "管理员退出成功，欢迎下次使用!" << endl;
	return true;
}