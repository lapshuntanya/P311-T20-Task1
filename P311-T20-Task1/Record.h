#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Record
{
private:
	/*У ньому зберігаються прізвище та ім'я людини, кількість та номери телефонів (масив рядків), адреса проживання, e-mail . */
	char name[50];
	int nPhones;
	char** phones;
	char address[50];
	char email[50];

public:
	//Конструктори + Деструктор
	Record(); //За замовчуванням
	Record(const char* name, const char* phone,
		const char* address, const char* email); //З параметрами
	~Record(); //Деструктор

	//Аксесори = сеттери та геттери
	void setName(const char* newName);
	void setAddress(const char* newAddress);
	void setEmail(const char* newEmail);

	const char* getName();
	int getAmountPhones();
	const char* getAddress();
	const char* getEmail();


	void showInfo(); //Виведення на екран
	void addPhoneNumber(const char* number);
};

