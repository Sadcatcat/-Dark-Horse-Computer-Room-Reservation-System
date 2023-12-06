#include<iostream>
#include"Show_Interface.h"
using namespace std;

int Print_Interface()
{	
	int Select_type;
	Show_Interface Interface;
	Interface.Print_test_Interface();
	cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ:";
	cin >> Select_type;
	system("cls");
	switch (Select_type)
	{
	case 1:Interface.Print_student_Interface(); break;
	case 2:Interface.Print_teacher_Interface(); break;
	case 3:Interface.Print_admin_Interface(); break;
	case 0:return 0;
	default:cout << "ÊäÈë´íÎó!"; break;
	}
	system("pause");
	return 1;
}

void test()
{
	while (1)
	{
		system("cls");
		if (!Print_Interface())
			return;
	}
	
}

int main()
{
	test();
	system("pause");
	return 0;
}