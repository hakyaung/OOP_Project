#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyStringClass.h"
#include "Account.h"
using namespace std;

Account::Account() :accountNumber(0), name(), balance(0) {}

Account::Account(int number, char* username, int money) :accountNumber(number), name(username),  balance(money) {}

Account::Account(Account& otherAccount) {
	accountNumber = otherAccount.accountNumber;
	balance = otherAccount.balance;
	name = otherAccount.name;
}

void Account::setAccountNumber(int number) {
	accountNumber = number;
}

void Account::setName(char* username) {
	name = username;
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

const String& Account::getName() const {
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
}