#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
class CheckingAccount : public Account{
private:
	double feeCharged;
public:
	CheckingAccount(const double &, const double &);
	void credit(const double &);
	void debit(const double &);
};
#endif