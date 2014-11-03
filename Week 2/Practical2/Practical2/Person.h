#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;
class Person{
private:
	string name;
	string tel;
public:
	Person();
	Person(string, string);
	void setName(string);
	string getName() const;
	void setTel(string);
	string getTel() const;


};

#endif