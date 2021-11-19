#include "std_lib_facilities.h"

struct Date {
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);
};
Date::Date(int year, int month, int day)
{
	if(year < 0) error("Invalid year"); 
	else 
		y = year;
	if(month < 1 || month > 12) error("Invalid month");
	else 
		m = month;
	if(day< 1 || day > 31) error("Invalid day");
	else 
		d = day;
}
void Date::add_day(int n){
	d += n;
	if(d > 31){
		d -= 31;
		m ++;
		if(m > 12){
			m -= 12;
			y++;
		}
	}
}
ostream& operator<<(ostream& os, const Date& d){
	return os << d.y << ". " << d.m << ". " << d.d << endl;
}

void f()
{
	Date my_birthday{2002, 7, 20};
	cout << "My birthday: " << my_birthday << endl;
	Date today {2021, 11, 19};
	cout << "Today: " << today << endl;
	Date last {2000,12,31};
	cout << "last: " << last << endl;
	last.add_day(1);
	cout << "last: " << last << endl;
	Date next = {2014,2,14};
	cout << "next: " << next << endl;
	Date christmas = Date{1976,12,24};
	cout << "christmas: " << christmas << endl;

}
int main(){
try{
	f();
	return 0;
}catch(exception& e){
	cerr <<e.what()<<"\n";
	return 1;
}
}