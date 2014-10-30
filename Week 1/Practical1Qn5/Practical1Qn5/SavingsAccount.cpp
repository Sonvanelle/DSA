#include <iostream>
#include "SavingsAccount.h"

using namespace std;
SavingsAccount::SavingsAccount(const double &balance, const double &intRate) :Account(balance){
	interestRate = intRate;
}

double SavingsAccount::calculateInterest(){
	return Account::getBalance() * interestRate;
}