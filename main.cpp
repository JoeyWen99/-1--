#pragma once
#include"Administrator.h"
#include"User.h"
#include"Interface.h"

Administrator admin;//全局唯一的管理员

int main() {

	int login_op = 0;//操作

	User user;
	while (true) {
		login_op = Interface::Boot_UI_Menu();
		switch (login_op)
		{
		case 1: {//1.用户登录
			admin.User_Login();
			clear_screen();
			break;
		}
		case 2: {//2.用户注册
			admin.User_register();
			break;
		}
		case 3: {//3.管理员登录
			admin.Admin_Login();
			break;
		}
		case 4: {//4.退出系统
			Interface::Exit_System();
		}
		}
	}
}