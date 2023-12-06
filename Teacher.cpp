#include"Teacher.h"

Teacher::Teacher() {}

Teacher::Teacher(string n, string p)
{
	this->name = n;
	this->password = p;
}

bool Teacher::Show_anyone_appointment()
{
	ifstream R_file("order.txt", ios::in);

	if (!R_file.is_open())
	{
		cout << "文件为空!" << endl;
		return false;
	}

	string data;
	int index = 1;
	int ID = 1;
	cout << endl;
	cout << "序列   预约日期   时段     学号    姓名     机房             状态" << endl;
	while (R_file >> data)
	{
		if ((index + 5) % 6 == 0)cout << ID << "      ";
		if ((index + 4) % 6 == 0) cout << "      ";
		if ((index + 3) % 6 == 0) cout << "    ";
		if ((index + 2) % 6 == 0) cout << "    ";
		if ((index + 1) % 6 == 0) cout << "    ";
		if (index % 6 == 0) cout << "   ";
		cout << data << " ";
		if (index % 6 == 0) { cout << endl; ID++; }
		index++;
	}
	cout << endl;
	R_file.close();
	return true;
}


vector<string> Get_student_ID_name(int line)
{
	ifstream R_order_file("order.txt", ios::in);
	vector<string>V;
	V.resize(2);
	V[0] = "error";
	V[1] = "error";
	if (!R_order_file.is_open())
	{
		cout << "预约文件不存在!" << endl;
		return V;
	}

	string data;
	int index=1;
	int dline = 1;
	while (R_order_file >> data)
	{
		if ((index + 3) % 6 == 0 && dline == line) V[0] = data;
		if ((index + 2) % 6 == 0 && dline == line) V[1] = data;
		if (index % 6 == 0) dline++;
		index++;
	}
	R_order_file.close();
	return V;

}
 
void Teacher::Agree_appointment()
{
	
	if (!this->Show_anyone_appointment()) return;
	int select_type, tag = 0;
	cout << "请选择您允许通过的学生预约ID:";
	cin >> select_type;
	vector<string>Vs = Get_student_ID_name(select_type);
	string ID = Vs[0];
	string name = Vs[1];
	if (ID == "error" and name == "error") return;
	string temp = ID + "_" + name + "_order.txt";
	fstream W_Rfile(temp, ios::in | ios::out);
	fstream W_R_order_file("order.txt", ios::in | ios::out);
	vector<string>V;
	V.resize(3);
	if (!W_Rfile.is_open())
	{
		cout << this->name << "预约文件未找到!" << endl;
		return;
	}
	else
	{
		string data;
		int index = 1;
		int line = 1;
		while (W_R_order_file >> data)
		{
			if (index % 6 == 0 && data == "已审核" && line == select_type) { tag = 1; cout << "该预约已经审核，不要重复操作!" << endl; break; }
			if (index % 6 == 0 && data == "已取消" && line == select_type) { tag = 1; cout << "该预约已经取消，无法审核!" << endl; break; }
			if (index % 6 == 0) line++;
			index++;
		}
		index = 1;
		line = 1;
		//要先清空流状态，在才能使用初始化功能
	
		W_R_order_file.clear();
		W_R_order_file.seekg(0);

		if (!tag)
		{
			if (!W_R_order_file.is_open())
			{
				cout << "预约文件未找到!" << endl;
				return;
			}
			else
			{
				string data;
				int index = 1;
				
				while (W_R_order_file >> data)
				{
					if ((index + 5) % 6 == 0 && line == select_type) V[0] = data;
					if ((index + 4) % 6 == 0 && line == select_type) V[1] = data;
					if ((index + 1) % 6 == 0 && line == select_type) V[2] = data;
					if ((index + 1) % 6 == 0 && line == select_type)
					{
						W_R_order_file.seekp(W_R_order_file.tellg());
						W_R_order_file << " 已审核" << endl;
						break;
					}
					if (index % 6 == 0) line++;
					index++;
				}
				W_R_order_file.close();
			}
		}

		W_Rfile.clear();
		W_Rfile.seekg(0);

		if (!tag)
		{
			string data;
			int index = 1;
			int is_line = 0;
			while (W_Rfile >> data)
			{
				if ((index + 3) % 4 == 0 && data == V[0]) is_line++;
				if ((index + 2) % 4 == 0 && data == V[1]) is_line++;
				if ((index + 1) % 4 == 0 && data == V[2]) is_line++;
				if ((index + 1) % 4 == 0 && is_line == 3)
				{
					W_Rfile.seekp(W_Rfile.tellg());
					W_Rfile << " 已审核" << endl;
					break;
				}
				if (index % 4 == 0) is_line = 0;
				index++;
			}
			W_Rfile.close();
			cout << "预约审核成功!" << endl;
		}
	}




}


bool Teacher::Quit_login()
{
	cout << this->name << "老师退出成功，欢迎下次使用!" << endl;
	return true;
}