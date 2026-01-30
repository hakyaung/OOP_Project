#include <iostream>
#include "HighCreditAccount.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int number, char* username, int money, int interest, int rating) :NormalAccount(number, username, money, interest), rating(rating) {}

void HighCreditAccount::ShowAccount() const {
	NormalAccount::ShowAccount();
	cout << "신용등급: ";
	switch (rating) {
	case 7:
		cout << 'A';
		break;
	case 4:
		cout << 'B';
		break;
	case 2:
		cout << 'C';
		break;
	default:
		break;
	}
	cout << endl;
}

void HighCreditAccount::deposit(int money) {
	int p = getBalance() * rating / 100;
	NormalAccount::deposit(money);
	Account::deposit(p);
}

int HighCreditAccount::getRating() const {
	return rating;
}

HighCreditAccount::~HighCreditAccount() {
	cout << getName() <<"[HighCreditAccount 소멸자]" << endl;
}