#include"Show_Interface.h"

void Show_Interface::Print_test_Interface()
{
	cout << "\t\t����ԤԼϵͳ" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(1):ѧ����¼\t\t    *" << endl;
	cout <<"*\t\t\t\t\t    *"<< endl;
	cout << "*\t\t(2):��ʦ��¼\t\t    *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(3):����Ա��¼\t\t    *" << endl;
	cout << "*\t\t\t\t\t    *" << endl;
	cout << "*\t\t(0):�˳�ϵͳ\t\t    *" << endl;
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
	cout << "������ѧ���˺�:";
	cin >> name;
	cout << "������ѧ������:";
	cin >> password;
	if (!stu_teacher_compare(name, password,1)) { cout << "��¼ʧ��,�˺Ż����������!\n����ϵ����Ա!" << endl; return; }
	Student stu(name,password);
	while (1)
	{
		system("cls");
		cout << "��ӭ" << name << "ͬѧ��¼��ϵͳ��" << endl;
		cout << "\t\tѧ��ϵͳ����" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):����ԤԼ\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):�鿴�ҵ�ԤԼ\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(3):�鿴����ԤԼ\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(4):ȡ��ԤԼ\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):ע����¼\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;

		int select_type;
		bool is_quit = false;
		cout << "��������Ҫ���еĲ���:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:stu.Apply_appointment(); break;
		case 2:stu.Show_My_appointment(); break;
		case 3:stu.Show_anyone_appointment(); break;
		case 4:stu.Cancel_appointment(); break;
		case 0:is_quit = stu.Quit_login(); break;
		default:cout << "�������!" << endl; break;
		}
		if (is_quit) return;
		system("pause");
	}
	
}

void Show_Interface::Print_teacher_Interface()
{
	ofstream W_stu_file("teacher.txt", ios::out | ios::app);
	string name, password;
	cout << "��������ʦ�˺�:";
	cin >> name;
	cout << "��������ʦ����:";
	cin >> password;
	if (!stu_teacher_compare(name, password, 2)) { cout << "��¼ʧ��,�˺Ż����������!\n����ϵ����Ա!" << endl; return; }
	Teacher Tea(name, password);

	while (1)
	{
		system("cls");
		cout << "\t\t��ʦϵͳ����" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):�鿴����ԤԼ\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):���ԤԼ\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):ע����¼\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		int select_type;
		bool is_quit = false;
		cout << "��������Ҫ���еĲ���:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:Tea.Show_anyone_appointment(); break;
		case 2:Tea.Agree_appointment(); break;
		case 0:is_quit = Tea.Quit_login(); break;
		default:cout << "�������!" << endl; break;
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
		cout << "��Ϊ��ϵͳû�й���Ա\n�״�ʹ��ϵͳ��Ҫ���ù���Ա�˺ź�����" << endl;
		cout << "������󶨵Ĺ���Ա�˺�:";
		cin >> name;
		cout << "������󶨵Ĺ���Ա����:";
		cin >> password;
		W_admin_file << name << " " << password << endl;
	}
	cout << "���������Ա�˺�:";
	cin >> name;
	cout << "���������Ա����:";
	cin >> password;
	if (!admin_compare(name, password)) { cout << "��¼ʧ��,�˺Ż������������!" << endl; return; }
	Administrator Admin(name, password);
	while (1) 
	{
		system("cls");
		cout << "��ӭ" << Admin.Show_admin_name() << "����Ա�û�����ϵͳ!" << endl;
		cout << endl;
		cout << "\t\t����Աϵͳ����" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(1):����˺�\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(2):�鿴�˺�\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(3):�鿴����\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(4):���ԤԼ\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "*\t\t(0):ע����¼\t\t    *" << endl;
		cout << "*\t\t\t\t\t    *" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;

		int select_type;
		bool is_quit = false;
		cout << "��������Ҫ���еĲ���:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:Admin.Add_account(); break;
		case 2:Admin.Show_account(); break;
		case 3:Admin.Show_computer(); break;
		case 4:Admin.Clear_appointment(); break;
		case 0:is_quit = Admin.Quit_login(); break;
		default:cout << "�������!" << endl; break;
		}
		if (is_quit) return;
		system("pause");
	}
	
}