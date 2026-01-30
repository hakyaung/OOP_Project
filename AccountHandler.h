#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include "Account.h"

class AccountHandler {
private:
	Account* ac[100];
	int acNumber;

public:
	AccountHandler();
	int printMenu();
	void createAccount();
	void deposit();
	void withdrawal();
	void printAllAccount();
	void exitProgram();
};

#endif // !__ACCOUNTHANDLER_H__
