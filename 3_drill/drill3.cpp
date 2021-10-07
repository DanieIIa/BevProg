#include "std_lib_facilities.h"


int main(){
	
	
	double a = 0, minn = 0, maxx = 0, sum = 0;
	string unit = "";
	const double m_to_cm = 10, in_to_cm = 2.54, ft_to_in = 12;
	char ki;
	vector<double> values;

	cout << "Please enter one value and a unit (cm, m, in, ft)" << endl;

	while((cin >> a) && a != '|'){

		cin >> unit;

		if(a <= 0){
			error("Wrong length value");
		}
		if(unit == "cm"){
			a /= m_to_cm;
			cout << a << "m" << endl; 

		}else if(unit == "m"){
			cout << a << "m" << endl;

		}else if(unit == "in"){
			a *= in_to_cm;
			a /= m_to_cm;
			cout << a << "m" << endl;
			
		}else if(unit == "ft"){
			a *= ft_to_in;
			a *= in_to_cm;
			a /= m_to_cm;
			cout << a << "m" << endl;
			
		}else{
			error("Wrong unit");
		}

		sum += a;
		values.push_back(a);

		if(minn > a || minn == 0){
			minn = a;
			cout << a << " the smallest so far." << endl;

		}
		else if(maxx < a){
			maxx = a;
			cout << a << " the largest so far." << endl;

		}
		cout << "Please enter one value and a unit (cm, m, in, ft)" << endl;
		
		/*cout << a  << " " << b << endl;
		if(a > b){
			cout << "The larger value is: " << a << endl;
			cout << "The smaller value is: " << b << endl;
		}else if(a < b){
			cout << "The larger value is: " << b << endl;
			cout << "The smaller value is: " << a << endl;
		}else if(a == b){
			cout << "The numbers are equal." << endl;
		}else if(a % b < 1 % 100){
			cout << "The numbers are almost equal" << endl;
		}*/

	}
	cout << endl << "The smallest value: " << minn << endl;
	cout << "The largest value: " << maxx << endl;
	cout << "sum = " << sum << endl << endl;


	sort(values);
	for(int i = 0; i < values.size(); i++){
		cout << i+1 << " " << values[i] << endl;
	}

	return 0;
}