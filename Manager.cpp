#include"Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this-> m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();
}

void Manager::operMenu()
{
	//ѡ��˵�
		cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.����˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.�鿴�˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.�鿴����            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          4.���ԤԼ            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.ע����¼            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����˺�����" << endl;
	cout << "1�����ѧ���˺�" << endl;
	cout << "2����ӽ�ʦ�˺�" << endl;
	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
	}
	else {
		cout << "������������������" << endl;
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

	cout << "�������û���" << endl;
	cin >> name;

	cout << "��������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

//�鿴�˺�
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
	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return ;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close(); // ѧ����ʼ��

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) 
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ: " << vTea.size() << endl;

	ifs.close();
}