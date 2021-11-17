#include "std_lib_facilities.h"
#include "my.h"

void print_foo(){
	cout << foo << endl;
}

void print(int i){
	cout << i << endl;
}
void swap_v(int a,int b){
	int temp; 
	temp = a;
	a=b;
	b=temp;
}
void swap_r(int& a,int& b){
	int temp;
	temp = a;
	a=b;
	b=temp;

}
/*oid swap_cr(const int& a, const int& b){ // konstans változók értékét nem lehet megváltoztatni
	int temp;
	temp = a;
	a= b;
	b=temp;
}*/