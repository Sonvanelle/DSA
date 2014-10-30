#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;
int main(){
	SavingsAccount sa1(200.0, 0.03);
	SavingsAccount sa2(400.0, 0.03);
	CheckingAccount ca1(600.0, 2);
	vector <Account *> acctVector(3);

	// Init Vector
	acctVector[0] = &sa1;
	acctVector[1] = &sa2;
	acctVector[2] = &ca1;

	//Allow user to specify amount to withdraw
	int wit, dep;

	//Process account
	for (size_t i = 0; i < acctVector.size(); i++){
		cout << "Enter Amount to withdraw in Account " << i << ": $";
		cin >> wit;
		cout << "Enter Amount to deposit in Account " << i << ": $";
		cin >> dep;
		//Downcast
		SavingsAccount* derivedPtr = dynamic_cast <SavingsAccount*>(acctVector[i]);
		if (derivedPtr != 0){
			int interest;
			derivedPtr->credit(dep);
			interest = derivedPtr->calculateInterest();
			derivedPtr->debit(wit);
			cout << "=================" << endl;
			cout << "Savings Account" << endl;
			cout << "=================" << endl;
			cout << "After withdrawing $" << wit << " and depositing $" << dep << " with interest added of $" << interest << "," << endl;
			cout << "Account Balance: $" << derivedPtr->getBalance() << endl;
		}
		else {
			CheckingAccount* derivedPtr2 = dynamic_cast <CheckingAccount*>(acctVector[i]);
			derivedPtr2->credit(dep);
			derivedPtr2->debit(dep);
			cout << "=================" << endl;
			cout << "Checking Account" << endl;
			cout << "=================" << endl;
			cout << "After withdrawing $" << wit << " and depositing $" << dep << "," << endl;
			cout << "Account Balance: $" << derivedPtr2->getBalance() << endl;
		}
		cout << endl;
	}


	return 0;
}