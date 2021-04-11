#pragma once
#include"Tool_fun.h"
#include<string>
using namespace std;

class Bill
{
public:
	string Bill_ID;
	string Goods_ID;
	double price;//交易金额
	string time;//交易时间
	string Saler_ID;
	string Buyer_ID;

	bool operator==(const Bill B);
};

