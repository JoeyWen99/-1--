#pragma once
#include"Tool_fun.h"
#include<string>
using namespace std;

class Bill
{
public:
	string Bill_ID;
	string Goods_ID;
	double price;//���׽��
	string time;//����ʱ��
	string Saler_ID;
	string Buyer_ID;

	bool operator==(const Bill B);
};

