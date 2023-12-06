#include"Student.h"

Student::Student()
{}

Student::Student(string n, string p)
{
	this->name = n;
	this->password = p;
}

string return_ID(string name)
{
	ifstream R_file("student.txt", ios::in);
	if (!R_file.is_open())
		return "error";
	
	string data;
	string ID;
	int index = 1;
	while (R_file >> data)
	{
		if((index+2)%3==0) ID = data;
		if ((index+1)%3== 0 && name == data) return ID;
		index++;
	}
	R_file.close();
	return "error";
}

bool is_Repeated_addition(vector<string>V, string temp)
{
	ifstream W_My_order_file(temp, ios::in);

	if (!W_My_order_file.is_open())
	{
		cout <<temp<< "�ļ�������" << endl;
		return false;
	}

	string data;
	int index = 1;
	int is_line = 0;
	while (W_My_order_file >> data)
	{
		if ((index + 3) % 4 == 0 && data == V[0]) is_line++;
		if ((index + 2) % 4 == 0 && data == V[1]) is_line++;
		if ((index + 1) % 4 == 0 && data == V[2]) is_line++;
		if (is_line == 3) return true;
		index++;
	}
	W_My_order_file.close();
	return false;
}

void Student::Apply_appointment()
{
	string ID = return_ID(this->name);
	string temp = ID +"_"+this->name + "_order.txt";
	ofstream W_My_order_file(temp, ios::out | ios::app);
	ofstream W_order_file("order.txt", ios::out | ios::app);
	vector<string>V;
	V.resize(3);
	int select_type;

	while (1)
	{
		cout << "��ѡ������=>" << endl;
		cout << "1.��һ  2.�ܶ�  3.����  4.����  5.����" << endl;
		cout << "��ѡ������:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:V[0] = "��һ"; break;
		case 2:V[0] = "�ܶ�"; break;
		case 3:V[0] = "����"; break;
		case 4:V[0] = "����"; break;
		case 5:V[0] = "����"; break;
		default:
			cout << "��������ڴ���!" << endl;
			continue;
		}
		break;
	}

	while (1)
	{
		cout << "��ѡ��ʱ���=��" << endl;
		cout << "1.����  2.����" << endl;
		cout << "��ѡ��ʱ���:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:V[1] = "����"; break;
		case 2:V[1] = "����"; break;
		default:
			cout << "�����ʱ�����!" << endl;
			continue;
		}
		break;
	}

	while (1)
	{
		cout << "��ѡ�����=��" << endl;
		cout << "1.һ�Ż���(100)\n2.���Ż���(150)\n3.���Ż���(200)" << endl;
		cout << "��ѡ�����:";
		cin >> select_type;
		switch (select_type)
		{
		case 1:V[2] = "һ�Ż���(100)"; break;
		case 2:V[2] = "���Ż���(150)"; break;
		case 3:V[2] = "���Ż���(200)"; break;
		default:
			cout << "����Ļ������д���!" << endl;
			continue;
		}
		break;
	}
	if (is_Repeated_addition(V, temp)) { cout << "�Ѿ����ظ���ԤԼ�������ظ����!" << endl; return; }
	cout << "����ԤԼ��Ϣ��ӳɹ�,�����ĵȴ�����Ա���!" << endl;
	W_My_order_file << V[0] << " " << V[1] << " " << V[2]<<" "<<"�����"<< endl;
	W_order_file<< V[0] << " " << V[1] <<" "<<ID<<" "<<this->name<<" " << V[2] << " " << "�����" << endl;
	W_order_file.close();
	W_My_order_file.close();
}


bool Student::Show_My_appointment()
{
	string ID = return_ID(this->name);
	string temp = ID + "_" + this->name + "_order.txt";
	ifstream R_file(temp, ios::in);
	
	if (!R_file.is_open())
	{
		cout << "�ļ�Ϊ��" << endl;
		return false;
	}

	string data;
	int index = 1;
	int ID_index = 1;
	cout << endl;
	cout << "����   ԤԼ����  ʱ��    ����             ״̬"<<endl;
	while (R_file >> data)
	{
		if ((index + 3) % 4 == 0) cout << ID_index << "      ";
		if ((index + 2) % 4 == 0) cout << "     ";
		if ((index + 1) % 4 == 0) cout << "   ";
		if (index % 4 == 0) cout << "   ";
		cout << data << " ";
		if (index % 4 == 0) { cout << endl; ID_index++; }
		index++;
	}
	cout << endl;
	R_file.close();
	return true;
}


void Student::Show_anyone_appointment()
{
	ifstream R_file("order.txt", ios::in);

	if (!R_file.is_open())
	{
		cout << "�ļ�Ϊ��!" << endl;
		return;
	}

	string data;
	int index = 1;
	int ID = 1;
	cout << endl;
	cout << "����   ԤԼ����   ʱ��     ѧ��    ����     ����             ״̬" << endl;
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
}


void Student::Cancel_appointment() 
{
	if (!this->Show_My_appointment()) return;
	int select_type,tag=0;
	cout << "��ѡ����Ҫȡ����ԤԼ:" << endl;
	cin >> select_type;
	string ID = return_ID(this->name);
	string temp = ID + "_" + this->name + "_order.txt";
	fstream W_Rfile(temp,ios::in|ios::out);
	fstream W_R_order_file("order.txt",ios::in|ios::out);
	vector<string>V;
	V.resize(2);
	if (!W_Rfile.is_open())
	{
		cout <<this->name<< "ԤԼ�ļ�δ�ҵ�!" << endl;
		return;
	}
	else
	{
		string data;
		int index = 1;
		int line = 1;
		while (W_Rfile >> data)
		{
			if (index % 4 == 0 && data == "��ȡ��" && line == select_type) { tag = 1; cout << "��ԤԼ�Ѿ�ȡ������Ҫ�ظ�����!" << endl; break; }
			if (index % 4 == 0) line++;
			index++;
		}
		index = 1;
		line = 1;
		//Ҫ�������״̬���ڲ���ʹ�ó�ʼ������
		W_Rfile.clear();
		W_Rfile.seekg(0);
	

		if (!tag) 
		{
			while (W_Rfile >> data)
			{
				if ((index + 3) % 4 == 0 && line == select_type) V[0] = data;
				if ((index + 2) % 4 == 0 && line == select_type) V[1] = data;
				if ((index + 1) % 4 == 0 && line == select_type)
				{
					W_Rfile.seekp(W_Rfile.tellg());
					W_Rfile << " ��ȡ��" << endl;
					break;
				}
				if (index % 4 == 0) line++;
				index++;
			}
			W_Rfile.close();
			cout << "ԤԼ�ɹ�ȡ��!" << endl;
			}
		}
		
	W_R_order_file.clear();
	W_R_order_file.seekg(0);
	if (!tag) 
	{
		if (!W_R_order_file.is_open())
		{
			cout << "ԤԼ�ļ�δ�ҵ�!" << endl;
			return;
		}
		else
		{
			string data;
			int index = 1;
			int is_line = 0;
			while (W_R_order_file >> data)
			{
				if ((index + 5) % 6 == 0 && data == V[0]) is_line++;
				if ((index + 4) % 6 == 0 && data == V[1]) is_line++;
				if ((index + 3) % 6 == 0 && data == ID) is_line++;
				if ((index + 2) % 6 == 0 && data == this->name) is_line++;
				if ((index + 1) % 6 == 0 && is_line == 4)
				{
					W_R_order_file.seekp(W_R_order_file.tellg());
					W_R_order_file << " ��ȡ��" << endl;
					break;
				}
				if (index % 6 == 0) is_line = 0;
				index++;
			}
			W_Rfile.close();
		}
	}
	
}

bool Student::Quit_login()
{
	cout << this->name << "ͬѧ�˳��ɹ�����ӭ�´�ʹ��!" << endl;
	return true;
}