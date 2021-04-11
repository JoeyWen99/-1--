#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>//cout格式化输出
#include<fstream>//写文件头文件
#include<algorithm>
#include<ctime>
#include"User.h"
#include"Goods.h"
#include"Bill.h"
#include"Tool_fun.h"
#include"Interface.h"
#include "windows.h"

#define USER_FILE "uers_list.txt"
#define GOODS_FILE "goods_list.txt"
#define BILL_FILE "bills_list.txt"
using namespace std;

class Administrator
{
public:
	Administrator();
	~Administrator();

	void Save2File(int num);
	void Users_Init();//开机从文件中初始化用户列表
	void Goods_Init();//开机从文件中初始化商品列表
	void Bills_Init();//开机从文件中初始化订单列表

	void Show_A_Goods_list(vector<Goods>&list);//1. 查看所有商品
	void Show_A_Bill_list(vector<Bill>&list);//3. 查看所有订单
	void Show_A_Users_list(vector<User>&list);//4. 查看所有用户

	void Admin_Login();//管理员登录
	void Admin_Logout();//管理员注销

	void Show_User_Goods_on_shelf();
	void Cout_A_Goods_for_Buyer(Goods &good);


	void Print_A_Goods(Goods & good);

	void Off_shelf_A_goods(vector<Goods>& list);

	void User_Login();//用户登录
	int Is_User_Exist(string nm,string ps);//c
	void User_Logout();//用户注销

	void User_register();//用户注册
	bool Modify_Goods(vector<Goods>& list, Goods & good);//传入一个商品的,查找总表中是否存在该商品,若存在则修改其信息,并更新文件,否则返回0

	void Invalid_User();//删除一个用户,并下架其所有在售商品
	void Off_shelf_User_list(User &it);//下架一个用户的所有在售商品
										
	
	void Search_Goods_list(char caller);
	void Get_next(string & str_P, int * next);
	int kmp(string &T, string &P, int T_start, int *next);

	void Add_Goods(Goods &good);//向商品总表中加入商品,并更新文件
	void Add_Biils(User & Buyer, User & Saler,Goods &good);//生成新订单
	string Get_time();

	vector<User> user_list;//用户列表
	vector<Goods> goods_list;//所有商品列表
	vector<Bill> bill_list;//所有订单信息
private:
	string admin_name;
	string admin_password;

};


