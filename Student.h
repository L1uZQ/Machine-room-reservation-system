#pragma once
#include<iostream>
using namespace std;

#include "Identity.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder(); //����

	void showMyOrder(); //�鿴�ҵ�ԤԼ

	void showAllOrder(); //�鿴����ԤԼ

	void candelOrder(); //ȡ��ԤԼ


private:
	//ѧ��
	int m_id;
};
