#include <iostream>
#include "CheckingAccount.h"

using namespace std;
CheckingAccount::CheckingAccount(const double &balance, const double &initFee) :Account(balance){
	feeCharged = initFee;
}
void CheckingAccount::debit(const double &amount){
	if (getBalance() >= (amount + feeCharged)){
		Account::debit(amount + feeCharged);
		cout << "Fee Charged for debit transaction: $" << feeCharged << endl;
	}
	else {
		cout << "Amount exceeds what is in the balance. Amount is not debited" << endl;
	}
}
void CheckingAccount::credit(const double &amount){
	Account::credit(amount);
	Account::debit(feeCharged);
	cout << "Fee Charged for credit transaction: $" << feeCharged << endl;
}