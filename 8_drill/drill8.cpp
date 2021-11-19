#include "std_lib_facilities.h"

struct Date {
	int y;
	int m; 
	int d;
};
void init_day(Date& dd, int y, int m, int d)
{
	if(y < 0) error("Invalid year"); 
	else 
		dd.y = y;
	if(m < 1 || m > 12) error("Invalid month");
	else 
		dd.m = m;
	if(d < 1 || d > 31) error("Invalid day");
	else 
		dd.d = d;
}
void add_day(Date& dd, int n){
	dd.d += n;
	if(dd.d > 31){
		dd.d -= 31;
		dd.m ++;
		if(dd.m > 12){
			dd.m -= 12;
			dd.y++;
		}
	}
}
ostream& operator<<(ostream& os, const Date& d){
	return os << d.y << ". " << d.m << ". " << d.d << endl;
}

void f()
{
	Date today;
	init_day(today, 2021, 11, 31);

	cout << "Today: " << today << endl;
	Date tomorrow = today;
	add_day(tomorrow,1);
	cout << "Tomorrow: " << tomorrow << endl;
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