#pragma once
#include"Tool_fun.h"
#include<vector>
#include<string>
using namespace std;
//enum Goods_State { Sold, Off_Shelf, On_Shelf };

class Goods
{
public:
	bool operator==(const Goods G);
public:
	string id;
	string name;
	double price;
	string description;
	string Saler_ID;
	string time;
	string state;
	int num_of_mess;
	vector<string> mess_board;
};

