#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>//cout��ʽ�����
#include<fstream>//д�ļ�ͷ�ļ�
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
	void Users_Init();//�������ļ��г�ʼ���û��б�
	void Goods_Init();//�������ļ��г�ʼ����Ʒ�б�
	void Bills_Init();//�������ļ��г�ʼ�������б�

	void Show_A_Goods_list(vector<Goods>&list);//1. �鿴������Ʒ
	void Show_A_Bill_list(vector<Bill>&list);//3. �鿴���ж���
	void Show_A_Users_list(vector<User>&list);//4. �鿴�����û�

	void Admin_Login();//����Ա��¼
	void Admin_Logout();//����Աע��

	void Show_User_Goods_on_shelf();
	void Cout_A_Goods_for_Buyer(Goods &good);


	void Print_A_Goods(Goods & good);

	void Off_shelf_A_goods(vector<Goods>& list);

	void User_Login();//�û���¼
	int Is_User_Exist(string nm,string ps);//c
	void User_Logout();//�û�ע��

	void User_register();//�û�ע��
	bool Modify_Goods(vector<Goods>& list, Goods & good);//����һ����Ʒ��,�����ܱ����Ƿ���ڸ���Ʒ,���������޸�����Ϣ,�������ļ�,���򷵻�0

	void Invalid_User();//ɾ��һ���û�,���¼�������������Ʒ
	void Off_shelf_User_list(User &it);//�¼�һ���û�������������Ʒ
										
	
	void Search_Goods_list(char caller);
	void Get_next(string & str_P, int * next);
	int kmp(string &T, string &P, int T_start, int *next);

	void Add_Goods(Goods &good);//����Ʒ�ܱ��м�����Ʒ,�������ļ�
	void Add_Biils(User & Buyer, User & Saler,Goods &good);//�����¶���
	string Get_time();

	vector<User> user_list;//�û��б�
	vector<Goods> goods_list;//������Ʒ�б�
	vector<Bill> bill_list;//���ж�����Ϣ
private:
	string admin_name;
	string admin_password;

};


