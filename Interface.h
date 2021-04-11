#pragma once
#include<iostream>
#include<string>
#include"windows.h"

using namespace std;
class Interface
{
public:
	static int Boot_UI_Menu();//显示开机菜单
	static void Exit_System();//退出系统
	static int Adimin_Menu();//显示管理员功能菜单
	static int User_Menu();//显示用户功能菜单
	static int Im_Buyer_Menu();	//买家功能菜单
	static int Im_Saler_Menu();//买家功能菜单
	static int User_Info_Menu();//用户个人信息菜单
private:

};
