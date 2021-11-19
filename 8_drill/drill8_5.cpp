#include "std_lib_facilities.h"

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

Year operator++(Year& y){
  return y.year()+1;
}

ostream& operator<<(ostream& os, Year y){
    return os << y.year();
}

enum class Month 
{
    jan=0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

const vector<string> month_v ={
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

Month operator++(Month& m)
{
	if(m == Month::dec){
		m = Month::jan;		
	}else{
		m = Month(int(m)+1);
	}
    return m;
}

ostream& operator<<(ostream& os, Month m)
{
    return os << month_v[int(m)];
}

class Date
{
    public:
        class Invalid{};
        Date():y(Year{2002}),m(Month::jun),d(20){};
        Date(Year y, Month m, int d);
        void add_day(int n);
        Year year() const {return y;};
        Month month() const {return m;};
        int day() const {return d;};
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


int main()
try
{
    Date today {Year{1978},Month::jun, 25};
    Date tomorrow=today;
    tomorrow.add_day(1);   
    cout<<"Today: "<< today<<"\n"<<"Tomorrow: "<<tomorrow<<"\n";
    Date defaultk;
    cout<<"Default: "<<defaultk<<"\n";
    vector<Date> birthdays(10);
  
    return 0;
}catch(Year::Invalid){
    cerr <<"Invalid year."<<"\n";
        return 1;
}catch(Date::Invalid){
    cerr <<"Invalid date."<<"\n";
        return 2;
}
catch(exception& e)
{
    cerr <<e.what()<<"\n";
    return 3;
}