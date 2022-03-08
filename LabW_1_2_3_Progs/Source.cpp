#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <malloc.h>
#include <algorithm>
#include <cstddef>
#include <utility>
#include <fstream>

using namespace std;




void firstGeneralTask();
void secondGeneralTask();
void individualTask();
void additionalTask();




int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	while (true) {
		std::cout << "\n\t\t����� �������\n\t1. ������� 1\t2. ������� 2\n\n\t3. �������������� ������� 7 �������\n\n\t4. �������������� �������\n\n\t0. �����\n\n\t";
		int inputNum;
		cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
		case(0): {return 0; }
		case(1): {firstGeneralTask();	break; }
		case(2): {secondGeneralTask();	break; }
		case(3): {individualTask();		break; }
		case(4): {additionalTask();		break; }
		default: {std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... "; char p = _getch(); std::system("cls"); break; }
		}
		std::system("cls");
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region firstGeneralTask

	/*������� ������ ����� ����� �� ���������� ����� (���� ����� ������ � ��������
	���������). ����������� ��� ����� fopen_s() � ��������������� �������.
	������ ����� � ����� � ���������� ��������� � �������. �������� ���, �����������
	�������� ������ ��� ������ � �������� ��������� �������� � ����.
	����� ���������� ����� ������������� ������ � ��������� ��� � ������ ����.*/

	//For Home PC
#define INPUT_FILE_LOCATION		"C:\\Users\\SAS_���\\source\\repos\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\1FisrtGeneralTask\\Input_Massive.txt"
#define OUTPUT_FILE_LOCATION	"C:\\Users\\SAS_���\\source\\repos\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\1FisrtGeneralTask\\Output_Massive.txt"

	//For laptop Samsung
//#define INPUT_FILE_LOCATION	"C:\\Users\\CAMSANG\\source\\repos\\DANTECK-dev\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\1FisrtGeneralTask\\Input_Massive.txt"
//#define OUTPUT_FILE_LOCATION	"C:\\Users\\CAMSANG\\source\\repos\\DANTECK-dev\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\1FisrtGeneralTask\\Output_Massive.txt"


void firstGeneralTask() {

	int* arr;
	int size = 0;

	ifstream inputArr;

	inputArr.open(INPUT_FILE_LOCATION);

	if (!inputArr.eof()) inputArr >> size;
	arr = new int[size];

	if (!inputArr.eof()) {
		cout << "\n\n\tReading Mass: ";
		for (int i = 0; i < size; i++) {
			inputArr >> arr[i];
			cout << arr[i] << ", ";
		}
		inputArr.close();
	}
	else {
		cout << "\n\n\tFile not fonded... ";
		char p = _getch();
		std::system("cls");
		return;
	};

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i; j++) {
			if (arr[j] < arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	ofstream outputArr(OUTPUT_FILE_LOCATION);

	for (int i = 0; i < size; i++) {
		outputArr << arr[i]<<endl;
	}

	cout << "\n\n\tSorter Mass: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}

	std::cout << "\n\n\t������� ����� ������� ��� ������... "; 
	char p = _getch();
	std::system("cls");
	return;

}


#pragma endregion 
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region secondGeneralTask

	/*��� ���� �� ������� ������� ������. ��� ������ � ���� ������ ����������� ������
	<fstream> � ��������������� ������.
	������ ����� � ����� � ���������� ���������. ����� ���� �������� �� ������, � ������
	������ ������ ����� (�������������), ������� � ������� ���� ��������.
	���������� ���������� ������ � ��������� �� ����� � ����������� �� �� ����� � ����
	�������. �������� ������ � ������� ���������, � ������� ������� ���� ���� 4, � ���������
	����.*/

	//For Home PC
#define INPUT_FILE_LOCATION		"C:\\Users\\SAS_���\\source\\repos\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\2SecondGeneralTask\\Input_Studenst.txt"
#define OUTPUT_FILE_LOCATION	"C:\\Users\\SAS_���\\source\\repos\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\2SecondGeneralTask\\Output_Studenst.txt"

	//For laptop Samsung
//#define INPUT_FILE_LOCATION	"C:\\Users\\CAMSANG\\source\\repos\\DANTECK-dev\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\2SecondGeneralTask\\Input_Studenst.txt"
//#define OUTPUT_FILE_LOCATION	"C:\\Users\\CAMSANG\\source\\repos\\DANTECK-dev\\LabW_1_2_3_Progs\\LabW_1_2_3_Progs\\2SecondGeneralTask\\Output_Studenst.txt"


void secondGeneralTask() {
	ifstream inputStudent;
	ofstream outputStudent;
	int *Num = NULL;
	string *Name = NULL;
	string* Surame = NULL;
	string* Patronymic = NULL;
	int *Mark = NULL;
	int size = 0;
	

	while (true) {
		inputStudent.open(INPUT_FILE_LOCATION);
	if (!inputStudent.eof()) {
		inputStudent >> size;
		if (size == 0) {
			cout << "\n\n\t������ � �������� ����� ��� ���� ����� ��� �������... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		Num = new int[size];			
		Name = new string[size];		
		Surame = new string[size];		
		Patronymic = new string[size];	
		Mark = new int[size];			

		for (int i = 0; i < size; i++) {
			Num[i] = { 0 };
			Name[i] = { "None" };
			Surame[i] = { "None" };
			Patronymic[i] = { "None" };
			Mark[i] = { 0 };

			inputStudent >> Num[i];
			inputStudent >> Surame[i];
			inputStudent >> Name[i];
			inputStudent >> Patronymic[i];
			inputStudent >> Mark[i];
		}
		inputStudent.close();
	}
		cout << "\n\t1. ����� � �������\n\t2. ������� �� �������\n\t0. �����\n\n\t";
		int inNum;
		cin >> inNum;
		std::system("cls");
		switch (inNum) {
			case(0): {return; }
			case(1): {
				cout << endl;
				for (int i = 0; i < size; i++) {
					cout	<<"\t" << Num[i]	<< " " << Surame[i] 
							<< " " << Name[i]	<< " " << Patronymic[i] 
							<< " " << Mark[i]	<< endl;
				}
				std::cout << "\n\n\t������� ����� ������� ��� ������... "; 
				char p = _getch(); 
				std::system("cls"); 
				break;
			}
			case(2): {
				cout << "\n\t������� ������: ";
				int inMark;
				cin >> inMark;
				int counter = 0; 
				system("cls");
				if (inMark <= 0 || inMark > 5) {
					cout << "\n\n\t������� �������� ��������... ";
					char p = _getch();
					system("cls");
					break;
				}
				cout << endl;
				outputStudent.open(OUTPUT_FILE_LOCATION);
				for (int i = 0; i < size; i++) {
					if (Mark[i] == inMark) {
						cout			<<"\t" << Num[i]	<< " " << Surame[i] 
										<< " " << Name[i]	<< " " << Patronymic[i] 
										<< " " << Mark[i]	<< endl;
						outputStudent	<< Num[i] << " "	<< Surame[i]
										<< " " << Name[i]	<< " " << Patronymic[i]
										<< " " << Mark[i]	<< endl;
						counter++;
					}
				}
				outputStudent.close();
				if (counter > 0) {
					cout << "\n\t��������� � ����: " << OUTPUT_FILE_LOCATION;
				}
				if (counter == 0) {
					system("cls");
					cout << "\n\t��� �����";
				}
				
				std::cout << "\n\n\t������� ����� ������� ��� ������... ";
				char p = _getch();
				std::system("cls");
				break;
			}
			default: {
				std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... ";
				char p = _getch();
				std::system("cls");
				break; 
			}
		}
		
	}
	std::cout << "\n\n\t������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return;
}


#pragma endregion
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region individualTask


struct person {
	person* next = NULL;
	person* prev = NULL;
	struct {
		string	Surname = { "None" };
		string	Name = { "None" };
		string	Patronymic = { "None" };
		string	Address = { "None" };
		string	PhoneNum = { "None" };
		string	PayDay = { "None" };
		int 	Summ = 0;
	}Data;
};

void fillClients(person* head, person* tail, person* clients);

void addClients(person* head, person* tail, person* clients);
void sortClients(person* head, person* tail, person* clients);
void transformClients(person* head, person* tail, person* clients);
void delClients(person*& head, person*& tail, person*& clients);
void showClients(person* head, person* tail, person* clients);
void searchClients(person* head, person* tail, person* clients);
//void selectionClients	(person* clients, int* counter);


void individualTask() {										//<<<<--------main ��������������� �������

	/*��������� ������������: ���� �������; ���; �������� �����; ����� ��������; �����
	�������. ����������� �������� � ����� ����� �������.
	*/

	/*1) �������� ������ �������� ������� �������� (���� ��� ������);
	2) ���������� ������� ��������;
	3) ��������� �������� ��������� (�������� ����� �������� � ������� ��������, � ���
	������ ���������� �� ����� ��������� ������������� ������);
	4) �������� ��������� �� ������� (����� ���������� �������� ������� ���������
	�������� ���������� �������� � ��������� ���������� ��������� � ������� ��������);
	5) ����� �� ����� ������� �������� � ���� �������. ����� �������� �����������
	�������� �� ����� �������, ��������� � ����� ��������.
	6) ����� � ������� �������� �� ��������� ��������� (�������������� �������� ����
	��������� � ���������� ����� �� ����). �� ���� ��� �����, �� ������ ������������ ������.*/


	person* head = NULL;
	head = new person;
	person* clients = head;
	//int* counter = new int;
	//*counter = 0;
	person* tail = NULL;
	tail = new person;
	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	clients = head;

	std::system("cls");

	fillClients(head, tail, clients);
	clients = head;
	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}

	///////	   ����    /////////

	while (true) {
		std::cout << "\n\t   ___ ___     ______    __  ___     __    __";
		std::cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		std::cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		std::cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		std::cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		std::cout << "\n\t  ----== ������� ����� ������� �������� ==----  ";
		std::cout << "\n\t       ----== 1. ��������  ������� ==----       ";
		std::cout << "\n\t   ----== 2. ����������� ���� �������� ==----   ";
		std::cout << "\n\t    ----== 3. �������� ������ ������� ==----    ";
		std::cout << "\n\t    ----== 4. �������  ������ ������� ==----    ";
		std::cout << "\n\t    ----== 5. ������� ������ �������� ==----    ";
		std::cout << "\n\t     ----== 6. ����� ������� �� ���� ==----     ";
		std::cout << "\n\t              ----== 0.  ����� ==----           \n\t";
		int inputNum;
		std::cin >> inputNum;
		std::system("cls");
		clients = head;
		switch (inputNum) {
		case(0): {std::cout << "\n\thead, �����\n"; return; }
		case(1): {addClients(head, tail, clients); break; }
		case(2): {sortClients(head, tail, clients); break; }
		case(3): {transformClients(head, tail, clients); break; }
		case(4): {delClients(head, tail, clients); break; }
		case(5): {showClients(head, tail, clients); break; }
		case(6): {searchClients(head, tail, clients); break; }
		default: {
			std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... ";
			char p = _getch();
			std::system("cls");
			break;
		}
		}
		clients = head;
		while (true) {
			if (clients->next == NULL) break;
			clients = clients->next;
			tail = clients;
		}
		while (true) {
			if (clients->prev == NULL) break;
			clients = clients->prev;
			head = clients;
		}
	}
}
//finished

void fillClients(person* head, person* tail, person* clients) {
	string surnames[10] = { "Wallace",		"��������", "����������",
			"������",		"����������",	"Brandon",	"���������",
			"������",		"���������",	"��������" };
	string names[10] = { "Carter",		"�����",	"����",
			"���������",	"�����",		"Rose",		"�����",
			"����",			"������",		"����" };
	string Patronymics[10] = { "None",				"��������",	"���������",
			"����������",		"����������",		"None",		"���������",
			"���������",		"��������������",	"����������", };
	string Address[10] = {
		"3959 Wyatt Street, West Palm Beach, Florida",
		"447191, ����������� �������, ����� ���������� �����, ����� ������, 92",
		"737989, �������� �������, ����� ���������, ������� 1905 ����, 22",
		"434586, ����������� �������, ����� �������, ������ ��������, 59",
		"337525, ��������� �������, ����� �����, ���. �������������, 97",
		"3850 Cedarstone Drive, Toledo, Ohio",
		"107943, �������� �������, ����� �������, ������� �����, 64",
		"314032, ��������������� �������, ����� �������, ����� �����������, 85",
		"038819, ������� �������, ����� ����, ������� �������, 27",
		"139377, ��������� �������, ����� ����-�������, ����� �����, 43", };
	string PhoneNums[10] = { "+18005553535",	"+78652158365",
				"+78664788078",	"+78027969659",	"+78895542709",
				"+18655790207",	"+78032538250",	"+78253336952",
				"+78412045196",	"+78003477306" };
	string PayDays[10] = { "29.03.2021",		"27.02.2021",	"03.04.2021",
			"01.02.2022",	"14.12.2021",		"23.11.2021",	"09.06.2021",
			"22.05.2021",	"01.02.2021",		"05.12.2021", };
	int Summs[10] = { 10333,			20419,			9103,
		23374,			1826,			2873,			7059,
		5318,			20832,			7256, };

	clients->Data.Surname = surnames[0];
	clients->Data.Name = names[0];
	clients->Data.Patronymic = Patronymics[0];
	clients->Data.Address = Address[0];
	clients->Data.PhoneNum = PhoneNums[0];
	clients->Data.PayDay = PayDays[0];
	clients->Data.Summ = Summs[0];
	//(*counter)++;

	for (int i = 1; i < 10; i++) {
		clients->next = new person;
		clients->next->prev = clients;
		clients = clients->next;
		clients->Data.Surname = surnames[i];
		clients->Data.Name = names[i];
		clients->Data.Patronymic = Patronymics[i];
		clients->Data.Address = Address[i];
		clients->Data.PhoneNum = PhoneNums[i];
		clients->Data.PayDay = PayDays[i];
		clients->Data.Summ = Summs[i];
		//(*counter)++;
	}
}
//finished

void addClients(person* head, person* tail, person* clients) {
	std::cout << "\n\n\t���������� �������\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	int		newSumm = 0;

	std::cout << "\n\t������� ������ �������\n";
	std::cout << "\n\t�������: "; 	cin.get();		std::getline(cin, newSurname);
	std::cout << "\n\t���: ";						std::getline(cin, newName);
	std::cout << "\n\t��������: ";					std::getline(cin, newPatronymic);
	std::cout << "\n\t������: ";					std::getline(cin, newAddress);
	std::cout << "\n\t����� �������� (��� +7): ";	std::getline(cin, newPhoneNum);
	std::cout << "\n\t���� ������ (��.��.����): ";	std::getline(cin, newPayDay);
	std::cout << "\n\t����� �������: ";				cin >> newSumm;
	std::system("cls");

	clients = tail;
	clients->next = new person;
	clients->next->prev = clients;
	clients = clients->next;
	clients->Data.Surname = newSurname;
	clients->Data.Name = newName;
	clients->Data.Patronymic = newPatronymic;
	clients->Data.Address = newAddress;
	clients->Data.PhoneNum = "+7" + newPhoneNum;
	clients->Data.PayDay = newPayDay;
	clients->Data.Summ = newSumm;

	//(*counter)++;

	std::cout << "\n\t�������� \n" << "\n\t�������: " << newSurname
		<< "\n\t���: " << newName << "\n\t��������: " << newPatronymic
		<< "\n\t������: " << newAddress << "\n\t����� ��������: +7" << newPhoneNum
		<< "\n\t���� ������: " << newPayDay << "\n\t����� �������: " << newSumm;

	std::cout << "\n\n\t������� ����� ������� ��� �������� � ����... ";
	char p = _getch();
	std::system("cls");
};
//finished

void sortClients(person* head, person* tail, person* clients) {

	std::cout << "\n\t����������� ���� �������� ��\n";
	std::cout << "\n\t1. �������\t2. ���\t0.�����\n\n\t";
	int inputNum;
	cin >> inputNum;
	clients = head;
	int counter = 1;
	person* temp = NULL;
	temp = new person;
	while (true) {
		counter++;
		clients = clients->next;
		if (clients == tail) break;
	}
	clients = head;
	std::system("cls");
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		for (int i = 1; i < counter; i++) {
			clients = head;
			for (int j = 0; j < counter - i; j++) {
				if (clients->Data.Surname > clients->next->Data.Surname) {
					temp->Data = clients->Data;
					clients->Data = clients->next->Data;
					clients->next->Data = temp->Data;
				}
				clients = clients->next;
			}
		}
		std::cout << "\n\n\t���������� �� ������� ���������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	case(2): {
		for (int i = 1; i < counter; i++) {
			clients = head;
			for (int j = 0; j < counter - i; j++) {
				if (clients->Data.Name > clients->next->Data.Name) {
					temp->Data = clients->Data;
					clients->Data = clients->next->Data;
					clients->next->Data = temp->Data;
				}
				clients = clients->next;
			}
		}
		std::cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
//finished

void transform(person* head, person* tail, person* clients) {
	std::cout << "\n\n\t����� ������ ��������\n"
		<< "\n\t1. ������� - " << clients->Data.Surname
		<< "\n\t2. ��� - " << clients->Data.Name
		<< "\n\t3. �������� - " << clients->Data.Patronymic
		<< "\n\t4. ������ - " << clients->Data.Address
		<< "\n\t5. ���������� ����� - " << clients->Data.PhoneNum
		<< "\n\t6. ���� ������ - " << clients->Data.PayDay
		<< "\n\t7. ����� - " << clients->Data.Summ
		<< "\n\t0. �����\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\t������� �������: ";		cin.get(); getline(cin, clients->Data.Surname); 	break; }
	case(2): {std::cout << "\n\n\t������� ���: ";			cin.get(); getline(cin, clients->Data.Name); 		break; }
	case(3): {std::cout << "\n\n\t������� ��������: ";		cin.get(); getline(cin, clients->Data.Patronymic);	break; }
	case(4): {std::cout << "\n\n\t������� ������: ";		cin.get(); getline(cin, clients->Data.Address); 	break; }
	case(5): {std::cout << "\n\n\t������� ����������: ";	cin.get(); getline(cin, clients->Data.PhoneNum); 	break; }
	case(6): {std::cout << "\n\n\t������� ����: ";			cin.get(); getline(cin, clients->Data.PayDay);		break; }
	case(7): {std::cout << "\n\n\t������� �����: ";			cin.get();		   cin >> clients->Data.Summ;		break; }
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
void transformClients(person* head, person* tail, person* clients) {
	std::cout << "\n\n\t�������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int searchID = -1;
		int couErr = 0;
		int id = 1;
		while (true) {
			if (clients->next == NULL) break;
			if (inputStr == clients->Data.Surname) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Name) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic) { searchID = id; couErr++; }
			clients = clients->next;
			id++;
		}
		if (couErr > 1) {
			std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID - 1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(head, tail, clients); return; }
			case(2): { return; }
			default: {
				std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
				char p = _getch();
				std::system("cls");
				return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0) { std::system("cls"); return; }
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(head, tail, clients); return; }
		case(2): { return; }
		default: {
			std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return; }
		}
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		return; }
	}

	std::system("cls");
}
//finished

void swapAndDelClients(person*& head, person*& tail, person*& clients) {
	if (clients != head && clients != tail) {
		clients->prev->next = clients->next;
		clients->next->prev = clients->prev;
	}
	else if (clients == head && clients != tail) {
		head = clients->next;
		head->prev = NULL;
	}
	else if (clients == tail && clients != head) {
		tail = clients->prev;
		tail->next = NULL;
	}
	else {
		head = NULL;
		tail = NULL;
	}
	delete clients;
}
void delClients(person*& head, person*& tail, person*& clients) {
	if (head == NULL || tail == NULL) {
		system("cls");
		cout << "\n\n\t������ ����";
		char p = _getch();
		system("cls");
	}
	clients = head;
	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}
	std::cout << "\n\t������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int id = 1;
		int searchID = -1;
		int couErr = 0;
		while (true) {
			if (inputStr == clients->Data.Surname) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Name) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic) { searchID = id; couErr++; }
			if (clients == tail) break;
			clients = clients->next;
			id++;
		}
		if (couErr > 1) {
			std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {
				swapAndDelClients(head, tail, clients);
				std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			case(2): { return; }
			default: {
				std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		clients = head;
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {
			swapAndDelClients(head, tail, clients);
			std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		case(2): { return; }
		default: {
			std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		}
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	}
	clients = head;
	/*while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}*/
	std::system("cls");
}


void showClients(person* head, person* tail, person* clients) {
	std::cout << "\n\n\t������� ������ ��������\n\n";

	int maxLenSurname = 7;
	int maxLenName = 3;
	int maxLenPatronymic = 8;
	int maxLenAddress = 15;
	int maxLenPhoneNum = 16;
	int maxLenPayDay = 11;
	int maxLenSumm = 13;

	int maxSumm = 0;

	clients = head;
	while (true) {
		int LenSurname = clients->Data.Surname.length();
		int LenName = clients->Data.Name.length();
		int LenPatronymic = clients->Data.Patronymic.length();
		int LenAddress = clients->Data.Address.length();
		int LenPhoneNum = clients->Data.PhoneNum.length();
		int LenPayDay = clients->Data.PayDay.length();
		int LenSumm = 0;
		int Summ = clients->Data.Summ;
		int g = 0;
		while (Summ > 0) { Summ /= 10; LenSumm++; }
		maxSumm += clients->Data.Summ;

		if (LenSurname > maxLenSurname) { maxLenSurname = LenSurname; }
		if (LenName > maxLenName) { maxLenName = LenName; }
		if (LenPatronymic > maxLenPatronymic) { maxLenPatronymic = LenPatronymic; }
		if (LenAddress > maxLenAddress) { maxLenAddress = LenAddress; }
		if (LenPhoneNum > maxLenPhoneNum) { maxLenPhoneNum = LenPhoneNum; }
		if (LenPayDay > maxLenPayDay) { maxLenPayDay = LenPayDay; }
		if (LenSumm > maxLenSumm) { maxLenSumm = LenSumm; }
		if (clients == tail) break;
		clients = clients->next;
	}
	clients = head;
	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic
		+ maxLenAddress + maxLenPhoneNum + maxLenPayDay + maxLenSumm + 22;



	std::cout << "\t";
	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname, "�������",
		maxLenName, "���",
		maxLenPatronymic, "��������",
		maxLenAddress, "�������� ������",
		maxLenPhoneNum, "���������� �����",
		maxLenPayDay, "���� ������",
		maxLenSumm, "����� �������");
	std::cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << "\n";

	while (true) {
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname, clients->Data.Surname.c_str(),
			maxLenName, clients->Data.Name.c_str(),
			maxLenPatronymic, clients->Data.Patronymic.c_str(),
			maxLenAddress, clients->Data.Address.c_str(),
			maxLenPhoneNum, clients->Data.PhoneNum.c_str(),
			maxLenPayDay, clients->Data.PayDay.c_str(),
			maxLenSumm, clients->Data.Summ
		);

		std::cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
		std::cout << endl;
		if (clients->next == NULL) break;
		clients = clients->next;
	}
	clients = head;
	std::cout << "\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	printf_s("| %*d |", maxLenSumm, maxSumm); std::cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	for (int i = 0; i < maxLenPayDay + 6; i++) { std::cout << "-"; }


	std::cout << "\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");
	std::system("cls");
}
//finished

void show(person* clients) {
	std::cout << "\n\n\t���: " << clients->Data.Surname << " " << clients->Data.Name << " " << clients->Data.Patronymic << " ������: "
		<< clients->Data.Address << "\n\t��������� �����: " << clients->Data.PhoneNum << " ���� ������: " << clients->Data.PayDay << " �����: " << clients->Data.Summ;
}
void searchClients(person* head, person* tail, person* clients) {
	std::cout << "\n\t����� ������� �� ����";
	std::cout << "\n\n\t������� ������� ��� ��� ��� ��������\t0. �����\n\n\t";
	string inputStr;
	cin >> inputStr;
	std::system("cls");
	if (inputStr == "0") { return; }
	clients = head;
	bool searchID = false;
	while (true) {
		if (clients->next == NULL) break;
		if (inputStr == clients->Data.Surname) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Name) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Patronymic) { searchID = true; show(clients); }
		clients = clients->next;
	}
	clients = head;
	if (searchID == true) { std::cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == false) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}
//finished

#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region additionalTask


void TreeSort(int* arr, int size) {

	struct BinaryTree {
		BinaryTree* left, * right;
		int Data;

		BinaryTree(int&& _Data = int()) {
			left = right = nullptr;
			Data = forward<int>(_Data);
		}
		int* operator()(int arr[]) {
			if (this->left)
				arr = this->left->operator()(arr);
			*arr++ = move(this->Data);
			if (this->right)
				arr = this->right->operator()(arr);
			return arr;
		}
	}root(move(arr[0]));

	for (int i = 1; i < size; i++) {
		bool inserted = false;
		BinaryTree* p_root = &root;
		while (!inserted) {
			if (arr[i] < p_root->Data) {
				if (p_root->left) p_root = p_root->left;
				else {
					p_root->left = new BinaryTree(move(arr[i]));
					inserted = true;
				}
			}
			else {
				if (p_root->right) p_root = p_root->right;
				else {
					p_root->right = new BinaryTree(move(arr[i]));
					inserted = true;
				}
			}
		}
	}
	root(arr);
}

void additionalTask() {
	/*���������� ��������� ���������� ������� ����� ����� �� ������ ��������� ���������
	������. ������ ����������� ������� ���������� ��������� � ������� (����� �������� ��
	������ �������� ��� ����������).*/

	/*BinaryTree* root = NULL;
	root = new BinaryTree;
	BinaryTree* leftBranch = NULL;
	BinaryTree* rightBranch = NULL;
	leftBranch = root;
	rightBranch = root;
	root->Data = rand() % 100;*/
	srand(time(NULL));

	cout << "\n\n\t������� ������ ������������� �������: ";
	int size;
	cin >> size;
	system("cls");
	int* arr = new int[size];
	cout << "\n\n\t��� ����������: ";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}

	TreeSort(arr, size);

	cout << "\n\n\t������������: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	std::cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... ";
	char p = _getch();
	std::system("cls");
	return;

}



#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////