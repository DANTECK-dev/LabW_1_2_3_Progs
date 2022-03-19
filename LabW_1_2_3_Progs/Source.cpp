#define _CRT_SECURE_NO_WARNINGS
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
		std::cout << "\n\t\tОбщие задания\n\t1. Задание 1\t2. Задание 2\n\n\t3. Индивидуальное задание 7 вариант\n\n\t4. Дополнительное задание\n\n\t0. Выход\n\n\t";
		int inputNum;
		cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
		case(0): {return 0; }
		case(1): {firstGeneralTask();	break; }
		case(2): {secondGeneralTask();	break; }
		case(3): {individualTask();		break; }
		case(4): {additionalTask();		break; }
		default: {std::cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... "; char p = _getch(); std::system("cls"); break; }
		}
		std::system("cls");
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region firstGeneralTask

	/*Считать массив целых чисел из текстового файла (файл может лежать в каталоге
	программы). Используйте для этого fopen_s() и соответствующие функции.
	Первое число в файле – количество элементов в массиве. Прочитав его, динамически
	выделите память под массив и считайте остальные элементы в него.
	После считывания нужно отсортировать массив и сохранить его в другой файл.*/

#define FIRST_INPUT_FILE_LOCATION		"Input_Massive.txt"
#define FIRST_OUTPUT_FILE_LOCATION	"Output_Massive.txt"


void firstGeneralTask() {

	int* arr;
	int size = 0;
	FILE* file = nullptr;
	
	fopen_s(&file, FIRST_INPUT_FILE_LOCATION, "r");
	
	if (file == NULL) {
		cout << "\n\tОшибка... ";
		char p = _getch();
	}

	fscanf_s(file, "%d", &size);
	arr = new int[size];

	if (size == 0) {
		std::cout << "\n\n\tОшибка, файл не найден или файл пустой... ";
		char p = _getch();
		std::system("cls");
		return;
	}

	std::cout << "\n\n\tReading Mass: ";
	for (int i = 0; i < size; i++) {
		int temp;
		fscanf_s(file, "%d", &temp);
		arr[i] = temp;
		std::cout << arr[i] << ", ";
	}
	fclose(file);
	file = NULL;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i; j++) {
			if (arr[j] < arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	fopen_s(&file, FIRST_OUTPUT_FILE_LOCATION, "w");

	for (int i = 0; i < size; i++)
		fprintf_s(file, "%d\n", arr[i]);

	fclose(file);

	std::cout << "\n\n\tSorter Mass: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ", ";
	}

	std::cout << "\n\n\tНажмите любую клавишу для выхода... "; 
	char p = _getch();
	std::system("cls");
	return;

}


#pragma endregion 
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region secondGeneralTask

	/*Дан файл со списком учебной группы. Для работы с этим файлом используйте потоки
	<fstream> и соответствующие методы.
	Первое число в файле – количество студентов. Далее файл разделен на строки, в каждой
	строке указан номер (идентификатор), фамилия и средний балл студента.
	Обеспечьте считывание данных о студентах из файла и отображение ее на экран в виде
	таблицы. Выведите номера и фамилии студентов, у которых средний балл выше 4, в отдельный
	файл.*/

#define SECOND_INPUT_FILE_LOCATION		"Input_Students.txt"
#define SECOND_OUTPUT_FILE_LOCATION	"Output_Students.txt"

void secondGeneralTask() {
	fstream inputStudent;
	fstream outputStudent;
	int *Num = NULL;
	string *Name = NULL;
	string* Surame = NULL;
	string* Patronymic = NULL;
	int *Mark = NULL;
	int size = 0;
	

	while (true) {
		inputStudent.open(SECOND_INPUT_FILE_LOCATION, ios::in);
	if (!inputStudent.eof()) {

		inputStudent >> size;
		
		if (size == 0) {
			std::cout << "\n\n\tОшибка в исходном файле или путь файла был изменен... ";
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
			inputStudent >> Num[i];
			inputStudent >> Surame[i];
			inputStudent >> Name[i];
			inputStudent >> Patronymic[i];
			inputStudent >> Mark[i];
		}
		inputStudent.close();
	}
	std::cout << "\n\t1. Вывод в консоль\n\t2. Выборка по оценкам\n\t0. Выход\n\n\t";
		int inNum;
		cin >> inNum;
		std::system("cls");
		switch (inNum) {
			case(0): {return; }
			case(1): {
				std::cout << endl;
				for (int i = 0; i < size; i++) {
					std::cout	<<"\t" << Num[i]	<< " " << Surame[i]
							<< " " << Name[i]	<< " " << Patronymic[i] 
							<< " " << Mark[i]	<< endl;
				}
				std::cout << "\n\n\tНажмите любую клавишу для выхода... "; 
				char p = _getch(); 
				std::system("cls"); 
				break;
			}
			case(2): {
				std::cout << "\n\tВведите оценку: ";
				int inMark;
				cin >> inMark;
				int counter = 0; 
				system("cls");
				if (inMark <= 0 || inMark > 5) {
					std::cout << "\n\n\tВведено неверное значение... ";
					char p = _getch();
					system("cls");
					break;
				}
				std::cout << endl;
				outputStudent.open(SECOND_OUTPUT_FILE_LOCATION, ios::out);
				for (int i = 0; i < size; i++) {
					if (Mark[i] == inMark) {
						std::cout			<<"\t" << Num[i]	<< " " << Surame[i]
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
					std::cout << "\n\tСохранено в файл: " << SECOND_OUTPUT_FILE_LOCATION;
				}
				if (counter == 0) {
					system("cls");
					std::cout << "\n\tНет таких";
				}
				
				std::cout << "\n\n\tНажмите любую клавишу для выхода... ";
				char p = _getch();
				std::system("cls");
				break;
			}
			default: {
				std::cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... ";
				char p = _getch();
				std::system("cls");
				break; 
			}
		}
		
	}
	std::cout << "\n\n\tНажмите любую клавишу для выхода... "; char p = _getch(); std::system("cls"); return;
}


#pragma endregion
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region individualTask

#define INDIVID_INPUT_FILE_LOCATION		"Input_Clients.txt"
#define INDIVID_OUTPUT_FILE_LOCATION	"Output_Clients.txt"

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

void addClients			(person*& head, person*& tail, person*& clients);
void sortClients		(person*& head, person*& tail, person*& clients);
void transformClients	(person*& head, person*& tail, person*& clients);
void delClients			(person*& head, person*& tail, person*& clients);
void showClients		(person*& head, person*& tail, person*& clients);
void searchClients		(person*& head, person*& tail, person*& clients);
void saveClients		(person*& head, person*& tail, person*& clients);
void downloadClients	(person*& head, person*& tail, person*& clients);

void individualTask() {										//<<<<--------main индивидуального задания

	/*Структура «Покупатель»: Дата покупки; ФИО; домашний адрес; номер телефона; сумма
	покупки. Вычисляемое значение – общая сумма покупки.*/

	/*1) Создание нового элемента массива структур (ввод его данных);
	2) Сортировка массива структур;
	3) Изменение заданной структуры (вводится номер элемента в массиве структур, и его
	данные изменяются на новые введенные пользователем данные);
	4) Удаление структуры из массива (можно удаляемому элементу массива присвоить
	значение последнего элемента и уменьшить количество элементов в массиве структур);
	5) Вывод на экран массива структур в виде таблицы. Также выводите вычисляемое
	значение по всему массиву, указанное в вашем варианте.
	6) Поиск в массиве структур по заданному параметру (самостоятельно выберите поле
	структуры и реализуйте поиск по нему). То есть это вывод, но только определенных данных.*/

	/* 3 Laba
	Измените программу индивидуального задания прошлой лабораторной работы. Добавьте
	в меню выбора новые действия пользователя «Сохранение» и «Загрузка».
	Действие «Сохранение» должно выполнять сохранение в файл всех данных вашего
	списка. При этом пользователю должен предоставляться выбор: сохранить в файл по
	умолчанию (придумайте название, к примеру, list.data) или пользователь сам вводит название
	файла, в который нужно сохранить список.
	Действие «Загрузить» должно выполнять загрузку данных вашего списка (заполнять
	список) из файла в память программы. При этом пользователю также должен предоставляться
	выбор: загрузить из файла по умолчанию или пользователь сам вводит название файла, из
	которого нужно загрузить список*/


	person* head = NULL;
	person* tail = NULL;
	person* clients = NULL;
	/*while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	 }*/

	std::system("cls");

	//fillClients(head, tail, clients);

	///////	   МЕНЮ    /////////

	while (true) {
		std::cout << "\n\t   ___ ___     ______    __  ___     __    __";
		std::cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		std::cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		std::cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		std::cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		std::cout << "\n\t  ----== Введите номер нужного действия ==----  ";
		std::cout << "\n\t       ----== 1. Добавить  клиента ==----       ";
		std::cout << "\n\t   ----== 2. Сортировать всех клиентов ==----   ";
		std::cout << "\n\t    ----== 3. Изменить данные клиента ==----    ";
		std::cout << "\n\t    ----== 4. Удалить  данные клиента ==----    ";
		std::cout << "\n\t    ----== 5. Вывести список клиентов ==----    ";
		std::cout << "\n\t     ----== 6. Поиск клиента по базе ==----     ";
		std::cout << "\n\t  ----== 7. Сохранить все  данные в файл==----  ";
		std::cout << "\n\t   ----== 8. Загрузить данные из файла ==----  ";
		std::cout << "\n\t              ----== 0.  Выход ==----           \n\t";
		int inputNum;
		std::cin >> inputNum;
		std::system("cls");
		clients = head;
		switch (inputNum) {
		case(0): {std::cout << "\n\thead, Выход\n"; return; }
		case(1): {addClients		(head, tail, clients); break; }
		case(2): {sortClients		(head, tail, clients); break; }
		case(3): {transformClients	(head, tail, clients); break; }
		case(4): {delClients		(head, tail, clients); break; }
		case(5): {showClients		(head, tail, clients); break; }
		case(6): {searchClients		(head, tail, clients); break; }
		case(7): {saveClients		(head, tail, clients); break; }
		case(8): {downloadClients	(head, tail, clients); break; }
		default: {
			std::cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... ";
			char p = _getch();
			std::system("cls");
			break;
		}
		}
		if (tail == NULL && head == NULL) continue;
		clients = head; 
		while (true) {
			if (clients->next == nullptr) break;
			clients = clients->next;
			tail = clients;
		}
		while (true) {
			if (clients->prev == nullptr) break;
			clients = clients->prev;
			head = clients;
		}
	}
}
//finished

void addClients(person*& head, person*& tail, person*& clients) {
	
	std::cout << "\n\n\tДобавление клиента\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	int		newSumm = 0;

	std::cout << "\n\tВведите данные клиента\n";
	std::cout << "\n\tФамилия: "; 	cin.get();		std::getline(cin, newSurname);
	std::cout << "\n\tИмя: ";						std::getline(cin, newName);
	std::cout << "\n\tОтчество: ";					std::getline(cin, newPatronymic);
	std::cout << "\n\tАдресс: ";					std::getline(cin, newAddress);
	std::cout << "\n\tНомер телефона (без +7): ";	std::getline(cin, newPhoneNum);
	std::cout << "\n\tДень оплаты (ДД.ММ.ГГГГ): ";	std::getline(cin, newPayDay);
	std::cout << "\n\tСумму покупки: ";				cin >> newSumm;
	std::system("cls");

	if (tail == NULL && head == NULL) {
			tail = new person;
			clients = tail;
			head = tail;
			clients->Data.Surname = newSurname;
			clients->Data.Name = newName;
			clients->Data.Patronymic = newPatronymic;
			clients->Data.Address = newAddress;
			clients->Data.PhoneNum = "+7" + newPhoneNum;
			clients->Data.PayDay = newPayDay;
			clients->Data.Summ = newSumm;

			std::cout << "\n\tДобавлен \n" << "\n\tфамилия: " << newSurname
				<< "\n\tИмя: " << newName << "\n\tОтчество: " << newPatronymic
				<< "\n\tАдресс: " << newAddress << "\n\tНомер телефона: +7" << newPhoneNum
				<< "\n\tДень оплаты: " << newPayDay << "\n\tСумму покупки: " << newSumm;

			std::cout << "\n\n\tНажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
	}
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

	std::cout << "\n\tДобавлен \n" << "\n\tфамилия: " << newSurname
		<< "\n\tИмя: " << newName << "\n\tОтчество: " << newPatronymic
		<< "\n\tАдресс: " << newAddress << "\n\tНомер телефона: +7" << newPhoneNum
		<< "\n\tДень оплаты: " << newPayDay << "\n\tСумму покупки: " << newSumm;

	std::cout << "\n\n\tНажмите любую клавишу для возврата в меню... ";
	char p = _getch();
	std::system("cls");
};
//finished

void sortClients		(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для сортировки...";
		char p = _getch();
		system("cls");
		return;
	}
	if (clients == head && clients == tail) {
		std::cout << "\n\n\tМало данных клиентов для сортировки...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\tСортировать всех клиентов по\n";
	std::cout << "\n\t1. Фамилии\t2. Имя\t0.Выход\n\n\t";
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
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
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
		std::cout << "\n\n\tСортировка по фамилии завершена, нажмите любую кдавишу для возврата в меню... ";
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
		std::cout << "\n\n\tСортировка по имени завершена, нажмите любую кдавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
//finished

void transform			(person*& head, person*& tail, person*& clients) {
	std::cout << "\n\n\tКакие данные изменить\n"
		<< "\n\t1. Фамилию - " << clients->Data.Surname
		<< "\n\t2. Имя - " << clients->Data.Name
		<< "\n\t3. Отчество - " << clients->Data.Patronymic
		<< "\n\t4. Адресс - " << clients->Data.Address
		<< "\n\t5. Телефонный номер - " << clients->Data.PhoneNum
		<< "\n\t6. День оплаты - " << clients->Data.PayDay
		<< "\n\t7. Сумму - " << clients->Data.Summ
		<< "\n\t0. Выход\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\tВведите Фамилию: ";		cin.get(); getline(cin, clients->Data.Surname); 	break; }
	case(2): {std::cout << "\n\n\tВведите Имя: ";			cin.get(); getline(cin, clients->Data.Name); 		break; }
	case(3): {std::cout << "\n\n\tВведите Отчество: ";		cin.get(); getline(cin, clients->Data.Patronymic);	break; }
	case(4): {std::cout << "\n\n\tВведите Адресс: ";		cin.get(); getline(cin, clients->Data.Address); 	break; }
	case(5): {std::cout << "\n\n\tВведите Телефонный: ";	cin.get(); getline(cin, clients->Data.PhoneNum); 	break; }
	case(6): {std::cout << "\n\n\tВведите День: ";			cin.get(); getline(cin, clients->Data.PayDay);		break; }
	case(7): {std::cout << "\n\n\tВведите Сумму: ";			cin.get();		   cin >> clients->Data.Summ;		break; }
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
void transformClients	(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для изменения...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\tИзменить данные клиента\n\n\t\tПоиск по \n\n\t1. ФИО\t2. Счёту в базе\t0. Выход\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\tВведите Фамилию или Имя или Отчество. 0. Выход\n\n\t";
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
			std::cout << "\n\n\tНайдено более одного клиента, введите дргуие даннные клиента. Нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID - 1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\tИзменить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(head, tail, clients); return; }
			case(2): { return; }
			default: {
				std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
				char p = _getch();
				std::system("cls");
				return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\tВведите номер в базе. 0. Выход\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0) { std::system("cls"); return; }
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\tИзменить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(head, tail, clients); return; }
		case(2): { return; }
		default: {
			std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return; }
		}
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return; }
	}

	std::system("cls");
}
//finished

void swapAndDelClients	(person*& head, person*& tail, person*& clients) {
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
void delClients			(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для удаления...";
		char p = _getch();
		system("cls");
		return;
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
	std::cout << "\n\tУдалить данные клиента\n\n\t\tПоиск по \n\n\t1. ФИО\t2. Счёту в базе\t0. Выход\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\tВведите Фамилию или Имя или Отчество. 0. Выход\n\n\t";
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
			std::cout << "\n\n\tНайдено более одного клиента, введите дргуие даннные клиента. Нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			std::cout << "\n\n\tУдалить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {
				swapAndDelClients(head, tail, clients);
				std::cout << "\n\n\tУспешно удалено, нажмите любую клавишу для выхода в меню... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			case(2): { return; }
			default: {
				std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			}
		}
	}
	case(2): {
		std::cout << "\n\n\tВведите номер в базе. 0. Выход\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		clients = head;
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\tУдалить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {
			swapAndDelClients(head, tail, clients);
			std::cout << "\n\n\tУспешно удалено, нажмите любую клавишу для выхода в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		case(2): { return; }
		default: {
			std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		}
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
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
//finished

void showClients		(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для вывода...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\tВывести список клиентов\n\n";

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
		maxLenSurname, "Фамилия",
		maxLenName, "Имя",
		maxLenPatronymic, "Отчество",
		maxLenAddress, "Домашний адресс",
		maxLenPhoneNum, "Телефонный номер",
		maxLenPayDay, "День оплаты",
		maxLenSumm, "Сумма покупки");
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


	std::cout << "\n\tНажмите любую клавишу для возврата в меню... "; char p = _getch(); std::system("cls");
	std::system("cls");
}
//finished

void show				(person*& clients) {
	std::cout << "\n\n\tФИО: " << clients->Data.Surname << " " << clients->Data.Name << " " << clients->Data.Patronymic << " Адресс: "
		<< clients->Data.Address << "\n\tТелефоный номер: " << clients->Data.PhoneNum << " День оплаты: " << clients->Data.PayDay << " Сумма: " << clients->Data.Summ;
}
void searchClients		(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для поиска...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\tПоиск клиента по базе";
	std::cout << "\n\n\tВведите Фамилию или Имя или Отчество\t0. Выход\n\n\t";
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
	if (searchID == true) { std::cout << "\n\n\tНажмите любую клавишу что-бы вернуться в меню... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == false) { std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}
//finished

void saveClients		(person*& head, person*& tail, person*& clients)
{
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для сохранения...";
		char p = _getch();
		system("cls");
		return;
	}
	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. Сохранить в файле с названием " << INDIVID_OUTPUT_FILE_LOCATION
		<< " с исходным кодом\n\t2. Изменить название файла\n\t0. Выход\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\tНажмите любую клавишу...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {
		ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);
		clients = head;
		while (true) {
			outClients	<<"ФИО: " << clients->Data.Surname << " " << clients->Data.Name << " "
						<< clients->Data.Patronymic << " Адресс: " << clients->Data.Address << " Номер тел.: "
						<< clients->Data.PhoneNum	<< " День оплаты: " << clients->Data.PayDay	<< " Сумма: "
						<< clients->Data.Summ		<< endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\tСохраненов файле " << INDIVID_OUTPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break; 
	}
	case(2): {
		std::cout << "\n\n\tВведите навание выходного файла (без расширения, используя только буквы): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ofstream outClients(newName);
		clients = head;
		while (true) {
			outClients	<<"ФИО: " << clients->Data.Surname << " " << clients->Data.Name << " "
						<< clients->Data.Patronymic << " Адресс: " << clients->Data.Address << " Номер тел.: "
						<< clients->Data.PhoneNum	<< " День оплаты: " << clients->Data.PayDay	<< " Сумма: "
						<< clients->Data.Summ		<< endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\tСохранено в файле "<<newName<<"...";
		char p = _getch();
		system("cls");
		break; 
	}
	default: {
		std::cout << "\n\n\tВведено невенрое значение...";
		char p = _getch(); 
		break; 
	}
	}
}
//finished

void downloadClients	(person*& head, person*& tail, person*& clients){
	string defaultFileName = (INDIVID_INPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. Загрузтиь из файла с названием " << INDIVID_INPUT_FILE_LOCATION
		<< " с исходным кодом\n\t2. Изменить название файла\n\t0. Выход\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\tНажмите любую клавишу...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {

		ifstream inClients(INDIVID_INPUT_FILE_LOCATION);

		if (inClients.bad()) {
			std::cout << "\n\tОшибка ввода-вывода при чтении...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\tДостигнут конец файла...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\tНеверный формат данных...";
			char p = _getch();
			system("cls");
			return;
		}

		int size = 0;
		inClients >> size;

		for (int i = 0; i < size; i++) {
			if (clients == NULL) {
				clients = new person;
				head = clients;
				tail = clients;
			}
			else {
				clients = tail;
				clients->next = new person;
				clients->next->prev = clients;
				clients = clients->next;
				tail = clients;
			}
			inClients.get();
			getline (inClients, clients->Data.Surname);
			getline (inClients, clients->Data.Name);
			getline (inClients, clients->Data.Patronymic);
			getline (inClients, clients->Data.Address);
			getline (inClients, clients->Data.PhoneNum );
			getline (inClients, clients->Data.PayDay);
			inClients>> clients->Data.Summ;
		}

		std::cout << "\n\n\tЗагруженно из файле " << INDIVID_INPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}
	case(2): {
		std::cout << "\n\n\tВведите навание выходного файла (без расширения, используя только буквы): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ifstream inClients(newName);

		if (inClients.bad()) {
			std::cout << "\n\tОшибка ввода-вывода при чтении...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\tДостигнут конец файла...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\tНеверный формат данных...";
			char p = _getch();
			system("cls");
			return;
		}

		int size = 0;
		inClients >> size;

		clients = new person;
		head = clients;

		for (int i = 0; i < size; i++) {
			if (clients == NULL) {
				clients = new person;
				head = clients;
			}
			else {
				clients = clients->next = new person;
				tail = clients;
			}
			inClients.get();
			getline(inClients, clients->Data.Surname);
			getline(inClients, clients->Data.Name);
			getline(inClients, clients->Data.Patronymic);
			getline(inClients, clients->Data.Address);
			getline(inClients, clients->Data.PhoneNum);
			getline(inClients, clients->Data.PayDay);
			inClients >> clients->Data.Summ;
		}

		std::cout << "\n\n\tЗагруженно из файле " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}
	default: {
		std::cout << "\n\n\tВведено невенрое значение...";
		char p = _getch();
		break;
	}
	}
}
//finished

#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region additionalTask


enum class Additional_Menu {
	Exit,
	AddStr,
	DelStr,
	ShowStr,
	SaveStr,
	LoadStr
};

void additionalTask() {
	/*
	Обеспечьте всю работу с файлами с помощью перенаправления стандартных потоков
	функцией freopen_s().
	Программа должна выполнять простую работу с массивом строк. При запуске
	пользователю на выбор предоставляется несколько действий:
		 Пользователь может добавить новую строку в массив.
		 Пользователь может удалить строку из массива по номеру (порядок строк должен остаться тот же).
		 Пользователь может вывести массив на экран.
		 Пользователь может сохранить массив строк в файле.
		 Пользователь может загрузить массив строк из файла.
		*/
	string* str = NULL;
	int size = 0;
	while (true)
	{
		cout	<< "\n\t1. Добавить строку"
				<< "\n\t2. Удалить строку" 
				<< "\n\t3. Вывести строки" 
				<< "\n\t4. Сохранить строки" 
				<< "\n\t5. Загрузить строки"
				<< "\n\t0. Выход\n\n\t";
		int menuNum;
		cin >> menuNum;
		system("cls");
		switch ((Additional_Menu)menuNum) 
		{
			case Additional_Menu::Exit: 
				return;

			case Additional_Menu::AddStr: 
			{
				cout << "\n\tДобавить строку\n\t0. Выход\n\n\t";
				string inputStr;
				cin.get();
				getline(cin, inputStr);
				if (inputStr == "0") break;
				size++;
				if (str == NULL) str = new string[size];
				else {

					string *temp = new string[size];

					for (int i = 0; i < size-1; i++)
					{
						temp[i] = str[i];
					}

					delete[] str;

					str = new string[size];

					for (int i = 0; i < size - 1; i++) 
					{
						str[i] = temp[i];
					}

					delete[] temp;
				}
				str[size-1] = inputStr;
				system("cls");
				//cout << str[size - 1];
				break;
			}

			case Additional_Menu::DelStr: 
			{
				if (size == 0)
				{
					cout << "\n\tНечего удалять... ";
					char p = _getch();
					system("cls");
					break;
				}

				if (size == 1)
				{
					cout << "\n\tУдалёнa последняя строка... ";
					delete[] str;
					size = 0;
					char p = _getch();
					system("cls");
					break;
				}

				cout << "\n\tУдаление строки\n\n\tВыберете строку:\n\n\t";

				for (int i = 0; i < size; i++)
				{
					cout << i + 1 << ": " << str[i]<<"\n\t";
				}

				int inI;
				cin >> inI;
				system("cls");

				cout << "\n\tУдалить " << str[inI - 1] << "\n\t1. Да\t0. Выход\n\t";

				int inputI;
				cin >> inputI;
				system("cls");

				switch (inputI) {
					case(0): break;
					case(1):
					{
						size--;

						string* temp = new string[size];

						for (int i = 0; i < inI; i++) 
						{
							temp[i] = str[i];
						}

						for (int i = inI; i < size; i++) 
						{
							temp[i] = str[i + 1];
						}

						delete[] str;

						str = new string[size];

						for (int i = 0; i < size; i++) 
						{
							str[i] = temp[i];
						}

						delete[] temp;
					}

					default:
					{
						cout << "Введено невеное значение... ";
						char p = _getch();
						system("cls");
						break;
					}
				}

				break;
			}

			case Additional_Menu::ShowStr: 
			{
				if (size == 0) {
					cout << "\n\tНечего выводить... ";
					char p = _getch();
					system("cls");
					break;
				}
				cout << "\n\tВывод строк(и): \n\n\t";
				for (int i = 0; i < size; i++) {
					cout << str[i]<<"\n\t";
				}
				break;
			}

			case Additional_Menu::SaveStr: 
			{
				cout << endl << "\n\tВведите имя файла (без расширения): ";
				char fileNameOut[100];
				cin >> fileNameOut;

				int counter = strlen(fileNameOut);
				fileNameOut[counter] = '.';
				fileNameOut[counter + 1] = 't';
				fileNameOut[counter + 2] = 'x';
				fileNameOut[counter + 3] = 't';
				fileNameOut[counter + 4] = '\0';

				if (size == 0)
				{
					cout << "\n\tНечего выводить... ";
					char p = _getch();
					system("cls");
					break;
				}

				FILE* file = NULL;

				freopen_s(&file, fileNameOut, "w", stdout);

				for (int i = 0; i < size; i++)
				{
					cout << str[i] << endl;
				}

				//fclose(file);
				freopen_s(&file, "CON", "w", stdout);

				cout << endl << "\n\tСохранено... ";
				char p = _getch();
				system("cls");
				
				/*else
				{
					cout << "\n\tОшибка открытия... ";
					freopen_s(&file, "CON", "w", stdout);
					char p = _getch();
					system("cls");
				}*/
				break;
			}

			case Additional_Menu::LoadStr: 
			{
				cout << endl << "\n\tВведите имя файла (без расширения): ";
				char fileNameIn[100];
				cin >> fileNameIn;

				cout << "\n\tВведите количество строк: ";
				int s;
				cin >> s;

				int counter = strlen(fileNameIn);
				fileNameIn[counter] = '.';
				fileNameIn[counter + 1] = 't';
				fileNameIn[counter + 2] = 'x';
				fileNameIn[counter + 3] = 't';
				fileNameIn[counter + 4] = '\0';

				FILE* file = NULL;

				freopen_s(&file, fileNameIn, "r", stdin);

				if (file != NULL) {
					cout << "\n\tФайл успешно откыт\n\t";
					for (int i = 0; i < s; i++)
					{
						size++;
						if (str == NULL) str = new string[size];
						else
						{
							string* temp = new string[size];

							for (int i = 0; i < size - 1; i++)
							{
								temp[i] = str[i];
							}

							delete[] str;

							str = new string[size];

							for (int i = 0; i < size - 1; i++)
							{
								str[i] = temp[i];
							}

							delete[] temp;
						}
						getline(cin, str[size - 1]);
						cout << "\n\tДобавлена строка: " << str[size-1];
					}
					cout << endl;
					//fclose(file);
					freopen_s(&file, "CON", "r", stdin);
				}
				else
				{
					cout << "\n\tОшибка открытия... ";
					freopen_s(&file, "CON", "r", stdin);
					char p = _getch();
					system("cls");
				}
				break;
			}
			default: 
			{
				cout << "\n\tОшибка... ";
				char p = _getch();
				system("cls");
			}
		}
		
	}
}



#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////