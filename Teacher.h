#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include<vector>

using namespace std;

class Teacher : public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder(); //���ԤԼ

	//friend void Manager::initVector(); //��Ҫ���������

	int m_EmpId;
private:

};