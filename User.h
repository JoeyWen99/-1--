#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include"Goods.h"
#include"Bill.h"
//#include"Administrator.h"

using namespace std;

class User
{
	friend class Administrator;
public:
	void Im_Buyer();
	void Im_Saler();
	void Init_My_goodslist();
	void Init_My_billslist();
	void Release_Goods();
	void Show_A_goods_list(vector<Goods>&list);
	void Print_A_Goods(Goods & g);
	void Print_A_User(User &user);
	void Modify_My_goods();
	void Modify_User_Info();
	void Buy_Goods();
	void Show_Goods_Description();
	void User_info();
	void Recharge();
	void Add_mess(vector<string> &mess_board);//给留言板添加留言
	void check_mess_board();

	//void Show_My_Buy_Bill_list();
	bool operator==(const User U);
private:
	string id;
	string name;
	string password;
	string phone;
	string addr;
	double money;

	bool valid;

	vector<Goods> My_Sale_Goods_list;//卖家商品
	vector<Bill> My_Sale_Bill_list;//卖家订单
	vector<Bill> My_Buy_Bill_list;//卖家订单
};

