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

	virtual void operMenu(); //菜单

	void addPerson();  //添加账号

	void showPerson();  //查看账号

	void showComputer(); //查看机房信息

	void cleanFile();  //清空预约记录

	void initVector(); //初始化容器
	vector<Student> vStu;
	vector<Teacher> vTea;
private:

};