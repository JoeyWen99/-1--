#include "Administrator.h"
#include "User.h"
extern Administrator admin;


Administrator::Administrator()
{
	admin_name = "admin";
	admin_password = "123456";
	Goods_Init();
	Bills_Init();
	Users_Init();
}
Administrator::~Administrator()
{

}


void Administrator::Save2File(int num)//将三个总表中的信息,写入文件
{
	{
		switch (num)
		{
		case 1: {
			ofstream ofs;
			ofs.open(USER_FILE, ios::out);//写用户列表文件
			for (int i = 0; i < (int)user_list.size(); i++) {
				ofs << user_list[i].id << " " << user_list[i].name << " "
					<< user_list[i].password << " " << user_list[i].phone << " "
					<< user_list[i].addr << " " << fixed << setprecision(1) << user_list[i].money << " "
					<< user_list[i].valid << endl;
			}
			ofs.close();
			return;
		}
		case 2: {
			ofstream ofs;
			ofs.open(GOODS_FILE, ios::out);//写商品列表文件
			for (int i = 0; i < (int)goods_list.size(); i++) {
				ofs << goods_list[i].id << " " << goods_list[i].name << " "
					<< fixed << setprecision(1) << goods_list[i].price << " " <<goods_list[i].description<<" "
					<< goods_list[i].Saler_ID << " " << goods_list[i].time << " " << goods_list[i].state << " " << (int)goods_list[i].mess_board.size() << endl;
				for (int j = 0; j < (int)goods_list[i].mess_board.size(); j++) {
					ofs << goods_list[i].mess_board[j] << " ";
				}
			}
			ofs.close();
			return;
		}
		case 3: {
			ofstream ofs;
			ofs.open(BILL_FILE, ios::out);//写订单列表文件
			for (int i = 0; i < (int)bill_list.size(); i++) {
				ofs << bill_list[i].Bill_ID << " " << bill_list[i].Goods_ID << " "
					<< fixed << setprecision(1) << bill_list[i].price << " " << bill_list[i].time<<" "
					<< bill_list[i].Buyer_ID << " " << bill_list[i].Saler_ID << endl;
			}
			ofs.close();
			return;

			return;
		}
		}

	}
}

void Administrator::Users_Init()
{
	ifstream ifs;
	ifs.open(USER_FILE, ios::in);
	//1.没有用户列表文件
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.用户列表文件不为空
	int i = 0;
	User temp;
	while (ifs >> temp.id && ifs >> temp.name && ifs >> temp.password && ifs >> temp.phone && ifs >> temp.addr && ifs >> temp.money&&ifs >> temp.valid) {
		temp.Init_My_goodslist();//初始化属于该用户的商品列表
		temp.Init_My_billslist();//初始化属于该用户的账单列表
		user_list.push_back(temp);
	}

	ifs.close();
}

void Administrator::Goods_Init()
{
	ifstream ifs;
	ifs.open(GOODS_FILE, ios::in);
	//1.没有用户列表文件
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.用户列表文件不为空
	int i = 0;
	Goods temp;
	while (ifs >> temp.id && ifs >> temp.name && ifs >>
		temp.price && ifs >> temp.description && ifs >>
		temp.Saler_ID && ifs >> temp.time && ifs >> temp.state && ifs >> temp.num_of_mess)//8项数据 
	{
		for (int i = 0; i < temp.num_of_mess; i++) {
			string mess;
			ifs >> mess;
			temp.mess_board.push_back(mess);
		}
		goods_list.push_back(temp);
		temp.mess_board.clear();
	}

	ifs.close();
}

void Administrator::Bills_Init()
{
	ifstream ifs;
	ifs.open(BILL_FILE, ios::in);
	//1.没有账单列表文件
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.账单列表文件不为空
	int i = 0;
	Bill temp;
	while (ifs >> temp.Bill_ID && ifs >> temp.Goods_ID && ifs >>
		temp.price && ifs >> temp.time && ifs >>
		temp.Buyer_ID && ifs >> temp.Saler_ID)//6项数据 
	{
		bill_list.push_back(temp);
	}

	ifs.close();
}

void Administrator::Show_A_Goods_list(vector<Goods>& list)
{
	cout << setw(15) << left << "ID" << setw(15) << left << "名称"
		<< setw(15) << left << "价格" << setw(15) << left << "上架时间"
		<< setw(15) << left << "卖家ID" << setw(15) << left << "商品状态" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].id<< setw(15) << left << list[i].name
			<< setw(15) << left << fixed << setprecision(1) << list[i].price << setw(15) << left << list[i].time
			<< setw(15) << left << list[i].Saler_ID << setw(15) << left << list[i].state << endl;
	}
}

void Administrator::Show_A_Bill_list(vector<Bill>& list)
{
	cout << setw(15) << left << "ID" << setw(15) << left << "名称"
		<< setw(15) << left << "价格" << setw(15) << left << "成交时间"
		<< setw(15) << left << "买家ID" << setw(15) << left << "卖家ID" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].Bill_ID<< setw(15) << left << list[i].Goods_ID
			<< setw(15) << left << fixed << setprecision(1) << list[i].price << setw(15) << left << list[i].time
			<< setw(15) << left << list[i].Buyer_ID << setw(15) << left << list[i].Saler_ID << endl;
	}
}

void Administrator::Show_A_Users_list(vector<User>& list)

{
	cout << setw(15) << left << "用户ID" << setw(15) << left << "用户名"
		<< setw(15) << left << "联系方式" << setw(15) << left << "地址"
		<< setw(15) << left << "钱包余额" << setw(15) << left << "valid" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].id<< setw(15) << left << list[i].name
			<< setw(15) << left << list[i].phone << setw(15) << left << list[i].addr
			<< setw(15) << left << fixed << setprecision(1) << list[i].money << setw(15) << left << list[i].valid << endl;
	}
}



void Administrator::User_register() //注册新用户,加入用户总表,并更新用户文件
{
	User *temp = new User;
	temp->id=to_string(admin.user_list.size());
	while ((int)temp->id.size() < 5) {
		temp->id = '0' + temp->id;
	}
	temp->id = 'U' + temp->id;
	cout << "请输入用户名: ";
	cin >> temp->name;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << "请输入用户密码: ";
	cin >> temp->password;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << "请输入手机联系方式:";
	cin >> temp->phone;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << "请输入地址:";
	cin >> temp->addr;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << "请输入充值金额:";
	cin >> temp->money;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 

	temp->valid = true;
	user_list.push_back(*temp);
	Save2File(1);
	cout << endl << endl;
	cout << "******注册成功!******" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "请牢记你的唯一登录ID: " << temp->id << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "******将返回主界面菜单******" << endl;
	cout << endl << endl;
	delete temp;
	clear_screen();
}
bool Administrator::Modify_Goods(vector<Goods>&list, Goods &good) //传入一个商品的,查找总表中是否存在该商品,若存在则修改其信息,并更新文件,否则返回0
{
	vector<Goods>::iterator it = find(list.begin(), list.end(), good);
	if (it != list.end()) {//修改并保存到文件中
		*it = good;
		Save2File(2);
		return 1;
	}
	else {
		return 0;
	}
}
void Administrator::Invalid_User()
{
	cout << "请输入要删除的用户ID: ";
	User to_Invaild;
	cin >> to_Invaild.id;

	vector<User>::iterator it = find(user_list.begin(), user_list.end(), to_Invaild);
	if (it != user_list.end()) {

		cout << "确认要删除该用户吗: " << endl;
		it->Print_A_User(*it);

		char ch;
		cout << "请选择(y/n): ";
		cin >> ch;
		if (ch == 'y'){
			it->valid = false;
			cout << endl << "删除成功!" << endl << endl;
			it->Print_A_User(*it);
			Off_shelf_User_list(*it);
			Save2File(1);
			Save2File(2);
		}
		else
		{
			cout << "取消删除!" << endl;
		}

	}
	else
	{
		cout << "输入的ID不存在!" << endl;
	}
}
void Administrator::Search_Goods_list(char caller)
{
	cout << "请输入商品名称: ";
	string str_P;
	cin >> str_P;
	int *next = new int[str_P.size()];

	vector<Goods> found_goods_list_4_admin;//用来保存找到的
	vector<Goods> found_goods_list_4_user;
	Get_next(str_P,next);

	for (int i = 0; i < (int)goods_list.size(); i++) {
		if (kmp(goods_list[i].name, str_P, 0, next) != -1) {
			if (goods_list[i].state == "On_Shelf") {
				found_goods_list_4_user.push_back(goods_list[i]);
			}
			found_goods_list_4_admin.push_back(goods_list[i]);
		}
	}
	if (found_goods_list_4_admin.size() != 0 && caller == 'A')
	{
		Show_A_Goods_list(found_goods_list_4_admin);
	}
	else if (found_goods_list_4_user.size() != 0 && caller == 'U')
	{
		Show_A_Goods_list(found_goods_list_4_user);
	}
	else
	{
		cout << endl << endl << "***************************" << endl;
		cout << "没有找到您想要搜索的商品!即将返回初始界面" << endl;
		cout << "***************************" << endl;
	}

}
void Administrator::Get_next(string & str_P, int *next)
{
	int k = -1;
	next[0] = -1;
	next[1] = 0;
	int j = 2;
	while (j < (int)str_P.size()) {
		k = next[j - 1];
		while (true)
		{
			if (k != -1) {
				if (str_P[j - 1] == str_P[k]) {
					k++;
					next[j] = k;
					j++;
					break;
				}
				else
				{
					k = next[k];
				}
			}
			else if (k == -1)
			{
				k++;
				next[j] = k;
				j++;
				break;
			}
		}
	}
	return;
}
int Administrator::kmp(string & T, string & P, int T_start, int * next)
{
	int P_idx = 0;
	int T_idx= T_start;

	while (P_idx < (int)P.size() && T_idx < (int)T.size())
	{
		if (P_idx != -1) {
			if (T[T_idx] == P[P_idx]) {
				P_idx++;
				T_idx++;
			}
			else
			{
				P_idx = next[P_idx];
			}
		}
		else if (P_idx == -1)
		{
			P_idx++;
			T_idx++;
		}
	}
	if (P_idx < (int)P.size()) {
		return -1;
	}
	else if (T_idx < (int)T.size())
	{
		return(T_idx - (int)P.size());

	}

	return 0;
}

void Administrator::Add_Goods(Goods &good)//向商品总表中加入商品,并更新文件
{
	goods_list.push_back(good);
	Save2File(2);
}

void Administrator::Add_Biils(User &Buyer,User &Saler,Goods &good)
{
	Bill *temp = new Bill;
	//生成订单号
	temp->Bill_ID=to_string(admin.bill_list.size());
	while ((int)temp->Bill_ID.size() < 5) {
		temp->Bill_ID = '0' + temp->Bill_ID;
	}
	temp->Bill_ID = 'T' + temp->Bill_ID;
	
	temp->Buyer_ID = Buyer.id;
	temp->Saler_ID = Saler.id;
	temp->Goods_ID = good.id;
	temp->time = admin.Get_time();
	temp->price = good.price;
	//加入总订单列表
	admin.bill_list.push_back(*temp);
	//加入买家订单
	Buyer.My_Buy_Bill_list.push_back(*temp);
	//加入卖家订单
	Saler.My_Sale_Bill_list.push_back(*temp);
	delete temp;
}

string Administrator::Get_time()
{
	string now;

	time_t timer;
	struct tm ptm_info;

	time(&timer);
	//timer 存取结果的时间指针变量，类型为time_t，
	//指针变量可以为null。如果timer指针非null，则time()函数返回值变量与timer指针一样，
	//都指向同一个内存地址；否则如果timer指针为null，则time()函数返回一个time_t变量时间。

	localtime_s(&ptm_info,&timer);
	//localtime()将日历时间转换为本地时间，从1970年起始的时间戳转换为1900年起始的时间数据结构

	now = to_string(ptm_info.tm_year + 1900) + '-' + to_string(ptm_info.tm_mon + 1)+'-'+to_string(ptm_info.tm_mday);

	return now;
}

void Administrator::Off_shelf_User_list(User & it)
{
	//先建立当前的出售表格
	it.Init_My_goodslist();
	//找到当前在售的所有商品
	for (int i = 0; i < (int)it.My_Sale_Goods_list.size(); i++) {
		if (it.My_Sale_Goods_list[i].state == "On_Shelf") {
			//在总表中找到要下架的商品
			vector<Goods>::iterator g_2_off = find(admin.goods_list.begin(), admin.goods_list.end(), it.My_Sale_Goods_list[i]);
			g_2_off->state = "Off_Shelf";
		}
	}
}

void Administrator::User_Login()
{
	string in_ID;
	string in_password;

	cout << "请输入用户ID: ";
	cin >> in_ID;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 

	cout << "请输入密码: ";
	cin >> in_password;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 

	int idx = -1;
	idx = Is_User_Exist(in_ID, in_password);

	if (idx != -1) {
		cout << "******登陆成功!按任意键进入用户选项菜单******" << endl;
		clear_screen();
		//登陆成功,进入第二层管理员菜单界面
		while (true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);
			cout << "当前登录ID: " << user_list[idx].id << " " << "昵称:" << user_list[idx].name << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			int user_op = 0;
			user_op = Interface::User_Menu();
			switch (user_op)
			{
			case 1://"1.注销登录
				User_Logout();
				//clear_screen();
				return;
			case 2://2.我是买家
				user_list[idx].Im_Buyer();
				break;
			case 3://3.我是卖家
				user_list[idx].Im_Saler();
				break;
			case 4://4.个人信息管理
				user_list[idx].User_info();
				break;
			}
		}
	}
	else
	{
		cout << endl;
		cout << endl;
		cout << "*****************" << endl;
		cout << "输入的账户不存在或密码错误!" << endl;
		cout << "即将返回开始界面!请重新登录!" << endl;
		cout << "*****************" << endl;
		cout << endl;
		cout << endl;
		return;
	}

}
int Administrator::Is_User_Exist(string nm,string ps)
{
	for (int i = 0; i < (int)user_list.size(); i++) {
		if (nm == user_list[i].id&&ps == user_list[i].password&&user_list[i].valid == 1) {
			return i;
		}
	}
	return -1;
}


void Administrator::User_Logout() {
	cout << endl;
	cout << "*******已注销当前登录,即将返回开始菜单*******" << endl;
	cout << endl;
}


void Administrator::Admin_Login()//管理员登录
{
	string in_name, in_password;

	cout << "请输入管理员姓名: ";
	cin >> in_name;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << "请输入密码: ";
	cin >> in_password;
	cin.ignore(100, '\n');//清除输入缓冲区的当前行 
	cout << endl;
	cout << endl;

	if (in_name == admin_name && in_password == admin_password) {
		cout << "****** 登陆成功!按任意键进入用户选项菜单 ******" << endl;
		clear_screen();
		
		//登陆成功,进入第二层管理员菜单界面
		while (true) {
			int admin_op = 0;
			admin_op = Interface::Adimin_Menu();
			switch (admin_op)
			{
			case 1://"1.查看所有商品
				Show_A_Goods_list(goods_list);
				clear_screen();
				break;
			case 2://2.搜索商品
				Search_Goods_list('A');
				clear_screen();
				break;
			case 3://3.查看所有订单 
				Show_A_Bill_list(bill_list);
				clear_screen();
				break;
			case 4://4.查看所有用户
				Show_A_Users_list(user_list);
				clear_screen();
				break;
			case 5://5.删除用户
				Invalid_User();
				clear_screen();
				break;
			case 6://6.下架商品 
				Off_shelf_A_goods(goods_list);
				clear_screen();
				break;
			case 7://7.注销
				Admin_Logout();
				clear_screen();
				return;
			}
		}
	}
	else
	{
		cout << "密码错误" << endl;
		clear_screen();
		return;
	}
}
void Administrator::Admin_Logout()
{
	cout << "已注销当前登录,即将返回开始菜单" << endl;
}

void Administrator::Show_User_Goods_on_shelf()
{
	cout << "*******************************************************************" << endl;
	cout << setw(15) << left << "ID" << setw(15) << left << "名称" << setw(15) << left << "价格" << setw(15) << left << "上架时间" << setw(15) << left << "卖家ID" << endl;
	for (int i = 0; i <(int)goods_list.size(); i++) {
		if (goods_list[i].state == "On_Shelf") {
			Cout_A_Goods_for_Buyer(goods_list[i]);
		}
	}
	cout << "*******************************************************************" << endl;
}

void Administrator::Cout_A_Goods_for_Buyer(Goods & good)
{
	cout << setw(15) << left << good.id  << setw(15) << left << good.name
		<< setw(15) << left << fixed << setprecision(1) << good.price << setw(15) << left << good.time
		<< setw(15) << left << good.Saler_ID << endl;
}

void Administrator::Print_A_Goods(Goods &good) {
	cout << "*************" << endl;
	cout << "商品名称: " << good.name << endl;
	cout << "商品金额: " << good.price << endl;
	cout << "商品描述: " << good.description << endl;
	cout << "商品状态: " << good.state << endl;
	cout << "*************" << endl;
}
void Administrator::Off_shelf_A_goods(vector<Goods>&list)
{
	admin.Show_A_Goods_list(list);
	Goods temp;
	//string id_temp;
	cout << "**************" << endl;
	cout << "请输入下加商品的ID:";
	cin >> temp.id;
	///////////////查找是否存在,并返回对应的下标////////////////
	vector<Goods>::iterator it = find(list.begin(), list.end(), temp);

	if (it != list.end()) {//商品存在
		Goods temp = *it;
		temp.state = "Off_Shelf";
		cout << "请确认修改后的信息!" << endl;
		admin.Print_A_Goods(temp);
		cout << "确认修改(y/n):";
		char c;
		cin >> c;
		if (c == 'y') {
			*it = temp;
			admin.Modify_Goods(list,temp);//修改传入的商品表格
			admin.Modify_Goods(admin.goods_list, temp);//修改总的商品表格
			cout << endl << endl << "修改成功!" << endl;
			//admin.Save2File(2);
			return;
		}
		else
		{
			cout << endl << endl << "修改失败!" << endl;
			return;
		}
	}
	else
	{
		cout << endl << endl << "商品不存在" << endl;
		return;
	}
}

