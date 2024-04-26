#include "Record.h"
#define DEBUG

Record::Record()
{
	//name = "Pupkin"; Помилка!!!
	strcpy_s(name, 50, "Pupkin");
	nPhones = 1;
	phones = new char* [nPhones];
	phones[0] = new char[20] {"+38(099)00-00-000" };
	
	strcpy_s(address, 50, "Kharkiv");
	strcpy_s(email, 50, "pupkin@gmail.com");

#ifdef DEBUG
	cout << "Record(): " << name << endl;
#endif // DEBUG
}

Record::Record(const char* name, const char* phone, const char* address, const char* email)
{
	strcpy_s(this->name, 50, name);
	nPhones = 1;
	//Виділяємо память для масиву рядків
	phones = new char* [nPhones]; 
	//Виділяємо пам'ять під перший рядок
	phones[0] = new char[20] {""};
	//Вносимо дані в цей рядок
	strcpy_s(phones[0], 20, phone);

	strcpy_s(this->address, 50, address);
	strcpy_s(this->email, 50, email);
#ifdef DEBUG
	cout << "Record(n, ph, add, email): " << name << endl;
#endif // DEBUG
}

Record::~Record()
{
#ifdef DEBUG
	cout << "~Record(): " << name << endl;
#endif // DEBUG
	for (int i = 0; i < nPhones; i++)
	{
		delete[] phones[i];
	}
	delete[] phones;
}

void Record::setName(const char* newName)
{
	if (strlen(newName) >= 2) {
		strcpy_s(name, 50, newName);
	}
	else {
		cout << "Erorr: strlen(newName) < 2!!!\n";
	}
}

void Record::setAddress(const char* newAddress)
{
	if (strlen(newAddress) >= 5) {
		strcpy_s(address, 50, newAddress);
	}
	else {
		cout << "Erorr: strlen(newAddress) < 5!!!\n";
	}
}

void Record::setEmail(const char* newEmail)
{
	if (strlen(newEmail) >= 5 && strstr(newEmail, "@") != NULL) {
		strcpy_s(email, 50, newEmail);
	}
	else {
		cout << "Erorr: strlen(newEmail) < 5 or Not found @!!!\n";
	}
}

const char* Record::getName()
{
	return name;
}

int Record::getAmountPhones()
{
	return nPhones;
}

const char* Record::getAddress()
{
	return address;
}

const char* Record::getEmail()
{
	return email;
}

void Record::showInfo()
{
	cout << "=========================================\n";
	cout << "Name: " << name << endl;
	cout << "Phones: " << nPhones << endl;
	for (int i = 0; i < nPhones; i++)
	{
		cout << "\t#" << i + 1 << ". " << phones[i] << endl;
	}
	cout << "Address: " << address << endl;
	cout << "Email: " << email << endl ;
	cout << "=========================================\n\n";
}

void Record::addPhoneNumber(const char* number)
{
	if (strlen(number) >= 5)
	{
		nPhones++;

		char** tmp = new char* [nPhones];
		for (int i = 0; i < nPhones - 1; i++)
		{
			tmp[i] = phones[i];
		}
		delete[] phones;

		tmp[nPhones - 1] = new char[50] {""};
		strcpy_s(tmp[nPhones - 1], 50, number);

		phones = tmp;
	}
	else
	{
		cout << "Error: strlen(number) < 5!\n";
	}
}
