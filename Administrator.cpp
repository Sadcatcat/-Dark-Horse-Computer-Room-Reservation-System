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
	cout << "����������˺ŵ�����(1.ѧ��  2.��ʦ):" << endl;
	cin >> select_type;
	if (select_type == 1)
	{
		string ID, Name, Password;
		ofstream W_student_file("student.txt", ios::out | ios::app);
		while (1)
		{
			cout << "������ѧ��ѧ��:";
			cin >> ID;
			if (is_ID_conflict(ID, select_type))
			{
				cout << "ѧ�ų�ͻ,����������!" << endl;
				continue;
			}
			cout << "������ѧ������:";
			cin >> Name;
			cout << "������ѧ������:";
			cin >> Password;
			break;
		}
		W_student_file << ID << " " << Name << " " << Password << endl;
		W_student_file.close();
		cout << "ѧ��:" << ID << " ����:" << Name << "ѧ���˺���Ϣ��ӳɹ�" << endl;
	}

	if (select_type == 2)
	{
		string ID, Name, Password;
		ofstream W_teacher_file("teacher.txt", ios::out | ios::app);
		while (1)
		{
			cout << "��������ʦ��ְ����:";
			cin >> ID;
			if (is_ID_conflict(ID, select_type))
			{
				cout << "ְ���ų�ͻ,����������!" << endl;
				continue;
			}
			cout << "��������ʦ����:";
			cin >> Name;
			cout << "��������ʦ����:";
			cin >> Password;
			break;
		}
		W_teacher_file << ID << " " << Name << " " << Password << endl;
		W_teacher_file.close();
		cout << "ְ����:" << ID << " ����:" << Name << "��ʦ�˺���Ϣ��ӳɹ�" << endl;
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
		cout << "�ļ�Ϊ��!" << endl;
		return;
	}
	
	string data;
	int index = 1;
	if (select == 1)
		cout << "ѧ��\t����\t����" << endl;
	else
		cout << "ְ����\t����\t����" << endl;
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
	cout << "������鿴�˺ŵ�����(1.ѧ��  2.��ʦ):" << endl;
	cin >> select_type;
	switch (select_type)
	{
	case 1:Show_user(1); break;
	case 2:Show_user(2); break;
	default:
		cout << "�������!" << endl;
		break;
	}

}


void Administrator::Show_computer()
{
	cout << "һ�Ż��� 100��\t���Ż���150��\t���Ż���200��" << endl;
}

void Administrator::Clear_appointment()
{
	char select;
	cout << "�Ƿ��������ļ���" << endl;
	cout << "Y or N:";
	cin >> select;
	if (select == 'Y' or select == 'y')
	{
		ofstream file("order.txt", ios::trunc);
		cout << "��ճɹ�!" << endl;
	}
}

bool Administrator::Quit_login()
{
	cout <<this->name<< "����Ա�˳��ɹ�����ӭ�´�ʹ��!" << endl;
	return true;
}