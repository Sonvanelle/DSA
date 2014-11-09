#include <iostream>
#include "List.h"

using namespace std;

int main(){
	List nameList;						//(a)
	nameList.add("Annie");				//(b)
	nameList.add("Jacky");				//(c)
	nameList.add("Wendy");				//(d)
	nameList.print();					//(e)
	nameList.add(2, "Brenda");			//(f)
	nameList.print();					//(g)
	nameList.remove(3);					//(h)
	nameList.print();					//(i)
	nameList.remove(1);					//(j)
	nameList.print();					//(k)
	
	return 0;
}