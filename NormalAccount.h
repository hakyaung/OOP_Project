#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account {
private:
	int interest;

public:
	NormalAccount(int number, char* username, int money, int interest);
	virtual void ShowAccount() const;
	virtual void deposit(int money);
	int getInterest() const;
	virtual ~NormalAccount();
};

#endif // !__NORMALACCOUNT_H__