#include <iostream>
#include "Person.h"

Person::Person(){ }

Person::Person(string Name, string telNo){
	name = Name;
	tel = telNo;
}

void Person::setName(string Name){
	name = Name;
}

string Person::getName() const{
	return name;
}

void Person::setTel(string telNo){
	tel = telNo;
}

string Person::getTel() const{
	return tel;
}