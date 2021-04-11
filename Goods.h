#pragma once
#include"Tool_fun.h"
#include<string>
using namespace std;
enum Goods_State { Sold, Off_shelf, On_shelf };

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
};

