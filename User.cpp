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
		case 1: {//1.�鿴��Ʒ�б�
			admin.Show_User_Goods_on_shelf();
			clear_screen();
			break;
		}
		case 2: {//2.������Ʒ
			Buy_Goods();
			clear_screen();
			break;
		}
		case 3: {//3.������Ʒ
			admin.Search_Goods_list('U');
			clear_screen();
			break;
		}
		case 4: {//4.�鿴��ʷ����
			admin.Show_A_Bill_list(this->My_Buy_Bill_list);
			clear_screen();
			break;
		}
		case 5: {//5.�鿴��Ʒ��ϸ��Ϣ
			Show_Goods_Description();
			clear_screen();
			break;
		}
		case 6: {//6.�����û�������
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
		case 1: {//1.������Ʒ 
			Release_Goods();
			clear_screen();
			break;
		}
		case 2: {//2.�鿴�ҵķ���
			admin.Show_A_Goods_list(this->My_Sale_Goods_list);
			clear_screen();
			break;
		}
		case 3: {//3.�޸��ҵķ��� 
			Modify_My_goods();
			clear_screen();
			break;
		}
		case 4: {//4.�¼��ҵķ��� 
			admin.Off_shelf_A_goods(this->My_Sale_Goods_list);
			clear_screen();
			break;
		}
		case 5: {//5.�鿴��ʷ���� 
			admin.Show_A_Bill_list(My_Sale_Bill_list);
			clear_screen();
			break;
		}
		case 6: {//6.�����û�������
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
	//��ʼ�����Ҷ���
	My_Buy_Bill_list.clear();
	My_Sale_Bill_list.clear();
	for (int i = 0; i < (int)admin.bill_list.size(); i++) {
		if (admin.bill_list[i].Saler_ID == this->id) {
			My_Sale_Bill_list.push_back(admin.bill_list[i]);
		}
	}
	//��ʼ����Ҷ���
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

	cout << "��������Ʒ����:";
	cin >> good.name;
	cout << "��������Ʒ�۸�:";
	cin >> good.price;
	cout << "��������Ʒ����:";
	cin >> good.description;
	cin.ignore(100, '\n');//������뻺����,�Է�����������ո�
	cout << endl;
	cout << endl;
	good.state = "On_Shelf";
	cout << "��ȷ�Ϸ�������Ʒ��Ϣ����!" << endl;
	Print_A_Goods(good);
	cout << endl;
	cout << endl;
	cout << "��ȷ��Ҫ��������Ʒ��(y/n): ";
	char i;
	cin >> i;
	if (i == 'y') {
		cout << "��Ʒ�����ɹ�!" << endl;	
		good.state = "On_Shelf";
		good.time = admin.Get_time();//��ʱ��ô����
		admin.Add_Goods(good);//д��������Ʒ�б�
		My_Sale_Goods_list.push_back(good);//д����û�����Ʒ�б�
		return;
	}
	else
	{
		cout << "��Ʒ����ʧ��!" << endl;
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
	cout << "��Ʒ����: " << good.name << endl;
	cout << "��Ʒ���: " << good.price << endl;
	cout << "��Ʒ����: " << good.description << endl;
	cout << "��Ʒ״̬: " << good.state << endl;
	cout << "*************" << endl;
}
void User::Print_A_User(User & user)
{
	cout << "*************" << endl;
	cout << "�û���: " << user.name << endl;
	cout << "��ϵ��ʽ: " << user.phone << endl;
	cout << "��ַ: " << user.addr << endl;
	cout << "Ǯ�����: " << user.money << endl;
	cout << "vaild: " << user.valid << endl;
	cout << "*************" << endl;
}



void User::Modify_My_goods()
{
	Show_A_goods_list(My_Sale_Goods_list);
	Goods temp;
	//string id_temp;
	cout << "**************" << endl;
	cout << "�������޸���Ʒ��ID:";
	cin >> temp.id;
	///////////////�����Ƿ����,�����ض�Ӧ���±�////////////////
	vector<Goods>::iterator it = find(My_Sale_Goods_list.begin(), My_Sale_Goods_list.end(), temp);
	
	if (it != My_Sale_Goods_list.end()) {//��Ʒ����
		Goods temp = *it;
		cout << "�������޸���Ʒ����(1.�۸� 2.���� 3.״̬): ";
		int op = 0;
		cin >> op;
	while (true)
		{
			if (op == 1) {
				cout << "�������޸ĺ�ļ۸�: ";
				cin >> temp.price;
				cout << "��ȷ���޸ĺ����Ϣ!" << endl;
				Print_A_Goods(temp);
				cout << "ȷ���޸�(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "�޸ĳɹ�!" << endl;
					return;
				}
				else
				{
					cout << "�޸�ʧ��!" << endl;
					return;
				}
			}
			else if (op == 2) {
				cout << "�������޸ĺ������: ";
				cin >> temp.description;
				cout << "��ȷ���޸ĺ����Ϣ!" << endl;
				Print_A_Goods(temp);
				cout << "ȷ���޸�(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "�޸ĳɹ�!" << endl;
					return;
				}
				else
				{
					cout << "�޸�ʧ��!" << endl;
					return;
				}
			}
			else if (op == 3) {
				cout << "�������޸ĺ��״̬(1:On_Shelf others:Off_Shelf) ";
				int shelf = 0;
				cin >> shelf;
				if (shelf == 1) {
					temp.state="On_Shelf";
				}
				else {
					temp.state="Off_Shelf";
				}
				cout << "��ȷ���޸ĺ����Ϣ!" << endl;
				Print_A_Goods(temp);
				cout << "ȷ���޸�(y/n):";
				char c;
				cin >> c;
				if (c == 'y') {
					*it = temp;
					admin.Modify_Goods(My_Sale_Goods_list, temp);
					admin.Modify_Goods(admin.goods_list, temp);
					cout << "�޸ĳɹ�!" << endl;
					return;
				}
				else
				{
					cout << "�޸�ʧ��!" << endl;
					return;
				}
			}
			else {
				cout << "����ȷ����: ";
				cin >> op;
				break;
			}
		}
	}
}

void User::Modify_User_Info()
{
	Print_A_User(*this);
	cout << "��ѡ���޸ĵ�����:(1.�û��� 2.��ϵ��ʽ 3.��ַ)";
	string to_change;
	int op = 0;
	cin >> op;
	while (true)
	{
		if (op == 1) {
			cout << "�������޸ĺ������: ";
			cin >> to_change;
			this->name = to_change;
			cout << "��ȷ���޸ĺ����Ϣ!" << endl;
			Print_A_User(*this);
			cout << "ȷ���޸�(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "�޸ĳɹ�!" << endl;
				return;
			}
			else
			{
				cout << "�޸�ʧ��!" << endl;
				return;
			}
		}
		else if (op == 2) {
			cout << "�������޸ĺ����ϵ��ʽ: ";
			cin >> to_change;
			this->phone = to_change;
			cout << "��ȷ���޸ĺ����Ϣ!" << endl;
			Print_A_User(*this);
			cout << "ȷ���޸�(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "�޸ĳɹ�!" << endl;
				return;
			}
			else
			{
				cout << "�޸�ʧ��!" << endl;
				return;
			}
		}
		else if (op == 3) {
			cout << "�������޸ĺ�ĵ�ַ: ";
			cin >> to_change;
			this->addr = to_change;
			cout << "��ȷ���޸ĺ����Ϣ!" << endl;
			Print_A_User(*this);
			cout << "ȷ���޸�(y/n):";
			char c;
			cin >> c;
			if (c == 'y') {
				admin.Save2File(1);
				cout << "�޸ĳɹ�!" << endl;
				return;
			}
			else
			{
				cout << "�޸�ʧ��!" << endl;
				return;
			}
		}
		else {
			cout << "����ȷ����: ";
			cin >> op;
			break;
		}
	}
}


void User::Buy_Goods()
{
	Goods temp;
	cout << "��������ƷID: ";
	cin >> temp.id;

	vector<Goods>::iterator it = find(admin.goods_list.begin(), admin.goods_list.end(), temp);
	//���ڼ�
	if (it != admin.goods_list.end() && it->state == "On_Shelf") {
		cout << "**************" << endl;
		cout << "��������!" << endl;
		cout << "����ʱ��: " << admin.Get_time() << endl;
		cout << "���׽��: " << it->price << endl;
		cout << "����״̬: ";
		//��Ǯ��
		if (this->money >= it->price) {
			//��Ʒ�۳�
			it->state = "Sold";
			cout << "���׳ɹ�" << endl;
			//��Ǯ
			this->money -= it->price;
			//�ҵ��������ܱ��е�λ��
			User Saler_temp;
			Saler_temp.id = it->Saler_ID;
			vector<User>::iterator Saler = find(admin.user_list.begin(), admin.user_list.end(), Saler_temp);
			//��Ǯ
			Saler->money += it->price;
			cout << "���:" << fixed << setprecision(1) << this->money << "Ԫ" << endl;
			cout << "**************" << endl;
			//���ɶ���
			
			admin.Add_Biils(*this, *Saler, *it);

			admin.Save2File(1);
			admin.Save2File(2);
			admin.Save2File(3);

			return;
		}
		else
		{
			cout << "����!" << endl;
			return;
		}
	}
	else
	{
		cout << "û�и���Ʒ!" << endl;
		return;
	}
}

void User::Show_Goods_Description()
{
	Goods temp;
	cout << "����������鿴����ƷID: ";
	cin >> temp.id;
	vector<Goods>::iterator it = find(admin.goods_list.begin(), admin.goods_list.end(), temp);
	if (it != admin.goods_list.end() && it->state == "On_Shelf") {
		cout << "****************************" << endl;
		cout << setw(15) << left << "����: " << setw(15) << left << it->name << endl;
		cout << setw(15) << left << "����: " << setw(15) << left << it->description << endl;
		cout << setw(15) << left << "�ϼ�ʱ��: " << setw(15) << left << it->time << endl;
		cout << setw(15) << left << "����ID: " << setw(15) << left << it->Saler_ID << endl;
		cout << setw(15) << left << "��Ʒ״̬: " << setw(15) << left << it->state << endl;
		cout << "****************************" << endl;
		return;
	}
	else
	{
		cout << "û�и���Ʒ!" << endl;
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
		case 1: {//1.�����û�������
			clear_screen();
			return;
		}
		case 2: {//2.�޸���Ϣ
			Modify_User_Info();
			clear_screen();
			break;
		}
		case 3: {//3.�鿴��Ϣ
			Print_A_User(*this);
			clear_screen();
			break;
		}
		case 4: {//4.��ֵ
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
	cout << "��������Ҫ��ֵ�Ľ��:";
	double charge = 0;
	cin >> charge;
	if (charge > 0) {
		cout << "��ȷ�ϳ�ֵ���: " << fixed << setprecision(1) << charge << "(y/n)" ;
		char c;
		cin >> c;
		if (c == 'y') {
			this->money += charge;
			admin.Save2File(1);
			cout << "��ֵ�ɹ�!" << endl;
			cout << "��ǰ���: " << this->money << endl;
			return;
		}
		else
		{
			cout << "��ֵʧ��!" << endl;
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


