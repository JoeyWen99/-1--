#include "Interface.h"

int Interface::Boot_UI_Menu()//显示开机界面
{
	int op = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout << "    _/    _/            _/  _/           " << endl;
	cout << "   _/    _/    _/_/    _/  _/    _/_/    " << endl;
	cout << "  _/_/_/_/  _/_/_/_/  _/  _/  _/    _/   " << endl;
	cout << " _/    _/  _/        _/  _/  _/    _/    " << endl;
	cout << "_/    _/    _/_/_/  _/  _/    _/_/    " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "==============================================" << endl;
	cout << "1.用户登录 2.用户注册 3.管理员登录 4.退出程序" << endl;
	cout << "==============================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "请输入1-4: ";
		cin >> op;
	}
	return op;
}

int Interface::Adimin_Menu()
{
	int op = 0;

	cout << "=========================================================================================" << endl;
	cout << "1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.删除用户 6.下架商品 7.注销" << endl;
	cout << "=========================================================================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 7) {
		cout << "请输入1-7: ";
		cin >> op;
	}
	return op;
}

int Interface::User_Menu()
{
	int op = 0;

	cout << "================================================" << endl;
	cout << "1.注销登录 2.我是买家 3.我是卖家 4.个人信息管理" << endl;
	cout << "================================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "请输入1-4: ";
		cin >> op;
	}
	return op;
}

int Interface::Im_Buyer_Menu()
{
	int op;

	cout << "========================================================================================" << endl;
	cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
	cout << "========================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 6) {
		cout << "请输入1-6: ";
		cin >> op;
	}
	return op;
}
int Interface::Im_Saler_Menu()
{
	int op = 0;

	cout << "======================================================================================" << endl;
	cout << "1.发布商品 2.查看我的发布 3.修改我的发布 4.下架我的发布 5.查看历史订单 6.返回用户主界面" << endl;
	cout << "======================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 6) {
		cout << "请输入1-6: ";
		cin >> op;
	}
	return op;
}

int Interface::User_Info_Menu()
{
	int op = 0;
	cout << "============================================" << endl;
	cout << "1.返回用户主界面 2.修改信息 3.查看信息 4.充值 " << endl;
	cout << "============================================" << endl;
	cout << endl;
	cout << endl;
	cout << "输入操作: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "请输入1-4: ";
		cin >> op;
	}
	return op;
}



void Interface::Exit_System() {//退出系统
	cout << "******系统已退出******" << endl;
	system("pause");
	exit(0);
}

