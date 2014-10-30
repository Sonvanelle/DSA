#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee{
public:
	Employee(string, string, int = 0);
	void setFirstName(string);
	string getFirstName() const;
	void setLastName(string);
	string getLastName() const;
	void setMonthlySalary(int = 0);
	int getMonthlySalary() const;
private:
	string firstName;
	string lastName;
	int monthlySalary;
};
#endif