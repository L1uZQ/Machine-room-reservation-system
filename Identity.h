//身份基类，之后派生出学生、老师与管理员类

#pragma once
#include<iostream>

using namespace std;

//身份抽象类
class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0;

	string m_Name; //用户名
	string m_Pwd;  //密码

};
