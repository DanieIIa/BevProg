#include "std_lib_facilities.h"


void print_array10(ostream& os, int*a){
	for(int i = 0; i < 10; i++){
		os << a[i] << " ";
	}
	os << endl;
}
void print_array(ostream& os, int* a, int n){
	for(int i = 0; i < n; i++){
		os << a[i] << " ";
	}
	os << endl;
}
void print_vector(vector<int> &v, int n){
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){

	int *array= new int[10];
	for(int i = 0; i < 10; i++){
		cout << array[i] << " ";
	}
	cout << endl << endl;
	print_array10(cout, array);

	int *array2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	print_array10(cout, array2);

	int *array3 = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	print_array(cout, array3, 11);
	
	int *array4 = new int[20]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
	print_array(cout, array4, 20);


	delete[] array;
	delete[] array2;
	delete[] array3;
	delete[] array4;

	vector<int> vector1{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	print_vector(vector1, 10);

	vector<int> vector2{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	print_vector(vector2, 11);

	vector<int> vector3{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,  111, 112, 113, 114, 115, 116, 117, 118, 119};
	print_vector(vector3, 20);

	return 0;
}