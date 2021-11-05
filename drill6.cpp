/*
	calculator08buggy.cpp
	Helpful comments removed.
	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token { //Token struktúra rétrehozása
	char kind;	//az inputról eldönti, hogy művelet vagy szám e
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), name(val) {}
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrt_num = 'S';
const char pow_num = 'P';



Token Token_stream::get()
{
//Buffer vizsgálata
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch; // a beírt művelet vizsgálata
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch); //visszaadja a megadott művelet értékét
	case '#':{
		    return Token(let); //visszaadja a let értékét
	}
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number, val); //visszaad egy számot
	}
	case 'k': { //egy előre definiált 1000-es
			cin.unget();
			char val;
			cin >> val;
			return Token(number,1000);
	}
	default:
		if (isalpha(ch)) { //a több karaktert igénylő műveletek értelmezése
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "#") return Token(let);
			if(s == "exit") return Token(quit);
			if(s == "sqrt") return Token(sqrt_num);
			if (s == "quit") return Token(name);
			if(s == "pow") return Token(pow_num);
			return Token{name, s};
		}
		error("Bad token"); //nem megfelelő karakter esetében létrejövő hibaüzenet
	}
}

void Token_stream::ignore(char c) //A tokken stream figyelmen kívül hagyása
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}


struct Variable { //a Variable struktura deklarációja
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; //names Variable típusú vektor deklarálása

double get_value(string s) //a names vektor értékét kéri le 
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s); // ha nincs ilyen értéke, hibaüzenet
}

void set_value(string s, double d) //a names vektor értékeit adja meg
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) //megvizsgálja, hogy van e ilyen szimbólum a names vektorban
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//A zárójelek a több karakteres műveletek, negatív számok kezelése
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': {	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case sqrt_num: {
		double d = expression();
			if(d < 0) error("cant be negative");
			else return sqrt(d);
			
	}
	case pow_num: {
			t = ts.get();
	        if (t.kind != '(') error("'(' expected");
	        double d = expression();
	        t = ts.get();
	        if (t.kind !=',') error("',' expected");
	        int i = expression();
	        t = ts.get();
	        if (t.kind != ')') error("')' expected");
	        return pow(d,i);
	}
	default:
		error("primary expected");
	}
}

//szorzás és osztás kezelése
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//összeadás és kivonás kezelése
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


double declaration() //új szimbólum beillesztése
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

//Az új változó deklarálásának lehetővé tétele
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() //minden figyelmen kívűl hagyása a ;-ig
{
	ts.ignore(print);
}

//konstans szimbólumok inicializálása
const string prompt = "> ";
const string result = "= ";

void calculate() //a számológép működésének összeállítása
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate(); // számológép meghívása
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}