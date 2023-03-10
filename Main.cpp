
#include<iostream>
using namespace std;
int main() {
	int select = 0;

	while (true)
	{
		cout << "======================  C++语法练手—机房预约系统  ====================="
			<< endl;
		cout << endl << "主菜单" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;

		switch (select) {
		case 1://学生身份
			//LoginIn(STUDENT_FILE, 1);
			break;

		case 2:  //老师身份


		case 3:  //管理员身份

		case 0: //退出系统
			cout << "欢迎下次使用"<<endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输出有误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}