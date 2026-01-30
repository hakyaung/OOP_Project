#include <iostream>
#include "NormalAccount.h"
using namespace std;

NormalAccount::NormalAccount(int number, char* username, int money, int interest) : Account(number, username, money), interest(interest) {}

void NormalAccount::ShowAccount() const {
	Account::ShowAccount();
	cout << "이자율: " << interest << '%' << endl;
}

void NormalAccount::deposit(int money) {
	int p = getBalance() * interest / 100;
	Account::deposit(money);
	Account::deposit(p);
}

int NormalAccount::getInterest() const {
	return interest;
}

NormalAccount::~NormalAccount() {
	cout << getName() << "[NormalAccount 소멸자]" << endl;
}