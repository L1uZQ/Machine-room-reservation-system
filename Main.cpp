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
		cout << "======================  C++�﷨���֡�����ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "���˵�" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;

		switch (select) {
		case 1://ѧ�����
			Login(STUDENT_FILE, 1);
			break;

		case 2:  //��ʦ���
			Login(TEACHER_FILE, 2);

		case 3:  //����Ա���
			Login(ADMIN_FILE, 3);

		case 0: //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��"<<endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "�������" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	
	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		//��¼��֤
		int fId;
		string fName;
		string fPwd;
		//������Կ���������ʵ��
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) { 
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				return;
			}
		}

	}
	else if (type == 2) {
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				managerMenu(person); //����managerMenu����
				return;
			}
		}
	}

	cout << "��֤ʧ��" << endl;

	system("pause");
	system("cls");
	return;
}


//����Ա�˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1) {
			cout << "����˺�";
			man->addPerson();
		}
		else if (select == 2) {
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ��Ϣ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}