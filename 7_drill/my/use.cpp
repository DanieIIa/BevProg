#include "my.h"
#include <iostream>


using namespace std;

int foo = 7;
int main(){

	print(foo);
	print_foo();

	char cc;
	cin>>cc;

	int x = 7;
	int y = 9;
	cout << "x = " << x << " y = " << y << endl; 
	swap_r(x,y);
	swap_v(7,9);
	cout << "x = " << x << " y = " << y << endl; 
	/*const int cx = 7; // konstansok értékét nem lehet megváltoztatni
	const int cy = 9;
	swap_(cx,cy);*/
	/*swap_(7.7,9.9); // double számokra nem működik, csak intekre
	double dx = 7.7;
	double dy = 9.9;
	swap_(dx,dy);*/
	return 0;
}