#pragma once
#include<iostream>
using namespace std;

#include "Identity.h"
#include<vector>
#include"globalFile.h"


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

	//friend void Manager::initVector(); //������Ҫ����˽�г�Ա������Ϊ��Ԫ
	int m_Id;  	//ѧ��

private:


};
