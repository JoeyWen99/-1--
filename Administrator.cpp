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


void Administrator::Save2File(int num)//�������ܱ��е���Ϣ,д���ļ�
{
	{
		switch (num)
		{
		case 1: {
			ofstream ofs;
			ofs.open(USER_FILE, ios::out);//д�û��б��ļ�
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
			ofs.open(GOODS_FILE, ios::out);//д��Ʒ�б��ļ�
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
			ofs.open(BILL_FILE, ios::out);//д�����б��ļ�
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
	//1.û���û��б��ļ�
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.�û��б��ļ���Ϊ��
	int i = 0;
	User temp;
	while (ifs >> temp.id && ifs >> temp.name && ifs >> temp.password && ifs >> temp.phone && ifs >> temp.addr && ifs >> temp.money&&ifs >> temp.valid) {
		temp.Init_My_goodslist();//��ʼ�����ڸ��û�����Ʒ�б�
		temp.Init_My_billslist();//��ʼ�����ڸ��û����˵��б�
		user_list.push_back(temp);
	}

	ifs.close();
}

void Administrator::Goods_Init()
{
	ifstream ifs;
	ifs.open(GOODS_FILE, ios::in);
	//1.û���û��б��ļ�
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.�û��б��ļ���Ϊ��
	int i = 0;
	Goods temp;
	while (ifs >> temp.id && ifs >> temp.name && ifs >>
		temp.price && ifs >> temp.description && ifs >>
		temp.Saler_ID && ifs >> temp.time && ifs >> temp.state && ifs >> temp.num_of_mess)//8������ 
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
	//1.û���˵��б��ļ�
	if (!ifs.is_open()) {
		ifs.close();
		return;
	}
	//2.�˵��б��ļ���Ϊ��
	int i = 0;
	Bill temp;
	while (ifs >> temp.Bill_ID && ifs >> temp.Goods_ID && ifs >>
		temp.price && ifs >> temp.time && ifs >>
		temp.Buyer_ID && ifs >> temp.Saler_ID)//6������ 
	{
		bill_list.push_back(temp);
	}

	ifs.close();
}

void Administrator::Show_A_Goods_list(vector<Goods>& list)
{
	cout << setw(15) << left << "ID" << setw(15) << left << "����"
		<< setw(15) << left << "�۸�" << setw(15) << left << "�ϼ�ʱ��"
		<< setw(15) << left << "����ID" << setw(15) << left << "��Ʒ״̬" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].id<< setw(15) << left << list[i].name
			<< setw(15) << left << fixed << setprecision(1) << list[i].price << setw(15) << left << list[i].time
			<< setw(15) << left << list[i].Saler_ID << setw(15) << left << list[i].state << endl;
	}
}

void Administrator::Show_A_Bill_list(vector<Bill>& list)
{
	cout << setw(15) << left << "ID" << setw(15) << left << "����"
		<< setw(15) << left << "�۸�" << setw(15) << left << "�ɽ�ʱ��"
		<< setw(15) << left << "���ID" << setw(15) << left << "����ID" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].Bill_ID<< setw(15) << left << list[i].Goods_ID
			<< setw(15) << left << fixed << setprecision(1) << list[i].price << setw(15) << left << list[i].time
			<< setw(15) << left << list[i].Buyer_ID << setw(15) << left << list[i].Saler_ID << endl;
	}
}

void Administrator::Show_A_Users_list(vector<User>& list)

{
	cout << setw(15) << left << "�û�ID" << setw(15) << left << "�û���"
		<< setw(15) << left << "��ϵ��ʽ" << setw(15) << left << "��ַ"
		<< setw(15) << left << "Ǯ�����" << setw(15) << left << "valid" << endl;
	for (int i = 0; i < (int)list.size(); i++) {
		cout << setw(15) << left << list[i].id<< setw(15) << left << list[i].name
			<< setw(15) << left << list[i].phone << setw(15) << left << list[i].addr
			<< setw(15) << left << fixed << setprecision(1) << list[i].money << setw(15) << left << list[i].valid << endl;
	}
}



void Administrator::User_register() //ע�����û�,�����û��ܱ�,�������û��ļ�
{
	User *temp = new User;
	temp->id=to_string(admin.user_list.size());
	while ((int)temp->id.size() < 5) {
		temp->id = '0' + temp->id;
	}
	temp->id = 'U' + temp->id;
	cout << "�������û���: ";
	cin >> temp->name;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << "�������û�����: ";
	cin >> temp->password;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << "�������ֻ���ϵ��ʽ:";
	cin >> temp->phone;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << "�������ַ:";
	cin >> temp->addr;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << "�������ֵ���:";
	cin >> temp->money;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 

	temp->valid = true;
	user_list.push_back(*temp);
	Save2File(1);
	cout << endl << endl;
	cout << "******ע��ɹ�!******" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "���μ����Ψһ��¼ID: " << temp->id << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "******������������˵�******" << endl;
	cout << endl << endl;
	delete temp;
	clear_screen();
}
bool Administrator::Modify_Goods(vector<Goods>&list, Goods &good) //����һ����Ʒ��,�����ܱ����Ƿ���ڸ���Ʒ,���������޸�����Ϣ,�������ļ�,���򷵻�0
{
	vector<Goods>::iterator it = find(list.begin(), list.end(), good);
	if (it != list.end()) {//�޸Ĳ����浽�ļ���
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
	cout << "������Ҫɾ�����û�ID: ";
	User to_Invaild;
	cin >> to_Invaild.id;

	vector<User>::iterator it = find(user_list.begin(), user_list.end(), to_Invaild);
	if (it != user_list.end()) {

		cout << "ȷ��Ҫɾ�����û���: " << endl;
		it->Print_A_User(*it);

		char ch;
		cout << "��ѡ��(y/n): ";
		cin >> ch;
		if (ch == 'y'){
			it->valid = false;
			cout << endl << "ɾ���ɹ�!" << endl << endl;
			it->Print_A_User(*it);
			Off_shelf_User_list(*it);
			Save2File(1);
			Save2File(2);
		}
		else
		{
			cout << "ȡ��ɾ��!" << endl;
		}

	}
	else
	{
		cout << "�����ID������!" << endl;
	}
}
void Administrator::Search_Goods_list(char caller)
{
	cout << "��������Ʒ����: ";
	string str_P;
	cin >> str_P;
	int *next = new int[str_P.size()];

	vector<Goods> found_goods_list_4_admin;//���������ҵ���
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
		cout << "û���ҵ�����Ҫ��������Ʒ!�������س�ʼ����" << endl;
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

void Administrator::Add_Goods(Goods &good)//����Ʒ�ܱ��м�����Ʒ,�������ļ�
{
	goods_list.push_back(good);
	Save2File(2);
}

void Administrator::Add_Biils(User &Buyer,User &Saler,Goods &good)
{
	Bill *temp = new Bill;
	//���ɶ�����
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
	//�����ܶ����б�
	admin.bill_list.push_back(*temp);
	//������Ҷ���
	Buyer.My_Buy_Bill_list.push_back(*temp);
	//�������Ҷ���
	Saler.My_Sale_Bill_list.push_back(*temp);
	delete temp;
}

string Administrator::Get_time()
{
	string now;

	time_t timer;
	struct tm ptm_info;

	time(&timer);
	//timer ��ȡ�����ʱ��ָ�����������Ϊtime_t��
	//ָ���������Ϊnull�����timerָ���null����time()��������ֵ������timerָ��һ����
	//��ָ��ͬһ���ڴ��ַ���������timerָ��Ϊnull����time()��������һ��time_t����ʱ�䡣

	localtime_s(&ptm_info,&timer);
	//localtime()������ʱ��ת��Ϊ����ʱ�䣬��1970����ʼ��ʱ���ת��Ϊ1900����ʼ��ʱ�����ݽṹ

	now = to_string(ptm_info.tm_year + 1900) + '-' + to_string(ptm_info.tm_mon + 1)+'-'+to_string(ptm_info.tm_mday);

	return now;
}

void Administrator::Off_shelf_User_list(User & it)
{
	//�Ƚ�����ǰ�ĳ��۱��
	it.Init_My_goodslist();
	//�ҵ���ǰ���۵�������Ʒ
	for (int i = 0; i < (int)it.My_Sale_Goods_list.size(); i++) {
		if (it.My_Sale_Goods_list[i].state == "On_Shelf") {
			//���ܱ����ҵ�Ҫ�¼ܵ���Ʒ
			vector<Goods>::iterator g_2_off = find(admin.goods_list.begin(), admin.goods_list.end(), it.My_Sale_Goods_list[i]);
			g_2_off->state = "Off_Shelf";
		}
	}
}

void Administrator::User_Login()
{
	string in_ID;
	string in_password;

	cout << "�������û�ID: ";
	cin >> in_ID;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 

	cout << "����������: ";
	cin >> in_password;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 

	int idx = -1;
	idx = Is_User_Exist(in_ID, in_password);

	if (idx != -1) {
		cout << "******��½�ɹ�!������������û�ѡ��˵�******" << endl;
		clear_screen();
		//��½�ɹ�,����ڶ������Ա�˵�����
		while (true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);
			cout << "��ǰ��¼ID: " << user_list[idx].id << " " << "�ǳ�:" << user_list[idx].name << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			int user_op = 0;
			user_op = Interface::User_Menu();
			switch (user_op)
			{
			case 1://"1.ע����¼
				User_Logout();
				//clear_screen();
				return;
			case 2://2.�������
				user_list[idx].Im_Buyer();
				break;
			case 3://3.��������
				user_list[idx].Im_Saler();
				break;
			case 4://4.������Ϣ����
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
		cout << "������˻������ڻ��������!" << endl;
		cout << "�������ؿ�ʼ����!�����µ�¼!" << endl;
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
	cout << "*******��ע����ǰ��¼,�������ؿ�ʼ�˵�*******" << endl;
	cout << endl;
}


void Administrator::Admin_Login()//����Ա��¼
{
	string in_name, in_password;

	cout << "���������Ա����: ";
	cin >> in_name;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << "����������: ";
	cin >> in_password;
	cin.ignore(100, '\n');//������뻺�����ĵ�ǰ�� 
	cout << endl;
	cout << endl;

	if (in_name == admin_name && in_password == admin_password) {
		cout << "****** ��½�ɹ�!������������û�ѡ��˵� ******" << endl;
		clear_screen();
		
		//��½�ɹ�,����ڶ������Ա�˵�����
		while (true) {
			int admin_op = 0;
			admin_op = Interface::Adimin_Menu();
			switch (admin_op)
			{
			case 1://"1.�鿴������Ʒ
				Show_A_Goods_list(goods_list);
				clear_screen();
				break;
			case 2://2.������Ʒ
				Search_Goods_list('A');
				clear_screen();
				break;
			case 3://3.�鿴���ж��� 
				Show_A_Bill_list(bill_list);
				clear_screen();
				break;
			case 4://4.�鿴�����û�
				Show_A_Users_list(user_list);
				clear_screen();
				break;
			case 5://5.ɾ���û�
				Invalid_User();
				clear_screen();
				break;
			case 6://6.�¼���Ʒ 
				Off_shelf_A_goods(goods_list);
				clear_screen();
				break;
			case 7://7.ע��
				Admin_Logout();
				clear_screen();
				return;
			}
		}
	}
	else
	{
		cout << "�������" << endl;
		clear_screen();
		return;
	}
}
void Administrator::Admin_Logout()
{
	cout << "��ע����ǰ��¼,�������ؿ�ʼ�˵�" << endl;
}

void Administrator::Show_User_Goods_on_shelf()
{
	cout << "*******************************************************************" << endl;
	cout << setw(15) << left << "ID" << setw(15) << left << "����" << setw(15) << left << "�۸�" << setw(15) << left << "�ϼ�ʱ��" << setw(15) << left << "����ID" << endl;
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
	cout << "��Ʒ����: " << good.name << endl;
	cout << "��Ʒ���: " << good.price << endl;
	cout << "��Ʒ����: " << good.description << endl;
	cout << "��Ʒ״̬: " << good.state << endl;
	cout << "*************" << endl;
}
void Administrator::Off_shelf_A_goods(vector<Goods>&list)
{
	admin.Show_A_Goods_list(list);
	Goods temp;
	//string id_temp;
	cout << "**************" << endl;
	cout << "�������¼���Ʒ��ID:";
	cin >> temp.id;
	///////////////�����Ƿ����,�����ض�Ӧ���±�////////////////
	vector<Goods>::iterator it = find(list.begin(), list.end(), temp);

	if (it != list.end()) {//��Ʒ����
		Goods temp = *it;
		temp.state = "Off_Shelf";
		cout << "��ȷ���޸ĺ����Ϣ!" << endl;
		admin.Print_A_Goods(temp);
		cout << "ȷ���޸�(y/n):";
		char c;
		cin >> c;
		if (c == 'y') {
			*it = temp;
			admin.Modify_Goods(list,temp);//�޸Ĵ������Ʒ���
			admin.Modify_Goods(admin.goods_list, temp);//�޸��ܵ���Ʒ���
			cout << endl << endl << "�޸ĳɹ�!" << endl;
			//admin.Save2File(2);
			return;
		}
		else
		{
			cout << endl << endl << "�޸�ʧ��!" << endl;
			return;
		}
	}
	else
	{
		cout << endl << endl << "��Ʒ������" << endl;
		return;
	}
}

