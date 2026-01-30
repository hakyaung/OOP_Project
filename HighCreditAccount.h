#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int rating;

public:
	HighCreditAccount(int number, char* username, int money, int interest, int rating);
	virtual void ShowAccount() const;
	virtual void deposit(int money);
	int getRating() const;
	virtual ~HighCreditAccount();
};

#endif // !__HIGHCREDITACCOUNT_H__
