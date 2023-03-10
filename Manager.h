#pragma once
#include<iostream>
#include"Identity.h"
#include<vector>

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

private:
	vector<Student> vStu;
	vector<Teacher> vTea;
};