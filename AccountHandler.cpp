#include <iostream>
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
using namespace std;

namespace CREDIT_RATING {
	enum {
		RATING_A = 7,
		RATING_B = 4,
		RATING_C = 2
	};
}

AccountHandler::AccountHandler() : acNumber(0) {}

int AccountHandler::printMenu() {
	int n = -1;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> n;

	return n;
}

void AccountHandler::createAccount() {
	int number, money, chooseNum, interest, rating;
	char name[50];

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> chooseNum;
	if (chooseNum == 1) {
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> number;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;
		cout << "이자율: ";
		cin >> interest;
		ac[acNumber] = new NormalAccount(number, name, money, interest);
		acNumber++;
	}
	else {
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: ";
		cin >> number;
		cout << "이 름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> money;
		cout << "이자율: ";
		cin >> interest;
		cout << "신용등급(1 to A, 2 to B, 3 to C): ";
		cin >> rating;
		switch (rating) {
		case 1:
			ac[acNumber] = new HighCreditAccount(number, name, money, interest, CREDIT_RATING::RATING_A);
			break;
		case 2:
			ac[acNumber] = new HighCreditAccount(number, name, money, interest, CREDIT_RATING::RATING_B);
			break;
		case 3:
			ac[acNumber] = new HighCreditAccount(number, name, money, interest, CREDIT_RATING::RATING_C);
			break;
		default:
			break;
		}
		acNumber++;
	}
}

void AccountHandler::deposit() {
	int number, money;

	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> number;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < acNumber; i++) {
		if (ac[i]->getAccountNumber() == number) {
			ac[i]->deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}

	cout << "해당계좌ID는 없는 ID 입니다." << endl;
}

void AccountHandler::withdrawal() {
	int number, money;

	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> number;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < acNumber; i++) {
		if (ac[i]->getAccountNumber() == number) {
			int nowBalance = ac[i]->withdrawal(money);
			if (nowBalance != -1) {
				cout << "출금완료" << endl;
				cout << "잔금" << nowBalance << endl;
				return;
			}
			else {
				cout << "잔액부족으로 인한 출금불가" << endl;
				return;
			}
		}
	}

	cout << "해당 계좌ID는 없는 ID 입니다." << endl;
}

void AccountHandler::printAllAccount() {
	cout << "[등록된 계좌정보]" << endl;

	for (int i = 0; i < acNumber; i++) {
		ac[i]->ShowAccount();
		cout << endl;
	}
}

void AccountHandler::exitProgram() {
	for (int i = 0; i < acNumber; i++) {
		delete ac[i];
	}
}