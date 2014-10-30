#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using std::string;

class Account{
private:
	double acctBalance;


public:
	Account(const double &);
	virtual void credit(const double &);
	virtual void debit(const double &);
	double getBalance() const;
};



#endif