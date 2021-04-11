#include"User.h"
#include"Administrator.h"
extern Administrator admin;

void User::Im_Buyer()
{
	clear_screen();

	this->Init_My_billslist();
	this->Init_My_goodslist();
	int buyer_op = 0;

	while (true) {
		buyer_op = Interface::Im_Buyer_Menu();
		switch (buyer_op)
		{
		case 1: {//1.查看商品列表
			admin.Show_User_Goods_on_shelf();
			clear_screen();
			break;
		}
		case 2: {//2.购买商品
			Buy_Goods();
			clear_screen();
			break;
		}
		case 3: {//3.搜索商品
			admin.Search_Goods_list('U');
			clear_screen();
			break;
		}
		case 4: {//4.查看历史订单
			admin.Show_A_Bill_list(this->My_Buy_Bill_list);
			clear_screen();
			break;
		}
		case 5: {//5.查看商品详细信息
			Show_Goods_Description();
			clear_screen();
			break;
		}
		case 6: {//6.返回用户主界面
			clear_screen();
			return;
		}
		}
	}


}
void User::Im_Saler()
{
	clear_screen();

	this->Init_My_billslist();
	this->Init_My_goodslist();

	int saler_op = 0;

	while (true) {
		saler_op = Interface::Im_Saler_Menu();
		switch (saler_op)
		{
		case 1: {//1.发布商品 
			Release_Goods();
			clear_screen();
			break;
		}
		case 2: {//2.查看我的发布
			admin.Show_A_Goods_list(this->My_Sale_Goods_list);
			clear_screen();
			break;
		}
		case 3: {//3.修改我的发布 
			Modify_My_goods();
			clear_screen();
			break;
		}
		case 4: {//4.下架我的发布 
			admin.Off_shelf_A_goods(this->My_Sale_Goods_list);
			clear_screen();
			break;
		}
		case 5: {//5.查看历史订单 
			admin.Show_A_Bill_list(My_Sale_Bill_list);
			clear_screen();
			break;
		}
		case 6: {//6.返回用户主界面
			clear_screen();
			return;
		}
		}
	}
}

void User::Init_My_goodslist() {
	My_Sale_Goods_list.clear();
	for (int i = 0; i < (int)admin.goods_list.size(); i++) {
		if (admin.goods_list[i].Saler_ID == this->id) {
			My_Sale_Goods_list.push_back(admin.goods_list[i]);
		}
	}
}
void User::Init_My_billslist() {
	//初始化卖家订单
	My_Buy_Bill_list.clear();
	My_Sale_Bill_list.clear();
	for (int i = 0; i < (int)admin.bill_list.size(); i++) {
		if (admin.bill_list[i].Saler_ID == this->id) {
			My_Sale_Bill_list.push_back(admin.bill_list[i]);
		}
	}
	//初始化买家订单
	for (int i = 0; i < (int)admin.bill_list.size(); i++) {
		if (admin.bill_list[i].Buyer_ID == this->id) {
			My_Buy_Bill_list.push_back(admin.bill_list[i]);
		}
	}
}

void User::Release_Goods() {
	Goods good;
	good.id = to_string(admin.goods_list.size());
	while ((int)good.id.size() < 5) {
		good.id = '0' + good.id;
	}
	good.id = 'M' + good.id;

	good.Saler_ID = this->id;

	cout << "请输入商品名称:";
	cin >> good.name;
	cout << "请输入商品价格:";
	cin >> good.price;
	cout << "请输入商品描述:";
	cin >> good.description;
	cin.ignore(100, '\n');//清除输入缓冲区,以防描述里面带空格
	cout << endl;
	cout << endl;
	good.state = "On_Shelf";
	cout << "请确认发布的商品信息无误!" << endl;
	Print_A_Goods(good);
	cout << endl;
	cout << endl;
	cout << "您确认要发布该商品吗(y/n): ";
	char i;
	cin >> i;
	if (i == 'y') {
		cout << "商品发布成功!" << endl;	
		good.state = "On_Shelf";
		good.time = admin.Get_time();//暂时这么处理
		admin.Add_Goods(good);//写入所有商品列表
		My_Sale_Goods_list.push_back(good);//写入该用户的商品列表
		return;
	}
	else
	{
		cout << "商品发布失败!" << endl;
		return;
	}
}

void User::Show_A_goods_list(vector<Goods>&list)
{
	for (int i = 0; i < (int)list.size(); i++) {
		cout << list[i].id << " " << My_Sale_Goods_list[i].name << " "
			<< fixed << setprecision(1) << list[i].price << " " << list[i].time << " "
			<< list[i].Saler_ID << " " << list[i].state << endl;
	}
}

void User::Print_A_Goods(Goods &good) {
	cout << "*************" << endl;
	cout << "商品名称: " << good.name << endl;
	cout << "商品金额: " << good.price << endl;
	cout << "商品描述: " << good.description << endl;
	cout << "商品状态: " << good.state << endl;
	cout << "*************" << endl;
}
void User::Print_A_User(User & user)
{
	cout << "*************" << endl;
	cout << "用户名: " << user.name << endl;
	cout << "联系方式: " << user.phone << endl;
	cout << "地址: " << user.addr << endl;
	cout << "钱包余额: " << user.money << endl;
	cout << "vaild: " << user.valid << endl;
	cout << "*************" << endl;
}



void User::Modify_My_goods()
{
	Show_A_goods_list(My_Sale_Goods_list);
	Goods temp;
	//string id_temp;
	cout << "**************" << endl;
	cout << "请输入修改商品的ID:";
	cin >> temp.id;
	///////////////查找是否存在,并返回对应的下标////////////////
	vector<Goods>::iterator it = find(My_Sale_Goods_list.begin(), My_Sale_Goods_list.end(), temp);
	
	if (it != My_Sale_Goods_list.end()) {//商品存在
		Goods temp = *it;
		cout << "请输入修改商品属性(1.价格 2.描述 3.状态): ";
		int op = 0;
		cin >> op;
	while (true)
		{
			if (op == 1) {
				cout << "请输入修改后的价格: ";
				cin >> temp.price;
				cout << "请确认修改后的信息!" << endl;
				Print_A_Goods(temp);
				cout << "确认修改(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "修改成功!" << endl;
					return;
				}
				else
				{
					cout << "修改失败!" << endl;
					return;
				}
			}
			else if (op == 2) {
				cout << "请输入修改后的描述: ";
				cin >> temp.description;
				cout << "请确认修改后的信息!" << endl;
				Print_A_Goods(temp);
				cout << "确认修改(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "修改成功!" << endl;
					return;
				}
				else
				{
					cout << "修改失败!" << endl;
					return;
				}
			}
			else if (op == 3) {
				cout << "请输入修改后的状态(1:On_Shelf others:Off_Shelf) ";
				int shelf = 0;
				cin >> shelf;
				if (shelf == 1) {
					temp.state="On_Shelf";
				}
				else {
					temp.state="Off_Shelf";
				}
				cout << "请确认修改后的信息!" << endl;
				Print_A_Goods(temp);
				cout << "确认修改(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "修改成功!" << endl;
					return;
				}
				else
				{
					cout << "修改失败!" << endl;
					return;
				}
			}
			else {
				cout << "请正确输入: ";
				cin >> op;
				break;
			}
		}
	}
}

void User::Modify_User_Info()
{
	Print_A_User(*this);
	cout << "请选择修改的属性:(1.用户名 2.联系方式 3.地址)";
	string to_change;
	int op = 0;
	cin >> op;
	while (true)
	{
		if (op == 1) {
			cout << "请输入修改后的名称: ";
			cin >> to_change;
			this->name = to_change;
			cout << "请确认修改后的信息!" << endl;
			Print_A_User(*this);
			cout << "确认修改(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "修改成功!" << endl;
				return;
			}
			else
			{
				cout << "修改失败!" << endl;
				return;
			}
		}
		else if (op == 2) {
			cout << "请输入修改后的联系方式: ";
			cin >> to_change;
			this->phone = to_change;
			cout << "请确认修改后的信息!" << endl;
			Print_A_User(*this);
			cout << "确认修改(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "修改成功!" << endl;
				return;
			}
			else
			{
				cout << "修改失败!" << endl;
				return;
			}
		}
		else if (op == 3) {
			cout << "请输入修改后的地址: ";
			cin >> to_change;
			this->addr = to_change;
			cout << "请确认修改后的信息!" << endl;
			Print_A_User(*this);
			cout << "确认修改(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "修改成功!" << endl;
				return;
			}
			else
			{
				cout << "修改失败!" << endl;
				return;
			}
		}
		else {
			cout << "请正确输入: ";
			cin >> op;
			break;
		}
	}
}


void User::Buy_Goods()
{
	Goods temp;
	cout << "请输入商品ID: ";
	cin >> temp.id;

	vector<Goods>::iterator it = find(admin.goods_list.begin(), admin.goods_list.end(), temp);
	//若在架
	if (it != admin.goods_list.end() && it->state == "On_Shelf") {
		cout << "**************" << endl;
		cout << "交易提醒!" << endl;
		cout << "交易时间: " << admin.Get_time() << endl;
		cout << "交易金额: " << it->price << endl;
		cout << "交易状态: ";
		//若钱够
		if (this->money >= it->price) {
			//商品售出
			it->state = "Sold";
			cout << "交易成功" << endl;
			//扣钱
			this->money -= it->price;
			//找到卖家在总表中的位置
			User Saler_temp;
			Saler_temp.id = it->Saler_ID;
			vector<User>::iterator Saler = find(admin.user_list.begin(), admin.user_list.end(), Saler_temp);
			//打钱
			Saler->money += it->price;
			cout << "余额:" << fixed << setprecision(1) << this->money << "元" << endl;
			cout << "**************" << endl;
			//生成订单
			
			admin.Add_Biils(*this, *Saler, *it);

			admin.Save2File(1);
			admin.Save2File(2);
			admin.Save2File(3);

			return;
		}
		else
		{
			cout << "余额不足!" << endl;
			return;
		}
	}
	else
	{
		cout << "没有该商品!" << endl;
		return;
	}
}

void User::Show_Goods_Description()
{
	Goods temp;
	cout << "请输入您想查看的商品ID: ";
	cin >> temp.id;
	vector<Goods>::iterator it = find(admin.goods_list.begin(), admin.goods_list.end(), temp);
	if (it != admin.goods_list.end() && it->state == "On_Shelf") {
		cout << "****************************" << endl;
		cout << setw(15) << left << "名称: " << setw(15) << left << it->name << endl;
		cout << setw(15) << left << "描述: " << setw(15) << left << it->description << endl;
		cout << setw(15) << left << "上架时间: " << setw(15) << left << it->time << endl;
		cout << setw(15) << left << "卖家ID: " << setw(15) << left << it->Saler_ID << endl;
		cout << setw(15) << left << "商品状态: " << setw(15) << left << it->state << endl;
		cout << "****************************" << endl;
		return;
	}
	else
	{
		cout << "没有该商品!" << endl;
		return;
	}
}

void User::User_info()
{
	clear_screen();

	int user_op = 0;
	while (true) {
		user_op = Interface::User_Info_Menu();
		switch (user_op)
		{
		case 1: {//1.返回用户主界面
			clear_screen();
			return;
		}
		case 2: {//2.修改信息
			Modify_User_Info();
			clear_screen();
			break;
		}
		case 3: {//3.查看信息
			Print_A_User(*this);
			clear_screen();
			break;
		}
		case 4: {//4.充值
			Recharge();
			clear_screen();
			break;
		}
		}
	}
}

void User::Recharge()
{
	Print_A_User(*this);
	cout << "请输入需要充值的金额:";
	double charge = 0;
	cin >> charge;
	if (charge > 0) {
		cout << "请确认充值金额: " << fixed << setprecision(1) << charge << "(y/n)" ;
		char c;
		cin >> c;
		if (c == 'y') {
			this->money += charge;
			admin.Save2File(1);
			cout << "充值成功!" << endl;
			cout << "当前余额: " << this->money << endl;
			return;
		}
		else
		{
			cout << "充值失败!" << endl;
			return;
		}

	}
}

bool User::operator==(const User U)
{
	if (this->id == U.id) {
		return true;
	}
	else
	{
		return false;
	}
}


