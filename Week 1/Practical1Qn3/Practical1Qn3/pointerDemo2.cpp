#include <iostream>
using namespace std;

void changeValue(int x, int* y){
	x += 10;
	*y += 10;
}

int main(){
	int x = 30;
	int y;
	y = x;
	changeValue(x, &y);
	cout << "X: " << x << ", Y: " << y << endl;
	return 0;
}