#include <iostream>
#include "Employee.h"

using namespace std;
int main(){
	Employee emp1("Tan", "Ah Kow", -74);
	Employee emp2("Jeffrey", "Rey", 100);

	cout << "Original Salary" << endl;
	cout << "Employee 1, " << emp1.getFirstName() << " " << emp1.getLastName() << " have a yearly salary of: " << emp1.getMonthlySalary() * 12 << endl;
	cout << "Employee 2, " << emp2.getFirstName() << " " << emp2.getLastName() << " have a yearly salary of: " << emp2.getMonthlySalary() * 12 << endl;

	emp1.setMonthlySalary(emp1.getMonthlySalary() * 1.1);
	emp2.setMonthlySalary(emp2.getMonthlySalary() * 1.1);
	cout << "After 10% Raise" << endl;
	cout << "Employee 1, " << emp1.getFirstName() << " " << emp1.getLastName() << " have a yearly salary of: " << emp1.getMonthlySalary() * 12 << endl;
	cout << "Employee 2, " << emp2.getFirstName() << " " << emp2.getLastName() << " have a yearly salary of: " << emp2.getMonthlySalary() * 12 << endl;
	return 0;
}