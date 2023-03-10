#pragma once
#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include<algorithm>

using namespace std;

class Manager : public Identity
{
public:

	Manager();

	Manager(string name, string pwd);

	virtual void operMenu(); //�˵�

	void addPerson();  //����˺�

	void showPerson();  //�鿴�˺�

	void showComputer(); //�鿴������Ϣ

	void cleanFile();  //���ԤԼ��¼

	void initVector(); //��ʼ������
	vector<Student> vStu;
	vector<Teacher> vTea;
private:

};