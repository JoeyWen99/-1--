#include "Interface.h"

int Interface::Boot_UI_Menu()//��ʾ��������
{
	int op = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout << "    _/    _/            _/  _/           " << endl;
	cout << "   _/    _/    _/_/    _/  _/    _/_/    " << endl;
	cout << "  _/_/_/_/  _/_/_/_/  _/  _/  _/    _/   " << endl;
	cout << " _/    _/  _/        _/  _/  _/    _/    " << endl;
	cout << "_/    _/    _/_/_/  _/  _/    _/_/    " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "==============================================" << endl;
	cout << "1.�û���¼ 2.�û�ע�� 3.����Ա��¼ 4.�˳�����" << endl;
	cout << "==============================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "������1-4: ";
		cin >> op;
	}
	return op;
}

int Interface::Adimin_Menu()
{
	int op = 0;

	cout << "=========================================================================================" << endl;
	cout << "1.�鿴������Ʒ 2.������Ʒ 3.�鿴���ж��� 4.�鿴�����û� 5.ɾ���û� 6.�¼���Ʒ 7.ע��" << endl;
	cout << "=========================================================================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 7) {
		cout << "������1-7: ";
		cin >> op;
	}
	return op;
}

int Interface::User_Menu()
{
	int op = 0;

	cout << "================================================" << endl;
	cout << "1.ע����¼ 2.������� 3.�������� 4.������Ϣ����" << endl;
	cout << "================================================" << endl;
	cout << endl;
	cout << endl;	
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "������1-4: ";
		cin >> op;
	}
	return op;
}

int Interface::Im_Buyer_Menu()
{
	int op;

	cout << "========================================================================================" << endl;
	cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û�������" << endl;
	cout << "========================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 6) {
		cout << "������1-6: ";
		cin >> op;
	}
	return op;
}
int Interface::Im_Saler_Menu()
{
	int op = 0;

	cout << "======================================================================================" << endl;
	cout << "1.������Ʒ 2.�鿴�ҵķ��� 3.�޸��ҵķ��� 4.�¼��ҵķ��� 5.�鿴��ʷ���� 6.�����û�������" << endl;
	cout << "======================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 6) {
		cout << "������1-6: ";
		cin >> op;
	}
	return op;
}

int Interface::User_Info_Menu()
{
	int op = 0;
	cout << "============================================" << endl;
	cout << "1.�����û������� 2.�޸���Ϣ 3.�鿴��Ϣ 4.��ֵ " << endl;
	cout << "============================================" << endl;
	cout << endl;
	cout << endl;
	cout << "�������: ";
	cin >> op;
	while (op < 1 || op > 4) {
		cout << "������1-4: ";
		cin >> op;
	}
	return op;
}



void Interface::Exit_System() {//�˳�ϵͳ
	cout << "******ϵͳ���˳�******" << endl;
	system("pause");
	exit(0);
}

