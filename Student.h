#pragma once
#include<iostream>
using namespace std;

#include "Identity.h"

class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder(); //申请

	void showMyOrder(); //查看我的预约

	void showAllOrder(); //查看所有预约

	void candelOrder(); //取消预约


private:
	//学号
	int m_id;
};
