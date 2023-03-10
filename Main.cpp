#include"globalFile.h"
#include"Identity.h"
#include"Student.h"
#include"Manager.h"
#include"Teacher.h"
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;

void Login(string fileName, int type);

void managerMenu(Identity*& maneger);

int main() {
	int select = 0;

	while (true)
	{
		cout << "======================  C++语法练手—机房预约系统  ====================="
			<< endl;
		cout << endl << "主菜单" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;

		switch (select) {
		case 1://学生身份
			Login(STUDENT_FILE, 1);
			break;

		case 2:  //老师身份
			Login(TEACHER_FILE, 2);

		case 3:  //管理员身份
			Login(ADMIN_FILE, 3);

		case 0: //退出系统
			cout << "欢迎下次使用"<<endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输出有误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}

void Login(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		//登录验证
		int fId;
		string fName;
		string fPwd;
		//这里可以考虑用链表实现
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) { 
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				return;
			}
		}

	}
	else if (type == 2) {
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				managerMenu(person); //调用managerMenu函数
				return;
			}
		}
	}

	cout << "验证失败" << endl;

	system("pause");
	system("cls");
	return;
}


//管理员菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1) {
			cout << "添加账号";
			man->addPerson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约信息" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}