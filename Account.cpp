#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account() {
	accountNumber = 0;
	name = NULL;
	balance = 0;
}

Account::Account(int number, char* username, int money) :accountNumber(number), balance(money) {
	name = new char[strlen(username) + 1];

	strcpy(name, username);
}

Account::Account(Account& otherAccount) {
	accountNumber = otherAccount.accountNumber;
	balance = otherAccount.balance;
	name = new char[strlen(otherAccount.name) + 1];
	strcpy(name, otherAccount.name);
}

void Account::setAccountNumber(int number) {
	accountNumber = number;
}

void Account::setName(char* username) {
	if (name != NULL) {
		delete[] name;
	}

	name = new char[strlen(username) + 1];

	strcpy(name, username);
}

void Account::setBalance(int money) {
	balance = money;
}

int Account::getAccountNumber() const {
	return accountNumber;
}

int Account::getBalance() const {
	return balance;
}

char* Account::getName() const {
	return name;
}

void Account::deposit(int money) {
	balance += money;
}

int Account::withdrawal(int money) {
	if (balance - money < 0) {
		return -1;
	}
	else {
		balance -= money;
		return balance;
	}
}

void Account::ShowAccount() const {
	cout << "°èÁÂID: " << accountNumber << endl;
	cout << "ÀÌ ¸§: " << name << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}

Account::~Account() {
	cout << name << "[Account °´Ã¼ ¼Ò¸ê]" << endl;
	delete[] name;
}