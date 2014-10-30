#include <iostream>
#include "Account.h"

using namespace std;
Account::Account(const double &balance){
	if (balance < 0){
		std::cout << "INVALID BALANCE" << std::endl;
		acctBalance = 0;
	}
	else {
		acctBalance = balance;
	}
}


void Account::credit(const double &amount){
	acctBalance += amount;
}

void Account::debit(const double &amount){
	acctBalance -= amount;
}

double Account::getBalance() const{
	return acctBalance;
}