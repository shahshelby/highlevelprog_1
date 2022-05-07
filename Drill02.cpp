#include "std_lib_facilities.h"
#define k 1000 //task 6 defined value for use in calculatior


struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	// added Token for string
	Token(char ch, string n) :kind(ch),name(n) { }
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

const char let = '#'; //task 10 “declaration keyword” from let to #.
const char quit = 'Q'; 
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareR = 's';
const char findPow = 'p';


Token Token_stream::get()
{
	if (full) 
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
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
	case ',': //added for use with power in task 9
		return Token(ch); 
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
	{	
		cin.unget(); 
		double val;
		cin >> val; 
		return Token(number, val); 
	}
	
	
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();
			if (s == "#") return Token(let); //task 10 cont'd
			if (s == "exit") return Token(quit); 
			if (s == "sqrt") return Token(squareR); //added sqrt from task 7
			if (s == "pow") return Token(findPow);  //added pow from task 9

			return Token(name,s);
		}
		
		error("Bad token");
	}
}


void Token_stream::ignore(char c)
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

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;


double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return names[i].value;
	error("get: undefined name ", s);
}


void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}


bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();


double primary()
{
	
	Token t = ts.get();
	switch (t.kind) 
	{
	//changed "expression"
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return d;
	}
	//changed "-primary"
	case '-':
		return -primary();
	//changed to"number"
	case number:
		return t.value;
	//changed "let name = value"
	case name:
		return get_value(t.name);
	// sqrt from task 7
	case squareR:
	{
		t = ts.get();
		if (t.kind != '(')
			error("'(' is expected");
		double d = expression();
		if (d < 0)
			error("cannot be negative integers"); // task 8
		t = ts.get();
		if (t.kind != ')')
			error("')' is expected");

		return sqrt(d);
	}
	//changed "pow(expression, expression)"
	case findPow:
	{
	// for "(" otherwise Error
		t = ts.get();
		if (t.kind != '(')
			error("'(' is expected");
		double d = expression(); // for acquiring number
		t = ts.get();
		if (t.kind != ',') // for comma seperate pow func
			error("',' is expected");
		double i = expression(); // for getting i as pow
		t = ts.get();
		if (t.kind != ')') // for ")" othewise Error
			error("')' is expected");
		return pow(d, i); // return by c.math library pow func
	}
	default:
		error("primary is expected");
	}
}


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
			if (d == 0) error("/:divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%:divide by zero");
			left = fmod(left, d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}


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


double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a')
		error("name expected in declaration");

	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", name);

	double d = expression();
	names.push_back(Variable(name, d));

	return d;
}

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

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
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
{
	try {
		calculate();
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
}