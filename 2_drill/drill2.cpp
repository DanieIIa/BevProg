#include "std_lib_facilities.h"


int main(){
	
	string first_name;
	
	cout << "Enter the name of the person you want to write to" << endl;
	cin >> first_name;
	cout << "Dear, " << first_name << endl;
	cout << "How are you? \n I am fine. \n I miss you." << endl;
	
	string friend_name;
	
	cout << "Enter the name of the your friend." << endl;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately." << endl;
	
	char friend_sex = 0;
	
	cout << "Enter an m if is male and an f if is female" << endl;
	cin >> friend_sex;
	if(friend_sex == 'm'){
		cout << "If you see " << friend_name << " please ask him to call me." << endl;
	}
	else if(friend_sex == 'f'){
		cout << "If you see " << friend_name << " please ask her to call me." << endl;
		
	}
	
	int age;
	
	cout << "Enter your age" << endl;
	cin >> age;
	
	if(age <= 0 || age >= 110){
		simple_error("you'r kidding!");
	}else if(age < 12){
		cout << "Next year you will be " << age + 1 << endl;
	}else if(age == 17){
		cout << "Next year you will be able to vote" << endl;
	}else if(age > 70){
		cout << "I hope you are enjoying retirement" << endl;
	}
	
	cout << "Yours sincerely, \t \t Mónika" << endl;
	return 0;
}
