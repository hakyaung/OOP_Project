#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;

int main() {
	AccountHandler manager;

	while (true) {
		bool sw = false;
		switch (manager.printMenu()) {
		case 1:
			manager.createAccount();
			break;
		case 2:
			manager.deposit();
			break;
		case 3:
			manager.withdrawal();
			break;
		case 4:
			manager.printAllAccount();
			break;
		case 5:
			cout << "프로그램 종료" << endl;
			sw = true;
			manager.exitProgram();
			break;
		default:
			break;
		}

		if (sw == true) {
			break;
		}
	}

	return 0;
}