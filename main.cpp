#pragma once
#include"Administrator.h"
#include"User.h"
#include"Interface.h"

Administrator admin;//ȫ��Ψһ�Ĺ���Ա

int main() {

	int login_op = 0;//����

	User user;
	while (true) {
		login_op = Interface::Boot_UI_Menu();
		switch (login_op)
		{
		case 1: {//1.�û���¼
			admin.User_Login();
			clear_screen();
			break;
		}
		case 2: {//2.�û�ע��
			admin.User_register();
			break;
		}
		case 3: {//3.����Ա��¼
			admin.Admin_Login();
			break;
		}
		case 4: {//4.�˳�ϵͳ
			Interface::Exit_System();
		}
		}
	}
}