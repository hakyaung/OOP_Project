#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MyStringClass.h"

class Account {
private:
	int accountNumber;
	String name;
	int balance;

public:
	Account();
	Account(int number, char* username, int money);
	Account(Account& otherAccount);

	void setAccountNumber(int number);
	void setName(char* username);
	void setBalance(int money);

	int getAccountNumber() const;
	int getBalance() const;
	const String& getName() const;

	virtual void deposit(int money);
	int withdrawal(int money);

	virtual void ShowAccount() const;

	virtual ~Account();
};

#endif // !__ACCOUNT_H__