#include "std_lib_facilities.h"

using namespace std;

class Year 
{
    static const int min = 1800;
    static const int max = 2200;
    public:
        class Invalid { };
        Year(int x) : y{x} { if (x<min || max<=x) throw Invalid{}; }
        int year() { return y; }
    private:
        int y;
};

Year operator++(Year& y)
{

    return y.year()+1;
}

ostream& operator<<(ostream& os, Year y){
    return os << y.year();
}

enum class Month 
{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_v =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
ostream& operator<<(ostream& os, Month m)
{
    return os << month_v[int(m)];
}
Month operator++(Month& m)
{
    if(m == Month::dec){
        m = Month(int(m)+1);
    }else{
        m = Month::jan;
    }
    return m;
}
class Date
{
    public:
        class Invalid{};
        Date(Year y, Month m, int d);
        Year year() {return y;};
        Month month() {return m;};
        int day() {return d;};
        void add_day(int n);
    private:
        Year y;
        Month m;
        int d;  
};

Date::Date(Year year, Month month, int day)
    : y(year), m(month), d(day)
{
	if(d<1 || d>31) error("Invalid day");
}

void Date::add_day(int n)
{
    d+=n;
    if(d>31)
    {
        ++m;
        d-=31;
    }
   if(m==Month::jan)
    {
        ++y;
    }
}

ostream& operator<<(ostream& os,Date& d)
{
    return os << d.year()<< ". " << d.month()<< ". " << d.day() << endl;
}

void f()
{
	Date dx3 {Year{1998}, Month::mar, 30};
	cout << dx3 << endl;
	dx3.add_day(3);
	cout << dx3 << endl;


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