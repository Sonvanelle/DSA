#include <iostream>
#include "Employee.h"

using namespace std;
Employee::Employee(string fn, string ln, int ms){
	firstName = fn;
	lastName = ln;
	if (ms >= 0){
		monthlySalary = ms;
	}
	else {
		monthlySalary = 0;
	}
}

void Employee::setFirstName(string fn){
	firstName = fn;
}
string Employee::getFirstName() const{
	return firstName;
}
void Employee::setLastName(string ln){
	lastName = ln;
}
string Employee::getLastName() const
{
	return lastName;
}
void Employee::setMonthlySalary(int ms){
	if (ms >= 0){
		monthlySalary = ms;
	}
	else {
		monthlySalary = 0;
	}
}
int Employee::getMonthlySalary() const{
	return monthlySalary;
}