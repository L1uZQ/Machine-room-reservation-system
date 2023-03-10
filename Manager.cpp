#include"Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this-> m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();
}

void Manager::operMenu()
{
	//选择菜单
		cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.添加账号            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.查看账号            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.查看机房            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          4.清空预约            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.注销登录            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "添加账号类型" << endl;
	cout << "1、添加学生账号" << endl;
	cout << "2、添加教师账号" << endl;
	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
	}
	else {
		cout << "输入有误，请重新输入" << endl;
		system("pause");
		system("cls");
		addPerson();
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "设置密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

//查看账号
void Manager::showPerson()
{

}

void Manager::showComputer()
{

}

void Manager::cleanFile()
{

}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return ;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量为：" << vStu.size() << endl;
	ifs.close(); // 学生初始化

	//读取教师文件信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) 
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为: " << vTea.size() << endl;

	ifs.close();
}